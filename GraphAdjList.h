#include <iostream>
using namespace std;

// Nodo para la lista de adyacencia
struct Node {
    int vertex;
    Node* next;
};

// Clase para el grafo
class GraphAdjList {
private:
    int numVertices;
    Node** adjList; // Arreglo de punteros a listas enlazadas

    // Crear un nuevo nodo
    Node* createNode(int vertex) {
        Node* newNode = new Node();
        newNode->vertex = vertex;
        newNode->next = nullptr;
        return newNode;
    }

public:
    // Constructor
    GraphAdjList(int vertices) {
        numVertices = vertices;
        adjList = new Node*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = nullptr;
        }
    }

    // Agregar arista
    void addEdge(int src, int dest) {
        Node* newNode = createNode(dest);
        newNode->next = adjList[src];
        adjList[src] = newNode;

        // Para grafo no dirigido, agregar también la arista inversa
        newNode = createNode(src);
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

    // Mostrar grafo
    void displayGraph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Nodo " << i << ": ";
            Node* temp = adjList[i];
            while (temp) {
                cout << temp->vertex << " -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    // Eliminar arista
    void removeEdge(int src, int dest) {
        // Eliminar dest de la lista de src
        Node* temp = adjList[src];
        Node* prev = nullptr;
        while (temp != nullptr && temp->vertex != dest) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {
            if (prev != nullptr) {
                prev->next = temp->next;
            } else {
                adjList[src] = temp->next;
            }
            delete temp;
        }

        // Eliminar src de la lista de dest
        temp = adjList[dest];
        prev = nullptr;
        while (temp != nullptr && temp->vertex != src) {
            prev = temp;
            temp = temp->next;
        }
        if (temp != nullptr) {
            if (prev != nullptr) {
                prev->next = temp->next;
            } else {
                adjList[dest] = temp->next;
            }
            delete temp;
        }
    }

    // Destructor
    ~GraphAdjList() {
        for (int i = 0; i < numVertices; i++) {
            Node* temp = adjList[i];
            while (temp) {
                Node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
        delete[] adjList;
    }
};

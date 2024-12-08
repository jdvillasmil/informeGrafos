#include <iostream>
using namespace std;

// Clase para el grafo con matriz de adyacencia
class GraphAdjMatrix {
private:
    int numVertices;
    int** adjMatrix;

public:
    // Constructor
    GraphAdjMatrix(int vertices) {
        numVertices = vertices;
        adjMatrix = new int*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new int[numVertices];
            for (int j = 0; j < numVertices; j++) {
                adjMatrix[i][j] = 0; // Inicializar matriz a 0
            }
        }
    }

    // Agregar arista
    void addEdge(int src, int dest) {
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // Eliminar esta línea si el grafo es dirigido
    }

    // Mostrar grafo
    void displayGraph() {
        cout << "Matriz de Adyacencia:" << endl;
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Eliminar arista
    void removeEdge(int src, int dest) {
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0; // Eliminar esta línea si el grafo es dirigido
    }

    // Destructor
    ~GraphAdjMatrix() {
        for (int i = 0; i < numVertices; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

#include <iostream>
#include "GraphAdjList.h"
#include "GraphAdjMatrix.h"
using namespace std;

int main() {
    // Pruebas con lista de adyacencia
    cout << "Grafo con Lista de Adyacencia:" << endl;
    GraphAdjList graphList(5);
    graphList.addEdge(0, 1);
    graphList.addEdge(0, 4);
    graphList.addEdge(1, 2);
    graphList.addEdge(1, 3);
    graphList.displayGraph();
    graphList.removeEdge(1, 4);
    cout << "Despues de eliminar arista 1-4:" << endl;
    graphList.displayGraph();

    // Pruebas con matriz de adyacencia
    cout << "\nGrafo con Matriz de Adyacencia:" << endl;
    GraphAdjMatrix graphMatrix(5);
    graphMatrix.addEdge(0, 1);
    graphMatrix.addEdge(0, 4);
    graphMatrix.addEdge(1, 2);
    graphMatrix.addEdge(1, 3);
    graphMatrix.displayGraph();
    graphMatrix.removeEdge(1, 4);
    cout << "Despues de eliminar arista 1-4:" << endl;
    graphMatrix.displayGraph();

    return 0;
}

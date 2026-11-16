
#include <iostream>
using namespace std;

const int SIZE = 6;
const int INF = 99999;

class Graph {
private:
    int adjacencyMatrix[SIZE][SIZE];
    char vertices[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F'};

public:
    Graph() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }

        adjacencyMatrix[0][1] = 4;
        adjacencyMatrix[0][2] = 2;
        adjacencyMatrix[1][2] = 5;
        adjacencyMatrix[1][3] = 10;
        adjacencyMatrix[2][4] = 3;
        adjacencyMatrix[4][3] = 4;
        adjacencyMatrix[3][5] = 11;
    }

    void displayPath(int parent[], int vertex) {
        if (parent[vertex] == -1) {
            cout << vertices[vertex];
            return;
        }

        displayPath(parent, parent[vertex]);
        cout << " -> " << vertices[vertex];
    }

    void dijkstra(int start) {
        int distance[SIZE];
        int parent[SIZE];
        bool visited[SIZE];

        for (int i = 0; i < SIZE; i++) {
            distance[i] = INF;
            parent[i] = -1;
            visited[i] = false;
        }

        distance[start] = 0;

        for (int count = 0; count < SIZE - 1; count++) {
            int minimum = INF;
            int current = -1;

            for (int i = 0; i < SIZE; i++) {
                if (!visited[i] && distance[i] < minimum) {
                    minimum = distance[i];
                    current = i;
                }
            }

            if (current == -1)
                break;

            visited[current] = true;

            for (int j = 0; j < SIZE; j++) {
                if (adjacencyMatrix[current][j] != 0 &&
                    !visited[j] &&
                    distance[current] + adjacencyMatrix[current][j] < distance[j]) {

                    distance[j] = distance[current] + adjacencyMatrix[current][j];
                    parent[j] = current;
                }
            }
        }

        cout << "\nShortest Paths from A:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << "\nDestination: " << vertices[i] << endl;

            if (distance[i] == INF) {
                cout << "Unreachable\n";
            }
            else {
                cout << "Path: ";
                displayPath(parent, i);
                cout << "\nTotal Cost: " << distance[i] << endl;
            }
        }
    }
};

int main() {
    Graph universityGraph;

    universityGraph.dijkstra(0);

    return 0;
}


#include <iostream>
#include <queue>
using namespace std;

const int SIZE = 6;

class Graph {
private:
    int adjacencyMatrix[SIZE][SIZE];

public:
    Graph() {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                adjacencyMatrix[i][j] = 0;
            }
        }

        adjacencyMatrix[0][1] = 1;
        adjacencyMatrix[0][2] = 1;
        adjacencyMatrix[1][3] = 1;
        adjacencyMatrix[2][4] = 1;
        adjacencyMatrix[2][5] = 1;
        adjacencyMatrix[3][5] = 1;
    }

    void topologicalSort() {
        int indegree[SIZE] = {0};

        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (adjacencyMatrix[i][j] == 1) {
                    indegree[j]++;
                }
            }
        }

        cout << "Indegrees:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << "Vertex " << i << " = " << indegree[i] << endl;
        }

        queue<int> courseQueue;

        for (int i = 0; i < SIZE; i++) {
            if (indegree[i] == 0) {
                courseQueue.push(i);
            }
        }

        int order[SIZE];
        int count = 0;

        while (!courseQueue.empty()) {
            int current = courseQueue.front();
            courseQueue.pop();

            order[count] = current;
            count++;

            for (int j = 0; j < SIZE; j++) {
                if (adjacencyMatrix[current][j] == 1) {
                    indegree[j]--;

                    if (indegree[j] == 0) {
                        courseQueue.push(j);
                    }
                }
            }
        }

        if (count != SIZE) {
            cout << "\nCycle detected!\n";
            cout << "No valid course completion order exists.\n";
        }
        else {
            cout << "\nValid Course Completion Order:\n";

            for (int i = 0; i < SIZE; i++) {
                cout << order[i] << " ";
            }

            cout << "\nNo cycle detected.\n";
        }
    }
};

int main() {
    Graph universityGraph;

    universityGraph.topologicalSort();

    return 0;
}

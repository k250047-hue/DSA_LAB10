
#include <iostream>
using namespace std;

const int SIZE = 6;

class Graph {
private:
    int adjacencyMatrix[SIZE][SIZE];
    char departments[SIZE] = {'A', 'B', 'C', 'D', 'E', 'F'};

public:
    Graph() {
        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                adjacencyMatrix[row][col] = 0;
            }
        }
    }

    void insertEdge(int source, int destination, int weight) {
        adjacencyMatrix[source][destination] = weight;
        cout << "Edge inserted successfully.\n";
    }

    void deleteEdge(int source, int destination) {
        adjacencyMatrix[source][destination] = 0;
        cout << "Edge deleted successfully.\n";
    }

    void displayMatrix() {
        cout << "\nAdjacency Matrix:\n\n";

        cout << "  ";
        for (int i = 0; i < SIZE; i++) {
            cout << departments[i] << " ";
        }

        cout << endl;

        for (int row = 0; row < SIZE; row++) {
            cout << departments[row] << " ";

            for (int col = 0; col < SIZE; col++) {
                cout << adjacencyMatrix[row][col] << " ";
            }

            cout << endl;
        }
    }

    void findOutgoingEdges(int vertex) {
        bool found = false;

        cout << "\nOutgoing edges of "
             << departments[vertex] << ":\n";

        for (int col = 0; col < SIZE; col++) {
            if (adjacencyMatrix[vertex][col] != 0) {
                cout << departments[vertex] << " -> "
                     << departments[col]
                     << " (Weight: "
                     << adjacencyMatrix[vertex][col]
                     << ")\n";

                found = true;
            }
        }

        if (!found) {
            cout << "No outgoing edges.\n";
        }
    }

    void findIncomingEdges(int vertex) {
        bool found = false;

        cout << "\nIncoming edges of "
             << departments[vertex] << ":\n";

        for (int row = 0; row < SIZE; row++) {
            if (adjacencyMatrix[row][vertex] != 0) {
                cout << departments[row] << " -> "
                     << departments[vertex]
                     << " (Weight: "
                     << adjacencyMatrix[row][vertex]
                     << ")\n";

                found = true;
            }
        }

        if (!found) {
            cout << "No incoming edges.\n";
        }
    }
};

int main() {
    Graph universityGraph;

    universityGraph.insertEdge(0, 1, 4);
    universityGraph.insertEdge(0, 2, 2);
    universityGraph.insertEdge(1, 2, 5);
    universityGraph.insertEdge(1, 3, 10);
    universityGraph.insertEdge(2, 4, 3);
    universityGraph.insertEdge(4, 3, 4);
    universityGraph.insertEdge(3, 5, 11);

    int choice, source, destination, weight, vertex;

    do {
        cout << "\n===== UNIVERSITY GRAPH =====\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Display Adjacency Matrix\n";
        cout << "4. Find Outgoing Edges\n";
        cout << "5. Find Incoming Edges\n";
        cout << "6. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source vertex (0-5): ";
            cin >> source;

            cout << "Enter destination vertex (0-5): ";
            cin >> destination;

            cout << "Enter communication cost: ";
            cin >> weight;

            if (source >= 0 && source < SIZE &&
                destination >= 0 && destination < SIZE &&
                weight > 0) {
                universityGraph.insertEdge(source, destination, weight);
            }
            else {
                cout << "Invalid input.\n";
            }
            break;

        case 2:
            cout << "Enter source vertex (0-5): ";
            cin >> source;

            cout << "Enter destination vertex (0-5): ";
            cin >> destination;

            if (source >= 0 && source < SIZE &&
                destination >= 0 && destination < SIZE) {
                universityGraph.deleteEdge(source, destination);
            }
            else {
                cout << "Invalid input.\n";
            }
            break;

        case 3:
            universityGraph.displayMatrix();
            break;

        case 4:
            cout << "Enter vertex (0-5): ";
            cin >> vertex;

            if (vertex >= 0 && vertex < SIZE) {
                universityGraph.findOutgoingEdges(vertex);
            }
            else {
                cout << "Invalid vertex.\n";
            }
            break;

        case 5:
            cout << "Enter vertex (0-5): ";
            cin >> vertex;

            if (vertex >= 0 && vertex < SIZE) {
                universityGraph.findIncomingEdges(vertex);
            }
            else {
                cout << "Invalid vertex\n";
            }
            break;

        case 6:
            cout << "Exiting program\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}

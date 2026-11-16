#include <iostream>
#include <climits>
using namespace std;

#define vertices 7

int main()
{
    int graph[vertices][vertices] = {
        {0, 1, 0, 5, 0, 0, 0},
        {1, 0, 4, 3, 0, 0, 0},
        {0, 4, 0, 0, 7, 0, 0},
        {5, 3, 0, 0, 1, 0, 4},
        {0, 0, 7, 1, 0, 1, 2},
        {0, 0, 0, 0, 1, 0, 10},
        {0, 0, 0, 4, 2, 10, 0}
    };

    int parent[vertices];
    int minWeight[vertices];
    bool visited[vertices];

    for (int i = 0; i < vertices; i++)
    {
        minWeight[i] = INT_MAX;
        visited[i] = false;
    }

    minWeight[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++)
    {
        int minimum = INT_MAX;
        int selectedVertex = -1;

        for (int i = 0; i < vertices; i++)
        {
            if (!visited[i] && minWeight[i] < minimum)
            {
                minimum = minWeight[i];
                selectedVertex = i;
            }
        }

        visited[selectedVertex] = true;

        for (int j = 0; j < vertices; j++)
        {
            if (graph[selectedVertex][j] != 0 &&
                !visited[j] &&
                graph[selectedVertex][j] < minWeight[j])
            {
                parent[j] = selectedVertex;
                minWeight[j] = graph[selectedVertex][j];
            }
        }
    }

    int totalWeight = 0;

    cout << "Minimum Spanning Tree:" << endl;

    for (int i = 1; i < vertices; i++)
    {
        cout << char(parent[i] + 'A') << " - "
             << char(i + 'A') << " : "
             << graph[i][parent[i]] << endl;

        totalWeight += graph[i][parent[i]];
    }

    cout << "Total Minimum Cost = " << totalWeight;

    return 0;
}
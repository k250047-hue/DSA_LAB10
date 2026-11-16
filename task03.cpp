
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    char source;
    char destination;
    int weight;
};

int parent[6];

int findParent(int vertex)
{
    if (parent[vertex] == vertex)
        return vertex;

    return parent[vertex] = findParent(parent[vertex]);
}

void unionSet(int u, int v)
{
    int parentU = findParent(u);
    int parentV = findParent(v);

    parent[parentU] = parentV;
}

int main()
{
    Edge edges[] = {
        {'A', 'B', 3},
        {'A', 'C', 5},
        {'A', 'D', 9},
        {'B', 'C', 3},
        {'B', 'D', 4},
        {'B', 'E', 7},
        {'C', 'D', 2},
        {'C', 'E', 6},
        {'C', 'F', 8},
        {'D', 'E', 2},
        {'D', 'F', 2},
        {'E', 'F', 5}
    };

    int totalEdges = 12;

    sort(edges, edges + totalEdges, [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    for (int i = 0; i < 6; i++)
    {
        parent[i] = i;
    }

    int totalWeight = 0;
    int selectedEdges = 0;

    cout << "Minimum Spanning Tree:" << endl;

    for (int i = 0; i < totalEdges; i++)
    {
        int u = edges[i].source - 'A';
        int v = edges[i].destination - 'A';

        if (findParent(u) != findParent(v))
        {
            unionSet(u, v);

            cout << edges[i].source << " - "
                 << edges[i].destination << " : "
                 << edges[i].weight << endl;

            totalWeight += edges[i].weight;
            selectedEdges++;

            if (selectedEdges == 5)
                break;
        }
    }

    cout << "\nTotal Minimum Cost = " << totalWeight;

    return 0;
}
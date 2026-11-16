#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

void addDirectedEdge(vector<vector<int>>& graph, int from, int to)
{
    graph[from].push_back(to);
}

void addUndirectedEdge(vector<vector<int>>& graph, int first, int second)
{
    graph[first].push_back(second);
    graph[second].push_back(first);
}

void bfs(vector<vector<int>>& graph, vector<string>& nodes, int start)
{
    vector<bool> visited(nodes.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        cout << nodes[current] << " ";

        for (int i = 0; i < graph[current].size(); i++)
        {
            int nextNode = graph[current][i];

            if (!visited[nextNode])
            {
                visited[nextNode] = true;
                q.push(nextNode);
            }
        }
    }

    cout << endl;
}

void dfsVisit(vector<vector<int>>& graph, vector<string>& nodes,
              vector<bool>& visited, int current)
{
    visited[current] = true;

    cout << nodes[current] << " ";

    for (int i = 0; i < graph[current].size(); i++)
    {
        int nextNode = graph[current][i];

        if (!visited[nextNode])
        {
            dfsVisit(graph, nodes, visited, nextNode);
        }
    }
}

void dfs(vector<vector<int>>& graph, vector<string>& nodes, int start)
{
    vector<bool> visited(nodes.size(), false);

    cout << "DFS: ";

    dfsVisit(graph, nodes, visited, start);

    cout << endl;
}

void displayResult(string graphName, vector<vector<int>>& graph,
                   vector<string>& nodes, int start)
{
    cout << "\nGraph " << graphName << endl;

    bfs(graph, nodes, start);
    dfs(graph, nodes, start);
}

int main()
{
    vector<string> nodesA = {"a", "b", "c", "d", "e"};
    vector<vector<int>> graphA(5);

    addDirectedEdge(graphA, 0, 1);
    addDirectedEdge(graphA, 0, 2);
    addDirectedEdge(graphA, 0, 3);
    addDirectedEdge(graphA, 0, 4);
    addDirectedEdge(graphA, 1, 3);
    addDirectedEdge(graphA, 2, 3);
    addDirectedEdge(graphA, 2, 4);
    addDirectedEdge(graphA, 3, 4);

    displayResult("A", graphA, nodesA, 0);


    vector<string> nodesB = {"1", "2", "3", "4", "5", "6", "7"};
    vector<vector<int>> graphB(7);

    addDirectedEdge(graphB, 0, 1);
    addDirectedEdge(graphB, 0, 3);
    addDirectedEdge(graphB, 1, 2);
    addDirectedEdge(graphB, 1, 4);
    addDirectedEdge(graphB, 2, 6);
    addDirectedEdge(graphB, 3, 5);
    addDirectedEdge(graphB, 4, 6);
    addDirectedEdge(graphB, 5, 6);

    displayResult("B", graphB, nodesB, 0);


    vector<string> nodesC = {"A", "B", "C", "D", "E", "F"};
    vector<vector<int>> graphC(6);

    addDirectedEdge(graphC, 0, 2);
    addDirectedEdge(graphC, 0, 1);
    addDirectedEdge(graphC, 2, 3);
    addDirectedEdge(graphC, 2, 1);
    addDirectedEdge(graphC, 2, 4);
    addDirectedEdge(graphC, 3, 4);
    addDirectedEdge(graphC, 1, 5);
    addDirectedEdge(graphC, 4, 5);

    displayResult("C", graphC, nodesC, 0);


    vector<string> nodesD = {"A", "B", "C", "D", "E", "F"};
    vector<vector<int>> graphD(6);

    addDirectedEdge(graphD, 0, 2);
    addDirectedEdge(graphD, 0, 1);
    addDirectedEdge(graphD, 2, 3);
    addDirectedEdge(graphD, 2, 1);
    addDirectedEdge(graphD, 2, 4);
    addDirectedEdge(graphD, 3, 4);
    addDirectedEdge(graphD, 1, 5);
    addDirectedEdge(graphD, 4, 5);

    displayResult("D", graphD, nodesD, 0);


    vector<string> nodesE = {"A", "B", "C", "D", "E", "F", "G", "H"};
    vector<vector<int>> graphE(8);

    addDirectedEdge(graphE, 0, 1);
    addDirectedEdge(graphE, 0, 3);
    addDirectedEdge(graphE, 1, 2);
    addDirectedEdge(graphE, 1, 5);
    addDirectedEdge(graphE, 2, 4);
    addDirectedEdge(graphE, 2, 6);
    addDirectedEdge(graphE, 2, 7);
    addDirectedEdge(graphE, 3, 5);
    addDirectedEdge(graphE, 4, 1);
    addDirectedEdge(graphE, 4, 5);
    addDirectedEdge(graphE, 5, 0);
    addDirectedEdge(graphE, 6, 4);
    addDirectedEdge(graphE, 6, 7);
    addDirectedEdge(graphE, 7, 0);

    displayResult("E", graphE, nodesE, 0);


    vector<string> nodesF = {"0", "1", "2", "3", "4", "5", "6", "7"};
    vector<vector<int>> graphF(8);

    addDirectedEdge(graphF, 0, 1);
    addDirectedEdge(graphF, 0, 2);
    addDirectedEdge(graphF, 0, 3);
    addDirectedEdge(graphF, 1, 3);
    addDirectedEdge(graphF, 2, 4);
    addDirectedEdge(graphF, 3, 5);
    addDirectedEdge(graphF, 3, 6);
    addDirectedEdge(graphF, 4, 5);
    addDirectedEdge(graphF, 4, 7);
    addDirectedEdge(graphF, 5, 2);

    displayResult("F", graphF, nodesF, 0);


    vector<string> nodesG = {"0", "1", "3", "4", "5", "6", "7"};
    vector<vector<int>> graphG(7);

    addUndirectedEdge(graphG, 0, 1);
    addUndirectedEdge(graphG, 0, 2);
    addDirectedEdge(graphG, 0, 6);
    addDirectedEdge(graphG, 1, 3);
    addDirectedEdge(graphG, 6, 3);
    addDirectedEdge(graphG, 6, 4);
    addDirectedEdge(graphG, 3, 4);
    addDirectedEdge(graphG, 3, 5);
    addDirectedEdge(graphG, 4, 5);

    displayResult("G", graphG, nodesG, 0);


    vector<string> nodesH = {"A", "B", "C", "D", "E", "F", "G", "H"};
    vector<vector<int>> graphH(8);

    addUndirectedEdge(graphH, 0, 1);
    addUndirectedEdge(graphH, 0, 3);
    addUndirectedEdge(graphH, 0, 5);
    addUndirectedEdge(graphH, 0, 7);
    addUndirectedEdge(graphH, 1, 2);
    addUndirectedEdge(graphH, 1, 4);
    addUndirectedEdge(graphH, 1, 5);
    addUndirectedEdge(graphH, 2, 4);
    addUndirectedEdge(graphH, 2, 6);
    addUndirectedEdge(graphH, 2, 7);
    addUndirectedEdge(graphH, 3, 5);
    addUndirectedEdge(graphH, 4, 5);
    addUndirectedEdge(graphH, 4, 6);
    addUndirectedEdge(graphH, 6, 7);

    displayResult("H", graphH, nodesH, 0);

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
struct Edge
{
    int src;
    int dest;
};
class Graph
{
public:
    int V;
    int E;
    vector<vector<int>> adjList;

    Graph(vector<Edge> edges, int V)
    {
        adjList.resize(V);
        for (auto e : edges)
        {
            adjList[e.src].push_back(e.dest);
        }
    }
};

vector<int> path;
//dont print the path
bool findpath(Graph g, int src, int dest, bool visited[])
{

    visited[src] = true;
    path.push_back(src);

    if (src == dest)
    {
        for (auto e : path)
            cout << e << " ";
        return true;
    }

    //src se jaha jaha bhi jaana possible hai , jaao, dest pe pahoch gaye to true return kar hi rahe hai, nahi to return false
    for (auto v : g.adjList[src])
    {
        if (!visited[v])
            if (findpath(g, v, dest, visited))
                return true;
    }
    path.pop_back();
    return false;
}

int main()
{
    int E, V;
    cin >> V >> E;
    vector<Edge> edges;
    for (int i = 0; i < E; i++)
    {
        int src;
        int dest;
        Edge e;
        cin >> src >> dest;
        e.src = src;
        e.dest = dest;
        edges.push_back(e);
    }

    Graph g(edges, V);

    int src, dest;
    cin >> src >> dest;
    bool visited[V]{};
    cout << endl << "path exists" << findpath(g, src, dest, visited);
}

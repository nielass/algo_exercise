#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph
{
public:
    Graph(int v) : v_(v), adj(vector<list<int>>(v)) {}

    void add_edge(int v, int w)
    {
        adj[v].push_back(w);
    }
    void add_edge_undirected(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void bfs(int);
    void dfs();

private:
    int v_;
    vector<list<int>> adj;
    void dfs_visit(int, vector<bool> *);
};

void Graph::bfs(int source)
{
    vector<bool> visited(v_, false);

    list<int> queue;
    visited[source] = true;
    queue.push_back(source);

    while (!queue.empty())
    {
        source = queue.front();
        cout << source << " ";
        queue.pop_front();
        for (auto bg = adj[source].begin(); bg != adj[source].end(); ++bg)
        {
            if (!visited[*bg])
            {
                visited[*bg] = true;
                queue.push_back(*bg);
            }
        }
    }
    cout << endl;
    cout << "BFS END" << endl;
}

void Graph::dfs_visit(int u, vector<bool> *visited)
{
    for (auto i : adj[u])
        if (!(*visited)[i])
        {
            (*visited)[i] = true;
            cout << i << " ";
            dfs_visit(i, visited);
        }
}

void Graph::dfs()
{
    vector<bool> visited(v_, false);
    for (int i = 0; i < v_; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            cout << i << " ";
            dfs_visit(i, &visited);
        }
    }
    cout << endl;
    cout << "DFS END" << endl;
}

int main()
{
    Graph test(7);
    test.add_edge_undirected(0, 2);
    test.add_edge_undirected(0, 5);
    test.add_edge_undirected(2, 3);
    test.add_edge_undirected(2, 4);
    test.add_edge_undirected(1, 2);
    test.add_edge_undirected(4, 1);
    cout << "The travel of bfs show below: " << endl;
    test.bfs(0);
    cout << endl;
    cout << "The travel of dfs show below: " << endl;
    test.dfs();

    return 0;
}
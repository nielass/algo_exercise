#include <iostream>
#include <list>
#include <memory>

using namespace std;
class DfsGraph
{

public:
    DfsGraph(int num) : v_(num), adj(new list<int>[num]), count(0), visited_time(new int[num]), finished_time(new int[num]) {}
    void add_edge(int v, int u)
    { // undirected
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    void print_visit_time()
    {
        for (int i = 0; i < v_; ++i)
        {
            cout << visited_time[i] << " ";
        }
        cout << endl;
    }

    void print_finish_time()
    {
        for (int i = 0; i < v_; ++i)
        {
            cout << finished_time[i] << " ";
        }
        cout << endl;
    }

    void dfs();

private:
    void dfs_visit(int, bool *);
    int v_;
    int count; // count the 'time'
    int *visited_time;
    int *finished_time;
    list<int> *adj;
};

void DfsGraph::dfs()
{
    bool *visited = new bool[v_];
    for (int i = 0; i < v_; ++i)
    {
        visited[i] = false;
    }

    count = 0;

    for (int i = 0; i < v_; ++i)
    {
        if (!visited[i])
        {
            cout << i << " ";
            visited[i] = true;
            dfs_visit(i, visited);
        }
    }
    delete visited;
}

void DfsGraph::dfs_visit(int i, bool *visited)
{
    count += 1;
    visited_time[i] = count;
    for (auto v : adj[i])
    {
        if (!visited[v])
        {
            visited[v] = true;
            cout << v << " ";
            dfs_visit(v, visited);
        }
    }
    count += 1;
    finished_time[i] = count;
}
int main()
{
    DfsGraph graph(9);
    graph.add_edge(0, 1);
    graph.add_edge(0, 4);
    graph.add_edge(2, 4);
    graph.add_edge(3, 4);
    graph.add_edge(5, 6);
    graph.add_edge(6, 7);
    graph.add_edge(5, 8);
    graph.add_edge(7, 8);
    graph.dfs();
    cout << endl;
    cout << "Visited time: " << endl;
    graph.print_visit_time();
    cout << "Finished time: " << endl;
    graph.print_finish_time();
    return 0;
}
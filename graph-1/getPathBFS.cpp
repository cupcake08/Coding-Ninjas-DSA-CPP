#include <iostream>
#include <cstring>
#include <map>
#include <queue>
using namespace std;
void printBFS(bool **edges, int n, int s, int e, bool *visited)
{
    bool path_exist=false;
    queue<int> q;
    q.push(s);
    map<int, int> mp;
    visited[s] = true;
    while (!q.empty())
    {
        int curr_ele = q.front();
        q.pop();
        if (curr_ele == e){
            path_exist=true;
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && edges[curr_ele][i])
            {
                q.push(i);
                visited[i] = true;
                mp[i] = curr_ele;
            }
        }
    }
    if(!path_exist) return;
    int i = e;
    cout << e << " ";
    while (i != s)
    {
        cout << mp[i] << " ";
        i = mp[i];
    }
}
int main()
{
    int n, e; //n->vertices,e->edges
    cin >> n >> e;
    bool **edges = new bool *[n]; //edges array(2D)
    for (int i = 0; i < n; i++)
    {
        edges[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = false;
        }
    }
    //taking input of edges
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    //visited array
    bool *visited = new bool[n];
    memset(visited, false, sizeof(visited));
    //call your working function below
    int start, end;
    cin >> start >> end;
    printBFS(edges, n, start, end, visited);
    // if(ans!=nullptr){
    // for(int i=0;i<ans->size();i++){
    //     cout<<ans->at(i)<<" ";
    // }
    // }
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}

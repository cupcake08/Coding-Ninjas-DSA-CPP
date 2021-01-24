#include <bits/stdc++.h>
using namespace std;
/************************MemoryEfficient MEthod********************/
void printBFS(bool **edges, int n, int s, int e, unordered_map<int,bool> visited)
{
    bool path_exist=false;
    queue<int> q;
    q.push(s);
    unordered_map<int, int> mp;
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
/**************Second Approach*****************/
vector<int> *getPathBFS(bool **edges,int n,int start,int end,unordered_map<int,bool> visited){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    bool done=false;
    unordered_map<int,int> mp;
    while(!q.empty() && !done){
        int curr=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!visited[i] && edges[curr][i]){
                mp[i]=curr;
                q.push(i);
                visited[i]=true;
                if(i==end){
                    done=true;
                    break;
                }
            }
        }
    }
    if(!done) return nullptr;
    vector<int> *output=new vector<int>();
    int cur=end;
    output->push_back(end);
    while(cur!=start){
        cur=mp[cur];
        output->push_back(cur);
    }
    return output;
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
    //call your working function below
    unordered_map<int,bool> visitedMap;
    for(int i=0;i<n;i++){
        visitedMap[i]=false;
    }
    int start, end;
    cin >> start >> end;
    vector<int> *ans=getPathBFS(edges,n,start,end,visitedMap);
    if(ans!=nullptr){
        for(int i=0;i<ans->size();i++){
            cout<<ans->at(i)<<" ";
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete ans;
}

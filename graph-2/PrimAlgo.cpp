#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <vector>

using namespace std;
int min_vertex(bool *visited,int *weight,int n){
	int min_vertex=-1;
	for(int i=0;i<n;i++){
		if(!visited[i] && (min_vertex==-1||weight[i]<weight[min_vertex])){
			min_vertex=i;
		}
	}
	return min_vertex;
}
void primAlgo(int **edge,int n){
	bool *visited=new bool[n];
	int *parent=new int[n];
	int *weight=new int[n];
    for(int i=0;i<n;i++){
            weight[i]=INT_MAX;
            visited[i]=false;
    }
	parent[0]=-1;
	weight[0]=0;
	for(int i=0;i<n-1;i++){
		int minV=min_vertex(visited,weight,n);
		visited[minV]=1;
		for(int j=0;j<n;j++){
			if(!visited[j] && edge[minV][j]){
				if(weight[j]>edge[minV][j]){
					weight[j]=edge[minV][j];
					parent[j]=minV;
				}
			}
		}
	}
	for(int i=1;i<n;i++){
		if(parent[i]<i){
			cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
		}else{
			cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
		}
	}
	delete [] visited;
	delete [] weight;
	delete [] parent;
}
int main(){
	int n,e;
	cin>>n>>e;
	int **edge=new int*[n];
	for(int i=0;i<n;i++){
		edge[i]=new int[n];
		for(int j=0;j<n;j++){
			edge[i][j]=0;
		}
	}
	for(int i=0;i<e;i++){
		int f,s,w;
		cin>>f>>s>>w;
		edge[f][s]=w;
		edge[s][f]=w;
	}
	//function
	primAlgo(edge,n);
	for(int i=0;i<n;i++){
		delete [] edge[i];
	}
	delete [] edge;
}

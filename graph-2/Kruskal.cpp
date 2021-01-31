#include <iostream>
#include <algorithm>

using namespace std;
class Edge{
	public:
	int source;
	int dest;
	int weight;
};
bool mysort(Edge x,Edge y){
	return x.weight < y.weight;
}
int find_parent(int v1,int *parent){
	int pv1=v1;
	while(parent[pv1] !=pv1){
		pv1=parent[pv1];
	}
	return pv1;
}
int main(){
	int n,e;
	cin>>n>>e;
	Edge input[e],output[n-1];
	for(int i=0;i<e;i++){
		int source,dest,weight;
		cin>>source>>dest>>weight;
		input[i].source=source;
		input[i].dest=dest;
		input[i].weight=weight;
	}
	int parent[n];
	for(int i=0;i<n;i++){
		parent[i]=i;
	}
	sort(input,input+e,mysort);
	int count=0,i=0,v1,v2;
	while(count<n-1){
		v1=input[i].source;
		v2=input[i].dest;
		int pv1=find_parent(v1,parent);
		int pv2=find_parent(v2,parent);
		if(pv1!=pv2){
			parent[pv2]=pv1;
			output[count].source=input[i].source;
			output[count].dest=input[i].dest;
			output[count].weight=input[i].weight;
			count++;
		}
		i++;
	}
	for(int i=0;i<n-1;i++){
	int minVertex=min(output[i].source,output[i].dest);
		int maxVertex=max(output[i].source,output[i].dest);
		cout<<minVertex<<" "<<maxVertex<<" "<<output[i].weight<<endl;
	}
	return 0;
}

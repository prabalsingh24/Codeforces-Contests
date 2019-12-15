#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int size[200005];
int parent[200005];
void make_set(int v){
	parent[v]=v;
	size[v]=1;
	return;
}
int find_set(int v){
	if(parent[v]==v){
		return v;
	}
	else{
		parent[v]=find_set(parent[v]);
		return parent[v];
	}
}
void merge_set(int u,int v){
	u=find_set(u);
	v=find_set(v);
	if(v!=u){
		if(size[u]<size[v]){
			parent[u]=v;
			size[v]+=size[u];
		}
		else{
			parent[v]=u;
			size[u]+=size[v];
		}
	}
}
int32_t main(){
	IOS;
	int n;
	cin>>n;
	for(int i=0;i<=n;i++){
		parent[i]=i;
		size[i]=1;
	}
	vector<int> graph[28];
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<s.length();j++){
			int number=s[j]-'a';
			//cout<<number<<endl;
			graph[number].push_back(i);
		}
	}
	for(int i=0;i<26;i++){
		if(graph[i].size()>1){
			for(int it=1;it<graph[i].size();it++){
				//cout<<"MERGING "<<graph[i][0]<<" "<<graph[i][it]<<endl;
				merge_set(graph[i][0],graph[i][it]);
			}
		}
	}
	set<int> s;
	for(int i=0;i<n;i++){
		s.insert(find_set(i));
	}
	cout<<s.size()<<endl;


}
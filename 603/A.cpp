#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
	IOS;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<string,int> mp;
		int changes=0;
		vector<pair<string,int>> v;
		for(int i=0;i<n;i++){
			string st;
			cin>>st;
			if(mp.count(st)==0){
				mp[st]=i;
			}
			else{
				v.push_back(make_pair(st,i));
			}
		}
		for(auto it:v){
			string stt=it.first;
			int flag=0;
			//cout<<"OUT oF THE LOOP"<<endl;
			for(int j=0;j<=3 and flag==0;j++){
				for(int k=0;k<=9 and flag==0;k++){
					stt[j]='0'+k;
			//		cout<<flag<<" "<<it.second<<" "<<endl;
					if(mp.count(stt)==0){
						mp[stt]=it.second;
						flag++;
			//			cout<<"I AM HERE"<<it.second<<" "<<stt<<" "<<flag<<endl;
						changes++;
					}
				}
			}
		}
		string ans[11];
		cout<<changes<<endl;
		for(auto it:mp){
			ans[it.second]=it.first;
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<endl;
		}
	}

}
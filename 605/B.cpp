#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
	IOS;
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		int l=0,r=0,u=0,d=0;
		for(int i=0;i<s.length();i++){
			if(s[i]=='L'){
				l++;
			}
			if(s[i]=='R'){
				r++;
			}
			if(s[i]=='U'){
				u++;
			}
			if(s[i]=='D'){
				d++;
			}
		}
		int one=min(l,r);
		int two=min(u,d);
		if(one+two==0){
			cout<<0<<endl;
		}
		else if(one==0 or two ==0){
			cout<<2<<endl;
			if(one==0){
				cout<<"UD"<<endl;
			}
			else{
				cout<<"LR"<<endl;
			}
		}
		else{
			cout<<2*(one+two)<<endl;
			for(int i=0;i<one;i++){
				cout<<"L";
			}
			for(int i=0;i<two;i++){
				cout<<"U";
			}
			for(int i=0;i<one;i++){
				cout<<"R";
			}
			for(int i=0;i<two;i++){
				cout<<"D";
			}
			cout<<endl;
		}
	}

}
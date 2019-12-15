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
		int a,b,c;
		cin>>a>>b>>c;
		int ans=1000000000000;
		for(int i=-1;i<2;i++){
			for(int j=-1;j<2;j++){
				for(int k=-1;k<2;k++){
					int temp=abs(a+i-b-j)+abs(a+i-c-k)+abs(b+j-c-k);
					ans=min(ans,temp);
				}
			}
		}
		cout<<ans<<endl;
	}

}
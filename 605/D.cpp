#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
int32_t main(){
	IOS;
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int max_right[n];
	int max_left[n];
	vector<int> decreasing_left;
	vector<int> increasing_right;
	deque<int> dq;
	int number=0;
	int length=0;
	for(int i=0;i<n;i++){
		if(a[i]>number){
			dq.push_back(a[i]);
			number=max(number,a[i]);
			length++;
		}
		else{
			while(!dq.empty()){
				dq.pop_front();
				increasing_right.push_back(length--);
			}
			dq.push_back(a[i]);
			number=a[i];
			length=1;
		}
	}
	while(!dq.empty()){
		dq.pop_front();
		increasing_right.push_back(length--);
	}
	number=10000000000000;
	length=0;
	for(int i=n-1;i>=0;i--){
		if(a[i]<number){
			dq.push_back(a[i]);
			number=min(number,a[i]);
			length++;
		}
		else{
			while(!dq.empty()){
				dq.pop_front();
				decreasing_left.push_back(length--);
			}
			dq.push_back(a[i]);
			number=a[i];
			length=1;
		}
	}
	while(!dq.empty()){
		dq.pop_front();
		decreasing_left.push_back(length--);
	}
	int ans=0;
	for(int it:increasing_right){
		ans=max(ans,it);
	}
	reverse(decreasing_left.begin(),decreasing_left.end());

	int dp[n];
	for(int i=n-2;i>0;i--){
		if(a[i-1]<a[i+1]){
			ans=max(ans,increasing_right[i+1]+decreasing_left[i-1]);
		}
	}
	cout<<ans<<endl;
}
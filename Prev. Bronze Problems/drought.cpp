/*
- Greedy solution
- if one is bigger than the other, you always subtract
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void solve(){
    int n;
    long long ans=0;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}

	if(n==1){
		cout<<"0\n";
		return;
	}else if (n==2){
		if (v[0]==v[1]){cout<<"0\n";}
		else {cout<<"-1\n";}
		return;
	}else if (v[0]>v[1] || v[n-1]>v[n-2]){
		cout<<"-1\n";
		return;
	}
    
    bool change=true;
		while(change){
			change=false;
			for (int i=1;i<n;i++){
				if (v[i-1]>v[i]){
					if (i==1){
						cout<<"-1\n";
						return;
					}
					change=true;
					int diff = v[i-1]-v[i];
					//cout<<"HIHI"<<diff;
					ans += diff;
					v[i-1] -= diff;
					v[i-2] -= diff;
					//make sure non neg
					if (v[i-1]<0 || v[i-2]<0){
						cout<<"-1\n";
						return;
					}
				}else if (v[i-1]<v[i]){
					if (i==n-1){
						cout<<"-1\n";
						return;
					}
					change = true;
					int diff = v[i]-v[i-1];
					//cout<<"JIA"<<diff;					
					ans += diff;
					v[i] -= diff;
					v[i+1] -= diff;
					if (v[i]<0 || v[i+1]<0){
						cout<<"-1\n";
						return;
					}
				}
			}
		}
	cout<<ans*2<<"\n";
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
	}

	return 0;
}

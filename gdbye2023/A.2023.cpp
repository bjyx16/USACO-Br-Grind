#include<iostream>
#include<vector>
using namespace std;

void solve(){
	int n,k;
	int b[6]={0};
	int pB = 1;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>b[i];
		pB*=b[i];
	}
	if (2023%pB!=0){
		cout<<"NO";
		return;
	}

	int need = 2023/pB;
	cout<<"YES\n"<<need<<" ";

	for (int i=0;i<k-1;i++){
		cout<<1<<' ';
	}
	return;
}

int main(){
	int t;cin>>t;
	while(t--){
		solve();
		cout<<"\n";
	}

	return 0;
}

#include<iostream>
#include<vector>
#include<set>
#include<cmath>
using namespace std;
const int MAX=1e9;

int main(){
	int t;cin>>t;
	while(t--){
		int n; cin>>n;
		long long total=0;
		for (int i=0;i<n;i++){
			int x;
			cin>>x;
			total += x;
		}
		long long test = sqrt(total);
		if (test*test==total){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		cout<<"\n";
	}

	return 0;
}

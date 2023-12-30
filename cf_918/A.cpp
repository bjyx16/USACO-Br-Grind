#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAX=1e9;

int main(){
	int t;cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if (a==b){cout<<c;}else if (b==c){ cout<<a;}else{cout<<b;}
		cout<<"\n";
	}

	return 0;
}

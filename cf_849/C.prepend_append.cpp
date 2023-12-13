#include<iostream>
#include<string>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,count=0; string s;
		cin>>n>>s;
		for (int i=0;i<n/2;i++){
			if (s[i] != s[n-1-i]){
				//cout<<i<<" ";
				count++;
			}else{
				break;
			}
		}
		cout<<n-count*2<<"\n";
	}

	return 0;
}

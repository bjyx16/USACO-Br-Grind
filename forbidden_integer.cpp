#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k,x;
		cin>>n>>k>>x;
		if (x!=1){
			cout<<"YES\n"<<n<<"\n";
			for (int i=0;i<n;i++){
				cout<<1<<' ';
			}
			cout<<"\n";
			continue;
		}
		//x=1
		if (k==1){
			cout<<"NO";
		}else{
			if (n%2==0){
				cout<<"YES\n"<<n/2<<"\n";
				for (int i=0;i<n/2;i++){
					cout<<2<<' ';
				}
			}else{
				if (k==2){
					cout<<"NO";
				}else{
					int m=n-3;
					int count = m/2;
					cout<<"YES\n"<<count+1<<"\n"<<3<<' ';
					for (int i=0;i<count;i++){
						cout<<2<<' ';
					}
				}
			}
		}
		cout<<"\n";
	}

	return 0;
}

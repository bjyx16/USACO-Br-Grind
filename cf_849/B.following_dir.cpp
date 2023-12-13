#include<iostream>
#include<string>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int x=0,y=0;
		int n; cin>>n;
		string dir;
		bool flag=0;
		cin>>dir;

		for (int i=0;i<n;i++){
			switch (dir[i]){
				case 'R':x++; break;
				case 'L':x--; break;
				case 'U':y++; break;
				case 'D':y--; break;
			}
			if (x==1 && y==1){
				cout<<"YES";
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"NO";
		}cout<<"\n";

	}

	return 0;
}

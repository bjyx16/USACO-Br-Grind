#include <iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	for (int i=0;i<t;i++){
		int n;
		cin>>n;
		int height[60]={};
		int length[60]={};
		int count=0;

		for (int j=0;j<n;j++){
			cin>>height[j]>>length[j];
			if (length[j]<height[j]){
				count++;
			}
		}
		cout<<count<<"\n";
	}
}

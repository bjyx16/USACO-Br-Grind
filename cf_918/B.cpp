#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
const int MAX=1e9;

int main(){
	int t;cin>>t;
	while(t--){
		for (int i=0;i<3;i++){
			int check[4]={};
			bool flag=0;
			for(int j=0;j<3;j++){
				char c;
				cin>>c;
				if (c=='?'){
					flag=1;
					continue;
				}
				check[c-'A']++;
			}
			if(flag){
				for (int k=0;k<3;k++){
					if (check[k]==0){
						cout<<char(k+'A')<<"\n";
						break;
					}
				}
			}
		}
	}

	return 0;
}

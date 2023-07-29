/*
- O(n*m)
- gene is viable if no nucleotides overlap between spotty and plain cows
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main(){
	freopen("cownomics.in","r",stdin);
	freopen("cownomics.out","w",stdout);

	int n,m;
	cin>>n>>m;
	int ans=0;
	vector<set<char> > gene(m);//spotty
	vector<set<char> > gene2(m);//plain

	for (int i=0;i<n;++i){
		string c;
		cin>>c;
		for (int j=0;j<m;++j){
			gene[j].insert(c[j]);
		}
	}
	
	/*for (int i=0;i<m;i++){
		for (auto element:gene[i]){
			cout<<element<<" ";
		}cout<<endl;
	}*/

	for (int i=0;i<n;++i){
		string c;
		cin>>c;
		for (int j=0;j<m;++j){
			gene2[j].insert(c[j]);
		}
	}
	char x[5]={'A','T','G','C'};
	for (int i=0;i<m;++i){
		bool flag=0;//if overlap in nucleotides
		for (int j=0;j<4;j++){
			if (gene[i].count(x[j])&&gene2[i].count(x[j])){//spotty and plain both have this
				flag=1;
				break;
			}
		}
		if (flag==0){
			ans++;
		}
	}
	cout<<ans;
	
	return 0;
}

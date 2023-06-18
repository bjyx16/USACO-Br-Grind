/*
- O(n)
*/
#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("blocks.in","r",stdin);
	freopen("blocks.out","w",stdout);

	int n;
	int l[26]={0};//for the whole picture
	string a,b;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a>>b;
		int w1[26]={0};//for each word pair
		int w2[26]={0};
		string::iterator it1;
		string::iterator it2;
		for (it1=a.begin();it1!=a.end();++it1){
			w1[*it1-'a']++;
		}
		for (it2=b.begin();it2!=b.end();++it2){
			w2[*it2-'a']++;
		}
		for (int j=0;j<26;j++){
			l[j]+=max(w1[j],w2[j]);
		}
	}
	for (int i=0;i<26;i++){
		cout<<l[i]<<"\n";
	}

	return 0;
}

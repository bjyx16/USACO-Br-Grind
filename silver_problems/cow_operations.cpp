/*
- order doesn't matter bc any two letters can flip order
e.g. OC -> CWWO -> CO
- thus any two of same letter can cancel each other out
- so it's the count:
1. 1 C
2. 1 OW or WO (makes C)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int q;
	string s;
	cin>>s>>q;
	int len = s.length();

	vector<int> c(len+1,0);
	vector<int> o(len+1,0);
	vector<int> w(len+1,0);

	for(int i=1;i<=len;i++){
		c[i] += c[i-1];
		o[i] += o[i-1];
		w[i] += w[i-1];

		if(s[i-1]=='C'){c[i]++;}
		else if(s[i-1]=='O'){o[i]++;}
		else{w[i]++;}
	}

	while(q--){
		int x,y;
		cin>>x>>y;
		
		int cc=c[y]-c[x-1];
		int oo=o[y]-o[x-1];
		int ww=w[y]-w[x-1];

		if ((cc%2==1 && oo%2==0 && ww%2==0) ||
			(cc%2==0 && oo%2==1 && ww%2==1)){
			cout<<'Y';
		}else{
			cout<<'N';
		}
	}
}

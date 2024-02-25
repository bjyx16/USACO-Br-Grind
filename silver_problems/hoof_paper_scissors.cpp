/*
- prefix sums and then brute force every possible switch point
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("hps.in","r",stdin);
	freopen("hps.out","w",stdout);

	int n;
	cin>>n;
	vector<char> john(n+1,'\0');
	vector<int> h(n+1,0);
	vector<int> p(n+1,0);
	vector<int> s(n+1,0);

	for (int i=1;i<=n;i++){
		cin>>john[i];
		h[i]+=h[i-1];
		p[i]+=p[i-1];
		s[i]+=s[i-1];

		if(john[i]=='P'){
			p[i]++;
		}else if(john[i]=='H'){
			h[i]++;
		}else{
			s[i]++;
		}
	}

	int maxWin=-1;
	for (int i=0;i<n;i++){//bessie switches moves after i
		int maxL=max(h[i],max(p[i],s[i]));
		int maxR=max(h[n]-h[i],max(p[n]-p[i],s[n]-s[i]));
		maxWin = max(maxWin, maxL+maxR);
	}

	cout<<maxWin<<"\n";

	return 0;
}

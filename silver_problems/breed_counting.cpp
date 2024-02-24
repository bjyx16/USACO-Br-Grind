#include <iostream>
#include <vector>
using namespace std;

int main(){
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);

	int n,q;
	cin>>n>>q;

	vector<int> hol(n+1,0);
	vector<int> guern(n+1,0);
	vector<int> jers(n+1,0);

	for (int i=1;i<=n;i++){	//p[i]=p[i-1]+a[i]
		int x;
		cin>>x;
		hol[i] += hol[i-1];
		guern[i] += guern[i-1];
		jers[i] += jers[i-1];
		
		if (x==1){
			hol[i]++;
		}else if (x==2){
			guern[i]++;
		}else{
			jers[i]++;
		}
	}

	while(q--){
		int x,y;
		cin>>x>>y;

		cout<<hol[y]-hol[x-1]<<' '<<
			guern[y]-guern[x-1]<<' '<<
			jers[y]-jers[x-1]<<"\n";
	}

	return 0;
}

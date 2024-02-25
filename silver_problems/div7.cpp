/*
- valid if (p[y]-p[x-1])%7 == 0
			p[y]%7 - p[x-1]%7 == 0
			p[y]%7 == p[x-1]%7
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	freopen("div7.in","r",stdin);
	freopen("div7.out","w",stdout);

	int n;
	cin>>n;

	vector<int> id(n+1);
	vector<int> p(n+1,0);
	for (int i=1;i<=n;i++){
		cin>>id[i];
		id[i]%=7;
		p[i] += (p[i-1] + id[i]) %7;
		//cout<<p[i]<<" ";
	}

	int ans=-1;//%7 = [0,6]
	for(int i=0;i<=6;i++){
		int maxL=-1,maxR=-1;
		for(int j=1;j<=n;j++){
			if (p[j]==i){
				maxL=j+1;//bc p[x-1]
				break;
			}
		}
		for(int j=n;j>0;j--){
			if (p[j]==i){
				maxR=j;
				break;
			}
		}
		ans = max(ans, maxR-maxL+1);
	}
	cout<<ans<<"\n";

	return 0;
}

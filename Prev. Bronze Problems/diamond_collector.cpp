/*
- O(n^2)
- start second for loop from i+1
- original mistake: counted all elements in [a[i]-k, a[i]+k]
	wrong bc exceeds k
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("diamond.in","r",stdin);
	freopen("diamond.out","w",stdout);

	int n,k;
	int a[1001]={0};
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=-1;
	sort(a,a+n);
	for (int i=0;i<n;i++){
		int count=1;
		for (int j=i+1;j<n;j++){
			if (abs(a[j]-a[i])<=k){
				count++;
			}
			ans = max(ans,count);
		}
	}
	cout<<ans;

	return 0;
}

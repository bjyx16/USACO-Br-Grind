/*
- O(nlogn)
- binary search
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("moobuzz.in","r",stdin);
	freopen("moobuzz.out","w",stdout);

	int n;
	long long l=1,r=1e18,mid;
	cin>>n;
	while(1){
		mid = (l+r)/2;
		long long num=mid/3 + mid/5 - mid/15;
		long long spoken = mid-num;
		//cout<<spoken<<' ';cout<<mid<<'\n';
		if (spoken<n){
			l = mid+1;
		}else if (spoken>n){
			r = mid-1;
		}else{//spoken==n
			while(mid%3==0 || mid%5==0){//remember to account for this possibility!
				mid--;
			}
			break;
		}
	}
	cout<<mid;

	return 0;
}

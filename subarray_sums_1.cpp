//sliding window/2-pointers

#include <iostream>
using namespace std;
//#define MAXN (int)(2 * 1e5 + 10)
const int MAXN = 2*1e5 + 10;

int n,x;
int a[MAXN]={0};	//rmb to check array size

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>x;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0;
	long long temp=0;

	int l=0;
	//*** l and i are independent of each other, because l never resets back to 0.
	//therefore O(l+i) aka O(2n) maybe, not O(n^2) 
	for (int i=0;i<n;i++){
		temp += a[i];
		while(temp>x && l!=i){
			temp -= a[l];
			l++;
		}
		if (temp==x){
			ans++;
			temp-=a[l];
			l++;
		}
	}

	//end the output with an "\n" instead of endl; endl doesn't buffer output
	cout<<ans<<"\n";
	
	return 0;
}
/*
- O(2n) basically
- to find max subarray sum: only 'worth it' to add negative numbers 
if sum of consecutive negative numbers doesn't cancel out whatever sum you have so far
if pos int, always add; if neg int, find the sum of neg numbers in consectutive subarray 
& if it cancels out the sum, it's not worth and start at next pos num
  - edge case is if all neg numbers
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, start=0;
	bool isPos=0;
	cin>>n;
	vector<long long> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
		if (isPos==0 && v[i]>0){
			//find first pos/nonzero number
			start=i;
			isPos=1;
		}
	}
	long long maxx=v[0];
	long long ans=-1,temp=0;

	if (isPos==0){//all neg
		for (int i=1;i<n;i++){
			maxx = max(maxx,v[i]);
		}
		cout<<maxx<<"\n";
		return 0;
	}

	for (int r=start;r<n;r++){//start at the first pos number
		//if this number is a negative number
		if (v[r]<0){
			long long negsum=v[r];
			int r1=r+1;
			while (v[r1]<0 && r1<n){
				negsum+=v[r1];
				r1++;
			}
			//cout<<negsum<<' '<<temp;
			if (temp+negsum<=0){//if this negative subarray will cancel out temp
				r = r1;//skip to the next appearance of a positive integer
				temp = 0;
			}
		}
		temp += v[r];
		ans = max(ans,temp);
		//cout<<" "<<temp<<endl;
	}
	cout<<ans<<"\n";
	
	return 0;
}

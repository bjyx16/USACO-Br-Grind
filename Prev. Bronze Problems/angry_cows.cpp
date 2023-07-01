/*
- O(n^3) = 1e6
- not as bad as expected, was a bit confusing to calculate the time complexity bc worried would TLE, but works with a brute force+recursive solution
- remembered undefined behaviour yay
*/

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int hay[105]={};
int leftCount=0;
int rightCount=0;

void leftChecker(int r, int pointer){
	bool hasExploded=false;
	int furthest;
	if (pointer!=0){//undefined behaviour
		for (int i=1;i<=r;++i){
			if (hay[pointer]-r<=hay[pointer-i] && pointer-i>=0){
				hasExploded=true;
				leftCount++;
				furthest=pointer-i;
			}else{
				break;
			}
		}
		if (hasExploded){
			//cout<<furthest<<" ";
			leftChecker(r+1,furthest);
		}
	}else{
		return;
	}
}

void rightChecker(int r, int pointer){
	bool hasExploded=false;
	int furthest;
	if (pointer!=n-1){//undefined behaviour
		for (int i=1;i<=r;++i){
			if (hay[pointer]+r>=hay[pointer+i] && pointer+i<=n-1){
				hasExploded=true;
				rightCount++;
				furthest=pointer+i;
			}else{
				break;
			}
		}
		if (hasExploded){
			//cout<<furthest<<" ";
			rightChecker(r+1,furthest);
		}
	}else{
		return;
	}
}

int main(){
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);

	int ans=-1;
	cin>>n;
	for (int i=0;i<n;++i){
		cin>>hay[i];
	}
	sort(hay,hay+n);

	//launch a cow at every single hay bale & determine if its the max
	for (int i=0;i<n;++i){
		leftCount=0;
		rightCount=0;
		leftChecker(1,i);
		//cout<<"\n";
		rightChecker(1,i);
		//cout<<"\n"<<rightCount<<" "<<leftCount<<"\n";
		ans = max(ans,(rightCount+leftCount+1));
	}
	cout<<ans;

	return 0;
}

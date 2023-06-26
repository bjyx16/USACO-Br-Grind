/*
- O(n)
- sort the array in order of arrival, then add the times. If gate is idle, just set time to the arrival time, otherwise, just add the duration
*/
  
#include <iostream>
#include <algorithm>
using namespace std;

struct cow{
	int arrive;
	int length;
};

bool comp(cow x, cow y){
	if (x.arrive==y.arrive){
		return x.length<y.length;
	}else{
		return x.arrive<y.arrive;
	}
}

int main(){

	freopen("cowqueue.in","r",stdin);
	freopen("cowqueue.out","w",stdout);

	int n;
	cin>>n;
	int time=0;
	cow a[105];
	for (int i=0;i<n;i++){
		cin>>a[i].arrive>>a[i].length;
	}
	sort(a,a+n,comp);

	for (int i=0;i<n;i++){
		if (a[i].arrive>time){  //gate idle
			time = a[i].arrive;
		}
		time += a[i].length;
		//cout<<time<<" ";
	}
	cout<<time;

	return 0;
}

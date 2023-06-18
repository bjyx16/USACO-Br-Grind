/*
- reattempted this problem from when I first tried in Jan - I can do it now yay
- O(n)
- remember to just use long long for everything
- max cost always going to be a value in price[n]
- if sort vector, then know how many cows can pay (n-i)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> price(n);
	for (int i=0;i<n;i++){
		cin>>price[i];
	}
	long long maxprofit=-1;
	long long maxcost;

	sort(price.begin(),price.end());
	for (int i=0;i<n;i++){
		long long profit = price[i] * (n-i);//number of cows willing to pay=n-i
		if (profit>maxprofit){
			maxprofit=profit;
			maxcost=price[i];
		}
	}
	cout<<maxprofit<<' '<<maxcost;

	return 0;
}

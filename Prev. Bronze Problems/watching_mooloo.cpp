/*
- O(n), time: 30 mins
- for every day that cow wants to watch TV, she has two options: 1. to continue her current subscription or 2. to start a new subscription
  - so just iterate through all the elements and calculate both options *must add it to whole sum in order to make correct comparison*, and
  track the start date of the current subscription
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	long long cost=0;
	vector<long long> sch(n);

	for (int i=0;i<n;i++){
		cin>>sch[i];		
	}

	long long temp=k+1;
	//hypothetically, if buy 1-day sub for day sch[0]
	long long day_start=sch[0];//so curr sub starts on sch[0]

	for (int i=1;i<n;i++){
		//price if extend subscription
		long long p1 = sch[i]-day_start+1 + k;
		//price if start new subscription
		long long p2 = k+1;

		if (p1+cost<=p2+cost+temp){//better to continue subscription
			temp = p1;
		}else{//better to start new sub
			day_start = sch[i];
			cost += temp;//add cost of old subscription
			temp = k+1;//curr sub price is 1-day sub
		}

	}
	cost += temp;
	cout<<cost;

	return 0;
}

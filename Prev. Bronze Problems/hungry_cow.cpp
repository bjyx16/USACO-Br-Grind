/*
- O(n), time = 1 hr
- Originally overthought the problem and created unnecessary variables, pretty happy with this solution - looks pretty clean.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long n,t,ans=0;
	long long storage=0;
	cin>>n>>t;
	vector<long long> day(n);
	vector<long long> bale(n);

	for (int i=0;i<n;i++){
		cin>>day[i]>>bale[i];
	}

	for (int i=1;i<n;i++){
		storage += bale[i-1];

		//feed the cow, non-inclusive of day[i] 
		if (storage <= (day[i]-day[i-1])){
			ans += storage;
			storage = 0;
		}else{
			ans += day[i]-day[i-1];
			storage -= day[i]-day[i-1];
		}
	}

	storage += bale[n-1];
	if (storage+day[n-1] > t){
		ans += t - day[n-1] + 1;
	}else{
		ans += storage;
	}

	cout<<ans;
	
	return 0;
}

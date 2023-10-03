/*
- O(n)
- sort in ascending order and then find the first time the next value exceeds the current sum 
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> v(n);
	long long sum=1;
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end());

	for (int i=0;i<n && v[i]<=sum;i++){
		sum += v[i];
	}
  /*
  or:
  for (int i=0;i<n;i++){
    if (sum<v[i]){
      cout<<sum;
      return 0;
    }
		sum += v[i];
	}
  */
	cout<<sum;

	return 0;
}

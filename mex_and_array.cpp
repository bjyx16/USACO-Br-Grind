/*
- O(n^3 * 10) solution
- O(n) solution if you realise that # of all possible subsets that an element a adds is (i+1)(n-i)
  - bc element is i+1 from the first element and n-i from the last element
  - knowing this, each number contributes at least (i+1)(n-i) to the answer, if it's zero then it's double bc zero adds 2 instead of 1
*/

#include<iostream>
#include<vector>
using namespace std;
#define ll long long

int main(){
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> v(n);
		ll ans=0;
		for (int i=0;i<n;i++){
			cin>>v[i];
		}
		for (int i=0;i<n;i++){
		    //find contribution of every subset of i-n integers
			for (int j=i;j<n;j++){
				int contribution=0;
				for(int k=i;k<=j;k++){
					if (v[k]==0){
						contribution++;
					}
					contribution++;
					//for each subset, add # of elements and # of zeroes
				}
				ans += contribution;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}

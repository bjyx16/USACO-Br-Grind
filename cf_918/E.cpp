//how to use dp -> look for the redundancies

#include<iostream>
#include<set>
#include<vector>
#include<cmath>
using namespace std;

/*
bool check(vector<int>& arr){ 
    // Iterate over the array 
    for(int i = 0; i < n; i++){ 
        int sum = 0; 
        for(int j = i; j < n; j++){ 
              
            // Check if position even
            if ((j - i) % 2 == 0) 
                sum += arr[j]; 
            else
                sum -= arr[j]; 
 
            if (sum == 0) 
                return true;
        } 
    } 
    return false;
}
*/

int n;

int main(){
	int t;cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		for (int i=0;i<n;i++){
			cin>>v[i];
		}
		set<long long> sums;
		sums.insert(0);
		long long sum=0;
		bool x=false;

		for (int i=0;i<n;i++){
			if (i%2){
				sum -= v[i];
			}else{
				sum += v[i];
			}
			if (sums.find(sum)!=sums.end()){
				x = true;
				break;
			}
			sums.insert(sum);
		}

		if (x){cout<<"YES";}
		else{cout<<"NO";}
		cout<<"\n";
	}

	return 0;
}

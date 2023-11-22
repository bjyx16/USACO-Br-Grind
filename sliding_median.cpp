/*
- O(nlog(n))
- using two multisets
- takeaway: learning how to break down all the scenarios for how to insert and adjust the multisets
  - write each scenario out and try to organise
- remember, to account for runtime error == if the sets are empty, or if begin/end don't exist anymore, etc...
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	if (k==1){
	    for (int i=0;i<n;i++){
		    cout<<v[i]<<' ';
	    }
	    return 0;
	}
	
	int l=1,r=k;
	int midval;
	if (k%2==1){
	    midval=k/2;
	}else{
	    midval=k/2-1;
	}
	vector<int> temp(k);
	for (int i=0;i<k;i++){
		temp[i]=v[i];
	}
	sort(temp.begin(),temp.end());
    multiset <int> lower;
    multiset <int> upper;

	for (int i=0;i<=midval;i++){
		lower.insert(temp[i]);
	}
	for (int i=midval+1;i<k;i++){
		upper.insert(temp[i]);
	}
	
	int prev=v[0],check=lower.size();
	cout<<*lower.rbegin()<<' ';
	
	while(r<n){
		//remove previous number
		auto it1=lower.find(prev);
		auto it2=upper.find(prev);		
		if (it1!=lower.end()){
			lower.erase(it1);
		}else if (it2!=upper.end()){
			upper.erase(it2);
		}
		
		//check if lower empty
		if (lower.empty()){
		    lower.insert(*upper.begin());
		    upper.erase(upper.begin());
		}

		//insert new number
		int c = *lower.rbegin();
		if (v[r]>c){
		    upper.insert(v[r]);
		    if (upper.size()>k/2){
		        lower.insert(*upper.begin());
		        upper.erase(upper.begin());
		    }
		}else{
		    lower.insert(v[r]);
		    if (lower.size()> (k+1)/2){
		        auto t=lower.end();t--;
		        upper.insert(*lower.rbegin());
		        lower.erase(t);
		    }
		}
		//cout median
		cout<<*lower.rbegin()<<' ';

		prev = v[l];
		l++;
		r++;
	}
	
	return 0;
}

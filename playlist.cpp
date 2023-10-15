/*
- O(n)
- two-pointer search; used maps to store the frequency of occurence
- could try to do this problem using sets too
- use a while loop instead of a for loop?
*/

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	vector<int> v(n);
	for (int i=0;i<n;i++){
		cin>>v[i];
	}
	int l=0,r=1;
	map<int, int> m;
	m[v[0]]=1;
	int ans=1,length=1;

	while(r<n){
		if (m.find(v[r])==m.end() || m[v[r]]==0){//not repeated
			length++;
			if(length>ans){
				ans = length;
				//cout<<l<<' '<<r<<'\n';
			}
			m[v[r]]++;
			r++;
		}else{
			length--;
			m[v[l]]--;
			l++;
		}
		
	}
	
	cout<<"\n"<<ans;

	return 0;
}

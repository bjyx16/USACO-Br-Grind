/*
- O(n*logn)
- Greedy
- work backwards, always add up the smallest two values
*KEEP THE DATA SET SORTED* which is why use multiset
 - if x and y  are the smallest two, erase x, erase y and insert x+y
*/

#include <iostream>
#include <set>
using namespace std;

int main(){
	int x,n;
	cin>>x>>n;
	multiset<int> l;
	long long ans=0;
	for (int i=0;i<n;i++){
		int y;
		cin>>y;
		l.insert(y);
	}

	for (int i=1;i<n;i++){
		multiset<int>::iterator it;
		it=l.begin();
		long long sum = *it;
		l.erase(it);
		it=l.begin();
		sum += *it;
		l.erase(it);
		l.insert(sum);

		ans += sum;
	}
	cout<<ans;

}

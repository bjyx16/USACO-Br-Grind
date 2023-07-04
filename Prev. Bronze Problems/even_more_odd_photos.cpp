/*
- O(n)
- didn't use greedy algorithm to solve this problem？ I think?
  - split into cases
- revision: replace vectors with integer tracking amount of even/odd numbers instead of using size() all the time
*/

#include <iostream>
#include <vector>
using namespace std;

bool check=0; //0 next grp must be even, 1 next grp must be odd
int ans=0;

void split(int x){
	while (x){
		if (!check){
			if (x>=2){
				ans++;
				//cout<<"yes"<<" ";
				x-=2;
				check=1;
			}else{
				ans--;
				x=0;
			}
		}else{
			if (x>=1){
				ans++;
				x--;
				check=0;
			}
		}
	}

}

int main(){
	int n;
	cin>>n;
	vector<int> odd;
	vector<int> even;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		if (x%2==0){
			even.push_back(x);
		}else{
			odd.push_back(x);
		}
	}
	//cout<<odd.size()<<" "<<even.size();

	if (even.size()==odd.size()){
		ans = n;
	}else if (even.size()>odd.size()){
		if (odd.size()==0){
			ans = 1;
		}else{
			ans = odd.size()*2+1;
		}
	}else{
		if (even.size()>0){
			ans = even.size()*2;//next group must be an even group
		}
		int a = odd.size()-even.size();
		split(a);
	}
	cout<<ans;

	return 0;
}

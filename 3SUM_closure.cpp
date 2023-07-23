/*
- O(n + 4^3)
- kind of tested random 3SUM_closure sequences to find rules, somehow it passed but not 100% sure it's correct, probably missed some cases
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool flag=false;
vector<int> num;

void check(){
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			for (int k=0;k<4;k++){
				if (i!=j&&j!=k&&i!=k){
					int sum = num[i]+num[j]+num[k];
					if (find(num.begin(),num.end(),sum)==num.end()){//invalid
						cout<<"NO";
						flag=true;
						return;
					}
				}
			}
		}
	}
}

int main(){
	int t;
	cin>>t;

	for (int x=0;x<t;x++){
		int n;
		cin>>n;
		num.clear();
		int zeroCount=0,first;
		bool nonZeroFound=false;
		for (int i=0;i<n;i++){
			int x;
			cin>>x;
			num.push_back(x);
			if (num[i]==0){
				zeroCount++;
			}
			if (nonZeroFound==false && num[i]!=0){
				first = num[i];//first non zero int
				nonZeroFound=true;
			}
		}
		if (n==3){
			int sum = num[0]+num[1]+num[2];
			if (find(num.begin(),num.end(),sum)!=num.end()){
				cout<<"YES";
			}else{
				cout<<"NO";
			}
		}else{
			if (zeroCount==n || zeroCount==n-1){//all zeroes or all zeros but one
				cout<<"YES";
			}else if (zeroCount==n-2){//one pos/neg pair + rest zeros
				//checking if pos/neg pair exists
				if (find(num.begin(),num.end(),first*-1)!=num.end()){
					cout<<"YES";
				}else{
					cout<<"NO";
				}
			}else if (zeroCount==0 && n==4){
				flag=false;
				check();
				if (flag==false){
					cout<<"YES";
				}
			}else{
			    cout<<"NO";
			}
		}
		cout<<endl;
	}
	
	return 0;
}

/*
- O(2^m) aka all possible subsets
- passed first try, complicated because lots of variables, but the problem itself isn't that hard
- takeaways: just because it seems like you're going to need a lot of variables doesn't mean you're doing it wrong
*/

#include <iostream>
using namespace std;

int n,m;
int cow[25][3]={};	//cow stalls, temperature cows need to be cooled by
int ac[15][4]={};	//ac stalls, temp cools stalls by, price
int ans=1e9+20;

int check[110]={0};//how much each stall has been cooled by, goes from index 1 to 100

int on_off[15]={0};	//0=off, 1=on

void search(int x){ //x is the index for i
	if (x==m){
		//need to reset check[] array.
		for (int i=1;i<=100;++i){
			check[i]=0;
		}
		int price=0;
		//check if it cools all the cows, calculate price
		for (int i=0;i<m;++i){
			if (on_off[i]){		//if ac is turned on
				for (int j=ac[i][0];j<=ac[i][1];++j){
					check[j]+=ac[i][2];
				}
				price+=ac[i][3];
			}
		}
		bool flag=1;
		//check if cools all the cows
		for (int i=0;i<n;i++){
			for (int j=cow[i][0];j<=cow[i][1];++j){
				if (check[j]<cow[i][2]){//doesn't match the cooling conditon
					flag=0;
					return;
				}	
			}
		}
		if (flag){//ac cools everything
			ans = min(ans,price);
		}
		return;
	}

	on_off[x]=1;
	search(x+1);  //if this ac is on
	on_off[x]=0;
	search(x+1);  //if this ac is off
}


int main(){
	cin>>n>>m;
	for (int i=0;i<n;++i){
		cin>>cow[i][0]>>cow[i][1]>>cow[i][2];
	}
	for (int i=0;i<m;++i){
		cin>>ac[i][0]>>ac[i][1]>>ac[i][2]>>ac[i][3];
	}

	search(0);
	cout<<ans;

	return 0;
}

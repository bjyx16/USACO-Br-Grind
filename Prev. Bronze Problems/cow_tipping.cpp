/*
- O(n^2)
- greedy -> find lower right corner of the rectangle aka the farthest tipped cow on the matrix
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
	freopen("cowtip.in","r",stdin);
	freopen("cowtip.out","w",stdout);

	int n;
	int count=0;
	int x=-1,y=-1;//farthest tipped cow
	cin>>n;
	vector<string> cow(n);//0=untipped, 1=tipped
	for (int i=0;i<n;i++){
		cin>>cow[i];
		for (int j=0;j<n;j++){
			if (cow[i][j]=='1'){
				x = i;
				y = j;
			}
		}
	}

	while (x!=-1 && y!=-1){
		//cout<<x<<' '<<y<<"\n";
		int newx=-1,newy=-1;
		//toggle all the cows in a given rect
		for (int i=0;i<=x;i++){
			for (int j=0;j<=y;j++){	
				if (cow[i][j]=='1'){
					cow[i][j]='0';
				}else if (cow[i][j]=='0'){
					cow[i][j]='1';
				}
			}
		}
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (cow[i][j]=='1'){
					newx = i;
					newy = j;
				}
			}
		}
		count++;
		x=newx;
		y=newy;
	}
	cout<<count<<"\n";

	return 0;
}

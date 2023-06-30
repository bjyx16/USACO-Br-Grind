/*
- O(n*n!)
- watch out for undefined behaviour -> what happens at the "extremes" of the array?
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main (){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);

	int n;
	string cow[8]={"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
	string cond[10][2]={};
	sort(cow,cow+8);
	cin>>n;
	for (int i=0;i<n;i++){
	    string f;
		cin>>cond[i][0]>>f>>f>>f>>f>>cond[i][1];
	}

	do{
	    bool flag=true;
	    for (int i=0;i<n;i++){
			for (int j=0;j<8;j++){
				if (cow[j]==cond[i][0]){
					if ((j < 7 && cow[j+1]==cond[i][1]) || (j > 0 && cow[j-1]==cond[i][1])){
						break;
					}else{
						flag=false;
						break;
					}
				}
			}
		}
		if (flag){
			for (int i=0;i<8;i++){
			    cout<<cow[i]<<"\n";
			}
			return 0;
		}
	}while (next_permutation(cow,cow+8));
	
	for (int i=0;i<n;i++){
	    cout<<cond[i][0]<<' '<<cond[i][1]<<"\n";
	}

	return 0;
}

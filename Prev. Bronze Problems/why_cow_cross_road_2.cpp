/*
- O(26^2) -> linear
- find the pattern & the correct condition: in this case its that the indexes for entry and exit points for cow i and j must be: entry[i]<entry[j]<exit[i]<exit[j]
*/

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){

	freopen("circlecross.in","r",stdin);
	freopen("circlecross.out","w",stdout);

	string cow;
	cin>>cow;
	int count=0;
	int track[26][2]={};
	int appear[26]={0};

	for (int i=0;i<52;i++){
		if (appear[cow[i]-'A']==0){
			track[cow[i]-'A'][0]=i;
		}else{
			track[cow[i]-'A'][1]=i;
		}
		appear[cow[i]-'A']++;
	}
	for (int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if (track[i][0]<track[j][0] && track[j][0]<track[i][1] && track[i][1]<track[j][1]){
				count++;
			}
		}
	}
	cout<<count;
    
	return 0;
}

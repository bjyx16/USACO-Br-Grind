/*
- O(q)
- four three letter configurations that could create "MOO"
- MOO, MOM, OOM, OOO; note that O must be the second letter
- if the string contains any of these combinations, then you delete the first and last characters until you are left with that combinations (length-3),
  and add however many moves you would need to convert that combo to "MOO"
*/

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	int q;
	vector<string> possibleCombos{"MOO","MOM","OOO","OOM"};
	cin>>q;
	for (int k=0;k<q;k++){
		string word;
		cin>>word;
		int s = word.size();
		int count=-1;
		if (s==3){
			if (word[1]=='O'){
				if (word=="MOO"){
					count=0;
				}else if (word=="MOM" || word=="OOO"){
					count=1;
				}else if (word=="OOM"){
					count=2;
				}
			}else{
				count=-1;
			}
		}else if (s<3){		//impossible
			count=-1;
		}else{				//length>3
			bool hasFound=false;
			for (int i=0;i<4;++i){
				int x = word.find(possibleCombos[i]);
				if (x!=string::npos){//the string contains one of the viable configs
					hasFound=true;
					//cout<<"found"<<' '<<s<<' ';
					char sub[4]={};
					for (int j=0;j<3;j++){
	        			sub[j]=word[x+j];
	    			}
	    			//cout<<sub;
	    			//cout<<x<<" ";
					count = s-3;
					if (strcmp(sub,"MOO")==0){
						count+=0;
					}else if (strcmp(sub,"MOM")==0 || strcmp(sub,"OOO")==0){
						count+=1;
					}else if (strcmp(sub,"OOM")==0){
						count+=2;
					}
					break;
				}
			}
		}
		cout<<count<<"\n";
	}
	return 0;
}

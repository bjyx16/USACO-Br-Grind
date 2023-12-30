#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAX=1e9;

string s;

vector<string> cv = {"ba","ca","da","be","ce","de"};
vector<string> cvc = {
"bab","bac","bad","beb","bec","bed",
"dab","dac","dad","deb","dec","ded",
"cab","cac","cad","ceb","cec","ced"};

bool check(string s,int length_array,vector<string>& vect){
	for (int i=0;i<length_array;i++){
		if (s==vect[i]){
			return true;
		}
	}
	return false;
}

bool isThree(int idxNext){
	string temp;
	temp.push_back(s[idxNext]);
	temp.push_back(s[idxNext+1]);

	if (check(temp,6,cv)){
		return true;
	}else{
		temp.push_back(s[idxNext+2]);
		if(!check(temp,18,cvc)){
			//both impossible
			return false;
		}
		return true;
	}
}

int main(){
	int t;cin>>t;
	while(t--){
		int n,counter=0;
		cin>>n;
		cin>>s;
		if (n<=3){cout<<s<<"\n"; continue;}

		int x=1,count=2;
		while(x<n){
			if(count<2){ count++; }

			if (n-1==x || n-2==x){
				for (int i=x-count+1;i<n;i++){
					cout<<s[i];
				}
				break;
			}
			
			if (count==2){
				string temp;
				temp.push_back(s[x-1]);
				temp.push_back(s[x]);
				if (check(temp,6,cv) && x+1<n){
					//check if 3 possible
					string three=temp;
						three.push_back(s[x+1]);
					if (check(three,18,cvc)){
						//both 2 and 3 possible = ambiguous case
						//check next 2-3, assuming string is three
						int idxNext=x+2;
						if (idxNext<n && isThree(idxNext)){
							cout<<three<<".";
							x+=2;
							count=0;
						}else{
							if(idxNext>=n){
								for (int i=x-1;i<n;i++){
									cout<<s[i];
								}
								break;
							}else{
								cout<<temp<<".";
								x+=1;
								count=0;									
							}
						}
					}else{
						//print 2;
						cout<<temp<<".";
						x+=1;
						count=0;
					}
				}else{
					//2 impossible so print 3
					cout<<s[x-2]<<s[x-1]<<s[x]<<".";
					x+=2;
					count=0;
				}
			}else{
				x++;
			}
			//cout<<x;
		}

		cout<<"\n";
	}

	return 0;
}

/*
- idk what the time complexity is at most it's O(n^3)
- spent ~90 minutes coding and debugging this one
- find the closest common ancestor for the two cows and mapped out scenarios essentially
*/

#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

void directfam(string x,string y, int z){
    cout<<x<<" is the ";
    for (int i=2;i<z;i++){
        cout<<"great-";
    }
    if (z>1){//if at least two generations apart
        cout<<"grand-";
    }
    cout<<"mother of "<<y;
}

int main(){
	freopen("family.in","r",stdin);
	freopen("family.out","w",stdout);

	int n;
	string c1,c2;
	cin>>n>>c1>>c2;
	vector<pair<string,string> > tree(n);
	bool found=false;
	
	vector<string> fam1{c1};//mark down the direct ancestors of cow1, in the order of generation, closest gen(mom) to farthest
	vector<string> fam2{c2};
	int ind1=-1,ind2=-1;//store index of c1 to find their parent

	for (int i=0;i<n;++i){
		cin>>tree[i].first>>tree[i].second;//first is parent of second
		//find parents of c1 and c2
		if (tree[i].second==c1){
		    if (tree[i].first==c2){
		        cout<<c2<<" is the mother of "<<c1;
		        found=true;
		    }
			ind1=i;
			fam1.push_back(tree[i].first);//found cow1's mom
		}else if (tree[i].second==c2){
		    if (tree[i].first==c1){
		        cout<<c1<<" is the mother of "<<c2;
		        found=true;
		    }
			ind2=i;
			fam2.push_back(tree[i].first);//found cow2's mom
		}
	}
	if (found){
	    return 0;
	}

	//if siblings
	else if (fam1[1]==fam2[1]){
		cout<<"SIBLINGS";
		return 0;
	}
	
	int dif=-1;
	//mark down direct ancestors of cow1;
	if (ind1!=-1){//need to specify this otherwise the program breaks bc fam1[1] doesn't exist if ind1=-1
	    string child=fam1[1];
        while(1){
        	bool flag=false;//whether this cow has a parent
        	for (int i=0;i<n;i++){
        		if (tree[i].second==child){
        			child = tree[i].first;
        			fam1.push_back(tree[i].first);
        			flag=true;
        			if (child==c2){//c1 is a direct descendant of c2
        				dif = fam1.size()-1;//number of greats we need
        				directfam(c2,c1,dif);
        				return 0;
        			}
        		}
        	}
        	if (!flag){
        		break;
        	}
        }
	}
	if (ind2!=-1){
	    string child=fam2[1];
    	while(1){
    		bool flag=false;//whether this cow has a parent
    		for (int i=0;i<n;i++){
    			if (tree[i].second==child){
    				child = tree[i].first;
    				fam2.push_back(tree[i].first);
    				flag=true;
    				if (child==c1){//c2 is a direct descendant of c1
    					dif = fam2.size()-1;//number of greats we need
    					directfam(c1,c2,dif);
    					return 0;
    				}
    			}
    		}
    		if (!flag){
    			break;
    		}
    	}
	}
	
	/*for (auto it=fam1.begin();it!=fam1.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	for (auto it=fam2.begin();it!=fam2.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;*/

	string ancestor;
	for (int i=1;i<fam1.size();i++){//find closest common ancestor
		for (int j=1;j<fam2.size();j++){
			if (fam1[i]==fam2[j]){
				ancestor=fam1[i];
				//cout<<ancestor<<' ';
				if (i==j || (i<j&&i!=1) || (i>j&&j!=1)){
					cout<<"COUSINS";
				}else if (i<j){//i is of an older generation
					cout<<c1<<" is the ";
					for (int k=1;k<abs(i-j);k++){
						cout<<"great-";
					}
					cout<<"aunt of "<<c2;

				}else{
					cout<<c2<<" is the ";
					for (int k=1;k<abs(i-j);k++){
						cout<<"great-";
					}
					cout<<"aunt of "<<c1;
				}
				return 0;
			}
		}
	}
	cout<<"NOT RELATED";
	
	return 0;
}

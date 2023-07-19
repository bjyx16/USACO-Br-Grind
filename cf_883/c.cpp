#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(const pair<int,int> &a,
              const pair<int,int> &b)
{
    if (a.first>b.first){
        return true;
    }else if (a.first==b.first && a.second<b.second){
        return true;
    }else{
        return false;
    }
}

int main(){
	int t;
	cin>>t;

	for (int i=0;i<t;i++){
		int n,m,h;
		cin>>n>>m>>h;
		vector< pair<int,int> > score;
		int rud1=0,rud2=0;
		for (int j=0;j<n;++j){//number of players
			vector<int> q(m);
			vector<int> sum(m);
			cin>>q[0];
			for (int k=1;k<m;k++){
				cin>>q[k];
			}
			sort(q.begin(),q.end());
			sum[0]=q[0];
			for (int k=1;k<m;k++){
				sum[k]=sum[k-1]+q[k];
			}
			int time=h;
			int pts=0,penalty=0;
			for (int k=0;k<m;k++){
				time-=q[k];
				if (time<0){
					break;
				}else{
					pts++;
					penalty += sum[k];
				}
			}

			if (j==0){
				rud1=pts;
				rud2=penalty;
				//cout<<rud1<<" "<<rud2<<"\n";
			}else{
				score.push_back(make_pair(pts,penalty));
			}
			
		}
        sort(score.begin(),score.end(),comp);
        /*for (vector< pair<int,int> >::const_iterator it=score.begin();it!=score.end();it++){
            cout<<it->first<<' '<<it->second<<"\n";
        }*/

        int x=1,flag=0;
        for (vector< pair<int,int> >::const_iterator it=score.begin();it!=score.end();it++){
			if (rud1>it->first){
				cout<<x;
				//cout<<"sdf";
				flag++;
				break;
			}else if(rud1==it->first && rud2<= it->second){
			    cout<<x;
			    //cout<<"asdifh";
			    flag++;
			    break;
			}
			x++;
		}
		if (flag==0){
		    cout<<n;
		}
		cout<<endl;
	}
	return 0;
}

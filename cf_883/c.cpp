/*
- sum/penalty variables overflowed
*/


#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool comp(const pair<long long,long long> &a,
              const pair<long long,long long> &b)
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
	long long t;
	cin>>t;

	for (long long i=0;i<t;i++){
		long long n,m,h;
		cin>>n>>m>>h;
		vector< pair<long long,long long> > score;
		long long rud1=0,rud2=0;
		for (long long j=0;j<n;++j){//number of players
			vector<long long> q(m);
			vector<long long> sum(m);
			cin>>q[0];
			for (long long k=1;k<m;k++){
				cin>>q[k];
			}
			sort(q.begin(),q.end());
			sum[0]=q[0];
			for (long long k=1;k<m;k++){
				sum[k]=sum[k-1]+q[k];
			}
			long long time=h;
			long long pts=0,penalty=0;
			for (long long k=0;k<m;k++){
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

        long long x=1,flag=0;
        for (vector< pair<long long,long long> >::const_iterator it=score.begin();it!=score.end();it++){
			if (rud1>it->first){
				cout<<x;
				//cout<<"sdf";
				flag++;
				break;
			}else if(rud1==it->first && rud2 <= it->second){
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

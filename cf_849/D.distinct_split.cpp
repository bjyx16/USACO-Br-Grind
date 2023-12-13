#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
const int MAX=200005;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,ans=0;
		string s;
		cin>>n>>s;
		
		int fw[26]={0};
        int bk[26]={0};

        for (int i=0;i<n;i++){
			fw[s[i]-'a']++;
		}

		for (int i=0;i<n;i++){
			fw[s[i]-'a']--;
			bk[s[i]-'a']++;
			int temp=0;
			for (int i=0;i<26;i++){
				temp += min(1,fw[i]) + min(1,bk[i]);
				//either add 1 or 0
			}

			ans = max(ans,temp);
		}
		cout<<ans<<"\n";
		
	}

	return 0;
}

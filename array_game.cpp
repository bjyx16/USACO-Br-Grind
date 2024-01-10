/*
- O(n) but the precomp() techinically O(n^2)??
- Check Assumptions: Originally assumed that would always choose the biggest num no matter what
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN=3*1e5;

int n;
vector<int> num(MAXN);
vector< pair<int, int> > consec(MAXN);//noninclusive of self

bool solveTurn(int count){
    if (count%2==1){
        return false;
    }
    return true;
}

void precomp(){
    int count=0,start=0;
    for (int i=0;i<n-1;i++){ //->
        if (num[i+1]>num[i]){
            count++;
        }else{
            consec[start].first = count;
            for (int j=start+1;j<=i;j++){
                count--;
                consec[j].first = count;
            }
            count=0;
            start=i+1;
        }
    }
    if (count!=0){
        consec[start].first = count;
        for (int j=start+1;j<=n-1;j++){
            count--;
            consec[j].first = count;
        }
    }

    start=n-1,count=0;
    for (int i=n-1;i>0;i--){ //<-
        if (num[i-1]>num[i]){
            count++;
        }else{
            consec[start].second = count;
            for (int j=start-1;j>=i;j--){
                count--;
                consec[j].second = count;
            }
            count=0;
            start=i-1;
        }
    }
    if (count!=0){
        consec[start].second = count;
        for (int j=start-1;j>=0;j--){
            count--;
            consec[j].second = count;
        }
    }

    return;
}

void win(int p){
    if(p==0){
        cout<<"Alice\n";
    }else{
        cout<<"Bob\n";
    }
    exit(0);
}

int main() {
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    precomp();

    /*for (int i=0;i<n;i++){
        cout<<consec[i].first<<' '<<consec[i].second<<'\n';
    }*/

    int start=0, end=n-1;
    bool player=0;
    int currMax=-1;

    while(1){
        //check if taking bigger number works
        if (num[start]>num[end]){
            if (solveTurn(consec[start].first) && num[start]>currMax){
                //cout<<"a";
                win(player);
            }
            //take from back
            if(num[end]>currMax){
                //cout<<"b";
                currMax = num[end];
                end--;
            }else{
                //cout<<"c";
                win(!player);
            }
        }else if (num[end]>num[start]){
            if (solveTurn(consec[end].second) && num[end]>currMax){
                //cout<<"d";
                win(player);
            }
            //take from front
            if(num[start]>currMax){
                //cout<<"e";
                currMax = num[start];
                start++;
            }else{
                //cout<<"f";
                win(!player);
            }
        }else{//if equal
            if (solveTurn(consec[start].first) || solveTurn(consec[end].second)){
                //cout<<"g";
                win(player);
            }else{
                //cout<<"f";
                win(!player);
            }
        }
        //cout<<currMax<<' ';
        //change player num
        player = !player;
    }

    return 0;
}

//each index -> # of increasing elements -> and <-
//5 6 7 2 1
//2 5 6 2 if end == start -> check which one to take based on

//what are all the possibilities & check assumptions.

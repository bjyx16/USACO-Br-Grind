/*

- The only cow that can be the leader with all cows of that breed in their list is the first cow of a breed
- Cases: -> to avoid overlap, ignore first cows and calculate the cases where the first two cows form a pair separately
1. Leader pair bc have all cows in the list
2. H leader bc includes list includes G leader (who has all cows of their breed)
3. vice versa
4. impossible! case: Leader pair bc have all cows in list and bc both lists include each other

The things that messed me up: *refer to note section at the end of the code for my first attempt - passed ~60% of cases
- wasn't careful with distinguishing the list[] elements and the indexes -> list[i] = index + 1. next time maybe just subtract when inputting list? or pay closer attention
- redundant code & if conditions bc didn't realise that the list corresponded to index+1; so can just do basic comparative operations
- main issue: overlooked the case where the first two cows are a pair
    - actually three possibilities (same three cases as above)

*/
#include <iostream>
using namespace std;
const int N = 1e5 + 1;

char cow[N]={};
int list[N]={0};

int main(){
    int n;
    int Hfirst=-1, Gfirst=-1;      //store index of the first cow of each breed
    bool seenH=0;                  //the only cow that can ever possibly be leader w/all breeed in list
    bool seenG=0;                  //is the first cow of the breed to appear
    bool Hleader=0, Gleader=0;
    int count=0;

    cin>>n;
    for (int i=0;i<n;++i){
        cin>>cow[i];
        if (!seenH && cow[i]=='H'){
            seenH=1;
            Hfirst=i;
        }
        if (!seenG && cow[i]=='G'){
            seenG=1;
            Gfirst=i;
        }
    }
    for (int i=0;i<n;++i){
        cin>>list[i];
    }
    
    int flag=0;
    for (int j=list[Hfirst];j<n;j++){//test if 1st H cow is leader
        if (cow[j]=='H'){
            flag++;
        }
    }
    if (flag==0){
        Hleader = 1;
    }
    flag=0;
    for (int j=list[Gfirst];j<n;j++){
        if (cow[j]=='G'){
            flag++;
        }
    }
    if (flag==0){
        Gleader = 1;
    }
    
    //cout<<Hleader<<' '<<Gleader<<"\n";
    //case 1
    if ((Hleader && Gleader) || (Gleader && list[Hfirst]-1>=Gfirst) || (Hleader && list[Gfirst]-1>=Hfirst)){
        count++;
        //cout<<"both"<<"\n";
    }

    //case 2: if one of the G cows has H's leader in their list
    if (Hleader){
        for (int i=0;i<Hfirst;i++){
            if (cow[i]=='G' && list[i]-1>=Hfirst){
                if (i != Gfirst){
                    count++;
                    //cout<<Hleader<<" "<<i<<"\n";
                }
            }
        }
    }
    
    if (Gleader){
        for (int i=0;i<Gfirst;i++){
            if (cow[i]=='H' && list[i]-1>=Gfirst){
                if (i != Hfirst){
                    count++;
                    //cout<<i<<" "<<Gleader<<"\n";
                }
            }
        }
    }
    cout<<count<<"\n";

    return 0;
}

/*#include <iostream>
using namespace std;
const int N = 5e5;

char cow[N]={};
int list[N]={0};

int main(){
    int n;
    int Hfirst=-1, Gfirst=-1;      //store index of the first cow of one breed to appear
    bool seenH=0;                  //the only cow that can ever possibly be leader w/all breeed in list
    bool seenG=0;                  //is the first cow of the breed to appear
    int Hleader=-1, Gleader=-1;
    int count=0;

    cin>>n;
    for (int i=0;i<n;++i){
        cin>>cow[i];
        if (!seenH && cow[i]=='H'){
            seenH=1;
            Hfirst=i;
        }
        if (!seenG && cow[i]=='G'){
            seenG=1;
            Gfirst=i;
        }
    }
    for (int i=0;i<n;++i){
        cin>>list[i];
        int flag=0;
        //check if is leader w all of one breed
        if(i==Hfirst){
            for (int j=list[i];j<n;j++){
                if (cow[j]=='H'){
                    flag++;
                }
            }
            if (flag==0){
                Hleader = i;
            }
        }
        if(i==Gfirst){
            for (int j=list[i];j<n;j++){
                if (cow[j]=='G'){
                    flag++;
                }
            }
            if (flag==0){
                Gleader = i;
            }
        }
    }
    //cout<<Hleader<<' '<<Gleader<<"\n";
    //case 1
    if (Hleader!=-1 && Gleader!=-1){
        count++;
        //cout<<"both"<<"\n";
    }

    //case 2: if one of the G cows has H's leader in their list

    for (int i=0;i<Hleader;i++){
        if (cow[i]=='G'){//might be a redundant piece of code bc if Hleader then all before have to be G
            if (Hleader<=list[i] && Hleader>=i+1){
                if (i != Gleader){
                    count++;
                    //cout<<Hleader<<" "<<i<<"\n";
                }
            }
        }
    }
    for (int i=0;i<Gleader;i++){
        if (cow[i]=='H'){//might be a redundant piece of code bc if Hleader then all before have to be G
            if (Gleader<=list[i] && Gleader>=i+1){
                if (i != Hleader){
                    count++;
                    //cout<<i<<" "<<Gleader<<"\n";
                }
            }
        }
    }
    cout<<count<<"\n";

    return 0;
}*/

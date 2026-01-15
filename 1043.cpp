#include <iostream>

using namespace std;

int N,M;



int main(){
    cin>>N>>M;

    int care_n, party_n;
    cin>>care_n;
    long long int carebit=0;
    for(int i=0;i<care_n;i++){
        int tmp;
        cin>>tmp;
        carebit= carebit|(1LL<<tmp);
    }

    long long int visited=0;
    long long int partypeoplebit[51]={0,};
    for(int i=0;i<M;i++){
        cin>>party_n;
        for(int j=0;j<party_n;j++){
            int tmp;
            cin>>tmp;
            partypeoplebit[i]=partypeoplebit[i]|(1LL<<tmp);
        }
    }
    int ans=M;
    for(int i=0;i<=50;i++){
        if((partypeoplebit[i]&carebit) !=0){
            ans--;
            visited = visited|partypeoplebit[i];
            partypeoplebit[i]=0; 
        }
    }
    bool ischange=true;
    while(ischange){
        ischange=false;
        for(int i=0;i<=50;i++){
            if((partypeoplebit[i] & visited) != 0){
                ans--;
                visited = visited|partypeoplebit[i];
                partypeoplebit[i]=0;
                ischange=true;
            }
        }
    }
    cout<<ans<<"\n";
}
    
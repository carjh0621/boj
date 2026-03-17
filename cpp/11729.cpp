#include <iostream>

using namespace std;


int hanoi_cnt(int n){
    if(n==1) return 1;
    return 2*hanoi_cnt(n-1) + 1;
}


void hanoi_trace(int n,int from,int via,int to){
    if(n==1){
        cout<<from<<" "<<to<<"\n";
        return;
    }
    hanoi_trace(n-1,from,to,via);
    cout<<from<<" "<<to<<"\n";
    hanoi_trace(n-1,via,from,to);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    cout<<hanoi_cnt(n)<<"\n";

    hanoi_trace(n,1,2,3);

}
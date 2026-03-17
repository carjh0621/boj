#include <iostream>

using namespace std;

int n,m;
int result[8];

void trace(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<result[i]+1<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=0;i<n;i++){
        int flag=0;
        for(int j=0;j<=depth-1;j++){
            if(i==result[j]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            result[depth]=i;
            trace(depth+1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    trace(0);
    


}
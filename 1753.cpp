#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;



int V,E;
int K;



void search(vector<vector<int>> &e){
    for(int k=1;k<=V;k++){
        for(int i=1;i<=V;i++){
            for(int j=1;j<=V;j++){
                if(e[i][k] == INT32_MAX || e[k][j] == INT32_MAX) continue;
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);   

            }
        }
    }
    
    for(int i=1;i<=V;i++){
        if(e[K][i]==INT32_MAX) cout<<"INF\n";
        else cout<<e[K][i]<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;

    cin>>K;

    vector<vector<int>> e(V+1,vector<int> (V+1,INT32_MAX));
    for(int i=1;i<=V;i++){
        e[i][i]=0;
    }
    for(int i=0;i<E;i++){
        int s,d,c;
        cin>>s>>d>>c;
        if(e[s][d]>c)
            e[s][d]=c;
    }
    
    
    search(e);

    return 0;
}
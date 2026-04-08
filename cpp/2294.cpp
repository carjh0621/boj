#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL); 
    int n,k;
    cin>>n>>k;
    
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    vector<int> dp(k+1, 100001); 
    dp[0] = 0; 
    for(int coin : v){
        for(int i=coin;i<=k;i++){
            if (dp[i-coin] != 100001) { 
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }

    if (dp[k] == 100001) { 
        cout<<-1<<endl;
    } else {
        cout<<dp[k]<<endl;
    }
    return 0;
}

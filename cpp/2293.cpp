#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    
    int n,k;
    cin>>n>>k;
    
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());

    vector<int> dp(k+1,0);
    dp[0] = 1;
    for(int coin : v){
        for(int i=coin;i<=k;i++){
            dp[i] += dp[i-coin];
        }

    }

    cout << dp[k] << endl;
    return 0;
}
/*
4 20
2
5
10
15
*/
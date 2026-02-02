/*
RGB거리에는 집이 N개 있다. 거리는 선분으로 나타낼 수 있고, 1번 집부터 N번 집이 순서대로 있다.

집은 빨강, 초록, 파랑 중 하나의 색으로 칠해야 한다. 각각의 집을 빨강, 초록, 파랑으로 칠하는 비용이 주어졌을 때, 아래 규칙을 만족하면서 모든 집을 칠하는 비용의 최솟값을 구해보자.

1번 집의 색은 2번 집의 색과 같지 않아야 한다.
N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans=INT32_MAX;
int result=0;
int n;
int depth=0;
vector<vector<int>> v;

//재귀함수로 하니까 시간초과 뜬다. dp나 반복문으로 바꿔야할듯
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    v.resize(n,vector<int>(3));
    
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1]>>v[i][2];
    }
    
    vector<vector<int>> dp(n, vector<int>(3));
    
    dp[0][0] = v[0][0];
    dp[0][1] = v[0][1];
    dp[0][2] = v[0][2];
    
    for(int i=1; i<n; i++){
        dp[i][0] = v[i][0] + min(dp[i-1][1], dp[i-1][2]);
        dp[i][1] = v[i][1] + min(dp[i-1][0], dp[i-1][2]);
        dp[i][2] = v[i][2] + min(dp[i-1][0], dp[i-1][1]);
    }
    
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]}) << "\n";
    
    return 0;
}
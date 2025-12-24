/*
문제
        7
      3   8
    8   1   0
  2   7   4   4
4   5   2   6   5
위 그림은 크기가 5인 정수 삼각형의 한 모습이다.

맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 
아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 
경로를 구하는 프로그램을 작성하라. 
아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 
대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

삼각형의 크기는 1 이상 500 이하이다. 
삼각형을 이루고 있는 각 수는 모두 정수이며, 범위는 0 이상 9999 이하이다.
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    vector<vector<int>> v(n,vector<int>(n,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>v[i][j];
        }
    }
    vector<vector<int>> dp(n,vector<int>(n,0));
    dp[0][0]=v[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0){
                dp[i][0]=v[i][0]+dp[i-1][0];
                continue;
            }
            else if(j==i){
                dp[i][j]=v[i][j]+dp[i-1][j-1];
                continue;
            }
            else {
                dp[i][j]=v[i][j]+max(dp[i-1][j-1], dp[i-1][j]);
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(ans<dp[n-1][i]) ans=dp[n-1][i];
    }
    cout<<ans<<"\n";
    return 0;



}
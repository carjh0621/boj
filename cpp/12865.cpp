#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,k;

	cin>>n>>k;

	vector<vector<int>> v(n+1,vector<int> (2,0));
	for(int i=1;i<=n;i++){
		for(int j=0;j<2;j++){
			cin>>v[i][j];
		}
	}
	//v[i][0] = weight v[i][1] = value
	
	vector<vector<int>> dp(n+1,vector<int> (k+1,0));
	

	for(int i=1;i<=n;i++){	
		for(int j=1;j<=k;j++){
			if(v[i][0]>j)
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j], dp[i-1][j-v[i][0]] + v[i][1]);
		}
	}	
	/*
	dp[i,w] = dp[i-1,w] (if w_i > w)
	dp[i,w] = max(dp[i-1,w], dp[i-1,w-(w_i)] + v_i (else)
	*/
	cout<<dp[n][k]<<"\n";

	return 0;
}

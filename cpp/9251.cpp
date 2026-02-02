/*
LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

첫째 줄과 둘째 줄에 두 문자열이 주어진다. 문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1,s2;

    cin>>s1>>s2;
    int l1=s1.size();
    int l2=s2.size();
    vector<vector<int>> v(l1+1, vector<int> (l2+1,0));
    
    
    
    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
        
            // 문자가 같다면 (문자열 인덱스는 0부터 시작하니 i-1, j-1로 접근)
            if (s1[i-1] == s2[j-1]) {
                v[i][j] = v[i-1][j-1] + 1; // 대각선 + 1
            } 
            // 문자가 다르다면
            else {
                v[i][j] = max(v[i-1][j], v[i][j-1]); // 위쪽과 왼쪽 중 큰 값
            }
        }
    }

    cout<<v[l1][l2]<<"\n";

}


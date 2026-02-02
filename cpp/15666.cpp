/*
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

N개의 자연수 중에서 M개를 고른 수열
같은 수를 여러 번 골라도 된다.
고른 수열은 비내림차순이어야 한다.
길이가 K인 수열 A가 A1 ≤ A2 ≤ ... ≤ AK-1 ≤ AK를 만족하면, 비내림차순이라고 한다.
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> arr;
set<vector<int>> ans;
vector<int> result;

void backtracking(int depth,int cur_pos){
    if(depth==m){
        ans.insert(result);
        return;
    }
    else{
        for(int i=cur_pos;i<n;i++){
            result.push_back(arr[i]);
            backtracking(depth+1,i);
            result.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>> n>>m;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        arr.push_back(tmp);
    }
    sort(arr.begin(),arr.end());
    backtracking(0,0);
    for(auto it= ans.begin();it!=ans.end();it++){
        for(int i=0;i<m;i++){
            cout<<(*it)[i]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
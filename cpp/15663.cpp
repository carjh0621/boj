/*
N과 M (9)
문제
N개의 자연수와 자연수 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.
    N개의 자연수 중에서 M개를 고른 수열
입력
첫째 줄에 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

둘째 줄에 N개의 수가 주어진다. 입력으로 주어지는 수는 10,000보다 작거나 같은 자연수이다.

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int N, M;
set<vector<int>> result;
vector<int> arr;
vector<int> ans;
void backtracking(int depth, vector<bool> visited) {
    if (depth == M) {
        result.insert(ans);
        return;
    }
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {  
            visited[i] = true;
            ans.push_back(arr[i]);
            backtracking(depth + 1, visited);
            visited[i] = false;
            ans.pop_back();
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<bool> visited(N, false);
    backtracking(0, visited);
    for (const auto& seq : result) {
        for (int num : seq) {
            cout << num << ' ';
        }
        cout << '\n';
    }
    return 0;
}
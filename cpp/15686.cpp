#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm> 
#include <climits>   
using namespace std;

struct market {
    int r;
    int c;
};

struct home {
    int r;
    int c;
};

int N, M;

vector<market> m;
vector<home> h;  
vector<market> picked;

int result = INT_MAX;

// 거리 계산 함수 
int distance(market mk, home hm) {
    return abs(mk.r - hm.r) + abs(mk.c - hm.c);
}

// M개를 모두 골랐을 때 도시의 치킨 거리를 계산하는 함수
void calculate_chicken_distance() {
    int city_total_dist = 0;

    for (int i = 0; i < h.size(); i++) {
        int min_dist = INT_MAX;
        
        // 현재 집(h[i])에서 가장 가까운 선택된 치킨집 찾기
        for (int j = 0; j < picked.size(); j++) {
            int d = distance(picked[j], h[i]);
            if (d < min_dist) {
                min_dist = d;
            }
        }
        city_total_dist += min_dist;
    }

    
    if (city_total_dist < result) {
        result = city_total_dist;
    }
}

//idx는 m에서 탐색할 인덱스, count는 현재 선택한 개수
void DFS(int idx, int count) {
    // M개를 모두 골랐으면 거리 계산
    if (count == M) {
        calculate_chicken_distance();
        return;
    }

    // 치킨집 고르기
    for (int i = idx; i < m.size(); i++) {
        picked.push_back(m[i]); // i번째 치킨집 선택
        DFS(i + 1, count + 1);  // 다음 것 고르러 감
        picked.pop_back();      // 선택 취소 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            if (tmp == 1) {
                h.push_back({i, j});
            }
            else if (tmp == 2) {
                m.push_back({i, j});
            }
        }
    }

   
    DFS(0, 0);

    cout << result << "\n";

    return 0;
}
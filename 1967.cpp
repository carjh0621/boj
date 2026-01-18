#include <iostream>
#include <climits>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n;

struct edge{
    int dest;
    int cost;
};


int search(int start_node, vector<vector<edge>> &e){
    vector<int> dist(n+1,0);
    vector<bool> visited(n+1, false);
    priority_queue<pair<int,int>,vector<pair<int,int>>> q;
    pair<int,int> dist_and_index;
    dist[start_node]=0;
    q.push(dist_and_index);

    while(!q.empty()){
        dist_and_index=q.top();
        q.pop();
        int cur=dist_and_index.second;
        visited[cur]=true;
        if(dist[cur]>dist_and_index.first) continue;
        for(auto it=e[cur].begin();it!=e[cur].end();it++){
            if(dist[it->dest] < dist[cur] + it->cost){
                if(visited[it->dest]==false){
                    dist[it->dest] = dist[cur] + it->cost;
                    dist_and_index.first = dist[it->dest];
                    dist_and_index.second = it->dest;
                    q.push(dist_and_index);
                }
            }
        }
    }
    sort(dist.begin(),dist.end());
    return dist[0];


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    vector<vector<edge>> e(n+1,vector<edge> ());

    for(int i=1;i<n;i++){
        int s,d,c;
        cin>>s>>d>>c;
        e[s].push_back({d,c});
        //e[d].push_back({s,c});
    }
    int ans=0;
    for(auto it = e[1].begin(); it!=e[1].end();it++){
        int tmp=0;
        tmp = search(it->dest,e) + it->cost;
        ans+=tmp;    
    }
    cout<<ans<<"\n";
}

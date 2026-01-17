#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;



int V,E;
int K;

struct edge{
    int dest;
    int cost;
};

void search(int s_node, int d_node , vector<vector<edge>> &e){
    vector<int> dist(V+1,INT32_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    pair<int,int> dist_and_index;
    vector<bool> visited(V+1,false);

    dist[s_node]=0;
    dist_and_index.first=dist[s_node];
    dist_and_index.second=s_node;
    
    q.push(dist_and_index);
    
    while(!q.empty()){
        dist_and_index=q.top();
        q.pop();
        int cur=dist_and_index.second;
        if(dist[cur]<dist_and_index.first) continue;
        visited[cur]=true;
        if(cur==d_node) break;
        for(auto it = e[cur].begin();it!=e[cur].end();it++){
            if(dist[it->dest] > dist[cur] + it->cost){
                if(visited[it->dest] == false){
                    dist[it->dest] = dist[cur] + it->cost;
                    dist_and_index.first=dist[it->dest];
                    dist_and_index.second=it->dest;
                    q.push(dist_and_index);
                }
            }  
        }

    }
    
    if(dist[d_node]==INT32_MAX){
        cout<<"INF"<<"\n";
    }
    else{
        cout<<dist[d_node]<<"\n";
    }
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>V>>E;

    cin>>K;

    vector<vector<edge>> e(V+1);

    for(int i=0;i<E;i++){
        int s,d,c;
        cin>>s>>d>>c;
        e[s].push_back({d,c});
    }

    for(int i=1;i<=V;i++){
        search(K,i,e);
    }

    return 0;
}
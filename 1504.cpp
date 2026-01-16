#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N,E;


struct edge{
    int dest;
    long long int cost;
};

long long int search(int start_node, int dest_node, vector<vector<edge>> &e){
    priority_queue<pair<long long int,int>,vector<pair<long long int,int>>,greater<pair<long long int, int>>> q;

    vector<bool> visited;
    visited.resize(N+1,false);

    vector<long long int> dist;
    dist.resize(N+1,INT64_MAX);
    dist[start_node]=0;

    pair <long long int, int> dist_and_index;
    dist_and_index.first=dist[start_node];
    dist_and_index.second=start_node;
    q.push(dist_and_index);
    
    
    while(!q.empty()){
        dist_and_index=q.top();
        q.pop();
        int cur=dist_and_index.second;
        if(dist[cur]<dist_and_index.first) continue;
        visited[cur]=true;
        if(cur == dest_node) break;
        for(auto it = e[cur].begin(); it!=e[cur].end();it++){
            if(dist[cur] + it->cost < dist[it->dest]){
                if(visited[it->dest]==false){
                    dist[it->dest]=dist[cur] + it->cost;
                    dist_and_index.first=dist[it->dest];
                    dist_and_index.second=it->dest;
                    q.push(dist_and_index);
                }
            }
        }
    }
    if(dist[dest_node]==INT64_MAX) return -1;
    else return dist[dest_node];
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>E;

    //vector<bool> visited(N+1,true);
    vector<vector<edge>> e(N+1,vector<edge> ());

    for(int i=0;i<E;i++){
        int s,d;
        long long int c;
        cin>>s>>d>>c;
        e[s].push_back({d,c});
        e[d].push_back({s,c});
    }

    int v1,v2;
    cin>>v1>>v2;

    
    long long int ans1=0, ans2=0;
    
    long long int tmp=0;
    tmp=search(1,v1,e);
    if(tmp!=-1){
        ans1+=tmp;
        tmp=search(v1,v2,e);
        if(tmp!=-1){
            ans1+=tmp;
            tmp=search(v2,N,e);
            if(tmp!=-1){
                ans1+=tmp;
            }
            else{
                ans1=INT64_MAX;
            }
        }
        else{
            ans1=INT64_MAX;
        }
        
    }
    else{
        ans1=INT64_MAX;
    }
    
     


    tmp=search(1,v2,e);
    if(tmp!=-1){
        ans2+=tmp;
        tmp=search(v2,v1,e);
        if(tmp!=-1){
            ans2+=tmp;
            tmp=search(v1,N,e);
            if(tmp!=-1){
                ans2+=tmp;
            }
            else{
                ans2=INT64_MAX;
            }
        }
        else{
            ans2=INT64_MAX;
        }
        
    }
    else{
        ans2=INT64_MAX;
    }
    
    long long int ans = min(ans1,ans2);
    if(ans==INT64_MAX) cout<<"-1"<<"\n";
    else cout<<ans<<"\n";




    return 0;
}
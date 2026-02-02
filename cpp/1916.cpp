/*
N개의 도시가 있다. 그리고 한 도시에서 출발하여 다른 도시에 도착하는 M개의 버스가 있다. 
우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다. 
A번째 도시에서 B번째 도시까지 가는데 드는 최소비용을 출력하여라. 도시의 번호는 1부터 N까지이다.
*/


#include <iostream> 
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdint>
using namespace std;

int n,m;

struct edge{
    int dest;
    int cost;
};

struct node{
    long long int path_length;
    int index;
};

struct cmp{
    bool operator()(node &a, node &b){
        if(a.path_length!=b.path_length) return a.path_length > b.path_length;
        else return a.index > b.index;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;
    
    
    vector<vector<edge>> adj(n+1);
    
    for(int i=0;i<m;i++){
        int start, dest, cost;
        cin>>start>>dest>>cost;
        adj[start].push_back({dest,cost});
    }

    int s,d;
    cin>>s>>d;
    

    vector<long long int> v(n+1,INT64_MAX);
    vector<bool> visited(n+1,false);
    v[s]=0;
    
    priority_queue<node,vector<node>, cmp> q;
    /*
    for(int j=1;j<=n;j++){
        q.push({&v[j],j});
    }
    */
    q.push({v[s],s});

    while(!q.empty()){
        int i=0;
        node tmp;    
        do{
            tmp=q.top();
            q.pop();
        }while(tmp.path_length>v[tmp.index] && !q.empty());
        visited[tmp.index]=true;
        int dest, start, cost;
        start=tmp.index;
        

        for(int j=0;j<adj[start].size();j++){
            /*
            for(int k=1;k<=n;k++){
                if(v[k]==INT64_MAX) cout<<"inf"<<" ";
                else cout<<v[k]<<" ";
            }cout<<"\n"<<"i: "<<i++<<"\n"<<"q: "<<tmp.index<<","<<tmp.path_length<<" ";
            */
            dest=adj[start][j].dest;
            cost=adj[start][j].cost;
            //cout<<"dest: "<<dest<<" cost: "<<cost<<"\n";
            if(v[dest]>cost + v[start] && v[start]!=INT64_MAX){
                v[dest] = cost + v[start];
                if(visited[dest]==false)        
                    q.push({v[dest],dest});        
            }
        }
        
        
        
    }
   
    
    cout<<v[d]<<"\n";

    
    


}

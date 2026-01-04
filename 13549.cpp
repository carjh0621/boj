
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int MAX = 1000000;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin>>n>>k;
    //dis,index
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dis(MAX +1,INT32_MAX);

    dis[n]=0;
    pq.push({dis[n],n});

    while(!pq.empty()){
        int cur_node = pq.top().second;
        pq.pop();
        if(cur_node==k){
            cout<<dis[cur_node]<<"\n";
            return 0;
        }

        if(cur_node*2 <= MAX && dis[cur_node*2]>dis[cur_node] && cur_node<k){
            dis[cur_node*2]=dis[cur_node];
            pq.push({dis[cur_node*2],cur_node*2});
            
            //cout<<"x2\n";
        }
        if(cur_node+1<=MAX && dis[cur_node+1]>dis[cur_node] && cur_node<k){
            dis[cur_node+1]=dis[cur_node]+1;
            pq.push({dis[cur_node+1],cur_node+1});
            
            //cout<<"+1\n";
        }
        if(cur_node-1>=0 && dis[cur_node-1]>dis[cur_node]){
            dis[cur_node-1]=dis[cur_node]+1;
            pq.push({dis[cur_node-1],cur_node-1});
            
            //cout<<"-1\n";
        }


    }

    

}
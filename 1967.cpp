#include <iostream>
#include <climits>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n;
int ans=0;
struct node{
    bool isleaf=false;
    vector<pair<int,int>> children; // child, edge_cost
    int diameter = 0;
    int longest_path=0;
};

void search(int root, vector<node> &tree){
    node& cur = tree[root];
    if(cur.isleaf==true) return;

    int best1=0, best2=0; // 자식 경로들 중 가장 긴 원투
    for(int i=0;i<cur.children.size();i++){
        int c=cur.children[i].first;
        int w=cur.children[i].second;

        search(c,tree);

        int cand = tree[c].longest_path + w;

        if(cand>best1){
            best2=best1;
            best1=cand;
        }
        else if(cand>best2){
            best2=cand;
        }
    }

    cur.longest_path = best1;
    cur.diameter = best1 + best2;
    if(ans<cur.diameter) ans=cur.diameter;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    cin>>n;

    vector<node> tree(n+1);

    for(int i=1;i<n;i++){
        int p,c,w;
        cin>>p>>c>>w;
        tree[p].children.push_back({c,w});
    }
    for(int i = 1; i <= n; i++){
        if(tree[i].children.empty()) tree[i].isleaf = true;
    }

    search(1,tree);
    cout<<ans<<"\n";
    
}

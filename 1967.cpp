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
    int left_child=0;
    int right_child=0;
    int left_edge_cost=0;
    int right_edge_cost=0;
    int diameter = 0;
    int longest_path=0;
};

void search(int root, vector<node> &tree){
    node& cur = tree[root];
    if(cur.isleaf==false){
        search(cur.left_child,tree);
        search(cur.right_child,tree);
        cur.longest_path = max(tree[cur.left_child].longest_path + cur.left_edge_cost, 
                                tree[cur.right_child].longest_path + cur.right_edge_cost);
        cur.diameter = tree[cur.left_child].longest_path + cur.left_edge_cost + 
                        tree[cur.right_child].longest_path + cur.right_edge_cost;
        if(ans<cur.diameter) ans=cur.diameter;
    }
    else{
        return;
    }
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
        if(tree[p].left_child==0) {
            tree[p].left_child=c;
            tree[p].left_edge_cost=w;
        }
        else{
            tree[p].right_child=c;
            tree[p].right_edge_cost=w;
        }
    }
    for(int i=0;i<=n;i++){
        if(tree[i].left_child ==0 && tree[i].right_child==0) 
            tree[i].isleaf=true;
    }
    search(1,tree);
    cout<<ans<<"\n";
    
}

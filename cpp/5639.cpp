#include <iostream>
#include <vector>

using namespace std;

struct node{
    int lc=0;
    int rc=0;
    int parent=0;
    int value=0;
};
vector<node> tree(10000);

int v;
int newnode=1;

void search(int idx){
    if(idx==0) return;
    search(tree[idx].lc);
    search(tree[idx].rc);
    cout<<tree[idx].value<<"\n";
}

void insert(){
    int p=1,c=1;
    bool islc=true;
    while(c != 0){
        p=c;
        if(v<tree[p].value){
            c=tree[p].lc;
            islc=true;
        }
        else{
            c=tree[p].rc;
            islc=false;
        }
    }
    newnode++;
    tree[newnode].value=v;
    tree[newnode].parent=p;
    if(islc) tree[p].lc=newnode;
    else tree[p].rc=newnode;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
   
    cin>>v;
    
    tree[1].value=v;

    while(cin>>v){
        insert();
    }


    search(1);

    return 0;
}
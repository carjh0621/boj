/*
이진 트리를 입력받아 전위 순회(preorder traversal), 중위 순회(inorder traversal), 
후위 순회(postorder traversal)한 결과를 출력하는 프로그램을 작성하시오.

예를 들어 위와 같은 이진 트리가 입력되면,

전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
가 된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
typedef struct Node{
    char value;
    Node* left_child;
    Node* right_child;
}node;

void pre_travel(node* cur){
    cout<<cur->value;
    if(cur->left_child!=NULL)
        pre_travel(cur->left_child);
    if(cur->right_child!=NULL)
        pre_travel(cur->right_child);
}

void in_travel(node* cur){
    if(cur->left_child!=NULL)
        in_travel(cur->left_child);
    cout<<cur->value;
    if(cur->right_child!=NULL)
        in_travel(cur->right_child);
}

void post_travel(node * cur){
    if(cur->left_child!=NULL)
        post_travel(cur->left_child);
    if(cur->right_child!=NULL)
        post_travel(cur->right_child);
    cout<<cur->value;
}

int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    vector<node> tree(n);
    
    char p,c1,c2;
    for(int i=0;i<n;i++){
        cin>>p>>c1>>c2;
        tree[(int)(p-'A')].value=p;
        tree[(int)(p-'A')].left_child=NULL;
        tree[(int)(p-'A')].right_child=NULL;
        if(c1!='.'){
            tree[(int)(p-'A')].left_child=&tree[(int)(c1-'A')];
        }
        if(c2!='.'){
            tree[(int)(p-'A')].right_child=&tree[(int)(c2-'A')];
        }
    }

    pre_travel(&tree[0]);
    cout<<"\n";
    in_travel(&tree[0]);
    cout<<"\n";
    post_travel(&tree[0]);
    cout<<"\n";



}
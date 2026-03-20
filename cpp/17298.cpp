#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    vector<int> v(n),cmiv(n,-1);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    stack<int> s; // store index
    int index=0;
    s.push(index);
    while(!s.empty()){
        if(index<n-1){
            index++;
        }
        while(!s.empty() && v[s.top()]<v[index]){
            cmiv[s.top()]=v[index];
            s.pop();
        }
        if(index<n-1) s.push(index);
        else if(index==n-1 && !s.empty()) s.pop();

    }
    for(int i=0;i<n;i++){
        cout<<cmiv[i]<<" ";
    }
    cout<<"\n";

}
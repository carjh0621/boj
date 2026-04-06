#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(pair<int,int>& a, pair<int,int>&b){
    if (a.first == b.first)
        return a.second<b.second;
    return a.first<b.first;
}


int main(){
    
    int N;
    cin>>N;

    vector<pair<int,int>> v(N); 
    for(int i=0; i<N;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end(),compare);

    priority_queue<int,vector<int>,greater<int>> heap;

    for(int i=0;i<N;i++){
        if(!heap.empty() && heap.top()<=v[i].first){
            heap.pop();
        }
        heap.push(v[i].second);
    }

    cout<<heap.size()<<"\n";
    

    return 0;
}
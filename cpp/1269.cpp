#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;

    set<int> s1,s2,tmps1,tmps2;

    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        s1.insert(tmp);
        tmps1.insert(tmp);
    }
    for(int i=0;i<m;i++){
        int tmp;
        cin>>tmp;
        s2.insert(tmp);
        tmps2.insert(tmp);
    }
    //s1-s2
    for(auto it = s2.begin();it!=s2.end();it++){
        if(s1.find(*it)!=s1.end()){
            tmps1.erase(*it);
        }
    }
    //s2-s1
    for(auto it = s1.begin();it!=s1.end();it++){
        if(s2.find(*it)!=s2.end()){
            tmps2.erase(*it);
        }
    }

    cout<<tmps1.size() + tmps2.size()<<"\n";

}
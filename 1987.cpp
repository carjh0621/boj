#include <iostream>
#include <vector>
#include <set>

using namespace std;

int R,C; //r:1~R-1 c:1~C-1
int ans=0;
int path=0;
set<char> s;

void search(int r, int c, vector<vector<char>> &b, vector<vector<bool>> &v){
    if(v[r][c] == false){
        if(s.find(b[r][c])!=s.end()) return;
        v[r][c]=true;
        s.insert(b[r][c]);
        path++;
        if(ans<path) ans=path;

        if(r-1>=0) search(r-1,c,b,v);
        if(r+1<=R-1) search(r+1,c,b,v);
        if(c-1>=0) search(r,c-1,b,v);
        if(c+1<=C-1) search(r,c+1,b,v);
        
        path--;
        v[r][c]=false;
        s.erase(b[r][c]);
        return;
        
    }
    else{
        return;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>R>>C;

    vector<vector<char>> b(R,vector<char> (C));

    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>b[i][j];
        }
    }

    
    vector<vector<bool>> v(R,vector<bool> (C,false));
    
    search(0,0,b,v);
    cout<<ans<<"\n";
    return 0;
}
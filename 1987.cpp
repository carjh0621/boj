#include <iostream>
#include <vector>
#include <set>

using namespace std;

int R,C; //r:1~R-1 c:1~C-1
int ans=0;
int path=0;
bool used[26]={false,};

void search(int r, int c, vector<vector<char>> &b){
   int idx = b[r][c] - 'A';
   if(used[idx]) return;

   used[idx] = true;
   path++;
   if(ans<path) ans=path;

   if(ans==26){
    used[idx]=false;
    path--;
    return;
   }
   if(r-1 >=0) search(r-1,c,b);
   if(r+1<=R-1) search(r+1,c,b);
   if(c-1>=0) search(r,c-1,b);
   if(c+1<=C-1) search(r,c+1,b);

   path--;
   used[idx]=false;
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

    
    search(0,0,b);
    cout<<ans<<"\n";
    return 0;
}
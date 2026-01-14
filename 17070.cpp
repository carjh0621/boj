#include <iostream>
#include <vector>

using namespace std;

int N;

struct point{
    int r;
    int c;
};

vector<point> wall;
vector<point> pipe(2);

int result=0;

int check_position(){
    int tr, tc, hr, hc;
    tr=pipe[0].r; tc=pipe[0].c; hr=pipe[1].r; hc=pipe[1].c;
    if(tr==hr-1 && tc==hc) return 0; // 세로
    if(tr==hr-1 && tc==hc-1) return 1; //대각선
    if(tr==hr && tc==hc-1) return 2; // 가로
    return -1;
}

int search_wall(int r,int c){
    for(int i=0;i<wall.size();i++){
        if(wall[i].r==r && wall[i].c==c) return 1;
   }
   return 0;
}

int wall_check(){
    int hr, hc;
    hr=pipe[1].r; hc=pipe[1].c;
    switch(check_position()){
        case 0:
            if(search_wall(hr,hc)) return 1;
            return 0;
            break;
        case 1:
            if(search_wall(hr,hc)) return 1;
            if(search_wall(hr,hc-1)) return 1;
            if(search_wall(hr-1,hc)) return 1;
            return 0;
            break;
        case 2:
            if(search_wall(hr,hc)) return 1;
            return 0;
            break;
        default:
            return 0;
            break;
    }
}

void dfs(){
    if(pipe[1].r>N || pipe[1].c>N) return;
    if(wall_check()) return; 
    if(pipe[1].r==N && pipe[1].c==N) {
        result++;
        return;
    }
    
    switch(check_position()){
        case 0:
            pipe[1].r++;
            pipe[0].r++;
            dfs();
            pipe[1].c++;
            dfs();
            pipe[1].r--;
            pipe[1].c--;
            pipe[0].r--;
            break;
        case 1:
            pipe[0].r++; pipe[0].c++;
            pipe[1].r++; 
            dfs();
            pipe[1].c++;
            dfs();
            pipe[1].r--;
            dfs();
            pipe[0].r--; pipe[0].c--;
            pipe[1].c--;
            break;
        case 2:
            pipe[0].c++;
            pipe[1].c++;
            dfs();
            pipe[1].r++;
            dfs();
            pipe[1].r--;
            pipe[1].c--;
            pipe[0].c--;
            break;
        default:
            break;
    } 
    
    
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            int tmp;
            cin>>tmp;
            if(tmp==1){
                wall.push_back({i,j});
            }
        }
    }
    pipe[0]={1,1}; pipe[1]={1,2};

    dfs();
    
    cout<<result<<"\n";
    return 0;
}
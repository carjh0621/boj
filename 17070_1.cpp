#include <iostream>

using namespace std;

int N;
int board[18][18];
int ans=0;

//파이프의 head 좌표, 파이프기 놓여있는 방향
// 0: 가로 1: 세로 2: 대각선
void dfs(int r, int c, int dir){
    if(r==N && c==N){
        ans++; 
        return;
    }

    //가로로 이동
    if(dir==0 || dir==2){
        if(c+1<=N && board[r][c+1]==0){
            dfs(r,c+1,0);
        }
    }
    
    //세로로 이동
    if(dir==1 || dir==2){
        if(r+1<=N && board[r+1][c]==0){
            dfs(r+1,c,1);
        }
    }

    //대각선으로 이동
    if(r+1 <= N && c+ 1 <=N){
        if(board[r][c+1] == 0 && board[r+1][c]==0 && board[r+1][c+1]==0){
            dfs(r+1,c+1,2);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>board[i][j];
        }
    }

    dfs(1,2,0);
    
    cout<<ans<<"\n";
    return  0;
}
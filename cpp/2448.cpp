#include <iostream>
#include <vector>

using namespace std;

int N;
int k;
vector<vector<char>> b;
void triangle(int r, int c){
    int cnt=0;
    for(int i=r;i<=r+2;i++){
        for(int j=c;j<=c+cnt;j++){
            if(i==r+1 && j==c+1) continue;
            b[i][j]='*';
        }
        cnt+=2;
        c--;
    }
}

void draw(int k,int r,int c){
    if(k==3){
        triangle(r,c);
        return;
    }
    else{
        k=k/2;
        draw(k,r,c);
        draw(k,r+k,c-k);
        draw(k,r+k,c+k);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    b.resize(N+1, vector<char> (2*N,' '));
    
    k=N;

    draw(k,1,N);
    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=2*N-1;j++){
            cout<<b[i][j]; 
        }
        cout<<"\n";
    }
    return 0;
}
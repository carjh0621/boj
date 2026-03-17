#include <iostream>


using namespace std;

char** arr;

void draw_pattern(int r,int c){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            arr[r+i][c+j]='*';
        }
    }
    arr[r+1][c+1]=' ';
}


void draw(int N, int r, int c){
    if(N==3){
        draw_pattern(r,c);    
        return;
    }
    draw(N/3,r,c);
    draw(N/3,r,c+N/3);
    draw(N/3,r,c+2*N/3);
    draw(N/3,r+N/3,c);
    draw(N/3,r+N/3,c+2*N/3);
    draw(N/3,r+2*N/3,c);
    draw(N/3,r+2*N/3,c+N/3);
    draw(N/3,r+2*N/3,c+2*N/3);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    arr = new char*[N];
    for(int i=0;i<N;i++){
        arr[i]=new char[N];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            arr[i][j]=' ';
        }
    }

    draw(N,0,0);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<arr[i][j];
        }
        cout<<"\n";
    }

    for(int i=0; i<N;i++){
        delete[] arr[i];
    }
    delete[] arr;

    return 0;

}

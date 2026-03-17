#include <iostream>

using namespace std;

long num = 1000000007;

int result[2][2] = {{1,0},{0,1}};
int base[2][2] = {{1,1},{1,0}};

//a=a*b == a=tmp*b
void op(int (&a)[2][2], int (&b)[2][2]){
    int ta[2][2],tb[2][2];
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            ta[i][j]=a[i][j];
            tb[i][j]=b[i][j];
        }
    }
    for(int r=0;r<2;r++){
        for(int c=0;c<2;c++){
            a[r][c]=0;
            for(int i=0; i<2;i++){
                a[r][c]=(a[r][c]+ 1LL * ta[r][i] * tb[i][c])%num;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unsigned long ans, t1,t2, n;

    cin>>n;

    if(n==0){
        cout<<0<<"\n";
        return 0;
    }
    if(n==1){
        cout<<1<<"\n";
        return 0;
    }
    while(n>0){
        if(n%2==1) op(result,base);
        op(base,base);
        n=n/2;
    }
    
    cout<<result[0][1]<<"\n";

    return 0;
}
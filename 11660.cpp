/*
N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 
합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.

예를 들어, N = 4이고, 표가 아래와 같이 채워져 있는 경우를 살펴보자.

1	2	3	4
2	3	4	5
3	4	5	6
4	5	6	7
여기서 (2, 2)부터 (3, 4)까지 합을 구하면 3+4+5+4+5+6 = 27이고, 
(4, 4)부터 (4, 4)까지 합을 구하면 7이다.

표에 채워져 있는 수와 합을 구하는 연산이 주어졌을 때, 이를 처리하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <vector>

using namespace std;

struct point{
    int r;
    int c;
};

int n,m;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n>>m;

    vector<vector<int>> v(n+1,vector<int> (n+1,0));
    point p1,p2;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tmp;
            cin>>tmp;
            v[i][j]=tmp+v[i-1][j]+v[i][j-1]-v[i-1][j-1];
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<"\n";
    }cout<<"\n";
    */
    for(int i=0; i<m;i++){
        cin>>p1.r>>p1.c>>p2.r>>p2.c;
        //cout<< v[p2.r][p2.c] <<" "<< v[p2.r][p1.c-1] <<" "<< v[p1.r-1][p2.c] <<" "<< v[p1.r-1][p1.c-1]<<"\n";
        cout<<v[p2.r][p2.c] - v[p2.r][p1.c-1] - v[p1.r-1][p2.c] + v[p1.r-1][p1.c-1]<<"\n";

    }

    



}

/*
정수 A를 B로 바꾸려고 한다. 가능한 연산은 다음과 같은 두 가지이다.

2를 곱한다.
1을 수의 가장 오른쪽에 추가한다. 
A를 B로 바꾸는데 필요한 연산의 최솟값을 구해보자.
*/

#include <iostream>

using namespace std;
unsigned long long int a,b;
int height=0;
int ans=-1;

void search(unsigned long long int cur){
    if(cur<b){
        height++;
        search(cur*2);
        height++;
        search(cur*10+1);
    }
    else if(cur==b){
        ans= height;
    }
    height--;
    return;

    
}

int main(){
    ios_base::sync_with_stdio;
    cin.tie(NULL);
    cout.tie(NULL);

    cin>> a>>b;
    search(a);
    if(ans==-1){
        cout<<ans<<"\n";
    }
    else{
        cout<<ans +1<<"\n";
    }

    return 0;
}
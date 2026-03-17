#include <iostream>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int arr[21];
    arr[0]=0;
    arr[1]=1;
    for(int i=2;i<=20;i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<arr[n];
    return 0;
}
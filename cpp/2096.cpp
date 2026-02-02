#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
using namespace std;

int n;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;

    //vector<vector<int>> v(n,vector<int> (3,0));
    //vector<vector<int>> mindp(n,vector<int> (3,0));
    //vector<vector<int>> maxdp(n,vector<int> (3,0));
    //dp->메모리 제한 4mb 초과. 슬라이딩 윈도우 사용해야 될듯 

    vector<int> v(3); 
    vector<int> mindp(3);
    vector<int> maxdp(3);

    
    cin>>v[0]>>v[1]>>v[2];
    
    mindp[0]=v[0];
    mindp[1]=v[1];
    mindp[2]=v[2];
    maxdp[0]=v[0];
    maxdp[1]=v[1];
    maxdp[2]=v[2];


    
    
    
    for(int i=1;i<n;i++){
        cin>>v[0]>>v[1]>>v[2];
        int min0,min1,min2;
        int max0,max1,max2;
        min0= min(mindp[0],mindp[1]);
        min1= min(min0,mindp[2]);
        min2= min(mindp[1],mindp[2]);
        max0= max(maxdp[0],maxdp[1]);
        max1= max(max0,maxdp[2]);
        max2= max(maxdp[1],maxdp[2]);

        mindp[0]=v[0]+min0;
        mindp[1]=v[1]+min1;
        mindp[2]=v[2]+min2;

        maxdp[0]=v[0]+max0;
        maxdp[1]=v[1]+max1;
        maxdp[2]=v[2]+max2;

    }

    int max=0,min=INT32_MAX;
    for(int i=0;i<3;i++){
        if(max<maxdp[i]) max=maxdp[i];
        if(min>mindp[i]) min=mindp[i];

    }
    cout<<max<<" "<<min<<"\n";
    
}
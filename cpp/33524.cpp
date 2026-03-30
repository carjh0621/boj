#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int n,m;
    std::cin>>n>>m;

    std::vector<int> A(n);
    std::vector<int> B(m);

    for(int i=0;i<n;i++) std::cin>>A[i];
    for(int i=0;i<m;i++) std::cin>>B[i];

    std::sort(A.begin(),A.end());

    for(int i=0;i<m;i++){
        B[i] = std::upper_bound(A.begin(), A.end(), B[i]) - A.begin();
    }

    
    std::vector<int> K;
    K.push_back(0);
    for(int i=1;i<1000;i++){
        K.push_back(3*i*(i-1)+1);
    }
    
    //std::vector<int> C;
    for(int i=0;i<m;i++){
        if(B[i]==0) {
            std::cout<<"0 ";
            continue;
        }
        int pos = std::lower_bound(K.begin(),K.end(),B[i])-K.begin();
        if(B[i]<K[pos]){
            std::cout<<pos-1<<" ";
        }
        else{
            std::cout<<pos<<" ";
        }
    }


    return 0;
}
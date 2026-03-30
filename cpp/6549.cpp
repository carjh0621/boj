#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

typedef long long int Long;

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    
    
    int n;

    std::cin>>n;
    while(n!=0){
        std::vector<Long> h(n);
        for(int i=0;i<n;i++){
            std::cin>>h[i];
        } 
        std::stack<int> stk;
        std::vector<Long> left(n),right(n);
        for(int i=0; i<n; i++){
            while(!stk.empty() && h[stk.top()]>=h[i]){
                stk.pop();
            }
            left[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }
        while (!stk.empty()) stk.pop();
        for(int i=n-1; i>=0; i--){
            while(!stk.empty() && h[stk.top()]>=h[i]){
                stk.pop();
            }
            right[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        Long ans=0;
        for(int i=0;i<n;i++){
            ans= std::max(ans,1LL*h[i]*(right[i] - left[i] -1));
        }
        std::cout<<ans<<'\n';
        std::cin>>n;
    }
}
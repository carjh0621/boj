#include <iostream>
#include <unordered_map>

unsigned long long N,P,Q;
std::unordered_map<unsigned long long , unsigned long long> m;

unsigned long long trace(unsigned long long n){
    if(n==1) return 2;
    if(n==0) return 1;
    unsigned long long tmp;
    if(!m.empty() && m.find(n)!=m.end()) {
        tmp = m.find(n)->second; 
        return tmp;
    }
    else{
        tmp = (unsigned long long)trace(n/P)+trace(n/Q);
        m.insert({n,tmp});
        return tmp;
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    
    std::cin>>N>>P>>Q;
    unsigned long long ans;
    ans=trace(N);

    std::cout<<ans;

    return 0;
}
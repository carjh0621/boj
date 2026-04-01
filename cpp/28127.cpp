#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

ll S(ll n, ll a, ll d){
    return n*(2*a + (n-1) * d) /2;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    
    int Q;
    std::cin>>Q;
    for(int t=0;t<Q;t++){
        ll a,d,x;
        std::cin>>a>>d>>x;
        
        ll low=1,high=1000001,mid;
        while(low<high){
            mid = (low + high)/2;
            if(S(mid, a, d) >= x){
                high = mid;
            }
            else low=mid+1;
        }

        ll floor = low;
        ll order = x - S(floor - 1, a, d);

        std::cout<<floor<<" "<<order<<"\n";
        
    }


    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

int n,k,x;
std::vector<int> v;
std::vector<ll> left;
std::vector<ll> right;

bool check(int mid){
    ll tmp=0;
    for(int i=1;i<=n-mid+1;i++){
        if(i+mid-1 != n){
            tmp = left[i-1] + right[n] - right[i+mid-1];
            if(tmp >= k){
                return true;
            }
        }
        else{
            if(left[i-1] >= k){
                return true;
            }
        }
    }
    return false;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::cin>>n>>k>>x;

    v.resize(n+1);
    left.resize(n+1, 0);
    right.resize(n+1, 0);

    for(int i=1;i<=n;i++){
        std::cin>>v[i];
    }

    for(int i=1;i<=n;i++){
        left[i] = left[i-1] + 1LL*v[i]*x;
        right[i] = right[i-1] + v[i];
    }

    int low=0, high=n, mid;
    while(low<high){
        mid=(low+high+1)/2;
        if(check(mid)) low=mid;
        else high=mid-1;
    }
    if(low == 0) std::cout<<-1;
    else std::cout << low;

    return 0;
}
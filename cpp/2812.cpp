#include <iostream>
#include <deque>
#include <string>



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    int N,K;

    std::cin>>N>>K;

    std::deque<int> deq;

    std::string s;
    std::cin>>s;

    for(int i=0;i<s.length();i++){
        int tmp = (int) s[i]-'0';
        while(!deq.empty() && K>0){
            if(deq.back() < tmp) {
                deq.pop_back();
                K--;
            }
            else{
                break;
            }
        }
        deq.push_back(tmp);
    }

    while(K>0){
        deq.pop_back();
        K--;
    }

    while(!deq.empty()){
        std::cout<<deq.front();
        deq.pop_front();
    }


}
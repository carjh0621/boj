#include <iostream>
#include <string>
#include <stack>



int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::string str;
    std::cin>>str;

    std::stack<int> s;
    //-1 = (  -2 = [
    for(int i=0; i<str.size(); i++){
        char c= str[i];
        if(c=='('){
            s.push(-1);
        }
        else if(c=='['){
            s.push(-2);
        }
        else if(c == ')' || c == ']'){
            int sum =0;

            while(!s.empty() && s.top()>0){
                sum+=s.top();
                s.pop();
            }

            if(s.empty()){
                std::cout<<0<<'\n';
                return 0;
            }

            if(c==')'){
                if(s.top() !=-1){
                    std::cout<<0<<'\n';
                    return 0;
                }
                s.pop();
                if(sum==0) s.push(2);
                else s.push(sum*2);
            }
            else{
                if(s.top() != -2){
                    std::cout<<0<<'\n';
                    return 0;
                }
                s.pop();
                if(sum==0) s.push(3);
                else s.push(sum*3);
            }
        }
    }

    int ans = 0;
    while(!s.empty()){
        if(s.top()<0){
            std::cout<<0<<'\n';
            return 0;
        }
        ans += s.top();
        s.pop();
    }
    std::cout<<ans<<'\n';
    return 0;

}
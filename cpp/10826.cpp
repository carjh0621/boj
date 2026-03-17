#include <iostream>
#include <vector>
using namespace std;



void str_add(vector<char>& ans, vector<char>& t1, vector<char>& t2){
    long b = t1.size();
    long c = t2.size();
    
    int plus=0;
    for(int i=0;i<b;i++){
        int tmp = plus + (int)(t1[i]-'0') +(int)( t2[i]-'0');
        plus=0;
        if(tmp>=10){
            tmp-=10;
            plus=1;
        }
        ans[i]=(char)tmp+'0';
    }
    for(int i=b;i<c;i++){
        int tmp=plus+t2[i]-'0';
        plus=0;
        if(tmp>=10){
            tmp-=10;
            plus=1;
        }
        ans[i]=(char)tmp + '0';
    }
    if(plus==1){
        if(ans.size()<=c){
            ans.push_back((char)plus + '0');
        }
        else{
            ans[c]+=plus+'0';
        }
        
    }

    t1.resize(t2.size());
    t2.resize(ans.size());
    for(int i=0;i<t2.size();i++){
        t1[i]=t2[i];
    }
    for(int i=0;i<ans.size();i++){
        t2[i]=ans[i];
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<char> ans,tmp1,tmp2;

    cin>>n;
    if(n==0) {
        cout<<0<<"\n";
        return 0;
    }
    if(n==1) {
        cout<<1<<"\n";
        return 0;
    }
    tmp1.push_back('0');
    tmp2.push_back('1');
    ans.resize(1);
    for(int i=2;i<=n;i++){
        str_add(ans,tmp1,tmp2);
    }
    for(int i=ans.size()-1;i>=0;i--){
        cout<<ans[i];
    }cout<<"\n";


    return 0;
}
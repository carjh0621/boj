#include <iostream>
#include <vector>
using namespace std;

int N;
int Ans=0;

int retabs(int n){
    if(n<0) return -n;
    return n;
}

void search(vector<int>& queens, int idx){
    bool isvalid;
    for(int col=0;col<N;col++){
        isvalid=true;
        for(int row =0;row<idx;row++){
            if(col == queens[row]){
                isvalid=false;
                break;
            }
            if(retabs(idx-row) == retabs(queens[row]-col)){
                isvalid=false;
                break;
            }
        }
        if(isvalid && idx<N-1){
            queens[idx]=col;
            search(queens, idx+1);
        }
        else if(isvalid && idx==N-1){
            queens[idx]=col;
            Ans++;
        }
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    vector<int> queens(N,0); //index:행, 값: 각 행에서 어느 열에 있는지 (0~N-1)
    search(queens,0);

    cout<<Ans<<"\n";
}
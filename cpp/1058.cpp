#include <iostream>
#include <vector>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;

    vector<vector<int>> arr1(n,vector<int> ());
    vector<vector<int>> arr2(n,vector<int>());

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char tmp;
            cin>>tmp;
            if(tmp=='Y' && j>i){
                arr1[i].push_back(j);
                arr1[j].push_back(i);
            }
        }
    }

    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int a=arr1[i].size();
            int b=arr1[j].size();
            int flag=1;
            for(int x=0;x<a;x++){
                for(int y=0;y<b;y++){
                    if(arr1[i][x]==j && arr1[j][y]==i){
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1){
                for(int x=0;x<a;x++){
                    for(int y=0;y<b;y++){
                        if(arr1[i][x]==arr1[j][y]){
                            arr2[i].push_back(j);
                            arr2[j].push_back(i);
                        }
                    }
                }
            }
        }
    }

    int max = 0;
    for(int i=0;i<n;i++){
        int tmp = arr1[i].size() +arr2[i].size();
        if(max<tmp) max=tmp;
    }
    cout<<max<<"\n";

}
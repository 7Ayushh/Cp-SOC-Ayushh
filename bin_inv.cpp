#include<iostream>
using namespace std;

// piche wala element bada hai

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t; i++){
        int m;
        cin>>m;
        int count=0;
        int arr[m];
        for(int j=0;j<m; j++){
            cin>>arr[j];
            for(int l=j;l>0;l--){
                if(arr[j]>arr[l]) count++;
            }
            cout<<count<<endl;
            count=0;
        }
    }
    return 0;
} 


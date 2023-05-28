#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>v(t,0);
    vector<int>v1(t,0);
    int arr[t][2];
    for(int i=0;i<t;i++){
        cin>>arr[i][0]>>arr[i][1];
    }
    for(int i=0;i<t;i++){
        for(int j=0;j<t;j++){ 
            if((i!=j) && (arr[i][0]<=arr[j][0]) && (arr[i][1]>=arr[j][1])) {
                v1[i]++;
                v[j]++;
            } 
        }  
        cout<<v1[i]<<" ";  
    }
    cout<<endl;
    for(int i=0;i<t;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;


    return 0;
}
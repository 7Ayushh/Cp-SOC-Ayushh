#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    long int arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }

    // do as many as possible 
    // highest number ke acc write bit sequence -- MSB jinki 1 -- or them , rest ko and -- starting from highest(oring), lowest(anding)

    // we want larger sum of sq -- but for any 2 no- sq of (a+b)^2 is same-- the more numbers are far from each other-- 
    //this operation pushes them even further ( or > a > b > and)
    // making product smaller .. eg. 4*4 vs 6*2 --  thus sq sum even larger


    long long int final;
    for(int i=0;i<t;i++){
        final += arr[i]*arr[i];
    }
    cout<<final<<endl;
    return 0;
}
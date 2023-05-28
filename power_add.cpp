#include<bits/stdc++.h>
using namespace std;

void func( int arr[][2] , int n){  // need to specify #columns 
    
    int maxtime = arr[0][1];
    for(int i=1; i<n; i++){  // start from left as evry number only looks at his left
        while(arr[i][0]>arr[i-1][0]){
            arr[i][0] += pow(2, arr[i][1]);
            arr[i][1] += 1;
        }
        cout<< arr[i][0] << " " << arr[i][0] <<endl;
        if(arr[i][1]>maxtime) maxtime=arr[i][1]; // maxima of all the #incr is the final answer.. only trouble was value changing that we dealt above
        //left se to bada hona hi chahiye to use ek saath karo, ya one by one doesnt matter
    }
    if( maxtime == 0 ) cout<< 0 << endl;
    else cout<< maxtime <<endl;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n; 
        cin>>n;
        int arr[n][2];  // make a type of map
        for(int k=0;k<n;k++){
            cin>>arr[i][0];
            arr[i][1]=0;
        }
        func(arr,n);
    }
    return 0;
}
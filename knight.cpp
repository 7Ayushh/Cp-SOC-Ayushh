#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=1;k<t;k++){
        //chess mei each posi diff -- coordinates, -- act like n*n chairs
        // (k*k)C2 - 2((k-2+1)*(k-3+1)*2)  -- phle 2 for vert hori, doosra for number of posi, k wala is for no of 2*3 slabs
        // doubt -- all answers should be double?? replace black and white -- seemingly we arent considering it
        cout<<((k*k)*(k*k-1)/2 - 2*((k-2+1)*(k-3+1)*2))<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

// (longest streak of "<" or ">") + 1 

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n;
        cin>>n;
        char str[n];
        for(int i=0; i<n; i++){
            cin>>str[i];
        }
        int count=1;  // not 0- its #elements
        int storage=1;
        for(int i=1;i<n; i++){ //not i=0
            if(str[i]==str[i-1]) count++;
            else { if(storage<count) storage = count;}
        }
        storage++;
        cout<< storage <<endl;
    }
    return 0;
}
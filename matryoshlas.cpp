#include<bits/stdc++.h>
// #include<algorithm>
// #include<vector>
using namespace std;

//sort the sequence, maxima of repetition is the answer

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        vector<int>v1;
        int n,inp,freq;
        cin>>n;
        for(int j=0; j<n; j++){
            cin>>inp;
            v1.push_back(inp);
        }
        sort(v1.begin(),v1.end());
        
        vector<int>v2;
        //v2,size()
        for(int j=0;j<v1.size();j++){
            freq=  count(v1.begin(),v1.end(),v1[j]);
            v2.push_back(freq);
        }
        int answer = *max_element(v2.begin(),v2.end());
        cout<<answer<<"\n";
    }
    return 0;
}
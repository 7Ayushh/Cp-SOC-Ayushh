#include<bits/stdc++.h>
using namespace std;

int maxSum( vector<int> vect, int n, int k)
{
    if (n < k) {
        cout << "Invalid";
        return -1;
    }
    int max_sum = 0;
    for (int i = 0; i < k; i++)
        max_sum += vect[i];
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += vect[i] - vect[i - k];
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main(){
    int t;
    cin>>t;
    for(int i=0; i<t; i++){
        int n,k,a;
        cin>>n>>k;
        vector<int>vec;
        for(int j=0; j<n;j++){
            cin>>a;
            vec.push_back(a);
        }
        cout<<maxSum(vec,n,k)<<endl;
    }
    return 0;
}

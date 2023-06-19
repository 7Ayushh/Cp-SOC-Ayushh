#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();

    // index and val of all maximas
    vector<pair<int,int>> maximas;
    for(int i=0;i<n;i++){ //check all elevations
        if( i==0 || (height[1]<height[0])){
            maximas.emplace_back(height[i],i);
        }
        if( i==(n-1) || (height[n-2]<height[n-1]) ){
            maximas.emplace_back(height[i],i);
        }

        if((height[i]>height[i-1]) && (height[i]>height[i+1])){
        maximas.emplace_back(height[i],i);
        }
    }

    //calculating qty using maximas
    int qty=0;
    for(int i=0; i<maximas.size(); i++){  // 1 segment
        int l= maximas[i+1].second - maximas[i].second;
        int minima= height[maximas[i].second];
        int comparator = min(maximas[i].first, maximas[i+1].first);
        for(int j=1; j<l; j++){
            //min for every segment calc after find maximas else useless cases
            if(minima > height[maximas[i].second +j]) minima = height[maximas[i].second +j];
        }
        for(int j=1;j<l;j++){
           if(comparator > height[maximas[i].second +j]) qty += (comparator - height[maximas[i].second +j]);
        }
    }
    return qty;

    }
};
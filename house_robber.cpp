//dp ques, leetcode

#include<bits/stdc++.h>
using namespace std;


// without dp - time limit exceed
class Solution {
public:
    int help(int i, vector<int>&nums){ //func hai
        if(i>=nums.size()) return 0;

        int opt1 = nums[i]+help(i+2,nums);
        int opt2 = help(i+1,nums); //ab piche wale ko bhul jao- consideration mei nahi aayenge

        return max(opt1,opt2);
    }
    int rob(vector<int>& nums) {
        return help(0,nums);
    }
};

//with dp, to avoid repitition, phle go to the end using a path, and then store the value for future use if required
// top down
class Solution2 {
public:
    int help(int i, vector<int>&nums, vector<int>&dp){ //func hai
        if(i>=nums.size()) return 0;

        if(dp[i] != -1) return dp[i];  // not -1 means already been calculated

        int opt1 = nums[i]+help(i+2,nums,dp);
        int opt2 = help(i+1,nums,dp); //ab piche wale ko bhul jao- consideration mei nahi aayenge

        return dp[i] = max(opt1,opt2); // return dp whose val is
    }
    int rob(vector<int>& nums) {
        //dp is just a storage vector 
        int n=nums.size();
        vector<int> dp(n,-1);  // size aur bhi rakh sakte
        int ans = help(0,nums,dp);
        for(auto a:dp) cout<< a <<" ";
        return ans;
    }
};

//bottom up
class Solution3 {
public:
    int rob(vector<int>&nums){
        int n=nums.size();
        vector<int> dp(n+2,-1);  // n+2 ki array coz we 2 need 2 buffer values to start from the last
        dp[n+1]= 0; // start of backwardness
        dp[n]=0;
        for(int i=n-1; i>=0; i--){
            int opt1 = dp[i+2]+ nums[i];
            int opt2 = dp[i+1];
            dp[i]= max(opt1,opt2);
        }
        return dp[0];
    }
};

//since we dont need the full array -- 3 consecutive values as c,a,b
class solution4{
public:
    int rob(vector<int>&nums){
        int n=nums.size();
        int a,b,c;
        a = 0; // start of backwardness
        b = 0;
        for(int i=n-1; i>=0; i--){
            int opt1 = b + nums[i];
            int opt2 = a;
            c = max(opt1,opt2);
        }
        return c;
    }
};
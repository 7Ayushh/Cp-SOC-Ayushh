#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    void localmaxima(vector<int> prices, vector<int> &maximas){
    //first should be a minimum
        for(int i=0; i<prices.size(); i++){
            if((prices[i-1]< prices[i]) && (prices[i+1]<prices[i])) maximas.push_back(prices[i]);
        }
    }
    void localminima(vector<int> prices, vector<int> &minimas){
        for(int i=0; i<prices.size(); i++){
            if((prices[i-1]>prices[i]) && (prices[i+1]>prices[i])) minimas.push_back(prices[i]);
        }    
    }
    //basic is phle min then max and you want 2 only -- doesnt matter which you pick up
    // brute force with conditions
    // problem facing -- use a vector of pair or vector of int for minimas -- though we input that minima always come first
    vector<int> getprofit (vector<int> minimas,vector<int> maximas){
        vector<int>profits;
        for(int i=0;i<minimas.size();i++){
            // phle minima
            for(int j=i;j<maximas.size();j++){
                
            }
        }
        for(int i=0;i<minimas.size();i++){ // use some i0 or j0
            for(int j=0;j<maximas.size();j++){
                // phle minima
            }
        }
        return profits;
    }

    int maxProfit(vector<int>& prices) {
        
        // phle buy then sell and not buy buy
        // 2 transactions
        // time complexity

        // draw a long wave aur uska varying amplitude -- phle minima then maxima 
        // jitne rises -- they are the point of concern

        vector<int>maximas;
        vector<int>minimas;
        vector<int>profits;
        
        //main problem is end points
        // minimas check before you call func for the function index and vice versa for maximas
        if(prices[0]<prices[1]) minimas.push_back(prices[0]);
        localminima(prices,minimas);
        localmaxima(prices,maximas);
        if(prices[prices.size()-1]>prices[prices.size()-2]) minimas.push_back(prices[prices.size()-1]);


        // max profit
        profits = getprofit(minimas, maximas);
        //if(maximas[0]<mimimas[0]) minimas.erase(minimas.begin()+0);
        sort(profits.begin(),profits.end());
        if(profits.size()>1) return (profits[profits.size()-1] + profits[profits.size()-2]) ;
        else return profits[0];
    }
};
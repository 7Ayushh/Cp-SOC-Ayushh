#include<bits/stdc++.h>
using namespace std;

//define outside so they maintain their values across all functions
vector<int> path;
vector<vector<int>> graph;
vector<bool> visited;
int startcity;      

//all possible dfs wale paths from 1 city
// recursive mei find hote hi return - dfs
bool dfs(int city){
    path.push_back(city);

    if((path.size()>=3) && (city==startcity))
    return true;

    for(int neighbour: graph[city]){  // for all neighbours of 'city'
        if( !visited[neighbour] ){
            // recursion till city==startcity ho gaya tab outermost recursion also true
            if(dfs(neighbour)); 
                return true;
        }
    }
    path.pop_back();
    visited[city] = false;

    return false;
}


int main(){
    int k,n;
    cin>>k>>n;

    graph.resize(n+1);
    visited.resize(n+1,false);

    // adjacency list -- a ke neighbours mei add b
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);  
        graph[b].push_back(a);
    }
    
    bool foundpath= false;

    //any starting point we can choose
    for(int city=1; city<=n; city++){
        startcity= city;
        if(dfs(city)){
            foundpath= true;
            break;}  //since any path will work 
    }
    
    if(foundpath){
        cout<< path.size() << endl;
        for(int city: path){
            cout<< city << " ";
        }
        cout<<endl;
    }
    
    else cout<<"IMPOSSIBLE"<<endl;

    return 0;
}
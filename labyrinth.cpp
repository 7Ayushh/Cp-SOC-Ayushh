#include<bits/stdc++.h>
using namespace std;

vector<char> matrix;

vector<int> path;  // datatype of path as int as we consider 2nd row 1st col as 6, 1st row 3rd col as 3
vector<vector<int>> graph; // array of pairs
vector<bool> visited;
int startcity,endcity;     


// dead end when "A" surrounded by wall or 4 mei se 3 neighbour of "." are walls ie no "." or "B" as neighbour
bool dfs(int x){
    path.push_back(x);

    if(x==endcity) 
    return true;

    for(int neighbour : graph[x]){   // entire (x+1)th row of a graph
        if( !visited[neighbour] ){
            if(dfs(neighbour)); 
                return true;
        }
    }
    path.pop_back();
    visited[x] = false;  // visited ka kuchh karna padega // coord se ache 1,2..6..25

    return false;
}



// name each spot from 1 to m*n
int main(){
    int x,y;
    cin>>y>>x;

    int count=0;
    vector<int> dotposi;
    //input matrix
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){  // start with 0
            char a;
            cin>>a;
            if(a=='A'){ //'A' (char) is right not "A" (string)
                startcity = x*i+j ;
            }
            if(a=='B'){
                endcity= x*i+j;
            }
            if(a=='.' || a=='A' || a=='B'){ //use in graph 
                dotposi[count]= x*i+j;
                count++;
            }
            // matrix has all values, dotposi has limited values and that too positions
            // matrix = {{1, 2, 3}, {4, 5, 6}}; where 1,2,3 are in first(0th) row
            matrix[x*i+j]= a;
        }
    }

    graph.resize(count); // counts and A,B
    visited.resize(count,false);

    
    // city question mei each city unique and its own set of neighbours-- yaha its same for a specific coordinate
    //graph of dots
    for(int i=0;i<count;i++){
        // also write neighbour of A,B
        // every dot ke around 4 directions mei search for only dots
        if(matrix[dotposi[i]+1] =='.') graph[i].push_back(matrix[i+1]);
        if(i>=1 && (matrix[dotposi[i]-1] =='.')) graph[i].push_back(matrix[i-1]);  // now graph own index or matrix index?
        if(matrix[dotposi[i]+x] =='.') graph[i].push_back(matrix[i+x]);
        if(i>=x && (matrix[dotposi[i]-x] =='.')) graph[i].push_back(matrix[i-x]);
    }

    bool foundpath =  false;
    if(dfs(startcity)) foundpath = true; 

    if(foundpath){
        cout<<"YES"<<endl<<path.size();
        // for( auto elem : path)
        for(int i=0; i<path.size(); i++){
            if((path[i+1]-path[i]) == x) cout<<"D";
            else if((path[i+1]-path[i]) == 1) cout<<"R"; 
            else if((path[i+1]-path[i]) == -1) cout<<"L"; 
            else if((path[i+1]-path[i]) == -x) cout<<"U";
            else cout<<"error";
        }
        cout<<endl;
    }
    else cout<< "NO"<< endl;
    
    return 0;
}
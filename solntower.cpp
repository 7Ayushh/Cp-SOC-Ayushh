#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)  // func ke liye from, to, using rods              
{    
	if (n == 0) {
		return;}
    //Shift ‘N-1’ disks from ‘A’ to ‘B’, using C.
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);   
    //Shift last disk from ‘A’ to ‘C’.
	cout << "Move disk " << n << " from rod " << from_rod<< " to rod " << to_rod << endl;
    //Shift ‘N-1’ disks from ‘B’ to ‘C’, using A.
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
	int N;
    cin>>N;
    //shift A to C using B
	towerOfHanoi(N, 'A', 'C', 'B'); 
	return 0;
}


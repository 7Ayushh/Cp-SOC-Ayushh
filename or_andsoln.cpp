#include <iostream>
#include <vector>
#include <algorithm> // sort

using namespace std;

// Function to calculate the largest sum of squares
long long int largestSumOfSquares(long int n, vector<long long int>& a) {
    
    // Sort the array in descending order
    sort(a.rbegin(), a.rend());

    // Variable to store the largest sum of squares
    long long int max_sum_squares = 0;

    // Iterate over each element in the array
    for (int i = 0; i < n; i++) {
        // Check if the current element can be paired with any previous element
        for (int j = i + 1; j < n; j++) {
            // Calculate the bitwise AND and OR of the two elements
            int ai = a[i] & a[j];
            int aj = a[i] | a[j];

            // Update the current element and the paired element
            a[i] = ai;
            a[j] = aj;
        }
        // Add the square of the current element to the sum
        max_sum_squares += a[i] * a[i];
    }
    return max_sum_squares;
}

int main() {
    long int n;
    cin >> n;

    vector<long long int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long int result = largestSumOfSquares(n, a);
    cout << result << endl;

    return 0;
}

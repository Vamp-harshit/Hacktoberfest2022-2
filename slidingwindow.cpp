//Sliding Window algorithm
// step1: Add the first K components together and save the result in the currentSum variable. Because this is the first sum, it is also the current maximum; thus, save it in the variable maximumSum.
// step2: As the window size is K, we move the window one place to the right and compute the sum of the items in the window.
// step3: Update the maximum if the currentSum is greater than the maximumSum, and repeat step 2.




//program
#include 
using namespace std;

// Returns maximum sum in a subarray of size k.
int maxSum(int arr[], int n, int k) {
    // n must be greater
    if (n < k) {
        cout << "Invalid";
        return -1;
    }

    //sum of first window of size k
    int window_sum = 0;
    for (int i = 0; i < k; i++)
        window_sum += arr[i];

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int max_sum = window_sum;
    for (int i = k; i < n; i++) {
        window_sum += (arr[i] - arr[i - k]);
        max_sum = max(max_sum, window_sum);
    }
    return max_sum;
}

int main(){
    int n = 5 , k = 3;;
    int arr[] = { 16,12,9,19,11,8};
    cout << maxSum(arr, n, k);
    return 0;
}

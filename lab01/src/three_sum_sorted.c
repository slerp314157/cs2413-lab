#include <stdio.h>

// stapling together previous solutions
// this is O(N^2)
int three_sum_zero_sorted_one(const int* nums, int n,
    int* out_i, int* out_j, int* out_k) {
    if (!nums || !out_i || !out_j || !out_k || n < 3)
        return 0;

    // Fix i at the left. 
    // subtract two from the length so there is space for a second number [n-1,n]
    int length = n - 1;
    for (int I = 0; I < length - 1; I++)
    {
        int J = I + 1;
        int K = length;
        int sum = 0;
        // treat this as a sorted two sum with an i constant. 
        while (J < K)
        {
            sum = nums[I] + nums[J] + nums[K];

            if (sum == 0)
            {
                *out_i = I;
                *out_j = J;
                *out_k = K;
                return 1;
            }
            // if its too small
            else if (sum < 0) {
                J++;
            }
            // if its too large 
            else
            {
                K--;
            }
        }
    }

    return 0;
}
// think about the time complexity and space complexity of your solution




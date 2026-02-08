#include <stdio.h>

/// in the case of {5}, that is just one number. Thus this set cannot have a two sum.  
int two_sum_sorted(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || !out_i || !out_j || n < 2)
    {
        return 0;
    }

    // TODO: implement Two Sum.
    // Requirements:
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0


    // TIME COMPLEXITY: O(N)

    int length = n;

    int i = 0;
    int j = length - 1;


    const int* val_ptr = nums;
    const int* sub_ptr = val_ptr + 1;

    // Calculate the address one past the last element
    const int* end_ptr = nums + length;
    // Loop over the array as in 1,2,3,4,5
    while (*(nums + i) + *(nums + j) != target)
    {
        // if its too small
        if (*(nums + i) + *(nums + j) < target)
        {
            i++;
        }

        // if its too large 
        if (*(nums + i) + *(nums + j) > target)
        {
            j--;
        }

        // hit a dead end. 
        if (i == j)
            break;

        if (*(nums + i) + *(nums + j) == target)
        {
            break;
        }

    }

    // handle the dead end
    if (i == j)
    {
        if (*(nums + i) != target)
            return 0;
    }
    // or else this is not a special case. 
    else
    {
        *out_i = i;
        *out_j = j;

        return 1;
    }
    return 0;
}
// think about the time complexity and space complexity of your solution




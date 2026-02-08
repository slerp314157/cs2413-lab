#include <stdio.h>



/// <summary>
/// [1,2,3,4,5]
/// first, loop for every element in the array
/// for each element i, then loop again over the array. 1,1 -> 1,2 -> 1,3
/// if 1 < other num,
/// check if they add up to. if so, then you update the outs and return. 
/// This is O(N^2) * 2
/// </summary>
int two_sum(const int* nums, int num_elements, int target_num, int* out_i, int* out_j) {
    int length = num_elements;

    const int* val_ptr = nums;
    const int* sub_ptr = val_ptr + 1;

    // Calculate the address one past the last element
    const int* end_ptr = nums + length;
    // Loop over the array as 1,2,3,4,5
    for (const int* val_ptr = nums; val_ptr < end_ptr; val_ptr++)
    {
        for (const int* sub_ptr = val_ptr + 1; sub_ptr < end_ptr; sub_ptr++)
        {
            if (*val_ptr + *sub_ptr == target_num)
            {
                *out_i = val_ptr - nums;
                *out_j = sub_ptr - nums;
                return 1;
            }
        }
    }
    return 0;
}

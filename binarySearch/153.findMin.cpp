#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right)
        {
            if (nums[left] < nums[right]) return nums[left];    // 顺序数组
            int mid = left + ((right - left) >> 1);
            if (nums[left] <= nums[mid]) left = mid + 1; 
            else right = mid;
        }

        return nums[left];
    }
};
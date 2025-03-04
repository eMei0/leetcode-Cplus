#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size() - 1);
    }

    int find(vector<int>& nums, int target, int startPos, int endPos) {
        if (startPos > endPos) return startPos;
        
        int midPos = (startPos + endPos) >> 1;
        if (nums[midPos] == target) return midPos;
        if (nums[midPos] > target) return find(nums, target, startPos, midPos - 1);
        else return find(nums, target, midPos + 1, endPos);
    }
};
#include<iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> cache;

        for (int i = 0; i < nums.size(); i++) {
            auto it = cache.find(target -nums[i]);
            if (it != cache.end()) {
                return {it->second, i};
            }

            cache[nums[i]] = i;
        }
        return {};
    }
};
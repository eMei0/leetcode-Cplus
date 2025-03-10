#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> counts(nums.size(), 0);
        vector<pair<int, int>> numsWithIndex(nums.size());
        
        // 初始化带索引的数组
        for (int i = 0; i < nums.size(); ++i) {
            numsWithIndex[i] = {nums[i], i};
        }
        
        mergeSort(numsWithIndex, 0, nums.size() - 1, counts);
        return counts;
    }

private:
    void mergeSort(vector<pair<int, int>>& nums, int left, int right, vector<int>& counts) {
        if (left >= right) return;
        
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid, counts);
        mergeSort(nums, mid + 1, right, counts);
        merge(nums, left, mid, right, counts);
    }

    void merge(vector<pair<int, int>>& nums, int left, int mid, int right, vector<int>& counts) {
        vector<pair<int, int>> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        int rightCount = 0;
        
        while (i <= mid && j <= right) {
            if (nums[i].first > nums[j].first) {
                rightCount++;
                temp[k++] = nums[j++];
            } else {
                counts[nums[i].second] += rightCount;
                temp[k++] = nums[i++];
            }
        }
        
        // 优化：合并剩余元素
        if (i <= mid) {
            for (; i <= mid; ++i) {
                counts[nums[i].second] += rightCount;
                temp[k++] = nums[i];
            }
        } else {
            for (; j <= right; ++j) {
                temp[k++] = nums[j];
            }
        }
        
        // 优化：使用memcpy代替循环
        memcpy(&nums[left], &temp[0], temp.size() * sizeof(pair<int, int>));
    }
};

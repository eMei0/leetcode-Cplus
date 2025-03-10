#include<iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if (m > n) return findMedianSortedArrays(nums2, nums1);  // 确保nums1是较短的数组
        
        int left = 0, right = m;
        int total = m + n;
        int half = (total + 1) / 2;  // 中位数的位置
        
        while (left <= right) {
            int i = left + (right - left) / 2;  // nums1的分割点
            int j = half - i;  // nums2的分割点
            
            int nums1Left = (i > 0) ? nums1[i - 1] : INT_MIN;
            int nums1Right = (i < m) ? nums1[i] : INT_MAX;
            int nums2Left = (j > 0) ? nums2[j - 1] : INT_MIN;
            int nums2Right = (j < n) ? nums2[j] : INT_MAX;
            
            if (nums1Left <= nums2Right && nums2Left <= nums1Right) {
                if (total % 2) return max(nums1Left, nums2Left);  // 奇数情况
                return (max(nums1Left, nums2Left) + min(nums1Right, nums2Right)) / 2.0;  // 偶数情况
            } else if (nums1Left > nums2Right) {
                right = i - 1;
            } else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};
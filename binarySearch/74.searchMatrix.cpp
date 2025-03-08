#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int left = 0, right = m * n - 1; left <= right;) {
            int mid = left + ((right - left) >> 1);
            int val = matrix[mid / n][mid % n];
            if (val == target) return true;
            val < target ? left = mid + 1 : right = mid - 1;
        }
        return false;
    }
};
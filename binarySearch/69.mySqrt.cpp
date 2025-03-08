#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid = 0;
        int division = 0;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            // 使用除法避免溢出
            division = x / mid;
            if (mid == division) return mid;
            if (mid < division) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};

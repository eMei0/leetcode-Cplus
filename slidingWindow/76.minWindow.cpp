#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        // 使用 vector 代替 unordered_map
        vector<int> tm(128, 0);  // ASCII 字符范围是 0-127
        for (auto c : t) {
            tm[c]++;
        }

        // 初始化滑动窗口
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int minStart = 0;
        int count = t.size();
        
        while (right < s.size()) {
            // 扩展右边界
            char c = s[right];
            if (tm[c] > 0) count--;  // 直接访问 vector
            tm[c]--;
            right++;

            // 当所有字符都匹配时，尝试收缩左边界
            while (count == 0) {
                // 更新最小窗口
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                // 收缩左边界
                char leftChar = s[left];
                if (tm[leftChar] == 0) count++;  // 直接访问 vector
                tm[leftChar]++;
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};
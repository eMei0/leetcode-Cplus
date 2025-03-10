#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
        int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        
        vector<int> charIndex(128, -1);  // ASCII字符集
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.length(); ++right) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {

    string s = "abcabcbb";
    Solution solution;

    cout << solution.lengthOfLongestSubstring(s) << endl;

    return 0;
}
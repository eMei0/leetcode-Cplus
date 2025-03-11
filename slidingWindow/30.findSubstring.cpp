#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string, int> wm;
        vector<int> ret;

        for (auto &word : words) {
            wm[word]++;
        }

        for (int i = 0; i < len; i++) {
            int left = i, count = 0;
            unordered_map<string, int> tmp;

            for (int j = i; j <= n - len; j += len) {
                string word = s.substr(j, len);

                if (wm.count(word)) {
                    tmp[word]++;
                    count++;

                    while (tmp[word] > wm[word]) {
                        string leftWord = s.substr(left, len);
                        tmp[leftWord]--;
                        count--;
                        left += len;
                    }

                    if (count == m) {
                        ret.push_back(left);
                        string leftWord = s.substr(left, len);
                        tmp[leftWord]--;
                        count--;
                        left += len;
                    }
                } else {
                    tmp.clear();
                    count = 0;
                    left = j + len;
                }
            }
        }

        return ret;
    }
};

int main() {
    string s = "a";
    vector<string> words;
    words.push_back("a");
    Solution solution;
    auto result = solution.findSubstring(s, words);
    cout << "[";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    return 0;
}

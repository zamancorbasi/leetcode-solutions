#include <iostream>
#include <vector>
using namespace std;



class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        string sub = "";
        sub[0] = s[0];
        for (int i = 0; i < s.length(); i++) {
            for (int j = 1; j < s.length(); j++) {
                sub += s[j];
                if (s[i] == s[j]) {
                    break;
                }
            }
            break;
        }

        cout << sub;

        return sub.length();
    }
};

int main() {
    Solution sol;

    vector<string> testCases = {
        "abcabcbb",
        "bbbbb",
        "pwwkew",
        "",
        "au",
        "dvdf"
    };

    for (auto& tc : testCases) {
        int result = sol.lengthOfLongestSubstring(tc);
        cout << "Input: \"" << tc << "\" -> Output: " << result << endl;
    }

    return 0;


    return 0;
}
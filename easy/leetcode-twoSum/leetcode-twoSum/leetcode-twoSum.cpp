#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<int> results;

        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[i] + nums[j] == target) {
                    results.push_back(i);
                    results.push_back(j);
                    return results;
                }
            }
        }

        return {}; // boş vektör, çözüm yoksa
    }
};

int main() {
    Solution sol;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> result = sol.twoSum(nums, target);

    if (result.empty()) {
        cout << "Çözüm yok" << endl;
    }
    else {
        cout << "Indexler: ";
        for (int idx : result) {
            cout << idx << " ";
        }
        cout << endl;
    }

    return 0;
}

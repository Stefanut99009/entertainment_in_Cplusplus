#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ceva;
        if (nums.size() < 2)
            return ceva;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) { 
                if (nums[i] + nums[j] == target) {
                    ceva.push_back(i);
                    ceva.push_back(j);
                    return ceva;
                }
            }
        }
        return ceva;
    }
};

int main() {
    Solution solution;
    vector<int> ceva = {30, 9, 39, 40, 21};
    vector<int> result = solution.twoSum(ceva, 51);

    if (!result.empty()) {
        cout << "Indexes of the two numbers are: ";
        for (int index : result) {
            cout << index << " ";
        }
        cout << endl;
    } else {
        cout << "No two numbers sum up to the target." << endl;
    }

    return 0;
}


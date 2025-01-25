#include <iostream>
#include <set>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars; 
        int left = 0; 
        int maxLength = 0; 
        for (int right = 0; right < s.length(); ++right) {
            while (chars.find(s[right]) != chars.end()) {
                chars.erase(s[left]); 
                left++; 
            }
            chars.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};
int main(){
    string ceva = "jhavsgakjsb";
    Solution sol;
    int result = sol.lengthOfLongestSubstring(ceva);
    cout << result<<endl;
    return 0;
}

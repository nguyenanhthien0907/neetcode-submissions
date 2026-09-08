class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int res = 0;
        unordered_set<char> charSet;
        for (int right = 0; right < s.size(); right++){
            while (charSet.count(s[right]) > 0){
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(s[right]);
            res = max(res, right - left + 1);
        }
        return res;
    }
};

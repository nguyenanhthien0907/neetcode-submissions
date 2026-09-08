class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int x : numSet){
            if (!numSet.count(x-1)){
                int current = x;
                int len = 1;
                while (numSet.count(current+1)){
                    current++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};

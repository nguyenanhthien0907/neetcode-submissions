class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;
        for (int x : numSet){
            if (!numSet.count(x-1)){ // start every number
                int curr = x; 
                int len = 1;
                while(numSet.count(curr + 1)){
                    curr++;
                    len++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};

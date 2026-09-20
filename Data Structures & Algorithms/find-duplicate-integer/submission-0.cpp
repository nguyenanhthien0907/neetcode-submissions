class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        unordered_set<int> numSet;
        for (int x : nums){
            if (numSet.count(x) == 1) return x;
            numSet.insert(x);
        }
        return -1;
    }
};

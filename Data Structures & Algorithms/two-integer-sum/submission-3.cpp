class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // for (int i = 0; i < nums.size(); i++){
        //     for (int j = i + 1; i < nums.size(); j++){
        //         if (nums[i] + nums[j] == target){
        //             return {i,j};
        //         }
        //     }
        // }
        // return {};
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++){
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++){
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i){
                return {i, indices[diff]};
            }
        }
        return {};
    }
};

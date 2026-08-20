class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // sort array from low to high
        size_t n = nums.size();
        for (size_t i = 0; i < n - 2; i++){
            if (nums[i] > 0){
                break; // 3 numbers is positive -> the sum cannot equal 0
            }
            if (i >0 && nums[i] == nums[i-1]){
                continue;
            }
            // 2 pointers
            int left = i + 1; 
            int right = n - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0){
                    result.push_back({nums[i], nums[left], nums[right]});
                                        // skip duplicate left value
                    while (left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    // skip duplicate right value
                    while (left < right && nums[right] == nums[right - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }else if(sum < 0){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return result;
    }
};

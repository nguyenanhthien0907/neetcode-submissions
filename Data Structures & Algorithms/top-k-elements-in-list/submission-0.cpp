class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using unordered_map
        unordered_map<int, int> count;
        for (const auto& num : nums){
            count[num]++; 
        }
        // convert in pair
        vector<pair<int,int>> arr;
        for (auto& x : count){
            arr.push_back({x.second, x.first});
        }
        // sort pair
        sort(arr.rbegin(), arr.rend());
        // push back the result in array
        vector<int> res;
        for (int i = 0; i < k; i++){
            res.push_back(arr[i].second);
        } 
        return res;
    }
};

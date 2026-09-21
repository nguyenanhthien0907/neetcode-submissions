class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // using hash map to solve
        unordered_map<int, int> hash_map; // key: value of numbers, value: index + 1
        for (int i = 0; i < numbers.size(); i++){
            int diff = target - numbers[i];
            if (hash_map.count(diff)) return {hash_map[diff], i+1};
            hash_map[numbers[i]] = i + 1;
        }
        return {};
    }
};

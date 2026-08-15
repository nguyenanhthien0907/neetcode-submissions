class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()){ // check length of 2 strings
            return 0;
        }
        int count[26] = {}; // create a array to contain count table
        for (char c : s){ 
            count[c -'a']++;
        }
        for (char c : t){
            count[c - 'a']--;
        }
        for (int x : count){
            if (x != 0){
                return 0;
            }
        }
        return 1;
    }
};

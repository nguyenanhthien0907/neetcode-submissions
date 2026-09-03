class Solution {
public:
    bool isAnagram(string s, string t) {
        // if (s.size() != t.size()) return 0;
        // sort(s.begin(), s.end());
        // sort(t.begin(), t.end());
        // return s==t;

        if (s.size() != t.size()) return 0;
        int count[26] = {0};
        for (char a : s) count[a -'a']++;
        for (char b : t) count[b -'a']--;
        for (int x : count){
            if (x != 0) return 0;
        }
        return 1;
    }
};

class Solution {
public:

    string encode(vector<string>& strs) {
        //5#hello5#world
        string res = "";
        for (string s : strs){
            res += to_string(s.size()) + '#' + s;
        }
        return res;
    }

    vector<string> decode(string s) { // ex:5#hello5#world
        vector<string> res;
        int i = 0;
        while (i < s.size()){
            int j = i;
            while (s[j] != '#'){
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j + 1, len);
            res.push_back(word);
            i = j + 1 + len;
        }
        return res;
    }
};

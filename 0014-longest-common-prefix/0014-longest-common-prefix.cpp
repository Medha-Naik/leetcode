class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        string res = strs[0];

        for (int k = 1; k < strs.size(); k++) {
            int i = 0;
            int n = min(strs[k].size(), res.size());

            while (i < n && strs[k][i] == res[i]) i++;

            res = res.substr(0, i);
            if (res.empty()) break;
        }
        return res;
    }
};
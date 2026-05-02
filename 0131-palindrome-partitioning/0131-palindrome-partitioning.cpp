class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(string &s, int ind, vector<string> &curr, vector<vector<string>> &res) {
        if (ind == s.size()) {
            res.push_back(curr);
            return;
        }

        for (int i = ind; i < s.size(); i++) {
            if (isPalindrome(s, ind, i)) {
                curr.push_back(s.substr(ind, i - ind + 1));
                backtrack(s, i + 1, curr, res);
                curr.pop_back(); 
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};
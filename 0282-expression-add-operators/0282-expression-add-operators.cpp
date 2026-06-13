class Solution {
public:
    void solve(string num, long long target, int ind, long long curr, long long prev,vector<string>&res, string path)
    {
        if(ind==num.size())
        {
            if(curr == target)
            {
                res.push_back(path);
            }
            return;
        }

        for(int i=ind; i<num.size(); i++)
        {
            if(i!=ind && num[ind]=='0')break;
            string part = num.substr(ind, i-ind+1);
            long long n =stoll(part);

            if (ind == 0) {
            solve(num, target, i+1, n, n, res, part);
        } else {
            solve(num, target, i+1, curr + n,  n, res, path + "+" + part);
            solve(num, target, i+1, curr - n, -n, res, path + "-" + part);
            solve(num, target, i+1,  curr - prev + prev*n, prev*n, res, path + "*" + part);
        }
        }
    }
    vector<string> addOperators(string num, int target) {
    
        vector<string>res;
        string path ="";
        solve(num, target, 0, 0, 0, res, path);
        return res;
    }
};
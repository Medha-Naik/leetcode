class Solution {
public:
    void generate(int n,string curr,vector<string>&res,int open,int close)
    {
        if(close==n)
        {
            res.push_back(curr);
            return;
        }
        if(open<n)generate(n,curr+'(',res,open+1,close);

        if(close<open)
        {
            generate(n,curr+')',res,open,close+1);
        }
        
    }
    vector<string> generateParenthesis(int n) {
        string curr;
        vector<string>res;
        generate(n,curr,res,0,0);
        return res;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int cur=0;
        int maxpar=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                cur++;
                maxpar=max(cur,maxpar);
            }
            else if(s[i]==')')
            {
                cur--;
            }
        }
        return maxpar;
    }
};
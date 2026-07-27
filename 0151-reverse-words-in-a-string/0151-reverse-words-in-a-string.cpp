class Solution {
public:
    string reverseWords(string s) {
        
        int n=s.size()-1;
        string ans="";
        while(n>=0)
        {
        while(n>=0 && s[n]==' ')
        {
            n--;
        }

        if(n<0)break;
        int end = n+1;

        while(n>=0&& s[n]!=' ')
        {
            n--;
        }
        int start = n+1;
        
        if(!ans.empty())
        {
            ans+= " ";
        }
        for(int i=start; i<end; i++)
        {
            ans+= s[i];
        }
        }
        return ans;
    }

};
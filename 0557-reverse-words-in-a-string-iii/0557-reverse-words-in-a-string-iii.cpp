class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string res="";
        int i=0;
        while(i<n)
        {
            int start = i;
            while(i<n && s[i]!=' ') i++;
            int end =i-1;
            
            for(int i=end; i>=start; i--)
            {
                res+= s[i];
            }
            if(end!=n-1)
            {
                res += " ";
            }
            i++;
        }
        return res;
    }
};
class Solution {
public:
    int maxDepth(string s) {
        int curr=0;
        int maxi= INT_MIN;
        for(char ch: s)
        {
            if(ch=='('||ch=='{'||ch=='[')curr++;
            else if(ch==')'||ch=='}'|| ch== ']') curr--;
            maxi= max(maxi,curr);
        }
        return maxi;
    }
};
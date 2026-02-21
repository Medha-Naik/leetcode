class Solution {
public:
    string countAndSay(int n) {
        string res="1";
        for(int i=1;i<n;i++)
        {
            string curr="";
            int cnt=1;
            int j=1;
            while(j<res.size())
            {
                if(res[j-1]==res[j])cnt++;
                else{
                curr+=to_string(cnt)+res[j-1];
                cnt=1;
                }
                j++;
            }
            curr+=to_string(cnt)+res[j-1];
            res=curr;
        }
    return res;
    }
};
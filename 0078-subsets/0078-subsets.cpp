class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int subs=1<<nums.size();
        vector<vector<int>>res;
        for(int n=0;n<subs;n++)
        {
            vector<int>temp;
            for(int i=0;i<nums.size();i++)
            {
                if(n&(1<<i))temp.push_back(nums[i]);
            }
            res.push_back(temp);
        }
        return res;

    }
};
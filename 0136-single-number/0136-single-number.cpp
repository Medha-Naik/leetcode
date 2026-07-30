class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singlenum=0;
        for(int i=0;i<nums.size();i++)
        {
            singlenum^=nums[i];
        }
        return singlenum;
    }
};
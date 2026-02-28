class NumArray {
public:
    vector<int>prefix;
    NumArray(vector<int>& nums) {
        prefix.resize(nums.size()+1,0);
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right+1]-prefix[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int total=0;
        int maxwater=INT_MIN;
        while(l<r)
        {
            total=min(height[r],height[l])*(r-l);
            maxwater=max(maxwater,total);
            if(height[r]<height[l])r--;
            else l++;
           
        }
        return maxwater;
        
    }
};
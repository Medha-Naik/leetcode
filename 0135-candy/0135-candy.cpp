class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        
        int i = 1, sum = 1;
        
        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum += 1;
                i++;
                continue;
            }
            
            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }
            
            int down = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                down++;
                sum += down;
                i++;
            }
            
            if (down >= peak) {
                sum += (down - peak + 1);
            }
        }
        return sum;
    }
};
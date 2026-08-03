class Solution {
public:
    int candy(vector<int>& ratings) {
         
         int n = ratings.size();
         int i = 1;
         int total = 1;
         while(i<n)
         {
            if(ratings[i]== ratings[i-1])
            {
                total+=1;
                i++;
                continue;
            }
            int peak = 1, down =0;
            while(i<n && ratings[i]>ratings[i-1])
            {
                peak++;
                total += peak;
                i++;
            }
            while(i<n && ratings[i]<ratings[i-1])
            {
                down++;
                total+=down;
                
                i++;
            }
            if(down>= peak)
            {
                total+= (down - peak + 1);
            }
         }
         return total;
    }
};
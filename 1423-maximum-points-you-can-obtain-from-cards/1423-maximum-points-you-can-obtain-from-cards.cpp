class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int points=0;
        int n=cardPoints.size();
        for(int i=0;i<k;i++)
        {
            points+=cardPoints[i];
        }
        int maxpoints=points;
        int i=0;
        for(int i=k-1;i>=0;i--)
        {
            points-=cardPoints[i];
            points+=cardPoints[n-k+i];
            maxpoints=max(maxpoints,points);
        }
        return maxpoints;
    }
};
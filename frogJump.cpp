class Solution {
  private:
    int solve(vector<int> height, int i, vector<int> &dp){
        if(i==height.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int left=solve(height,i+1,dp)+abs(height[i]-height[i+1]);
        int right=INT_MAX;
        if(i+2<height.size())
            right=solve(height,i+2,dp)+abs(height[i]-height[i+2]);
        return dp[i]=min(left,right);
    }
    
  public:
    int minCost(vector<int>& height) {
        
        vector<int> dp(height.size()+1,-1);
        return solve(height,0,dp);
    }
};
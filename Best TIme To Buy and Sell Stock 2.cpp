class Solution {
    public:
        int func(int i, int n, int act, vector<int>& prices, vector<vector<int>>& dp){
            if(i==n) return 0;
            if(dp[i][act]!=INT_MIN) return dp[i][act];
            int ans=0;
            if(act==0){
                ans = max(-prices[i]+func(i+1,n,1,prices,dp), func(i+1,n,0,prices,dp));
            }
            else{
                ans = max(prices[i]+func(i+1,n,0,prices,dp), func(i+1,n,1,prices,dp));
            }
            dp[i][act] = ans;
            return ans;
            
        }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<int>> dp(n,vector<int>(2,INT_MIN));
            int ans = func(0,n,0,prices,dp);
            return ans;
        }
    };
class Solution {
    public:
        int func(int i,int n,int act,int tran,vector<int>& prices,vector<vector<vector<int>>>& dp){
            if(i==n || tran == 2) return 0;
            if(dp[i][act][tran]!=INT_MIN) return dp[i][act][tran];
            int ans = 0;
            if(act==0){
                ans = max(-prices[i]+func(i+1,n,1,tran,prices,dp),func(i+1,n,0,tran,prices,dp));
            }
            if(act==1){
                ans = max(prices[i]+func(i+1,n,0,tran+1,prices,dp),func(i+1,n,1,tran,prices,dp));
            }
            dp[i][act][tran] = ans;
            return ans;
        }
        int maxProfit(vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,INT_MIN)));
            int ans = func(0,n,0,0,prices,dp);
            return ans;
        }
    };
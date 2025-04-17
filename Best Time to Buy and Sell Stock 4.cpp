class Solution {
    public:
        int func(int i, int n, int k, int act, int tran, vector<int>& prices, vector<vector<vector<int>>>& dp){
            if(i==n || tran == k) return 0;
            if(dp[i][act][tran]!=INT_MIN) return dp[i][act][tran];
            int ans=0;
            if(act==0){
                ans = max(-prices[i]+func(i+1,n,k,1,tran,prices,dp),func(i+1,n,k,0,tran,prices,dp));
            }
            else{
                ans = max(prices[i]+func(i+1,n,k,0,tran+1,prices,dp),func(i+1,n,k,1,tran,prices,dp));
            }
            dp[i][act][tran] = ans;
            return ans;
        }
        int maxProfit(int k, vector<int>& prices) {
            int n = prices.size();
            vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,INT_MIN)));
            int ans = func(0,n,k,0,0,prices,dp);
            return ans;
        }
    };
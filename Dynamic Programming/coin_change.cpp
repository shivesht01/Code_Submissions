    int dp[10009];
    int func(int amount,vector<int>& coins)
    {
        
        if(amount==0)return 0;
        if(dp[amount]!=-1)return dp[amount];
        int res=INT_MAX;
        for(auto coin: coins)
        {
            if(amount-coin >=0)
            res=min(res +0LL,func(amount-coin,coins)+1LL);
        }
        return dp[amount]=res;
    }
    int coinChange(vector<int>& coins, int amount)
    {
        memset(dp,-1,sizeof(dp));
        int ans=func(amount,coins);
        return ans==INT_MAX ? -1: ans;
    }

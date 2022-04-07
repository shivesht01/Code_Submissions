
int dp[10000];
int func(int n,vector<int> &a )
    {
       if(n==0)return 0;
            int sum=0;
            if(dp[n]!=-1)return dp[n];
            for(int i=a.size();i>=1;i--)
            {
                if(n-i>=0)
                sum=max(sum,func(n-i,a)+a[i-1]);
            }
            return dp[n]=sum;
    }
int cutRod(int price[], int n )
    {
        memset(dp,-1, sizeof(dp));
        vector<int> a(price, price+n);
        return func(n,a);
    }
};

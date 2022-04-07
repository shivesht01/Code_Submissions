    int ans=0;
    int dp[3000];
    int func(vector<int>&nums, int i)// check ith position sequence
    {
        int res=1;
        if(dp[i]!=-1)return dp[i];
        for(int j=0;j<i;j++)
        {
            if(nums[j]<nums[i])
                res=max(res,func(nums,j)+1);
        }
        return dp[i]=res;
    }
    int lengthOfLIS(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
         int n=nums.size();
        for(int i=0;i<n;i++)
         ans=max(ans,func(nums,i));
        return ans;
    }
};

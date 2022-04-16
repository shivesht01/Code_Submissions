int dp[205][20500];
    bool func(vector<int>& nums,int i, int sum)
    {
        if(sum==0)return true;
        if(i<0)return false;
        if(dp[i][sum]!=-1)return dp[i][sum];
        bool check=func(nums, i-1, sum);
        if(sum-nums[i]>=0)
        check |= func(nums, i-1, sum-nums[i]);
        
        return dp[i][sum]=check;
    }
    
    bool canPartition(vector<int>& nums) 
    {
        memset(dp,-1,sizeof(dp));
        int n=nums.size()-1;
        int z=0;
        for(auto i: nums)
        {
            z+=i;
        }
        if(z%2!=0)return false;
        z/=2;
        return func(nums,n,z);
        
    }

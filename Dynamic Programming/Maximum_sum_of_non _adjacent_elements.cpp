//recursive
int func(int n,vector<int>&a) 
{
    if(n==0)return a[0];
    if(n<0)return 0;
    //if(dp[n]!=-1)return dp[n];
    if(dp[n]!=-1)return dp[n];
    int left=a[n]+func(n-2,a);
    
    int right=func(n-1,a);
        
    return dp[n]=max(left, right);
}
// iterative

int maximumNonAdjacentSum(vector<int> &a)
{
    int n=a.size();
   	vector<int>dp(n+1,-1);
       dp[0]=a[0];
      // dp[1]=a[0];
       for(int i=1;i<n;i++)
       {
       
         	int pick=a[i];if(i>1)pick+=dp[i-2];
        	int non_pick=dp[i-1];
        
        	dp[i]=max(pick,non_pick);
       }
       return dp[n-1];
       
}

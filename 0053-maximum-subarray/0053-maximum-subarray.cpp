class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0,m=INT_MIN;
        int l=nums.size();
        for(int i=0;i<l;i++)
        {
            sum+=nums[i];

            if(sum>m)
            {
                m=sum;
            }
            if(sum<0)
            {
                sum=0;
            }
        }
        return m;
    }
};
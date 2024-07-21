class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++)
        {
            mini=min(mini,prices[i]);
            int profit=prices[i]-mini;
            maxprofit=max(maxprofit,profit);
        }
        return maxprofit;
        
    }
};
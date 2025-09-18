class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        
        int n=nums.size();
        vector<int> temp;
        int pos=0;
        for(int i=0;i<n;i++){
            if(nums[i]==x){
                temp.push_back(i);
            }
        }
        vector<int>ans;
        for(int i:queries){
            if(i-1<temp.size()){
                ans.push_back(temp[i-1]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;

    }
};
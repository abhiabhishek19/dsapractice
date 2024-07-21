class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        
        
        
        for(int r=1;r<=numRows; r++)
        {
            vector<int>res;
            res.push_back(1);
            int temp=1;
            for(int c=1;c<r;c++)
            {
                temp=temp*(r-c);
                temp=temp/c;
                res.push_back(temp);
            }
            ans.push_back(res);
        }


        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> m;
        int freq[201]={0};
        for (int x: nums ) {
            int& f=freq[x];
            if(f==m.size())
                m.push_back({x});
            else
                m[f].push_back(x);
            f++;
        }
        return m;
    }
};
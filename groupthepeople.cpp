class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mpp;
        vector<vector<int>> ans;
        // map groupsizes and values
        for(int i=0; i<groupSizes.size(); i++){
            mpp[groupSizes[i]].push_back(i);
        }

        

        for(auto it : mpp) {
            int groupSize = it.first;
            vector<int>& members = it.second;
            int n = members.size();

            // Divide members into groups of size groupSize
            for(int i = 0; i < n; i += groupSize) {
                vector<int> temp;
                // Copy groupSize elements from members starting from index i
                temp.assign(members.begin() + i, members.begin() + i + groupSize);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
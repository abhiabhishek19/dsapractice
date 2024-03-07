class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int X = 0;

        for (size_t i = 0; i < operations.size(); ++i) {
            const string& op = operations[i];   //consider reference &op to store array element
            if (op == "++X" || op == "X++") {
                X++;
            } else if (op == "--X" || op == "X--") {
                X--;
            }
        }

        return X;
    }
};


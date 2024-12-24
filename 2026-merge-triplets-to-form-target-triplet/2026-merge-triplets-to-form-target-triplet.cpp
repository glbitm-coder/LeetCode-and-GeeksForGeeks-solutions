class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<bool> isFound(3, false);
        for(int i = 0; i < triplets.size(); ++i){
            if(triplets[i][0] == target[0] && triplets[i][1] <= target[1] && triplets[i][2] <= target[2]){
                isFound[0] = true;
            }
            if(triplets[i][1] == target[1] && triplets[i][0] <= target[0] && triplets[i][2] <= target[2]){
                isFound[1] = true;
            }
            if(triplets[i][2] == target[2] && triplets[i][1] <= target[1] && triplets[i][0] <= target[0]){
                isFound[2] = true;
            }
        }

        for(auto it:isFound){
            if(it == false) return false;
        }
        return true;
    }
};
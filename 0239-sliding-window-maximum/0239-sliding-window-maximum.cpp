class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        if(k >= nums.size()){
            ans.push_back(*max_element(nums.begin(), nums.end()));
            return ans;
        }
        for(int i = 0; i < k; ++i){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        for(int i = 1, j = k; j < nums.size(); ++i, ++j){
            pq.push({nums[j], j});
            while(pq.top().second < i){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
           
        return ans;
    }
};
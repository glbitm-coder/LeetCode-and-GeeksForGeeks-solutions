class Solution {
public:
    int candy(vector<int>& ratings) {
        // [3,2,1,2,3]
        //   3 2 1 2 3

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        
        int n = ratings.size();
        vector<int> ans(n, 1);

        for(int i = 0; i < n; ++i){
            p.push({ratings[i],i});
        }

        while(!p.empty()){
            pair<int,int> v = p.top();
            int left = v.second - 1;
            int right = v.second + 1;
            if(left >= 0 && ratings[left] > v.first){
                ans[left] = max(ans[left], ans[v.second] + 1);
            }
            if(right < n &&  ratings[right] > v.first){
                ans[right] = max(ans[right], ans[v.second] + 1);
            }
            p.pop();
        }
        int res = 0;
        for(int i = 0; i < n; ++i){
            res += ans[i];
            cout<<ans[i]<<" ";
        }
        return res;
    }
};
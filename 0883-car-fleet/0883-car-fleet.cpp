class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> v;
        int n = position.size();
        
        for(int i = 0; i < n; ++i){
            v.push_back({position[i], speed[i]});
        }

        sort(v.begin(), v.end());

        vector<float> time(n, 0);
        for(int i = 0; i < n; ++i){
            time[i] = (float)(target - v[i].first ) / v[i].second;
        }

        stack<float> st;
        int ans = 0;
        for(int i = n - 1; i >= 0; --i){
            if(st.empty()){
                st.push(time[i]);
            }
            else{
                if(st.top() < time[i]){
                    st.push(time[i]);
                }
            }
        }
        return st.size();
    }
};
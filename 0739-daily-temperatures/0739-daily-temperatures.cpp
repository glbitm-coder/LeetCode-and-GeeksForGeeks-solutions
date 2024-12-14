class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;
        int val = 0;
        for(int i = temperatures.size() - 1; i >= 0; --i){
            if(st.empty()){
                st.push({i, 0});
            }
            else{
                val = 0;
                while(!st.empty() && temperatures[st.top().first] <= temperatures[i]){
                    temperatures[st.top().first] = st.top().second;
                    val += st.top().second;
                    st.pop();
                }
                if(st.empty()){
                    st.push({i,0});
                }
                else{
                    st.push({i, val + 1});
                }
            }
        }
        while(!st.empty()){
            temperatures[st.top().first] = st.top().second;
            st.pop();
        }
        return temperatures;
    }
};
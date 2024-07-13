class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        map<int,pair<char,int>> mp;

        int n = positions.size();

        for(int i = 0; i < n; ++i){
            mp[positions[i]] = {directions[i], healths[i]};
        }

        stack<int> st;
        for(auto it: mp){
            if(st.empty()){
                st.push(it.first);
            }
            else{
                int curr = st.top();
                pair<char,int> vals = mp[curr];
                while(true){
                    if(st.empty()){
                        st.push(it.first);
                        mp[it.first] = {it.second.first, it.second.second};
                        break;
                    }
                    curr = st.top();
                    vals = mp[curr];
                    
                    if(it.second.first == vals.first || vals.first == 'L' && it.second.first == 'R'){
                        st.push(it.first);
                        mp[it.first] = {it.second.first, it.second.second};
                        break;
                    }
                    else{
                        if(it.second.second > vals.second){
                            st.pop();
                            it.second.second = it.second.second - 1;
                            continue;
                        }
                        else if(it.second.second < vals.second){
                            mp[curr] = {vals.first, vals.second - 1};
                            break;
                        }
                        else{
                            st.pop();
                            break;
                        }

                    }
                }

            }
        }
        
        vector<int> ans;
        unordered_set<int> s;

        while(!st.empty()){
            int c = st.top();
            s.insert(c);
            st.pop();
        }

        for(auto it:positions){
            if(s.find(it) != s.end()){
                ans.push_back(mp[it].second);
            }
        }
        return ans;
    }
};
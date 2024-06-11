class Solution {
    
public:
    int minimumEffortPath(vector<vector<int>>& heights) {  
        set<pair<int,pair<int,int>>> s;

        int rows = heights.size();
        int cols = heights[0].size();

        map<pair<int,int>,int> ans;

        s.insert({0, {0,0}});

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                ans[{i,j}] = INT_MAX;
            }
        }
        ans[{0,0}] = 0;

        vector<int> xDir{0,0,1,-1};
        vector<int> yDir{1,-1,0,0};

        while(!s.empty())
        {
            auto it = *(s.begin());
            int value = it.first;
            int xValue = it.second.first;
            int yValue = it.second.second;

             s.erase(it);

             for(int i = 0; i < 4; ++i){
                int upDatedX = xValue + xDir[i];
                int upDatedY = yValue + yDir[i];

                if(upDatedX >= 0 && upDatedY >= 0 && upDatedX < rows && upDatedY < cols)
                {
                    // cout<<xValue<<" "<<yValue<<" "<<upDatedX<<" "<<upDatedY<<"\n";
                    int prevVal = heights[xValue][yValue];
                    int currentVal = heights[upDatedX][upDatedY];
                    
                    if(ans[{upDatedX,upDatedY}] > max(value, abs(currentVal - prevVal))){
                        // cout<<xValue<<" "<<yValue<<" "<<upDatedX<<" "<<upDatedY<<"\n";
                        ans[{upDatedX,upDatedY}] = max(value, abs(currentVal - prevVal));
                        s.insert({ans[{upDatedX,upDatedY}], {upDatedX,upDatedY}});
                    }
                    
                }
             }
        }
        // cout<<ans[{1,0}]<<"\n";
        return ans[{rows - 1, cols - 1}];
    }
};
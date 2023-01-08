class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       int res = 1;
        for(int i=0;i<points.size();i++)
        {
             map<double,int>mp;
            for(int j=i+1;j<points.size();j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                
                double value1 = (y2-y1);
                int value2 = (x2-x1);
                
               if(value2 == 0)
               {
                   mp[INT_MAX]++;//if slope is infinity.
                   continue;
               }
                else
                {
                    double slope = value1 /value2; //Value of slope
                    mp[slope]++;
                }
                
            } //this is the end of "j for loop".
            
            /* For Every Points:-
            Checking for the maximum number of Points with same slope.*/
            for(auto x:mp)
            {
                res = max(res,x.second+1);
                //We are adding 1 beacuse we are counting the point (x1,y1) also on that line.
            }
           
        }
        return res;
       
    }
};
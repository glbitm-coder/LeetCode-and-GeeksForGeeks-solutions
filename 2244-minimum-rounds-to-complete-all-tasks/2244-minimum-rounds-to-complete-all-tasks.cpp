class Solution {
public:
    int fill_map(int num)
    {
        int ans = 0;
        if(num == 1)
        {
            return -1;
        }
       if(num % 3 == 0)
       {
           return num / 3; 
       }
       else
       {
           return num / 3 + 1;
       }
    }
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(int i = 0 ; i < (int)tasks.size(); ++i)
        {
            mp[tasks[i]]++;
        }
        int ans = 0;
        for(auto it:mp)
        {
            int get = fill_map(it.second);
             if( get == -1)
             {
                 return -1;
             }
            ans += get;
        }
        return ans;
    }
};
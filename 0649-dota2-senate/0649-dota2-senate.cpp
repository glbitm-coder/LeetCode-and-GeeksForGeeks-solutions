class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r;
        queue<int> d;
        for(int i = 0; i < senate.size(); ++i)
        {
            if(senate[i] == 'R')
            {
                r.push(i);
            }
            else
            {
                d.push(i);
            }
        }
        while(!r.empty() && !d.empty())
        {
            int a = r.front();
            int b = d.front();
            if(a < b)
            {
                d.pop();
                r.pop();
                r.push(a + senate.size() - 1);
            }
            else
            {
                r.pop();
                d.pop();
                d.push(b + senate.size() - 1);
            }
        }
        if(r.empty())
            return "Dire";
        else
            return "Radiant";
    
    }
};
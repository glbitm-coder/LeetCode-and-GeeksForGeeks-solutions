class Solution {
public:
    
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i = 0; i < stones.size(); ++i){
            pq.push(stones[i]);
        }    

        if(pq.size() == 1) return pq.top();

        while(pq.size() > 1){
            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();
            if(n2 == n1){
                continue;
            }
            else{
                pq.push(n1 - n2);
            }
        }
        return pq.size() == 0 ? 0 : pq.top();
    }
};
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int> , greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        sort(nums.begin(), nums.end());
        
        int p = nums.size() - k;
        if(p < 0)
            p = 0;
        for(int i = p; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > k)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
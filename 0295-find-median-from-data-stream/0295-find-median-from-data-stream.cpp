class MedianFinder {
public:
    priority_queue<int, vector<int>, less<int>> maxH;
    priority_queue<int, vector<int>, greater<int>> minH; 
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxH.push(num);
        if(!minH.empty() && maxH.top() > minH.top()){
            minH.push(maxH.top());
            maxH.pop();
        }
        if(maxH.size() > minH.size() + 1){
            minH.push(maxH.top());
            maxH.pop();
        }
        if(minH.size() > maxH.size() + 1){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        if(minH.size() == maxH.size()){
            return (double)(maxH.top() + minH.top()) / 2;
        }
        else{
            if(maxH.size() > minH.size()){
                return maxH.top();
            }
            else{
                return minH.top();
            }
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
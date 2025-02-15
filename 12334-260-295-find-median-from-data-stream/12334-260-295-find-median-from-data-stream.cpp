class MedianFinder {
public:
    priority_queue<double> small;
    priority_queue<double,vector<double>,greater<double>> large;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        small.push(num);

        if(!small.empty()&&!large.empty()&&small.top()>large.top()){
            large.push(small.top());
            small.pop();
        }

        if(small.size() > large.size()+1){
            large.push(small.top());
            small.pop();
        }else if(large.size()>small.size()){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size()==large.size()+1) return small.top();
        return (large.top()+small.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
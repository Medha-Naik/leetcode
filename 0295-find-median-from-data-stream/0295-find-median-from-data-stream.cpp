class MedianFinder {
public:
priority_queue<int>lmax;
priority_queue<int,vector<int>,greater<int>>rmin;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lmax.push(num);
        int val=lmax.top();
        lmax.pop();
        rmin.push(val);
        if(rmin.size()>lmax.size())
        {
            int n=rmin.top();
            rmin.pop();
            lmax.push(n);
        }
    }
    
    double findMedian() {
        double median;
        if(lmax.size()==rmin.size())
        {
            double n1=lmax.top();
            double n2=rmin.top();
            median=(n1+n2)/2;
            return median;
        }
        else return lmax.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
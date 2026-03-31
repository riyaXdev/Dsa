class MedianFinder {
public:
    priority_queue<double,vector<double>,greater<double>> mini;
    priority_queue<double> maxi;
    double med;
    int signum(int a,int b){
        if(a==b) return 0;
        else if(a>b) return 1;
        else return -1;
    }
    void call_med(double ele){
        switch(signum(maxi.size(), mini.size())){
            case 0: if(ele > med){
                mini.push(ele);
                med = mini.top();
            }
                    else{//ele < med insert into max heap
                maxi.push(ele);
                med = maxi.top();
                    }
                   break;
            case 1: if(ele > med){
                mini.push(ele);
            }
                  else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(ele);
                  }
                  med = (maxi.top() + mini.top()) / 2;
                  break;
            case -1: if(ele > med){
                      maxi.push(mini.top());
                      mini.pop();
                      mini.push(ele);
            }
                    else{
                        maxi.push(ele);
                    }
                    med = (maxi.top() + mini.top()) / 2;
                    break;
        }
    }

    MedianFinder() {
        med = 0;
    }
    
    void addNum(int num) {
        double ele = num;
        call_med(ele);
    }
    
    double findMedian() {
        return med;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
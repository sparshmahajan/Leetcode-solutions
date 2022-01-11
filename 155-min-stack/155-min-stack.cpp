class MinStack {
    int min=INT_MAX;
    int arr[3*10000][2];
    int tp;
public:
    MinStack() {
       tp = -1;
    }
    
    void push(int val) {
        tp++;
        arr[tp][0]=val;
        if(val < min) min = val;
        arr[tp][1]=min;
    }
    
    void pop() {
        tp--;
        if(tp==-1) min = INT_MAX;
        else min=arr[tp][1];
        
    }
    
    int top() {
        return arr[tp][0];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
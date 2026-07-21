class MyQueue {
public:
    stack<int>st;
    stack<int>helper;
    int cap;
    MyQueue() {
        cap=0;
    }
    
    void push(int x) {
        st.push(x);
        cap++;
    }
    
    int pop() {
        if(cap==0) return -1;
        while(st.size()>1){
            helper.push(st.top());
            st.pop();
        }
        int x=st.top();
        st.pop();
        cap--;
        
        while(helper.size()>0){
        st.push(helper.top());
        helper.pop();
        }
        return x;
    }
    
    int peek() {
        if(cap==0) return -1;
        while(st.size()>1){
            helper.push(st.top());
            st.pop();
        }        
        int x =st.top();
        while(helper.size()>0){
        st.push(helper.top());
        helper.pop();
        }
        return x;

    }
    
    bool empty() {
        if(cap==0) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
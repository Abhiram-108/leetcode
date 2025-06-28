class CustomStack {
    vector<int>st;
    int maxsize;
    int size;
public:
    CustomStack(int maxSize) {
        maxsize=maxSize;
        size=0;
        
    }
    
    void push(int x) {
        if(size==maxsize)
        return;
        st.push_back(x);
        size++;
        
    }
    
    int pop() {
        if(size==0)
        return -1;
        int top=st.back();
        st.pop_back();
        size--;
        return top;
        
    }
    
    void increment(int k, int val) {
        for(int i=0;i<min(k,size);i++){
            st[i]+=val;

        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
class MyCircularQueue {
    int *q;
    int frontIndex;
    int lastIndex;
    int size;
    int s;
public:
    MyCircularQueue(int k) {
        q = new int[k];
        size = 0;
        frontIndex = -1;
        lastIndex = 0;
        s = k;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        q[lastIndex] = value;
        lastIndex = (lastIndex+1)%s;
        if(frontIndex == -1)
            frontIndex = 0;
        ++size;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        frontIndex = (frontIndex+1)%s;
        --size;
        if(size == 0)
        {
            frontIndex = -1;
            lastIndex = 0;
        }
        return true;
    }
    
    int Front() {
        if(size == 0)
            return -1;
        return q[frontIndex];
    }
    
    int Rear() {
        if(size == 0)
            return -1;
        return q[(frontIndex+size-1)%s];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == s;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
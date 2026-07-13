class MyCircularQueue {
private:
    //int* front=0;
    //int* rear=-1;
    //we use indices for cirular queues instead of using pointers
    int front=0;
    int rear=-1;
    vector<int>queue;
    int capacity=0;
    int currsize=0;
public:
    MyCircularQueue(int k) {
        queue.resize(k); //since we have to define the size here
        capacity=k;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            rear = (rear+1)%capacity;
            queue[rear]=value;
            currsize++;
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            front =(front+1)%capacity;
            currsize--;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(!isEmpty())
            return queue[front];
        else
            return -1;
    }
    
    int Rear() {
        if(!isEmpty())
            return queue[rear];
        else
            return -1;
    }
    
    bool isEmpty() {
        if(currsize==0)
            return true;
        return false;
    }
    
    bool isFull() {
        if(currsize==capacity)
            return true;
        return false;
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
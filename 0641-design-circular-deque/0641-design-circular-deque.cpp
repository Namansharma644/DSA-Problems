class MyCircularDeque {
public:
    int f;
    int r;
    int* arr;
    int size;
    int cap;
    MyCircularDeque(int k) {
        cap=k;
        arr=new int[k];
        f=0;
        r=k-1;
        size=0;
    }
    
    bool insertFront(int value) {
        if(isFull())
        {
            return false;
        }

        f=(f-1+cap)%cap;
        arr[f]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
        {
            return false;
        }

        r=(r+1)%cap;
        arr[r]=value;   
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
        {
            return false;
        }

        f=(f+1)%cap;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
        {
            return false;
        }

        r=(r-1+cap)%cap;
        size--;
        return true;
    }
    
    int getFront() {
        if(isEmpty())
        {
            return -1;
        }
        return arr[f];
    }
    
    int getRear() {
        if(isEmpty())
        {
            return -1;
        }
        return arr[r];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        return cap==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
### Circular Queue

Manipulates an array into a ring. 

```c++
class CircularQueue{
    private: 
    int *arr;
    int count;
    int front;
    int len;
    
    public:
    CircularQueue(int k){
        vec = new int[k];
        front = 0;
        len = k;
    }
    
    bool enQueue(int value){
        if(isFull())return false;
        vec[(front + count)%len] = value;
        count++;
        return true;
    }
    
    bool deQueue(){
        if(isEmpty())return false;
        front = (front+1)%len;
        count--;
        return true;
    }
    
    int Front(){
        if(isEmpty())return -1;
        return vec[front];
    }
    
    int Rear(){
        if(!isEmpty())return vec[(front + count -1)%len];
        else return -1;
    }
    bool isEmpty() {
        return count==0;
    }
    
    bool isFull() {
        return count == len;
    }
}
```


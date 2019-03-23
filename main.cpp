#include <iostream>

using namespace std;

// array implementation of a queue
//////////////////////////////////
class QueueArrImpl{
    private:
        int front,rear,numOfElements,size;
        int *queueArr;

        void resize(){
            int tempSize = size * 2;
            int *tempArr = new int[tempSize];
            for(int i = 0; i < size; i++){
                tempArr[i] = queueArr[(front + i) % size];
            }

            delete [] queueArr;
            queueArr = tempArr;

            front = 0;
            rear = size - 1;

            size = tempSize;
        }


    public:
        QueueArrImpl(int size){
            front = rear = -1;
            this->size = size;
            queueArr = new int[size];
            numOfElements = 0;
        }

        ~QueueArrImpl(){
            delete [] queueArr;
        }

        void enqueue(int data){
            // means theres no more space
            if(numOfElements == size){
                resize();
                cout << "resitze being called" << endl;
            }

            if(front == -1 && rear == -1)
                front = rear = 0;
            else
                rear = (rear + 1) % size;

            queueArr[rear] = data;
            numOfElements++;
        }

        int dequeue(){
            if(numOfElements == 0){
                return -1;
            }
            else{
                int temp = queueArr[front];
                if(front == rear)
                    rear = front = -1;
                else
                    front = (front + 1) % size;

                numOfElements--;
                return temp;

            }
        }
};



// Helper class for linkedlist
class Node{
    public:
        int data;
        Node *next;
        Node(int data){
            this->data = data;
            next = NULL;
        }

};

// Queue Implemented using a linked list
/////////////////////////////////////////////////
class QueueLinkedListImpl{
    private:
        Node *front;
        Node *rear;

    public:
        QueueLinkedListImpl(){
            front = rear = NULL;
        }
        ~QueueLinkedListImpl(){
            Node *next;
            while(front != NULL){
                next = front->next;
                delete front;
                front = next;
            }
        }

        void enqueue(int data){
            Node *n = new Node(data);
            if(rear == NULL)
                rear = front = n;
            else{
                rear->next = n;
                rear = n;
            }
        }
        int dequeue(){
            if(front == NULL){
                cout << "Empty Queue" << endl;
                return -1;
            }
            Node *temp = front;
            int tempData = front->data;
            if(front == rear)
                front = rear = NULL;
            else
                front = front->next;

            delete temp;
            return tempData;
        }
};




int main(){
    QueueArrImpl queue(3);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;

}

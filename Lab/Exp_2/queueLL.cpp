#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Queue{
public:
    Node* front;
    Node* rear;

    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty(){
        return front == nullptr;
    }

    void enque(int value){
        Node* newnode = new Node(value);
        if(rear == nullptr){
            front = newnode;
            rear = newnode;
        }
        else{
            rear -> next = newnode;
            rear = newnode;
        }
        cout << value << " enqued in the queue" << "\n";
    }

    void deque(){
        if(isEmpty()) {
            cout << "Queue empty" << endl;
            return;
        }
        Node* temp = front;
        front = front -> next;
        if(front == nullptr) rear = nullptr;
        cout << temp -> data << " dequed from the queue" << "\n";
        delete temp;
    }

    void print(){
        if(isEmpty()) {
            cout << "Queue Empty\n";
            return;
        }
        cout << "Printing the elements: ";
        Node* temp = front;
        while(temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
        delete temp;
    }
};
int main(){
    Queue q;
    q.enque(1);
    q.print();
    q.enque(2);
    q.print();
    q.enque(3);
    q.print();
    q.enque(4);
    q.print();
    q.deque();
    q.print();
    q.deque();
    q.print();
    q.deque();
    q.print();
    q.deque();
    q.print();
    return 0;
}
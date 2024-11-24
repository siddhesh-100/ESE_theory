#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};
class Stack{
public:
    Node* top;
    Stack() : top(nullptr) {}
    
    bool isEmpty(){ return top == nullptr; }

    void push(int value){
        Node* newnode = new Node(value);
        newnode -> next = top;
        top = newnode;
        cout << value << " pushed in the stack." << "\n";
    }

    void pop(){
        if(isEmpty()){
            cout << "Stack empty" << "\n";
            return;
        }
        Node* temp = top;
        top = top -> next;
        cout << "Popped " << temp -> data << " from the stack" << "\n";
        delete temp;
    }

    int peek(){
        if(isEmpty()){
            cout << "Stack Empty" << "\n";
            return -1;
        }
        return top -> data;
    }

    void print(){
        if(isEmpty()){
            cout << "Stack Empty\n";
            return;
        }
        Node* temp = top;
        cout << "Printing Stack elements: ";
        while(temp){
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << "\n";
        delete temp;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.print();
    cout << s.peek() << "\n";
    s.push(2);
    s.print();
    s.push(3);
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
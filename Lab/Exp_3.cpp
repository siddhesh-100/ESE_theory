#include <iostream>
#include <vector>
using namespace std;
class Node{
    public:
        int sweetness;
        Node* next;
        Node(int val) : sweetness(val), next(nullptr) {}
};
void insertInSortedOrder(Node* &head, int k){
    Node* newnode = new Node(k);
    if(!head || head -> sweetness > k){
        newnode -> next = head;
        head = newnode;
        return;
    }
    Node* current = head;
    while(current -> next &&  current -> next -> sweetness < k){
        current = current -> next;
    }
    newnode -> next = current -> next;
    current -> next = newnode;
}
int removeFirstNode(Node* &head){
    if(!head) return -1;
    Node* temp = head;
    int val = head -> sweetness;
    head = head -> next;
    delete temp;
    return val;
}
int minOperations(Node* &head, int k){
    int operations = 0;
    while(head && head -> sweetness < k){
        if(!head -> sweetness) return -1;
        int leastSweet = removeFirstNode(head);
        int secondLeastSweet = removeFirstNode(head);
        int newSweetness = leastSweet + 2 * secondLeastSweet;
        insertInSortedOrder(head, newSweetness);
        operations++;
    }
    return operations;
}
Node* createList(vector<int> &v){
    Node* head = nullptr;
    for(int i : v) insertInSortedOrder(head, i);
    return head;
}
void printList(Node* head){
    while(head){
        cout << head -> sweetness << "->";
        head = head -> next;
    }
    cout << "NULL\n";
}
int main(){
    vector<int> cookies = {2, 5, 11, 53, 2, 5, 6, 3, 6};
    int k = 5;
    Node* head = createList(cookies);
    printList(head);
    int result = minOperations(head, k);
    printList(head);
    cout << "Result = " << result << "\n";
    return 0;
}
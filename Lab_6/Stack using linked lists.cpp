#include <iostream>
using namespace std;

//implementing stack using linked list
//creating node class
class Node {
public:
    int element;
    Node *next;
    Node(int value) {
        element = value;
        next = NULL;
    }
};
//creating stack class
class Stack {
private:
    Node *top;
    int maxSize;
    int count;

public:
    Stack(int size) {
        top = NULL;
        maxSize = size;
        count = 0;
    }

    ~Stack() {   //creating new stack as an empty one
        Node *temp = top;
        while (top != NULL) {
            top = top->next;
            delete temp;
            temp = top;
        }
    }

    bool isEmpty() {  //checking if the stack is empty
        return (top == NULL);
    }

    bool isFull() {  //checking if the stack is full
        return (count == maxSize);
    }

    void push(int element) {  //entering elements to the stack
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        Node *temp = new Node(element);
        temp->next = top;
        top = temp;
        count++;
    }

    void pop() { //remove elements from the stack
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    int stackTop() {  //getting the top element of the stack
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return top->element;
    }

    void display() {  //displaying the stack
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack: ";
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->element << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    Stack s(size);
     for(int i=0;i<size;i++){  //enter elements to the stack
        int num;
        cout <<"Enter the element to the stack:";
        cin >>num;
        s.push(num);
    }

    s.display();    // display the stack
    

    return 0;
}

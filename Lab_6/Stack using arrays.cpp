#include <iostream>
using namespace std;

//implementing stack using arrays
//creating stack class
class Stack {
    private:
        int *arr;
        int top;
        int size;

    public:
        Stack(int stack_size) {
            size = stack_size;
            arr = new int[size];
            top = -1;
    }

    ~Stack() {
        delete[] arr;  //creating a new stack as an empty one
    }

    bool isEmpty() {
        return (top == -1); //checking if the stack is empty
    }

    bool isFull() {
        return (top == size-1);  //checking if the stack is full
    }

    void push(int element) { //add elements to the stack
        if (isFull()) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        arr[top] = element;
    }

    void pop() {  //removing elements from the stack
        if (isEmpty()) {
            cout << "Stack underflow" << endl;
        return;
        }
        top--;
    }

    int stackTop() { //displaying the top element of the stack
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        return -1;
        }
        return arr[top];
    }

    void display() { //printing the stack
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size; //getting the stack size as user input

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

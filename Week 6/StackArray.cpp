#include <iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;

class Stack {  // Creating the Stack
  private:
    int* arr;  // pointer to the array used for the stack
    int top;   // index of the top element of the stack
    int size;  // size of the stack

  public:
    // Constructor to initialize the stack
    Stack(int s) {
      arr = new int[s];
      top = -1;
      size = s;
    }

    
    // Method to push an element onto the top of the stack
    void push(int val) {
      if (top >= size - 1) {
        cout << "Stack Overflow\n";
        return;
      }
      top++;
      arr[top] = val;
    }

    // Method to pop the top element off the stack and return its value
    int pop() {
      if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;
      }
      int val = arr[top];
      arr[top] = 0;
      top--;
      return val;
    }

    // Method to return the value of the top element of the stack
    int Stacktop() {
      if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;
      }
      return arr[top];
    }

    // Method to check if the stack is empty
    bool isEmpty() {
      return (top < 0);
    }

    // Method to check if the stack is full
    bool isFull() {
      return (top >= size - 1);
    }

    void Display() {
        for(int i =0; i < size; i++){
            cout << arr[i] << " ";
        }
         
    }
};

// Example usage
int main() {
    int size;
    cout << "Enter size of stack: ";
    cin >> size;
    Stack myStack(size);
    
    srand(std::time(nullptr));

    int sum = 0;
    
    for(int j= 0; j < 500000; j++) {

        auto start = high_resolution_clock::now();
        for(int i = 0 ; i < size; i++){
            int random_number = std::rand() % 100 ;   // Generate a random integer between 0 and 99
            myStack.push(random_number);
        }

        for(int i = 0 ; i < size; i++){
            myStack.pop();
        }


        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        sum = sum + duration.count();

    }
    cout << "Time taken For operations = " << (double)sum/(double)500000 << " microseconds";
     
     myStack.push(45);
     myStack.push(423);
     myStack.push(76);
     myStack.push(93);
     myStack.push(23);
     myStack.pop();
     myStack.pop();
     myStack.pop();
     myStack.pop();
     myStack.push(150);


     cout << "" <<endl;
     myStack.Display();
     return 0;
}

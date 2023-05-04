#include <iostream>
#include<cstdlib>
#include<ctime>
#include<chrono>

using namespace std;
using namespace std::chrono;

#include <iostream>

// Define a node class for the linked list
class Node {
  public:
    int data;     // The data stored in the node
    Node* next;   // A pointer to the next node in the list
};

// Define a stack class that uses a linked list to store data
class Stack {
  private:
    Node* top;    // A pointer to the top node in the stack
    int size;     // The number of nodes in the stack
    int capacity; // The maximum number of nodes allowed in the stack

public:
  // Constructor that takes the capacity of the stack as an argument
  Stack(int capacity) {
    this->top = nullptr;    // Set the top pointer to null, indicating an empty stack
    this->size = 0;         // Set the size to 0, indicating an empty stack
    this->capacity = capacity;  // Set the maximum capacity of the stack
  }


  // Function that checks if the stack is full
  bool isFull() {
    return size == capacity;   
  }

  // Function that checks if the stack is empty
  bool isEmpty() {
    return top == nullptr;     // The stack is empty if the top pointer is null
  }

  // Function that adds a new node to the top of the stack
  void push(int data) {
    if (isFull()) {             
      cout << "Stack overflow" << endl;  
      return;                   
    }

    Node* new_node = new Node();    // Create a new node
    new_node->data = data;          
    new_node->next = top;           
    top = new_node; 
    size++;                
  }

  // Function that removes the top node from the stack and returns its data
  int pop() {
    if (isEmpty()) {              // If the stack is empty
      cout << "Stack underflow" << endl;   // Output an error message
      return -1;                  // Return -1 to indicate an error
    }

    Node* temp = top;             // Create a temporary pointer to the top node
    int data = temp->data;        
    top = top->next;              
    delete temp;                  
    size--;                       
    return data;                  // Return the data of the top node
  }

  // Function that returns the data of the top node without removing it
  int StackTop() {
    if (isEmpty()) {             
      cout << "Stack underflow" << endl;   
      return -1;                  
    }
    return top->data;             
  }

  void Display() {
  // Traverse through the stack from top to bottom
  Node* current = this->top;
  while (current != nullptr) {
    // Print the data value of the current node
    cout << current->data << " ";

    // Move to the next node in the stack
    current = current->next;
  }
  cout << endl;
}


};
  
// Example usage
int main() {

    int capacity;
    cout << "Enter the number of elements that should be in the stack " <<endl;
    cin >> capacity;

    Stack myStack(capacity);
    srand(std::time(nullptr));

    int sum = 0;
    
    for(int j= 0; j < 500000; j++) {


        auto start = high_resolution_clock::now();
        for(int i = 0 ; i < capacity; i++){
            int random_number = std::rand() % 100 ;   // Generate a random integer between 0 and 99
            myStack.push(random_number);
        }

        for(int i = 0 ; i < capacity; i++){
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

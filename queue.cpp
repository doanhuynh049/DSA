#include <iostream>
using namespace std;

// Define a Node class to represent nodes in the linked list that is the underlying data structure for the queue
class Node{
    public:
        int data;
        Node *next;
};

// Define a Queue class that encapsulates the functionality of a queue using a linked list
class Queue{
    private:
        Node *front; // Pointer to the front of the queue
        Node *rear;  // Pointer to the rear of the queue
    public:
        // Constructor to initialize the pointers to NULL
        Queue() {
            front = NULL;
            rear = NULL;
        }
        
        // Returns true if the queue is empty, false otherwise
        bool isEmpty(){
            return (front == NULL && rear == NULL);
        }
        
        // Adds a new element to the rear of the queue
        void enqueue(int data){
            Node *newnode = new Node();
            newnode -> data = data;
            newnode -> next = NULL;
            if(isEmpty()){
                front = rear = newnode;
            }
            else {
                rear->next = newnode;
                rear = newnode;
            }
        }
        
        // Removes the element at the front of the queue and deallocates its memory
        void dequeue(){
            if (isEmpty()){
                cout <<"Queue is already empty" << endl;
            } 
            else if (front == rear){
                Node *temp = front;
                front = rear = NULL;
                free(temp); // Note: In C++, use delete instead of free to deallocate memory
            }
            else{
                Node *temp =front;
                front = front->next;
                free(temp); // Note: In C++, use delete instead of free to deallocate memory
            }
        }
        
        // Prints the queue from front to rear
        void display(){
            Node * temp = front;
            cout<<"Queue: ";
            while (temp!=NULL){
                cout << temp->data <<" <= ";
                temp = temp->next;
            }
            cout << endl;
        }
        
        // Returns the minimum element in the linked list that underlies the queue
        int Min_linkedlist(){
            Node *temp = front;
            int min = temp->data;
            while(temp != NULL){
                if (temp ->data < min){
                    min = temp->data;
                }
                temp =temp->next;
            }
            return min;
        }
};

int main(){
    Queue queue; // Create a new queue object
    
    // Enqueue some elements into the queue
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    
    queue.display(); // Display the queue
    
    queue.dequeue(); // Dequeue an element from the queue
    
    queue.display(); // Display the queue again
    
    cout << "Min of queue: " <<queue.Min_linkedlist() <<endl; // Print the minimum element in the queue
}
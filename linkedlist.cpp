#include <iostream>
#include <bits/stdc++.h> // This header file includes various standard libraries such as iostream, string, etc.
using namespace std;
class Node{ // Definition of a Node class
    public: 
        int data;
        Node *next;
};
class Process_node{ // Definition of a Process_node class
    public:
    void printList(Node *n){ // Definition of a function to print the elements of a linked list
        while (n!=NULL){ // while the node pointer is not null
            cout << n->data <<" <= "; // print the data stored in the node and an arrow
            n = n->next; // move the node pointer to the next node
        }
        cout << "NULL" << endl; // print null when the end of the linked list is reached
    }
    //Add a node at the front
    // This function inserts a new node at the beginning of the linked list.
    void push(Node** head_ref, int new_data){
        Node* new_node = new Node(); // allocate memory for the new node
        new_node ->data = new_data; // set the data of the new node to new_data
        new_node->next = *head_ref; // set the next pointer of the new node to the current head
        (*head_ref)=new_node; // update the head to point to the new node
    }

    // This function inserts a new node after a given node in the linked list.
    void insertAfter(Node* prev_node, int new_data){
        if (prev_node == NULL){ // if the given previous node is NULL, print an error message and return
            cout <<"Can't insert after NULL node";
            return;
        }
        Node* new_node = new Node(); // allocate memory for the new node
        new_node->data = new_data; // set the data of the new node to new_data
        new_node->next = prev_node->next; // set the next pointer of the new node to the next pointer of the previous node
        prev_node->next = new_node; // update the next pointer of the previous node to point to the new node
    }

        // This function appends a new node with the given data to the end of the linked list.
    void append(Node* head_ref, int new_data){
        Node* new_node = new Node(); // allocate memory for the new node
        new_node->data = new_data; // set the data of the new node to new_data
        new_node->next = NULL; // set the next pointer of the new node to NULL
        
        Node* temp = head_ref;
        if(temp == NULL){ // if the linked list is empty, set the head to the new node and return
            temp = new_node;
            return;
        }
        while (temp->next != NULL){ // traverse the linked list until the end is reached
            temp = temp->next;
        }
        temp->next = new_node; // set the next pointer of the last node to the new node
    }

    // This function searches for a node with the given data in the linked list.
    // It returns true if the node is found, and false otherwise.
    bool search_node(Node *head_ref, int data){
        Node *temp = head_ref;
        while( temp != NULL){ // traverse the linked list until the end is reached
            if(temp->data == data){ // if a node with the given data is found, return true
                return true;
            }
            temp = temp->next;
        }
        return false; // if the end of the linked list is reached and the node is not found, return false
    }

    // This function recursively searches for a node with the given data in the linked list.
    // It returns true if the node is found, and false otherwise.
    bool search_node_recursive(Node *head_ref, int data){
        Node *temp = head_ref;
        if(temp == NULL){ // if the end of the linked list is reached and the node is not found, return false
            return false;
        }
        if(temp->data == data){ // if a node with the given data is found, return true
            return true;
        }
        return search_node_recursive(temp->next, data); // recursively call the function with the next node in the linked list
    }

    // This function recursively finds the length of the linked list.
    int length_node(Node* head_ref){
        Node* temp = head_ref;
        if(temp == NULL){ // if the end of the linked list is reached, return 0
            return 0;
        }
        else{
            return 1 + length_node(temp->next); // recursively call the function with the next node in the linked list
        }
    }

    // This function reverses the linked list iteratively and returns the new head of the reversed list.
    Node* reverse_iterative(Node *head_ref){
        Node* curr = head_ref;
        Node* prev = NULL;
        Node* next = NULL;
        while (curr!=NULL){ // traverse the linked list
            next = curr->next; // temporarily store the next node
            curr->next= prev; // reverse the next pointer of the current node
            prev = curr; // move the prev pointer to the current node
            curr = next; // move the current pointer to the next node
        }
        return prev; // return the last node before the new head of the reversed list
    }
    Node* reverse_recursive(Node *head_ref){
        Node* curr = head_ref; // Initialize the current node as the head of the linked list
        Node* prev = NULL; // Initialize the previous node as null
        Node* next = NULL; // Initialize the next node as null
        while (curr!=NULL){ // Iterate until the current node reaches the end of the linked list
            next = curr->next; // Store the next node of the current node
            curr->next= prev; // Reverse the link of the current node
            prev = curr; // Move the previous node to the current node
            curr = next; // Move the current node to the next node
        }
        return prev; // Return the new head of the reversed list, which is the last node before the reversal
    }

    // Delete a node from the linked list at a given position
    void delete_node(Node **head_ref, int position){
        if (position >= length_node(*head_ref)) // If the position is greater than or equal to the length of the linked list, print an error message
            cout<<"Because position over length linked"<<endl;
        else {
            Node *temp = *head_ref;
            Node *prev = *head_ref;
            while(position-->0){ // Traverse the linked list to find the node at the given position
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next; // Remove the node by adjusting the link of the previous node
            free(temp); // Free the memory occupied by the deleted node
        }
    }

    // Print the middle node of the linked list
    void print_middle(Node *head_ref){
        int n = length_node(head_ref)/2; // Calculate the index of the middle node
        Node *temp = head_ref;
        while(n-- > 0){ // Traverse the linked list until the middle node is reached
            temp = temp->next;
        }
        cout<<"Printf middle node: "<< temp->data <<endl; // Print the data of the middle node
    }

    // Count the number of occurrences of a given key in the linked list
    int count_number(Node *head_ref, int key){
        Node *temp = head_ref;
        int count = 0;
        while(temp !=NULL ){ // Traverse the linked list until the end is reached
            if(temp->data == key){ // If the current node contains the given key, increment the count
                count++;
            }
            temp = temp->next; // Move to the next node
        }
        return count; // Return the count of occurrences of the key in the linked list
    }
};

// Driver's code
int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Process_node process ;

    // allocate 3 nodes in the heap
    head = new Node();
    second = new Node();
    third = new Node();
  
    head->data = 1; // assign data in first node
    head->next = second; // Link first node with second
  
    second->data = 2; // assign data to second node
    second->next = third;
  
    third->data = 3; // assign data to third node
    third->next = NULL;
    
    // Function call
    cout << "origin node: ";
    process.printList(head);
    
    cout << "push node: ";
    process.push(&head,4);
    process.printList(head);

    cout << "insert node after head_node: ";
    process.insertAfter(head,5);
    process.printList(head);
    
    cout << "add last node: ";
    process.append(head,6);
    process.printList(head);

    cout <<"search in linked:  ";
    process.search_node(head,7)?cout<<"yes":cout<<"no";
    cout<<endl;

    cout <<"search in linked:  ";
    process.search_node_recursive(head,3)?cout<<"yes":cout<<"no";
    cout<<endl;

    cout <<"len of linked: ";
    cout<< process.length_node(head)<< endl;
    
    cout << "Reversed linked ";
    head = process.reverse_iterative(head);
    process.printList(head);

    cout << "Delete Node: ";
    process.delete_node(&head,3);
    process.printList(head);

    process.print_middle(head);
    process.append(head,3);
    cout <<"Count the number of times: "<<process.count_number(head,3)<<endl;
    return 0;
}

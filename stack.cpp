#include <iostream>
using namespace std;
#define MAX_SIZE 5
class Node{
    public:
        int data;
        Node *link;
        Node(int n){
            this->data = n;
            this->link = NULL;
        }
};
class Stack{
    private:
        Node *top;
    public:
        Stack(){top =NULL; }
        void display(){
            Node *temp = top;
            cout <<"Stack: ";
            while(temp != NULL){
                cout << temp->data << "<= ";
                temp = temp->link;
            }
            cout << "NULL" << endl;
        }
        void push(int data){
            int n = length_Stack();
            if ( n > MAX_SIZE ){
                cout << "Stack Overflow "<<endl;
                exit(1);
            }
            else{
                Node *temp = new Node(data);
                if(!temp){
                    cout <<"\nStack Underflow";
                    exit(1);
                }
                temp->data;
                temp->link = top;
                top = temp;
            }
        }
        void pop(){
            if (top == NULL){
                cout <<"Stack Underflow";
                exit(1);
            }
            else{
                Node *temp= top;
                top = top->link;
                free(temp);
            }
        }
        int length_Stack(){
            Node *temp = top;
            int length;
            while(temp != NULL){
                length ++;
                temp = temp->link;
            }
            return length;
        }
};
int main(){
    Stack s;
    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    s.display();
    cout<<"After popping :";
    s.pop();
    s.display();

    s.push(11);
    s.push(22);
    s.push(33);
    s.push(44);
    cout <<"length of Stack: " << s.length_Stack() << endl;
}
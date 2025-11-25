//Infix to Postfix
#include<iostream>
using namespace std;
class MyStack{
    string result;
    int top;
    int size;
    public:
        MyStack(int s){
            top=-1;
            result = " ";
            size=s;
        }
        void push(int data){
            if(top==size-1){
                cout<<"Stack OverFlow"<<endl;
                return;
            }
            array[++top]=data;
        }
        int pop(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return array[top--];
        }
        int peek(){
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
                return -1;
            }
            return array[top];
        }
        void Display(){
             for(int i=top; i >= 0; i--) {
            cout << i << "->" << array[i] << endl;
        }
        }
};
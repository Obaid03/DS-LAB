#include <iostream>
using namespace std;
class Node{
    public:
    string data;
    Node* Next;
        Node(string d):data(d),Next(NULL){}
};
class MyStack{
    Node* Top;
    int count;
    public:
        MyStack(){
            Top=NULL;
            count=0;
        }
        void push(string x){
            Node* temp=new Node(x);
            temp->Next=Top;
            Top=temp;
            count++;
        }
        string pop(){
            if(Top==NULL){
                cout<<"Stack Underflow"<<endl;
                return "Null";
            }
            Node* temp=Top;
            Top=temp->Next;
            string val=temp->data;
            count--;
            delete temp;
            return val;
        }
        string seek(){
            if(Top==NULL){
                cout<<"Stack UnderFlow"<<endl;
                return "Null";
            }
            return Top->data;;
        }
        void Display(){
            if(Top==NULL){
                cout<<"Stack UnderFlow"<<endl;
                return;
            }
            Node* temp=Top;
            cout<<"Displaying Stack Data"<<endl;
            while(temp!=NULL){
                cout<<temp->data<<endl;
                temp=temp->Next;
            }
        }
};
int main(){
    MyStack S;
    //going in Forward Direction by pushing
    S.push("Home page Page");
    S.push("Fisrt Page");
    S.push("Second Page");
    S.push("Third Page");
    S.push("Fourth Page");
    //showing history by displaying
    cout<<"After Pushing"<<endl;
    S.Display();
    //going in backward direction by poping
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    cout<<"After Popping"<<endl;
    S.Display();
    //showing exact page by seeking
    cout<<"Current Page"<<endl;
    cout<<S.seek();
}


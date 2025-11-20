#include<iostream>
using namespace std;
class MyQueue{
    int *array;
    int Front;
    int capacity;
    public:
    MyQueue(int s){
        capacity=s;
        array=new int[s];
        Front=-1;
    }
    void Enqueue(int data){
        if(Front==capacity-1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        array[++Front]=data;
    }
    void Dequeue(){
        if(Front==-1){
            cout<<"Queue Already Empty"<<endl;
            return; 
        }
        for(int i=1;i<=Front;i++){
            array[i-1]=array[i];
        }
        Front--;
    }
    void Display(){
         if(Front==-1){
            cout<<"Queue Already Empty"<<endl;
            return; 
        }
        for(int i=0;i<=Front;i++){
            cout<<array[i]<<endl;
        }
    }
    bool isempty(){
        return Front==-1;
    }
    bool isfull(){
        return Front==capacity-1;
    }
};
int main(){
    MyQueue Q(5);
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    cout<<"After Pushing"<<endl;
    Q.Display();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    cout<<"After Popping"<<endl;
    Q.Display();

}
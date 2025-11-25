#include<iostream>
using namespace std;
class MyQueue{
    int *array;
    int Front;
    int Rear;
    int capacity;
    public:
    MyQueue(int s){
        capacity=s;
        array=new int[s];
        Front=0;
        Rear=-1;

    }
    void Enqueue(int data){
        if(isfull()){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        array[++Rear]=data;
    }
    void Dequeue(){
        if(isempty()){
            cout<<"Queue Already Empty"<<endl;
            return; 
        }
        Front++;
        if(Front>Rear){
            Front=0;
            Rear=-1;
        }
    }
    void Display(){
         if(isempty()){
            cout<<"Queue Already Empty"<<endl;
            return; 
        }
        for(int i=Front;i<=Rear;i++){
            cout<<array[i]<<endl;
        }
    }
    bool isempty(){
        return Front>Rear;
    }
    bool isfull(){
        return Rear==capacity-1;
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
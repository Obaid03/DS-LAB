#include <iostream>
using namespace std;
class Cqueue{
    int* array;
    int capacity;
    int Front;
    int Rear;
    public:
        Cqueue(int S){
            capacity=S;
            array=new int[S];
            Front=-1;
            Rear=-1;
        }
        void Enqueue(int data){
            if(isfull()){
                cout<<"Queue Already Full"<<endl;
                return;
            }
            if(Front==-1){
                Front=0;
            }
            Rear=(Rear+1)% capacity;
            array[Rear]=data;
            
        }
        void Dequeue(){
            if(isempty()){
                cout<<"Queue Already Empty"<<endl;
                return;
            }
            if(Rear==Front){
                Front=-1;
                Rear=-1;
                return;
            }
            Front=(Front+1)%capacity;

        }
        void Display(){
            if(isempty()){
                cout<<"Queue Already Empty"<<endl;
                return;
            }
            if(Rear>Front){
                for(int i=Front;i<capacity;i++){
                    cout<<array[i]<<" ->";
                }
            }
            if(Rear<=Front){
                for(int i=Front;i<capacity;i++){
                    cout<<array[i]<<" ->";
                }
                for(int i=0;i<=Rear;i++){
                    cout<<array[i]<<" ->";
                }
            }
            
        }
        bool isfull(){
            return (Rear+1)%capacity==Front;
        }
        bool isempty(){
            return Front==-1;
        }

};
int main(){
    Cqueue q(5);
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Enqueue(50);
    q.Display();
    cout<<endl;
    q.Dequeue();
    q.Enqueue(60);
    q.Display();
}
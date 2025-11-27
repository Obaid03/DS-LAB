#include<iostream>
using namespace std;
class MyStack{
    char* oper;
    int top;
    int size;
    public:
        MyStack(int s){
            top=-1;
            oper=new char[s];
            for(int i=0; i<s; i++){
                oper[i] = '\0';
            }
            size=s;
        }
        void push(char data){
            if(top==size-1){
                cout<<"Stack OverFlow"<<endl;
                return;
            }
            oper[++top]=data;
        }
        char pop(){
            if(top==-1){
                return '\0';
            }
            return oper[top--];
        }
        char peek(){
            if(top==-1){
                return '\0';
            }

            return oper[top];
        }
        bool empty(){
            return top==-1;
        }
        
};
int prec(char c){
    if (c=='+'||c=='-'){
                return 1;
            }
            else if (c=='*'||c=='/'){
                return 2;
            }
            else return 0;
        }
int isoperator(char c){
        if(c=='+'||c=='-'||c=='*'||c=='/'){
            return 1;
        }
        else return 0;
        }
string convert(string pre, MyStack &S){
            string result;
            int i=0;
            while(i<pre.length()){
                if(! isoperator(pre[i])){
                    result+=pre[i];
                }
                else{
                    while(!S.empty()&&prec(pre[i])<=prec(S.peek())){
                        result+=S.pop(); 
                        
                    }
                    S.push(pre[i]);            
                }
                i++;
            }
            while (!S.empty()) {
            result += S.pop();
            }
            
            return result;
        }
string reverse(string str){
    string temp;
    int l=str.length();
    for(int i=l-1;i>=0;i++){
        if(str[i]=='(') str[i]=')';
        else if(str[i]==')') str[i]='(';
        temp+=str[i];
    }
    return temp;
    
} 
int main(){
    MyStack S(10);
    string str="a+b*c-d/e";
    str=reverse(str);
    string prefix=convert(str,S);
    prefix=reverse(prefix);
    cout<<"preficx --> "<<prefix<<endl;
}
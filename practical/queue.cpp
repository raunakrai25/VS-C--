#include<bits/stdc++.h>
using namespace std;
#define N 5

int stack1[5], stack2[5];
int top1 = -1 , top2 = -1;
int coun = 0 ;

void push1(int data){
    if (top1 == N-1){
        cout << "\nStack Overflow !!!";
    }
    else {
        top1++;
        stack1[top1] = data;
    }
}

int pop1(){
    if (top1 == -1){
        cout << "\nStack Underflow !!!";
    }
    else{
        int a = stack1[top1];
        top1--;
        return a;
    }
}

void push2(int x){
    if (top2 == N-1){
        cout << "stack is Full";
    }
    else{
        top2++;
        stack2[top2] = x; 
    }
}

int pop2(){
    int element = stack2[top2];
    top2--;
    return element;   
}

void enqueue(int x){
    push1(x);
    coun++;
}

void dequeue(){
    if((top1==-1)&& (top2 == -1)){
        cout << "Queue is enpty";
    }
    else {
        for (int i=0; i<coun; i++){
            int element = pop1();
            push2(element);
        }
        int b = pop2();
        cout << "the Dequeued Element is : "<<b<<endl;
        coun--;

        for (int i=0; i<coun; i++){
            int a = pop2();
            push1(a);
        }
    }
}

void display(){
    for (int i=0; i<top1; i++){
        cout << stack1[i];
    }
}

int main(){
    int n,i;
  
    int data;
    

    char ch = 'y';
    int op;
    while (ch == 'y' ){
        cout << "What OPeration you wanna perform : \n";
        cout << "Enter (1) to display\nEnter (2) to Dequeue.\nEnter (3) to enqueue.";
        cin >> op;
        if (op == 1){
            display();
        }
        else if (op == 2){
            dequeue();
        }
        else if(op == 3){
            cout << "enter data:";
        cin>> data;
        enqueue(data);
        }
        else {
            cout << "\nPlease Enter Valid Choice !!";
        }
        cin >> ch;
    }
    
    return 0;
}
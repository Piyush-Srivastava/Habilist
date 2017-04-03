#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sqlite>

using namespace std;

class Habit{
    protected:
    char* task;
    int time;
    
    public:
    Habit(char *a,int t){
                
        task = a;
        time = t;
    }
    
};

class ToDo:public Habit{
    public:
    ToDo(char *a ,int t):task(a),time(t){}
    
    
    
}

void new_task(){
    Habit h1;
    ToDo d1;
    cout<<"Select the type of task:\n ";
    cout<<"1.Habit\n 2.To-Do\n";
    int ch;
    char* s[100];
    cin>>ch;
    int time;
    switch(ch)
    {
        case 1: cout<<"Enter the task: \n";
                cin>>s;
                cout<<"Enter the deadline in hours:\n";
                cin>>time;
                h1(s,time);
                break;
        
        case 2: cout<<"Enter the task:\n";
                cin>>s;
                cout<<"Enter the deadline in hours:\n";
                cin>>time;
                d1(s,time);
                break;
        
        default: cout<<"Invalid option\n";
        
                
                
                
    }
    
}

void sql_(){
    
}


int main()
{
    cout<<"Welcome to the Habilist\n";
    while(1){
    cout<<"Select your choice\n: ";
    cout<<"1.Enter a new task\n 2.Edit a task\n 3.Delete a task \n4.Display all tasks \n5.Exit\n";
    int ch;
    switch(ch)
    {
        case 1: void new_task();break;
                
        case 2: void edit_task();break;
        
        case 3: void delete_task();break:
        
        case 4: exit(0);
        
        default: exit(0);
    }
    
    
    }
    
}
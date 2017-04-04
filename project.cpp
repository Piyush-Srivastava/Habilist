#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
// #include <sqlite>

using namespace std;

class Habit{
    protected:
    string task;
    int time_;
    
    public:
    Habit(){
        task="";
        time_=0;
    }
    void get_habit(string a,int t){
        task=a;
        time_=t;
    }
    friend void new_task();
    friend void insert(Habit);
    
};

class ToDo{
    string task;
    int time_;
    
    public:
    ToDo(){task="";time_=0;}
    ToDo(string a ,int t){
        task=a;
        time_=t;
    }
    void get_ToDo(string a,int t){
        task=a;
        time_=t;
    }
    
    friend void new_task();
    
};

void new_task(){
    Habit h1;
    ToDo d1;
    cout<<"Select the type of task:\n ";
    cout<<"1.Habit\n 2.To-Do\n";
    int ch;
    string task;
    
    cin>>ch;
    int time_;
    switch(ch)
    {
        case 1: cout<<"Enter the task: \n";
                cin>>task;
                cout<<"Enter the deadline in hours:\n";
                cin>>time_;
                // ofstream habits("habits.txt");
                h1.get_habit(task,time_);
                insert(h1);
                break;
        
        case 2: cout<<"Enter the task:\n";
                cin>>task;
                cout<<"Enter the deadline in hours:\n";
                cin>>time_;
                d1.get_ToDo(task,time_);
                break;
        
        default: cout<<"Invalid option\n";
        
                
                
                
    }
    
}

void insert(Habit H){
    ofstream habits("habits.txt");
    habits<< H.task<<' '<<H.time_;
    
    
    
}


int main()
{   
    system("cls");
    system("title Habilist");
    // ofstreams habits("habits.txt");
    
    cout<<"       Welcome to the Habilist       \n";
    while(1){
    cout<<"Select your choice:\n ";
    cout<<"1.Enter a new task\n 2.Edit a task\n 3.Delete a task\n 4.Display all tasks\n 5.Exit\n";
    int ch;
    cin>>ch;
    
    
    switch(ch)
    {
        case 1: new_task();break;
                
        // case 2: void edit_task();break;
        
        // case 3: void delete_task();break:
        
        // case 4: exit(0);
        
        default: exit(0);
    }
    
    
    }
    
}
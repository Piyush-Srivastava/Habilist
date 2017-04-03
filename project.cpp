#include <iostream>
#include <cstdlib>
#include <fstream>

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
    
}

void new_task(){
    Habit h1;
    Daily d1;
    cout<<"Select the type of task:\n ";
    cout<<"1.Habit\n 2.Dailies\n";
    int ch;
    char* s[100];
    cin>>ch;
    int time;
    switch(ch)
    {
        case 1: cout<<"Enter the task: \n";
                cin>>s;
                h1(s,time);
                
                
    }
    
}


int main()
{
    cout<<"Welcome to the Habilist\n";
    cout<<"Select your choice\n: ";
    cout<<"1.Enter a new task\n 2.Edit a task\n 3.Delete a task\n";
    int ch;
    switch(ch)
    {
        case 1: void new_task();
                
        case 2: void edit_task();
        
        case 3: void delete_task();
        
        default: exit(0);
    }
    
    
    
    
}
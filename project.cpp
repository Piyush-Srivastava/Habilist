#include <iostream>
#include <cstdlib>
#include <fstream>

#include <cstring>
// #include <sqlite>

using namespace std;
int count = 0;

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
    friend void edit_task();
   void insert();
    
};

class ToDo:public Habit{
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
    void insert();
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
                h1.insert();
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

void Habit::insert(){
    count++;
    
    ofstream habits;
    habits.open("habits.txt",ios::app);
    habits<<count <<' '<< task<<' '<<time_<<endl;
    
    habits.close();
    
}

void edit_task()
{
    Habit h;
    ToDo d;
    int s_no;
    int id;
    string task;
    string newtask;
    int time;
    int newtime;
    
    fstream habits;
    habits.open("habits.txt",ios::in|ios::out);
    cout<<"Enter the task no. you wish to edit:\n";
    cin>>id;
    
    while(habits >> s_no >> task >>time)
    {
        int totallength = 1+task.length()+2+2; //use to move fptr back to replace the line
        if(id==s_no){
            cout<< s_no <<' '<< task <<' '<<time<<endl;
            cout<<"Is this the task you want to edit(y/n):\n";
            char ch;
            cin>>ch;
            if(ch=='y')
            {   
                habits.seekg(-totallength,ios::cur);
                cout<<"Enter the new task:\n";
                cin>>newtask;
                cout<<"Enter the new deadline:\n";
                cin>>newtime;
                
                habits << s_no <<' '<< newtask <<' '<<newtime<<endl;
            }
            
        }
        else{
            cout<<"Task not found\n";
        }
        
       
        }
    }



int main()
{   
    system("cls");
    system("title Habilist");
    
    
    cout<<"       Welcome to the Habilist       \n";
    while(1){
    cout<<"Select your choice:\n ";
    cout<<"1.Enter a new task\n 2.Edit a task\n 3.Delete a task\n 4.Display all tasks\n 5.Exit\n";
    int ch;
    cin>>ch;
    
    
    switch(ch)
    {
        case 1: new_task();break;
                
        case 2: edit_task();break;
        
        // case 3: void delete_task();break:
        
        // case 4: exit(0);
        
        default: exit(0);
    }
    
    
    }
    
}
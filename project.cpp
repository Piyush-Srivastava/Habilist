#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <istream>
// #include <chrono>
#include <time.h>
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
    friend void edit_task();
    friend void display_task();
    friend void delete_task();
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
    int s_no;
    ifstream habits("habits.txt");;
    string line;
    int count=1;
    while(getline(habits,line)){
        count++; //to read no. of lines for s.no.
    }
    habits.close();
    
    ofstream habit;
    habit.open("habits.txt",ios::app); //to append in the habits file
    habit<<count <<' '<< task<<' '<<time_<<endl;
    
    habit.close();
    
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
    int flag=0;
    
    ifstream habits;
    habits.open("habits.txt",ios::in|ios::out); 
    cout<<"Enter the task no. you wish to edit:\n";
    cin>>id;
    
    ofstream temp; //temporary file to write the data of habits.txt excluding the line to be edited
    temp.open("temp.txt",ios::out);
    
    while(habits >> s_no >> task >>time) //read from habits.txt line by line
    {
            
            if(id!=s_no){
                temp<< s_no<<' '<<task<<' '<<time<<endl; //write the data to temp file
                
            }
            
            else if(id==s_no){
                flag=1;
            cout<<s_no<<' '<<task<<' '<<time<<endl;
            cout<<"Is this the task you want to edit(y/n):\n";
            char ch;
            cin>>ch;
            if(ch=='y')
            {   
                cout<<"Enter the new task:\n";
                cin>>newtask;
                cout<<"Enter the new deadline:\n";
                cin>>newtime;
                
                temp << s_no <<' '<< newtask <<' '<<newtime<<endl; //write the new task to temp file
            }
            
        }
        
       
    }
        
         if(flag==0) //id not found
        {
            cout<<"Task not found\n";
        }
        temp.close();
        habits.close();
        remove("habits.txt"); //remove habits.txt
        rename("temp.txt","habits.txt"); //rename temp.txt to habits.txt
    }
    
    
void display_task(){
    int s_no;
    string task;
    int time;
    fstream habits;
    habits.open("habits.txt",ios::in); //read from file
    cout<<"S.no"<<setw(10)<<"Tasks"<<setw(20)<<"Deadline"<<endl<<endl;
    while(habits >>s_no >>task >>time){
        cout<<s_no<<setw(15)<<task<<setw(15)<<time<<endl;
        
    }
}


void delete_task()
{
    Habit h;
    ToDo d;
    int s_no;
    int id;
    int time_;
    string task;
    int flag=0;
    
    time_t now=time(0);
    struct tm *now_tm;
    int hour;
    int min;

    // now = time(0);
    now_tm = localtime(&now);
    hour = now_tm->tm_hour;
    min = now_tm->tm_min;
    
    if(min>30){
        hour=hour+1;
    }
    ifstream habits;
    habits.open("habits.txt",ios::in|ios::out); 
    cout<<"Enter the task no. you wish to delete:\n";
    cin>>id;
    
    ofstream temp; //temporary file to write the data of habits.txt excluding the line to be edited
    temp.open("temp.txt",ios::out);
    
    while(habits >> s_no >> task >>time_) //read from habits.txt line by line
    {
            
            if(id!=s_no){
                temp<< s_no<<' '<<task<<' '<<time_<<endl; //write the data to temp file
                
            }
            
            else if(id==s_no){
                flag=1;
            cout<<s_no<<' '<<task<<' '<<time_<<endl;
            cout<<"Is this the task you want to delete(y/n):\n";
            char ch;
            cin>>ch;
            if(ch=='y')
            {   
               if(time_>hour){
                   cout<<"Bravo! You finished the task on time\n";
                   
               }
               else{
                   cout<<"Oops! Looks like you coudn't finish the task on time\n";
               }
            }
            
        }

       
    }
        
         if(flag==0) //id not found
        {
            cout<<"Task not found\n";
        }
        temp.close();
        habits.close();
        remove("habits.txt"); //remove habits.txt
        rename("temp.txt","habits.txt"); //rename temp.txt to habits.txt
    
}


int main()
{   
    system("cls"); //to clear the output screen
    system("title Habilist"); //to display the name of the program at the top
    
    
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
        
        case 3: delete_task();break;
        
        case 4: display_task();break;
        
        default: exit(0);
    }
    
    
    }
    
}
#include<iostream>
#include<fstream>
using namespace std;

class list{
public:

    string taskName;
    string taskDiscription;
    bool status;
    string date;
    static int count;

    void print() {
        ifstream in("to.txt");
        string str;

        
        for(int i = 0; i < count; i++) {
            
            
            
            cout << i+1 << "):-" << endl;
            getline(in, str);
            cout << "  Task Name : " << str << endl;
            getline(in, str);
            cout << "  Description : " << str  << endl;
            getline(in, str);
            cout <<  "  Date : " << str << endl;
            getline(in, str);
            cout << "  Status : " << str << endl;
        }

        cout << endl;
        in.close();

    }

    void add() {
        
        count++;
        ofstream out("to.txt", ios::app);
        string str;
        cout << "Task : " << count << endl;
        cout << "Enter task name : ";
        cin.ignore();
        str = input();
        out << str << "\n";

        cout << "Enter task Detail : ";
        str = input();
        out << str << "\n";

        cout << "Enter task Date(DD-MM-YYYY) : ";
        str = input();
        out << str << "\n";

        out << "Pending" << "\n";

        out.close();

        cout << "Successfully added !! " << endl;
    }

    string input() {
        string str;
        
        getline(cin, str);
        
        return str;
    }

    void delChange(int num,bool change) {

        
        string str;
        ofstream out("temp.txt", ios::app);
        ifstream in("to.txt");

        for(int i = 0; i < count; i++) {
            if(i+1 == num && !change) {continue;}

            getline(in, str);
            out << str << "\n";
            getline(in, str);
            out << str << "\n";
            getline(in, str);
            out << str << "\n";
            getline(in, str);
            if((i+1 == num) && change) {
                out << "Completed" << "\n";
            } else {
                
                out << str << "\n";
            }

        }
        out.close();
        in.close();

        remove("to.txt");
        rename("temp.txt","to.txt");
        if(!change) {
            cout << "Task - " << num << " deleted successfully" << endl;
            count--;
        } else {
            cout << "Updated successfully" << endl;
        }

    }

    
    bool enter(bool n) {
        cout << "Total no of tasks : " << count << endl;
        
        int pos;
        if(n) {    
            cout << "Enter  task no for update : ";
            cin >> pos;
        } else {
            cout << "Enter  task no for Delete : ";
            cin >> pos;
        }

        if(pos<0 || pos > count) {
            return 0;
        } else if(n){
            delChange(pos, n);
        } else {
            delChange(pos, n);
        }
    }

};


int list::count = 0;

int main () {
    int x;
    
    do{
        cout << " 1 - Add Task : " << endl;
        cout << " 2 - Delete Task : " << endl;
        cout << " 3 - update status : " << endl;
        cout << " 4 - view tasks : " << endl;
        cout << " 0 - exit : " << endl << ":- "; 
        cin >> x ; 
        list l;
        
        if(x == 1) {
            l.add();
        } else if(x == 2) {
            
            if(l.enter(0) == 0){
                cout << "Entered wrong position : " << endl;
            }        
        } else if(x == 3){
            if(l.enter(1) == 0) {
                cout << "Entered wrong position : ";
            }
        } else if (x == 4) {
            l.print();
        } else if(x!=0){
            cout << "chose from avobe options " << endl;
        }

        

    }while(x);
    
    cout << "Thank you :)" << endl;
    ofstream("to.txt", ios::trunc);
        

    return 0;
}
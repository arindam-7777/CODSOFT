#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Guess{

public:
    int count = 0;
    int min, max;
    int random;

    Guess(int level) {
        if(level == 1) {
            easy();
        } else if(level == 2) {
            mid();
        } else {
            hard();
        }
    }

    void easy() {
        min = 0;
        max = 20;
        generate();
    }

    void mid() {
        min = 0;
        max = 50;
        generate();
    }

    void hard() {
        min = 0; 
        max = 100;
        generate();
    }

    void generate(){
        srand(time(0));
        random = rand() % (max - min + 1) + min;
        check();
    }



    void check() {
        int user;
        cout << "Range is - " << min << " - " << max << " " << endl;
        cout << "Guess the number  :  : ";
        cin >> user; 

        do {
            if(user > random) {
                cout << " Your number is greater " << endl << endl;
            } else if (user < random){
                cout << " Your number is lesser " << endl << endl;
            }

            if(user != random) {
                cout << "Enter again : ";
                cin >> user;
            }
        }while(user != random);

        cout << " Congratulations !!! you got it : " << endl << endl;
    }


};




int  main() {
    int x;

    do {
        cout << "Enter : - " << endl;
        cout << " 1 - for play : " << endl;
        cout << " 0 - for exit : " << endl;
        cout << " :- ";
        cin >> x;

        if(x == 1){
            int lev;
            
            for(int i = 0 ; i < 1; i++) {

            
                cout << "Select level : " << endl;
                cout << "  Easy - 1 : " << endl;
                cout << "  Medium - 2 : " << endl;
                cout << "  Hard - 3 : " << endl;
                cout << "Enter : - ";
                cin >> lev;

                if(lev <= 0 || lev > 3) {
                    i--;
                    cout << "Entered only given options :( " << endl;
                }else {
                    Guess g(lev); 
                }

            }

        } else if(x != 0) {
            cout << " Error 404 :) " << endl;
        }

    }while(x);

    cout << "Thank you !!!!!" << endl;

    return 0;

}


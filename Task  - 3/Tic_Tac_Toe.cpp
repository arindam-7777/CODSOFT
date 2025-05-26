#include<iostream>
using namespace std;


int winnerFound = 0;

class TicTacToe{

public:

char grid[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row = 3;
int col = 3;



string player1, player2;
char choiceP1, choiceP2;
 



TicTacToe() {
    cout << "Enter name of first player : ";
    getline(cin, player1);
    
    cout << "Enter name of second player : ";
    getline(cin, player2);

    cout << " enter 1 or 2 for choice : ( player 1 or player 2 ) : ";
    int sel;
    cin >> sel;

    
    if(sel == 1){
    
        cout << "enter choice for player 1( " << player1 << " ) O / X  : " ;
        cin.ignore();
        char c = getchar();
        cin.ignore(); 

        if(c == 'o' || c == 'O') {
            choiceP1 = 'O';
            choiceP2 = 'X';
            cout << "for player 2( " << player2 << " ) - ' X ' is selected :" << endl;
        } else {
            choiceP1 = 'X';
            choiceP2 = 'O';
            cout << "for player 2( " << player2 << " ) - ' O ' is selected :" << endl;
        }

    } else {
        cout << "enter choice for player 2( " << player2 << " ) O / X  : " ;
        cin.ignore();
        char c1 = getchar();
        cin.ignore(); 

        if(c1 == 'o' || c1 == 'O') {
            choiceP2 = 'O';
            choiceP1 = 'X';
            cout << "for player 1( " << player1 << " ) - ' X ' is selected :" << endl;
        } else {
            choiceP2 = 'X';
            choiceP1 = 'O';
            cout << "for player 1( " << player1 << " ) - ' O ' is selected :" << endl;
        }
    }

    print();


}

void print() {

    for(int i = 0; i < row; i++) {                                                        
        cout << "      |     |      " << endl; 
        cout << " ";                                             
        for(int j = 0 ; j < col; j++){                                            
            
            cout << "  " << grid[i][j]  << "  ";
            if(j < 2) {
                cout << "|";
            }
            
        }
        cout << endl;
        
        if(i < 2){
            cout << "______|_____|______" << endl;
        } else { 
            cout << "      |     |      " << endl;
        }
    }
}
    
    void change(int pos, char ch) {
        
        if(pos < 4) {
            grid[0][pos-1] = ch;  
        } else if(pos < 7) {
            grid[1][pos-4] = ch;
        } else {
            grid[2][pos-7] = ch;
        }
        
    }
    

    void check() {
        for(int i = 0; i < row; i++) {
            
            if ( ( grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2])) {
                winner(grid[i][0]);
            }

            if ( (grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i])) {
                winner(grid[0][i]);
            }            
        }

        if(grid[0][0] == grid[1][1] && grid[2][2] == grid[1][1]) {
            winner(grid[1][1]);
        }

        
        if(grid[0][2] == grid[1][1] && grid[2][0] == grid[1][1]) {
            winner(grid[1][1]);
        }
    
    }

    void winner(char win) {
        
        if(win == choiceP1) {
            cout << player1 << " is the winner !!!!!! " << endl;
            
        } else {
            cout << player2 << " is the winner !!!!!! " << endl;
        }
        winnerFound = 1;
    }

    int find(int pos) {
        int i , j;

        if(pos < 4) {
            i = 0; 
            j = pos-1; 
        } else if(pos < 7) {
            i = 1;
            j = pos-4;
        } else {
            i = 2;
            j = pos-7;
        }

        if(grid[i][j] != 'O' && grid[i][j] != 'X')return true;
        
        return false;
    }

};




int main() {

    while(true) {
        char ch;

        cout << "Do you want to play ( For yes - Y/y & For no - n/N ) : ";
        ch = getchar();
        cin.ignore();
        
        if(ch == 'Y' || ch == 'y'){// 0p1  1p2 2p1 3p2 4p1 5p2 6p1 7p2 8p1; 
            TicTacToe t1;

            for (int i=0; i<9; i++) {
                int pos;
                
                
                if(i%2 == 0) {
                    cout << " Turn of "<< t1.player1 << " ( " << t1.choiceP1 << " ) :" << endl;
                    cout << " Enter position (1 - 9) : ";
                    cin >> pos;

                    if(t1.find(pos) && pos <= 9) {
                        t1.change(pos, t1.choiceP1); 
                        t1.print();
                        t1.check();

                        if(winnerFound){
                            break;
                        } 
                    } else if(pos > 9) {
                        cout << " out of range \n";
                        i--;
                    } else{
                        cout << "Already used \n";
                        i--;
                    }   

                } else {
                    cout << " Turn of "<< t1.player2 << " ( " << t1.choiceP2 << " ) :" << endl;
                    cout << " Enter position (1 - 9) : ";
                    cin >> pos;

                    if(t1.find(pos) && pos <= 9) {
                        t1.change(pos, t1.choiceP2); 
                        t1.print();
                        t1.check();

                        if(winnerFound){
                            break;
                        } 
                    } else if(pos > 9) {
                        cout << " out of range \n";
                        i--;
                    } else{
                        cout << "Already used \n";
                        i--;
                    }
                }
            }

            if(!winnerFound) {
                cout << "It's a draw \n"  << endl;
            }
        } else {
            cout << "Thank you !" << endl;
            break;
        }
    }

   
    

    return 0;
}
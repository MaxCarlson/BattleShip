/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: C-60
 *
 * Created on May 19, 2017, 8:43 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */

class Ocean
{
public:
    char playerOcean[10][10];
    char aiOcean[10][10];
    
    Ocean(){
        for(int i= 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                playerOcean[i][j] = '~';
            }
        }
        for(int i= 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                aiOcean[i][j] = '~';
            }
        }
    }
    
    void playerPlace(){
        cout << "Place your four battle ships! (battleship length of three)" << endl;
        
        for(int i = 0; i < 4; i++){
            cout << "Enter the top left most coordinate of ship Y: 0-9 / X: 0-9 (no spaces) " << endl;
            cout << "Ex: Y1 X2 = 12"
            int c, c1;
            cin >> c;
            cout << "Enter direction your ship is facing 'N' or 'E' " << endl;
            char d;
            cin >> d;
            c1 = c%10;
            c /= 10;
            if(d == 'N'){
                playerOcean[c][c1] = 'B';
                playerOcean[c+1][c1] = 'B';
                playerOcean[c+2][c1] = 'B';
                
            } else if (d == 'E'){
                playerOcean[c][c1] = 'B';
                playerOcean[c][c1+1] = 'B';
                playerOcean[c][c1+2] = 'B'; 
            }
            
            printPlayerOcean();
            
        }
    }
    
    void printPlayerOcean(){
        cout << "  ";
        for(int i = 0; i < 10; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < 10; i++){
            cout << i << " ";
            for(int j = 0; j < 10; j++){
                cout << playerOcean[i][j] << " ";
            }
            std::cout << endl;
        }
    }
    
    
    
    
    
};


int main(int argc, char** argv) {
    
    
    //Ocean* newOcean = new Ocean();
    //newOcean->printOcean;
    
    Ocean newOcean;
    
    newOcean.playerPlace();
    newOcean.printPlayerOcean();
    
    

    return 0;
}


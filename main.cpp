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
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
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
        cout << "Place your four battle ships! (battleship length of four)" << endl;
        int i = 0;
        do{
            cout << "Enter the top left most coordinate of ship X: 0-9 / Y: 0-9 (no spaces) " << endl;
            cout << "Ex: Y1 X2 = 12" << endl;
            int c, c1;
            cin >> c;
            cout << "Enter direction your ship is facing 'N' or 'E' " << endl;
            char d;
            cin >> d;
            c1 = c / 10;
            c = c%10;
            if(d == 'N' && c < 7){
                if(playerOcean[c][c1]!='B'&&playerOcean[c+1][c1]!='B'&&playerOcean[c+2][c1]!='B'&&playerOcean[c+3][c1]!='B'){
                    playerOcean[c][c1] = 'B';
                    playerOcean[c+1][c1] = 'B';
                    playerOcean[c+2][c1] = 'B';
                    playerOcean[c+3][c1] = 'B';
                    ++i;
                }
                
            } else if (d == 'E' && c1 < 7){
                if(playerOcean[c][c1]!='B'&&playerOcean[c][c1+1]!='B'&&playerOcean[c][c1+2]!='B'&&playerOcean[c][c1+3]!='B'){
                    playerOcean[c][c1] = 'B';
                    playerOcean[c][c1+1] = 'B';
                    playerOcean[c][c1+2] = 'B'; 
                    playerOcean[c][c1+3] = 'B';
                    ++i;
                }
            } else {
                cout << "Invalid Placement, try again" << endl;
            }
            
            printPlayerOcean();
            
        }while(i<4);
    }
    
    void aiPlace(){
        printAiOcean();
        int xR , yR, i = 0;
        srand(time(NULL));

        do{
            xR = rand() % 10;
            yR = rand() % 10;
            bool N = rand() % 2;
            if(N == true && yR < 7){
                if(aiOcean[yR][xR] != 'B' && aiOcean[yR+1][xR]!= 'B'&& aiOcean[yR+2][xR]!='B'&&aiOcean[yR+3][xR]!='B'){
                    aiOcean[yR][xR] = 'B';
                    aiOcean[yR+1][xR] = 'B';
                    aiOcean[yR+2][xR] = 'B';
                    aiOcean[yR+3][xR] = 'B';
                    i++;
                }
            } else if(N == false && xR < 7){
                if(aiOcean[yR][xR] != 'B' && aiOcean[yR][xR+1]!= 'B'&& aiOcean[yR][xR+2]!='B'&&aiOcean[yR][xR+3]!='B'){
                    aiOcean[yR][xR] = 'B';
                    aiOcean[yR][xR+1] = 'B';
                    aiOcean[yR][xR+2] = 'B';
                    aiOcean[yR][xR+3] = 'B';
                    i++;
                }
            } 
            printAiOcean();
        } while(i < 4);
        
        
        
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
            cout << endl;
        }
    }
    
    void printAiOcean(){
        cout << "  ";
        for(int i = 0; i < 10; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < 10; i++){
            cout << i << " ";
            for(int j = 0; j < 10; j++){
                cout << aiOcean[i][j] << " ";
            }
            cout << endl;
        }
        
    }  
};


int main(int argc, char** argv) {
    
    
    //Ocean* newOcean = new Ocean();
    //newOcean->printOcean;
    
    Ocean newOcean;
    
    //newOcean.playerPlace();
    newOcean.aiPlace();
    
    

    return 0;
}


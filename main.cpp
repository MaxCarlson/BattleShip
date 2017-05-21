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
#include <ctype.h>
using namespace std;

/*
 * 
 */

class Ocean
{
public:
    char playerOcean[10][10];
    char aiOcean[10][10];
    char playerHMOcean[10][10];
    int playerHits = 0;
    int aiHits = 0;
    
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
        for(int i= 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                playerHMOcean[i][j] = '~';
            }
        }
    }
    
    void playerPlace(){
        cout << "Place your four battle ships! (battleship length of four)" << endl;
        int i = 0;
        do{
            cout << "Enter the top left most coordinate of ship X: 0-9 / Y: 0-9 (no spaces) " << endl;
            cout << "Ex: X=1 Y=2 = 12" << endl;
            int c, c1;
            cin >> c;
            cout << "Enter direction your ship is facing 'N' or 'E' " << endl;
            char d;
            cin >> d;
            c1 = c / 10;
            c = c%10;
            if(tolower(d) == 'n' && c < 7){
                if(playerOcean[c][c1]!='B'&&playerOcean[c+1][c1]!='B'&&playerOcean[c+2][c1]!='B'&&playerOcean[c+3][c1]!='B'){
                    playerOcean[c][c1] = 'B';
                    playerOcean[c+1][c1] = 'B';
                    playerOcean[c+2][c1] = 'B';
                    playerOcean[c+3][c1] = 'B';
                    ++i;
                } else {
                    cout << "Invalid Placement, try again" << endl;
                } 
            } else if (tolower(d) == 'e' && c1 < 7){
                if(playerOcean[c][c1]!='B'&&playerOcean[c][c1+1]!='B'&&playerOcean[c][c1+2]!='B'&&playerOcean[c][c1+3]!='B'){
                    playerOcean[c][c1] = 'B';
                    playerOcean[c][c1+1] = 'B';
                    playerOcean[c][c1+2] = 'B'; 
                    playerOcean[c][c1+3] = 'B';
                    ++i;
                } else {
                    cout << "Invalid Placement, try again" << endl;
                }
            } else {
                cout << "Invalid Placement, try again" << endl;
            }
            
            printPlayerOcean();
            
        }while(i<4);
        printPlayerHMOcean();
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
            //printAiOcean();
        } while(i < 4);
        
        
        
    }
    
    void playerAttack(){
        cout << "Enter attack coordinate, no spaces x/y" << endl;
        int aC;
        cin >> aC;
        int x = aC / 10;
        int y = aC%10;
        if(aiOcean[y][x] == 'B'){
            aiOcean[y][x] = 'H';
            playerHMOcean[y][x] = 'H';
            playerHits += 1;
            cout << "You hit the enemy's ship!" << endl;
        } else if(aiOcean[y][x]=='~'){
            playerHMOcean[y][x]='M';
            cout << "You missed!" << endl;
        }
        
    }
    
    void aiAttack(){
        bool notHit = false;
        srand(time(NULL));
        do{
            int y = rand() % 10;
            int x = rand() % 10;
            if(playerOcean[y][x] == 'B'){
                playerOcean[y][x] = 'H';
                cout << "The enemy hit your battleship!" << endl;
                aiHits += 1;
                notHit = false;
            } else if(playerOcean[y][x]== 'H'){
                notHit = true;
            } else if(playerOcean[y][x] == '~'){
                playerOcean[y][x] = 'M';
                cout << "The enemy missed!" << endl;
                notHit = false;
            }
        }while(notHit);
        
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
    void printPlayerHMOcean(){ //player ocean + hit miss ocean
        cout << "Player Ocean" << "                " << "Player Hits Ocean" << endl;
        cout << "  ";
        for(int i = 0; i < 10; i++){
            cout << i << " ";
        }
        cout << "        ";
        for(int i = 0; i < 10; i++){
            cout << i << " ";
        }
        cout << endl;
        for(int i = 0; i < 10; i++){
            cout << i << " ";
            for(int j = 0; j < 10; j++){
                cout << playerOcean[i][j] << " ";
            }
            cout << "      ";
            cout << i << " ";
            for(int j = 0; j < 10; j++){
                cout << playerHMOcean[i][j] << " ";
            }
            cout << endl;
        }  
    }
    
    void game(){
        char playAgain = 'y';
        while(playAgain == 'y'){
            aiPlace();
            playerPlace();
            while(playerHits < 16 && aiHits < 16){
                playerAttack();
                if(playerHits >= 16){
                    cout << "You Win!!! Play Again? y/n";
                    cin >> playAgain;
                    if(playAgain =='n'){
                        exit(0);
                    } else if(playAgain != 'n' || playAgain != 'y'){
                        cout << "That's not a 'y' or 'n' enter either or to play again or quit" << endl;
                        cin >> playAgain;
                    }
                    continue;
                }
                aiAttack();
                if(aiHits >= 16){
                    cout << "You Lose :( . Play Again? y/n";
                    cin >> playAgain;
                    if(playAgain =='n'){
                        exit(0);
                    } else if(playAgain != 'n' || playAgain != 'y'){
                        cout << "That's not a 'y' or 'n' enter either or to play again or quit" << endl;
                        cin >> playAgain;
                    }
                    continue;    
                }
                printPlayerHMOcean();
            }
        }
    }
    
    
    
};


int main(int argc, char** argv) {
    
    
    //Ocean* newOcean = new Ocean();
    //newOcean->printOcean;
    
    Ocean newOcean;
    
    //newOcean.playerPlace();
    //newOcean.aiPlace();
    //newOcean.printPlayerHMOcean();
    newOcean.game();
    
    

    return 0;
}


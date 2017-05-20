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

using namespace std;

/*
 * 
 */

class Ocean
{
public:
    char ocean[10][10];
    
    Ocean(){
        for(int i= 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                ocean[i][j] = '~';
            }
        }
    }
    
    void playerPlace(){
        
    }
    
     printOcean(){
        
        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cout << ocean[i][j];
            }
            cout << endl;
        }
    }
    
    
    
    
    
};


int main(int argc, char** argv) {
    
    Ocean* newOcean = new Ocean();
    
    newOcean->printOcean;

    return 0;
}


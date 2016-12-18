/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Christoph
 *
 * Created on 16. Dezember 2016, 21:56
 */

#include <string>
#include <iostream>
#include <utility>
#include "futil.h"
#include "sorting.h"
#include "graphics.h"
#include "menu.h"
using namespace std;

enum menu_actions {
    SHOW_DATA=1,
    QUIT
};

int main(int argc, char** argv) {
    int n;
    int* a;
    char* chars;
    int action;
    do {
        try{
        string name = filename();
        a = new int[n] {
        };
        chars = menu(n);
        string file = file_lines(name);
        for (int i = 0; i < n; i++) a[i] = count_char(file, chars[i]);
        action = menu_action();
        switch (action) {
            case SHOW_DATA:
                show_data_horizontally(a, n);
                for (int i = 0; i < n; i++) cout << chars[i];
                break;
            case QUIT:
                break;
        }
        cout << endl;
        }catch(...){
            cout << "invalid input";
        }
    } while (action != 2);

    delete[] a;
    delete[] chars;
    a = NULL;
    chars = NULL;
    return 0;
}


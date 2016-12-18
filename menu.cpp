/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   menu.cpp
 * Author: Christoph
 * 
 * Created on 18. Dezember 2016, 22:00
 */
#include <string>
#include <iostream>
#include "menu.h"
using namespace std;


string filename() {
    string filename;
    cout << "Enter the file's name: ";
    cin >> filename;
    return filename;
}

char* menu(int& n) {
    int cnt;
    cout << "Enter the numbers of chars u r searching for: ";
    cin >> cnt;
    n = cnt;
    char* chars = new char[cnt] {
    };
    cout << "Enter the chars u r searching for:  (seperated by a space)";
    for (int i = 0; i < cnt; i++)cin >> chars[i];
    return chars;
}

int menu_action() {
    string action;
    string actions[]{"(1) show Data horizontally", "(2) Quit"};
    for (int i = 0; i < 2; i++) cout << actions[i] << endl;
    cin >> action;
    return stoi(action);
}

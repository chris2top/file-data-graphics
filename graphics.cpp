/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   graphics.cpp
 * Author: Christoph
 * 
 * Created on 18. Dezember 2016, 21:59
 */
#include <iostream>
#include "graphics.h"
#include "sorting.h"
using namespace std;

void show_data_vertically(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) cout << "*";
        cout << endl;
    }
}

void show_data_horizontally(int a[], int n) {
    int m = max(a, n);
    for (int i = m; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (a[j] >= i)cout << "+";
            else cout << " ";
        }
        cout << endl;
    }
}

int count_char(string file, char c) {
    int cnt = 0;
    for (auto s : file) if (s == c)cnt++;
    return cnt;
}

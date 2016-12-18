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
using namespace std;

void bubble(int a[], int n) { //iteral
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

void bubble(int a[], int n, int i) { //recursive with 1 for
    if (i < n - 1) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
        bubble(a, n, ++i);
    }
}

void bubble(int a[], int n, int i, int j) { // recursive
    if (i < n - 1) {
        if (j < n - 1) {
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
            bubble(a, n, i, ++j);
        }
        bubble(a, n, ++i, j);
    }
}

void insertion(int a[], int n) { //iteral
    int i = 0;
    while (i < n) {
        int j;
        int temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--) a[j] = a[j - 1];
        a[j] = temp;
        i++;
    }
}

void insertion(int a[], int n, int i) { //recursive
    if (i < n) {
        int j;
        int temp = a[i];
        for (j = i; j > 0 && a[j - 1] > temp; j--) a[j] = a[j - 1];
        a[j] = temp;
        insertion(a, n, ++i);
    }
}

void selection(int a[], int n) { //iteral
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[min])
                min = k;
        }
        swap(a[min], a[i]);
    }
}

void selection(int a[], int n, int i) { //recursive doe 1 for 
    int min;
    if (i < n - 1) {
        min = i;
        for (int k = i + 1; k < n; k++) {
            if (a[k] < a[min]) min = k;
        }
        swap(a[min], a[i]);
        selection(a, n, ++i);
    }
}

void selection(int a[], int n, int i, int j) { //recursive  working?
    int min;
    if (i < n - 1) {
        min = i;
        if (j < n) {
            if (a[j] < a[min]) min = j;
            selection(a, n, i, ++j);
        }
        swap(a[min], a[i]);
        selection(a, n, ++i, j);
    }
}

int divide(int a[], int start, int end) {
    int pivot = a[end];
    int i = start - 1;
    for (int j = start; j < end; j++) {
        if (a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[end]);
    return i + 1;
}

void quicksort_(int a[], int start, int end) {
    if (start < end) {
        int p = divide(a, start, end);
        quicksort_(a, start, p - 1);
        quicksort_(a, p + 1, end);
    }
}

void quicksort(int a[], int n) {
    quicksort_(a, 0, n - 1);
}

int min(int a[], int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) if (a[i] < a[0]) min = a[i];
    return min;
}

int max(int a[], int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) if (a[i] > a[0]) max = a[i];
    return max;
}

int* rev(int a[], int n) { //iteral
    int* rev = new int[n] {
    };
    int cnt = n;
    for (int i = 0; i < n; i++) {
        cnt--;
        rev[i] = a[cnt];
    }
    return rev;
}

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


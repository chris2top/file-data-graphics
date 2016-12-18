/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sorting.cpp
 * Author: Christoph
 * 
 * Created on 18. Dezember 2016, 21:54
 */


#include <utility>
#include "sorting.h"
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

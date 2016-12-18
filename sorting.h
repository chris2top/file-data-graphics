/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   sorting.h
 * Author: Christoph
 *
 * Created on 18. Dezember 2016, 21:54
 */

#ifndef SORTING_H
#define SORTING_H
void bubble(int a[], int n);
void bubble(int a[], int n, int i);
void bubble(int a[], int n, int i, int j);
void insertion(int a[], int n);
void insertion(int a[], int n, int i);
void selection(int a[], int n);
void selection(int a[], int n, int i);
void selection(int a[], int n, int i, int j);
void quicksort(int a[], int n);
int min(int a[], int n);
int max(int a[], int n);
int* rev(int a[], int n);
#endif /* SORTING_H */

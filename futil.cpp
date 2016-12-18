/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   futil.cpp
 * Author: Christoph
 * 
 * Created on 16. Dezember 2016, 22:05
 */

#include "futil.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void w_file(string fname, string cont[], int n){
    ofstream infile;
    infile.open(fname);
    if (infile.fail()) perror(fname.c_str());//!
    for(int i=0;i<n;i++)infile << cont[i] << endl;
    infile.close(); 
}

string* r_file(string filename, int &n){
    ifstream infile(filename);//!
    int cnt = 0;
    string line;
    while(getline(infile, line)) cnt++;//!

    string* contents = new string[cnt];

    infile.clear();//!
    infile.seekg(0);//!

    for (int i=0; i<cnt; ++i) {
        getline(infile, line);//!
        contents[i] = line;
    }

    infile.close();//!
    n = cnt;
    return contents;
}

string file_lines(string filename){
    ifstream infile(filename);
    string line, flines;
    while(getline(infile, line)) flines += line;
    return flines;
}

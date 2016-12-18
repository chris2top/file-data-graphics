/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   futil.h
 * Author: Christoph
 *
 * Created on 16. Dezember 2016, 22:05
 */

#ifndef FUTIL_H
#define FUTIL_H
#include <string>

void w_file(std::string fname, std::string cont[], int n);
std::string* r_file(std::string name, int& n);
std::string file_lines(std::string filename);
#endif /* FUTIL_H */

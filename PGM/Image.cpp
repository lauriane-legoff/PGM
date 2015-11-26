/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.cpp
 * Author: eleve
 * 
 * Created on 26 novembre 2015, 10:54
 */
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <fstream>

#include "Image.h"

using namespace std;

Image::Image() {
    
}



Image::~Image() {
}

void Image::ecriture (){
    
    ofstream file(path.c_str());
    ostream_iterator<double> itf(file);
    
    file << "P2" << endl << "#" << endl << largeur << " " << hauteur << endl << "255" << endl;
    
    for(int i = 0 ; i < hauteur ; i++)
    {
        for(int j = 0 ; j < largeur ; j++)
        {
            file << image.at(i).at(j) << "\t";
        }
        file << endl;
    }
}
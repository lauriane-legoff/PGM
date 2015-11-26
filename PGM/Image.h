/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Image.h
 * Author: eleve
 *
 * Created on 26 novembre 2015, 10:54
 */


#ifndef IMAGE_H
#define IMAGE_H
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

class Image {

private :
    int largeur;
    int hauteur;
    string path;
    vector<vector<int> > image;
    Image* histogramme;
public :
    Image();
    void lecture(string);
    void ecriture();
    void createHistogramme();
    
    int getLargeur () {return largeur;};
    int getLongueur() {return hauteur;};
    string getPath () {return path;};
    vector<vector<int> > getImage () {return image;};
    Image* getHisto () {return histogramme;};
    
    void setPath(string s) {path = s;};
   
    
   
    virtual ~Image();


};

#endif /* IMAGE_H */


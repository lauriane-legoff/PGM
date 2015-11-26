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

#include "Image.h"
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include<fstream>
#include <iterator>
using namespace std;


Image::Image() {
    
}

Image::~Image() {
}



void Image::lecture(string nom_fichier){
    string p, diese;
    int teinte_max;
    int i,j;
    ifstream fichier(nom_fichier.c_str(), ios::in);  // on ouvre le fichier en lecture
    if(fichier)  // si l'ouverture a réussi
    {       
        fichier>>p;
        fichier>>diese;
        fichier>>largeur;
        fichier>>hauteur;
        fichier>>teinte_max;
        vector<int> ligne(largeur,0);
        vector<vector<int> > image_2(hauteur, ligne);
        image= image_2;
        for(i=0; i<hauteur; i++){
            for(j=0; j<largeur; j++){
                fichier>>image[i][j];
            }
        }
        fichier.close();  // on ferme le fichier
    }
    else  // sinon
    {        
        cout << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Image::ecriture (string nom_fichier){
    
    ofstream file(nom_fichier.c_str());
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
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
#include <fstream>
#include <iterator>
#include <limits>
#include <cmath>

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
        fichier.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // on ignore le commentaire s'il y en a un
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

void Image::createHistogramme()
{
	float nbValeurs[256] = { 0 };
	histogramme = new Image();
	histogramme->setLargeur(256);
	histogramme->setHauteur(70);

	for(int i = 0 ; i < hauteur ; i++)
		for(int j = 0 ; j < largeur ; j++)
			nbValeurs[image[i][j]]++;

	float maxVal = 0;
	for(int i = 0 ; i < 256 ; i++)
		if(nbValeurs[i] > maxVal)
			maxVal = nbValeurs[i];

	// on met les valeurs entre 0 et 70
	for(int i = 0 ; i < 256 ; i++)
		nbValeurs[i] *= 70.0/maxVal;

	// on crée l'image de l'histogramme
	vector<vector<int> > imgHisto;
	for(int i = 0 ; i < 70 ; i++)
	{
		vector<int> aAjouter;
		for(int j = 0 ; j < 256 ; j++)
		{
			if(i > 70 - nbValeurs[j])
				aAjouter.push_back(255);
			else
				aAjouter.push_back(0);
		}
		imgHisto.push_back(aAjouter);
	}

	histogramme->setDonneesImage(imgHisto);
}

// x: nouvelle largeur, y: nouvelle hauteur
void Image::redimmension(int x, int y)
{
	vector< vector<int> > newImage;

	for(int i = 0 ; i < y ; i++)
	{
		vector<int> ligne;
		for(int j = 0 ; j < x ; j++)
		{
			// on copie le pixel qui correspond au plus proche de l'image source
			ligne.push_back(image[round((float)i/y*(hauteur-1))][round((float)j/x*(largeur-1))]);
		}
		newImage.push_back(ligne);
	}

	image = newImage;
	largeur = x;
	hauteur = y;
}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: eleve
 *
 * Created on 26 novembre 2015, 12:41
 */

#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include<fstream>
#include "Image.h"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    Image lena;
    lena.lecture("lena.pgm");
    lena.ecriture("test.pgm");
    lena.createHistogramme();
    lena.getHisto()->ecriture("histogramme.pgm");

    return 0;
}


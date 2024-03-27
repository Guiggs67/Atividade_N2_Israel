#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>
#include "PESSOA.h"

using namespace std;

#ifndef CALCULOS_H
#define CALCULOS_H

#include <string>
#include <vector>

class Calculos {
public:
    static double calcularMedia(const std::vector<float>& valores);
    static double calcularMediana(std::vector<float> valores);
    static double calcularDesvioPadrao(const std::vector<float>& valores);
    static void calcularEstatisticasCSV(const std::string& filename, int indiceAtributo);
};

#endif

#include "Calculos.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

double Calculos::calcularMedia(const vector<float>& valores) {
    double soma = 0.0;
    for (float valor : valores) {
        soma += valor;
    }
    return soma / valores.size();
}

double Calculos::calcularMediana(vector<float> valores) {
    sort(valores.begin(), valores.end());
    if (valores.size() % 2 == 0) {
        int meio = valores.size() / 2;
        return (valores[meio - 1] + valores[meio]) / 2.0;
    }
    else {
        return valores[valores.size() / 2];
    }
}

double Calculos::calcularDesvioPadrao(const vector<float>& valores) {
    double media = calcularMedia(valores);
    double somaDiferencasQuadrado = 0.0;
    for (float valor : valores) {
        somaDiferencasQuadrado += pow(valor - media, 2);
    }
    double variancia = somaDiferencasQuadrado / valores.size();
    return sqrt(variancia);
}

void Calculos::calcularEstatisticasCSV(const string& filename, int indiceAtributo) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo " << filename << endl;
        return;
    }

    string line;
    vector<float> valores;

    // Lê o arquivo linha por linha
    while (getline(file, line)) {
        stringstream ss(line);
        string field;

        // Ignora as primeiras linhas (caso haja cabeçalho)
        if (line.find("Nome") != string::npos)
            continue;

        // Armazena os campos de cada linha
        vector<string> fields;
        while (getline(ss, field, ';')) {
            fields.push_back(field);
        }

        // Converte o campo numérico para float e o armazena
        float valor = stof(fields[indiceAtributo]);
        valores.push_back(valor);
    }

    file.close();

    // Calcula média, mediana e desvio padrão para os valores
    double media = calcularMedia(valores);
    double mediana = calcularMediana(valores);
    double desvioPadrao = calcularDesvioPadrao(valores);

    // Exibe os resultados
    cout << "Estatísticas para o atributo no índice " << indiceAtributo << ":" << endl;
    cout << "Média: " << media << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Desvio padrão: " << desvioPadrao << endl;
}

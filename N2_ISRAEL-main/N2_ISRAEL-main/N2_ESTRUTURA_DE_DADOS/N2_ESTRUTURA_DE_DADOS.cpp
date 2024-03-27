#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "PESSOA.h"
#include <sstream>
#include "Calculos.h"

using namespace std;

int main() {
    // Nome do arquivo CSV
    string filename = "C:\\Users\\guilh\\Downloads\\dados_pessoais.csv";

    // Abre o arquivo
    ifstream file(filename);

    // Verifica se o arquivo foi aberto corretamente
    if (!file.is_open()) {
        cout << "Erro ao abrir o arquivo " << filename << endl;
        return 1;
    }

    int numLinhas = 0; // Inicializa numLinhas com zero

    string line;

    // Conta o número de linhas no arquivo
    while (std::getline(file, line)) {
        numLinhas++;
    }

    file.clear(); // Limpa a flag de fim de arquivo

    file.seekg(0); // Retorna ao início do arquivo

    vector<PESSOA> pessoas;

    // Lê o arquivo linha por linha
    for (int i = 0; i < numLinhas; i++) {
        // Armazena os campos de cada linha
        vector<string> fields;

        // Usa stringstream para dividir a linha em campos usando o ponto e vírgula como delimitador
        getline(file, line); // Lê uma linha do arquivo
        stringstream ss(line);
        string field;
        if (i > 0)
        {
            while (getline(ss, field, ';')) {
                fields.push_back(field);
            }

            pessoas.push_back(PESSOA(fields[0], fields[1], fields[2], fields[3]));
        }
    }

    // Fecha o arquivo após a leitura
    file.close();


    

    // Ordena as pessoas pelo nome usando o método bubbleSortNome

    vector<PESSOA> pessoasOrdenadas = PESSOA::ordenarPessoasPorNome(pessoas);
    vector<PESSOA> pessoasOrdenadas2 = PESSOA::ordenarPessoasPorNomeInsertion(pessoas);
    vector<PESSOA> pessoasOrdenadas3 = PESSOA::ordenarPessoasPorNomeSelection(pessoas);
    vector<PESSOA> pessoasOrdenadas4 = PESSOA::ordenarPessoasPorNomeMerge(pessoas);
    vector<PESSOA> pessoasOrdenadas5 = PESSOA::ordenarPessoasPorNomeQuick(pessoas);

    // Calcula estatísticas para o atributo de peso (índice 2)
    Calculos::calcularEstatisticasCSV(filename, 2);

    // Calcula estatísticas para o atributo de altura (índice 3)
    Calculos::calcularEstatisticasCSV(filename, 3);

    return 0;

    return 0;

}



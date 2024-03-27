#include "PESSOA.h"
#include <chrono>
#include <sstream>
#include <vector>
#include <ctime>
#include <iostream>

using namespace std;
using namespace std::chrono;

PESSOA::PESSOA() {
    Nome = "";
    Idade = 0;
    Peso = 0.0f;
    Altura = 0.0f;
}
PESSOA::PESSOA(std::string nome, std::string dataNascimento, string peso, string altura) {
    Nome = nome;
    Idade = ConverteIDADE(dataNascimento);
    Peso = std::stof(peso);
    Altura = std::stof(altura);
    
}

string PESSOA::getNome() {
    return Nome;
}

int PESSOA::getIdade() {
    return Idade;
}

float PESSOA::getPeso() {
    return Peso;
}

float PESSOA::getAltura() {
    return Altura;
}

int PESSOA::ConverteIDADE(std::string dataStr) {
    std::tm tmData;
    std::istringstream ss(dataStr);
    std::vector<std::string> tokens;
    std::string token;

    // Divide a string usando o caractere '-'
    while (std::getline(ss, token, '/')) {
        tokens.push_back(token);
    }

    // Converter as partes da data para inteiros
    int ano, mes, dia;
    std::istringstream(tokens[0]) >> dia;
    std::istringstream(tokens[1]) >> mes;
    std::istringstream(tokens[2]) >> ano;

    ano -= 1900;
    mes -= 1;

    time_t mytime;
    mytime = time(NULL);
    struct tm data_atual;
    localtime_s(&data_atual, &mytime);


    int idade;
    idade = data_atual.tm_year - ano;

    if (data_atual.tm_mon < mes || (data_atual.tm_mon == mes && data_atual.tm_mday > dia))
    {
        idade--;
    }

    return idade;
};

void PESSOA::dadosPessoais() {
    cout << "Nome:" << Nome << "," << "Idade:" << Idade << "," << "Peso:" << Peso << ",Altura:" << Altura << endl;
}

void PESSOA::bubbleSortNome(std::vector<PESSOA>& pessoas) {
    auto start = high_resolution_clock::now();
    int n = pessoas.size();
    bool trocou;
    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (pessoas[j].getNome() > pessoas[j + 1].getNome()) {
                // Troca as posições dos elementos
                std::swap(pessoas[j], pessoas[j + 1]);
                trocou = true;
            }
        }
        // Se não houve trocas nesta iteração, o vetor já está ordenado
        if (!trocou) break;
           
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração em milissegundos
    std::cout << "Tempo de execução do Bubble Sort: " << duration.count() << " milliseconds" << std::endl;
   
}

std::vector<PESSOA> PESSOA::ordenarPessoasPorNome(std::vector<PESSOA>& pessoas) {
    bubbleSortNome(pessoas);

    // Mostra os dados das pessoas após a ordenação
    std::cout << "Dados das pessoas após a ordenação Bubble:" << std::endl;
    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].dadosPessoais();
    }

    return pessoas;
}




void PESSOA::insertionSortNome(std::vector<PESSOA>& pessoas) {
    auto start = high_resolution_clock::now();
    int n = pessoas.size();
    
    for (int i = 1; i < n; i++) {
        PESSOA chave = pessoas[i];
        int j = i - 1;
        
        while (j >= 0 && pessoas[j].getNome() > chave.getNome()) {
            pessoas[j + 1] = pessoas[j];
            j = j - 1;
        }
        
        pessoas[j + 1] = chave;
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração em milissegundos
    std::cout << "Tempo de execução do Insertion Sort: " << duration.count() << " milliseconds" << std::endl;
}

std::vector<PESSOA> PESSOA::ordenarPessoasPorNomeInsertion(std::vector<PESSOA>& pessoas) {
    insertionSortNome(pessoas);

    // Mostra os dados das pessoas após a ordenação
    std::cout << "Dados das pessoas após a ordenação Insertion:" << std::endl;
    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].dadosPessoais();
    }

    return pessoas;
}




void PESSOA::selectionSortNome(std::vector<PESSOA>& pessoas) {
    auto start = high_resolution_clock::now();
    int n = pessoas.size();

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (pessoas[j].getNome() < pessoas[min_idx].getNome()) {
                min_idx = j;
            }
        }
        std::swap(pessoas[min_idx], pessoas[i]);
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração em milissegundos
    std::cout << "Tempo de execução do Selection Sort: " << duration.count() << " milliseconds" << std::endl;
}

std::vector<PESSOA> PESSOA::ordenarPessoasPorNomeSelection(std::vector<PESSOA>& pessoas) {
    selectionSortNome(pessoas);

    // Mostra os dados das pessoas após a ordenação
    std::cout << "Dados das pessoas após a ordenação Selection:" << std::endl;
    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].dadosPessoais();
    }

    return pessoas;
}


void PESSOA::mergeSortNome(std::vector<PESSOA>& pessoas, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        mergeSortNome(pessoas, inicio, meio);
        mergeSortNome(pessoas, meio + 1, fim);
        merge(pessoas, inicio, meio, fim);
    }
}

void PESSOA::merge(std::vector<PESSOA>& pessoas, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    std::vector<PESSOA> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = pessoas[inicio + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = pessoas[meio + 1 + j];
    }

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i].getNome() <= R[j].getNome()) {
            pessoas[k] = L[i];
            i++;
        }
        else {
            pessoas[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        pessoas[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        pessoas[k] = R[j];
        j++;
        k++;
    }
}

std::vector<PESSOA> PESSOA::ordenarPessoasPorNomeMerge(std::vector<PESSOA>& pessoas) {
    auto start = high_resolution_clock::now();
    mergeSortNome(pessoas, 0, pessoas.size() - 1);
    auto stop = high_resolution_clock::now();

    // Mostra os dados das pessoas após a ordenação
    std::cout << "Dados das pessoas após a ordenação Merge:" << std::endl;
    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].dadosPessoais();
    }

    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração em milissegundos
    std::cout << "Tempo de execução do Merge Sort: " << duration.count() << " milliseconds" << std::endl;

    return pessoas;
}




void PESSOA::quickSortNome(std::vector<PESSOA>& pessoas, int inicio, int fim) {
    if (inicio < fim) {
        int indicePivo = partition(pessoas, inicio, fim);
        quickSortNome(pessoas, inicio, indicePivo - 1);
        quickSortNome(pessoas, indicePivo + 1, fim);
    }
}

int PESSOA::partition(std::vector<PESSOA>& pessoas, int inicio, int fim) {
    std::string pivo = pessoas[fim].getNome();
    int indicePivo = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (pessoas[j].getNome() <= pivo) {
            indicePivo++;
            std::swap(pessoas[indicePivo], pessoas[j]);
        }
    }

    std::swap(pessoas[indicePivo + 1], pessoas[fim]);
    return indicePivo + 1;
}

std::vector<PESSOA> PESSOA::ordenarPessoasPorNomeQuick(std::vector<PESSOA>& pessoas) {
    auto start = high_resolution_clock::now();
    quickSortNome(pessoas, 0, pessoas.size() - 1);
    auto stop = high_resolution_clock::now();

    // Mostra os dados das pessoas após a ordenação
    std::cout << "Dados das pessoas após a ordenação Quick:" << std::endl;
    for (size_t i = 0; i < pessoas.size(); i++) {
        pessoas[i].dadosPessoais();
    }

    auto duration = duration_cast<milliseconds>(stop - start); // Calcula a duração em milissegundos
    std::cout << "Tempo de execução do Quick Sort: " << duration.count() << " milliseconds" << std::endl;

    return pessoas;
}




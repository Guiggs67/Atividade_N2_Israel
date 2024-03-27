#ifndef PESSOA_H
#define PESSOA_H
#include <chrono>
#include <string>
#include <vector>
using namespace std;

class PESSOA
{
public:
	PESSOA();
	PESSOA(string nome, string dataNascimento, string peso, string altura);
	string getNome();
	int getIdade();
	float getPeso();
	float getAltura();
	void dadosPessoais();
	static void bubbleSortNome(std::vector<PESSOA>& pessoas);
	static void insertionSortNome(std::vector<PESSOA>& pessoas);
	static void selectionSortNome(std::vector<PESSOA>& pessoas);
	static void mergeSortNome(vector<PESSOA>& pessoas, int inicio, int fim);
	static void merge(std::vector<PESSOA>& pessoas, int inicio, int meio, int fim);
	static void quickSortNome(std::vector<PESSOA>& pessoas, int inicio, int fim);
	static int partition(std::vector<PESSOA>& pessoas, int inicio, int fim);
	static std::vector<PESSOA> ordenarPessoasPorNome(std::vector<PESSOA>& pessoas);
	static std::vector<PESSOA> ordenarPessoasPorNomeInsertion(std::vector<PESSOA>& pessoas);
	static std::vector<PESSOA> ordenarPessoasPorNomeSelection(std::vector<PESSOA>& pessoas);
	static std::vector<PESSOA> ordenarPessoasPorNomeMerge(std::vector<PESSOA>& pessoas);
	static std::vector<PESSOA> ordenarPessoasPorNomeQuick(std::vector<PESSOA>& pessoas);




private:
	string Nome;
	int Idade;
	float Peso;
	float Altura;
	int ConverteIDADE(std::string dataStr);
};

#endif PESSOA_H
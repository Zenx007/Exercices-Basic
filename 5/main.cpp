#include <iostream>
#include <fstream>
using namespace std;
/*
Contador de Palavras em um Arquivo de Texto
Contar o número de palavras em um arquivo de
texto.
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	ifstream* leitura = new ifstream;
	string* palavra = new string;
	int* soma = new int;
	*soma = 0;
	
	leitura->open("texto.txt");
	
	while(*leitura >> *palavra){
		*soma = *soma + 1;
	}
	cout<<"O arquivo tem " << *soma << " palavras.";
	leitura->close();
	
	delete leitura;
	leitura = nullptr;
	delete palavra;
	palavra = nullptr;
	delete soma;
	soma = nullptr;
	
	return 0;
}

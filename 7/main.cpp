#include <iostream>
#include <fstream>

using namespace std;
/*
Cadastro de Livros em uma Biblioteca - Aplicação em Gestão de Biblioteca:
Um sistema para cadastrar livros em uma biblioteca, onde as informações de cada livro são
gravadas em um arquivo de texto e depois lidas para exibição
*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Livro {
	string titulo;
	string autor;
	
	void registraTitulo();
	void registraAutor();
	void registraLivro();
	void arquivarDados();
	void exibirDados();
};

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Livro* livro = new Livro;
	char* flag = new char;
	do {
		livro->registraLivro();
		livro->arquivarDados();
		
		cout << "Deseja continuar? [s/n]"<<endl;
		cin >> *flag;
		
	} while(*flag == 's');

	cout<<"Exibindo dados do arquivo:"<<endl;
	livro->exibirDados();
	
	delete livro;
	livro = nullptr;
	delete flag;
	flag = nullptr;
	return 0;
}

void Livro::registraTitulo(){
	cout << "Digite o título:";
	cin >> titulo;
}

void Livro::registraAutor(){
	cout << "Digite o autor: ";
	cin >> autor;
}

void Livro::registraLivro(){
	registraTitulo();
	registraAutor();
}

void Livro::arquivarDados(){
	ofstream escrever;
	escrever.open("livros.txt", ios::app);
	escrever << "Título: " << titulo << endl;
	escrever << "Autor: " << autor <<endl;
	escrever << endl;
	escrever.close();
}

void Livro::exibirDados(){
	ifstream leitura;
	string linha;
	leitura.open("livros.txt");
	
	while(getline(leitura, linha)){
		cout << linha << endl;
	}
	
	leitura.close();
	
}

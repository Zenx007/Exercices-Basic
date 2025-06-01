#include <iostream>
#include <fstream>

using namespace std;

/*
Cadastro de Funcionários em RH:
Registrar as informações de funcionários,
gravar em um arquivo e, depois, fazer a leitura desses dados.
Utilizando structs para representar um funcionário
e alocação dinâmica para armazenar os dados,
o programa grava as informações no arquivo e lê esses dados posteriormente.

*/

struct Funcionario {
	string nome;
	string endereco;
	string telefone;
	float salario;
	
	string registrarNome();
	string registrarEndereco();
	string registrarTelefone();
	float registrarSalario();
	void arquivarDados();
	void lerDados();
};


/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Funcionario* funcionario = new Funcionario;
	char* flag = new char;
	int* totalFuncionarios = new int;
	*totalFuncionarios = 0;
	
	do {
		*totalFuncionarios += 1;
		cout << "Funcionário " << *totalFuncionarios << "\n";
		cout << "Digite o nome: ";
		funcionario->registrarNome();
		cout << "Digite o endereço: ";
		funcionario->registrarEndereco();
		cout << "Digite o telefone: ";
		funcionario->registrarTelefone();
		cout << "Digite o salário: ";
		funcionario->registrarSalario();
		funcionario->arquivarDados();
		cout << "Dados arquivados!"<<endl;
		
		cout << "Deseja continuar [s/n]: \n";
		cin >> flag;
		
	} while(*flag == 's');
	
	cout << "Lendo arquivo... \n";
	
	funcionario->lerDados();

	
	delete flag;
	flag = nullptr;
	delete funcionario;
	funcionario = nullptr;
	delete totalFuncionarios;
	totalFuncionarios = nullptr;

	return 0;
}

string Funcionario::registrarNome(){
	cin >> nome;
	return nome;
}
string Funcionario::registrarEndereco(){
	cin >> endereco;
	return endereco;
}
string Funcionario::registrarTelefone(){
	cin >> telefone;
	return telefone;
}
float Funcionario::registrarSalario(){
	cin >> salario;
	return salario;
}
void Funcionario::arquivarDados(){
	ofstream escrever;
	escrever.open("funcionarios.txt", ios::app);
	escrever << "Nome: " << nome << endl;
	escrever << "Endereço: " << endereco << endl;
	escrever << "Telefone: " << telefone << endl;
	escrever << "Salário: " << salario << endl;
	escrever << "\n";
	
	escrever.close();
	
}
void Funcionario::lerDados(){
	ifstream leitura;
	string linha;
	
	leitura.open("funcionarios.txt");
	while (getline(leitura, linha)){
		cout << linha << endl;
	}
}



#include <iostream>
#include <fstream>

using namespace std;

/*
Registro de Estoque de Produtos - Aplicação Comercial
Registrar a quantidade e o preço de cada produto em
estoque. 
Armazenar esses dados e calcular o valor total do estoque.
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Produto{
	float preco;
	int quantidade;
	
	void registrarProduto();
};

void arquivarProdutos(Produto *produtos, string arquivo, int *quantProdutos);

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	
	int* quantProdutos = new int;
	cout << "Digite a quantidade de produtos: " << endl;
	cin >> *quantProdutos;
	Produto* produtos = new Produto[*quantProdutos];
	
	for (int i = 0; i < *quantProdutos; i++){
		cout << "Produto " << i + 1 << ":" << endl;
		produtos[i].registrarProduto();
	}
	
	string arquivo = "produtos.txt";
	arquivarProdutos(produtos, arquivo, quantProdutos);
	
	delete quantProdutos;
	quantProdutos = nullptr;
	delete[] produtos;
	produtos = nullptr;

	return 0;
}

void Produto::registrarProduto(){
	cout << "Digite o preço: " << endl;
	cout << "R$"; 
	cin >> preco;
	
	cout << "Digite a quantidade: " << endl;
	cin >> quantidade;
}

void arquivarProdutos(Produto *produtos, string arquivo, int *quantProdutos){
	ofstream escrever;
	escrever.open(arquivo);
	int somaEstoque = 0;
	float valorTotal = 0;
	
	for(int i = 0; i < *quantProdutos; i++) {
		escrever << "Produto " << i + 1 << endl;
		escrever << "Preço: R$" << produtos[i].preco << endl;
		escrever << "Quantidade: " << produtos[i].quantidade << endl << endl;
		valorTotal += produtos[i].preco;
		somaEstoque += produtos[i].quantidade;
	}
	cout<<"\n\n";
	cout<<"Total no estoque: " << somaEstoque << endl;
	cout<<"Valor total R$"<<valorTotal
	
	cout<<"Produtos registrados no arquivo.";
	
	escrever.close();
}


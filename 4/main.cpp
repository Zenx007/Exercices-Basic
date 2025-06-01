#include <iostream>
#include <fstream>

using namespace std;

struct RelatorioDia {
	int quilometragem;
	float valorArrecadado;
	
	void registrarKm();
	void registrarValorArrecadado();
	
};

struct RelatorioSemana{
	RelatorioDia relatorio[7];
	int totalKm = 0;
	float faturamento = 0;
	ofstream escrever;
	
	int calcularTotalKm();
	float calcularFaturamento();
	void arquivarSemana();
	void registrarSemana();
	
};



int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	RelatorioSemana* relatorioSemana = new RelatorioSemana;
	
	relatorioSemana->registrarSemana();
	relatorioSemana->arquivarSemana();
	
	cout << "Programa encerrado \n ";
	cout << "Semana arquivada";
	
	return 0;
}


void RelatorioDia::registrarKm(){
	cout << "Digite a quilometragem: \n";
	cin >> quilometragem;
}
void RelatorioDia::registrarValorArrecadado(){
	cout << "Digite o valor arrecadado: \n";
	cin >> valorArrecadado;
}

int RelatorioSemana::calcularTotalKm(){
	for(int i = 0; i < 7; i++){
		totalKm += relatorio[i].quilometragem;
	}
	return totalKm;
}
float RelatorioSemana::calcularFaturamento(){
	for(int i = 0; i < 7; i++){
		faturamento += relatorio[i].valorArrecadado;
	}
	return faturamento;
}

void RelatorioSemana::arquivarSemana(){
	ofstream escrever;
	escrever.open("viagemSemana.txt");
	
	for(int i = 0; i < 7; i++){
		escrever << "Dia " << i + 1 <<": \n";
		escrever << "	Km: " <<relatorio[i].quilometragem << ". \n";
		escrever << "	Arrecadado: " << relatorio[i].valorArrecadado << "R$. \n";
	}
	escrever << "\n\n";
	escrever <<"Relatório da semana: \n";
	escrever << "	Km: " << calcularTotalKm() << ". \n";
	escrever << "	Faturamento: " << calcularFaturamento();
	escrever.close();
}

void RelatorioSemana::registrarSemana(){
	for(int i = 0; i < 7; i ++){
		cout <<"Dia " << i + 1 << ":\n";
		relatorio[i].registrarKm();
		relatorio[i].registrarValorArrecadado();
	}
}

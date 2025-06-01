#include <iostream>
#include <fstream>

using namespace std;

/*
. Registro de Temperaturas Semanais - Aplicação em Meteorologia
Registrar as temperaturas durante a semana,
três períodos do dia (manhã, tarde e noite). 
Armazenar informações em um arquivo e,
calcular a maior, menor e média das temperaturas
*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float calcularMaiorTemp(float *temperaturas[]);
float calcularMenorTemp(float *temperaturas[]);
float somarTemperaturas(float *temperaturas[]);
float mediaTemperaturas(float *temperaturas[]);

void montarMatriz(float *temperaturas[]);
void desmontarMatriz(float *temperaturas[]);

string definirDiaDaSemana(int i);
string definirPeriodo(int j);


int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	float** temperaturas = new float*[7];
	float* menorTemp = new float;
	float* maiorTemp = new float;
	float* media = new float;
	ofstream escrever;
	escrever.open("Temperaturas.txt");
	escrever.clear();
	
	
	montarMatriz(temperaturas);
	
	escrever << "Dia da semana \t | \t Manhã \t | \t Tarde \t | \t Noite"<<endl;
	for(int i = 0; i < 7; i++){
		string diaDaSemana = definirDiaDaSemana(i);
		escrever << diaDaSemana <<":  \t";
		for(int j = 0; j < 3; j++){
			string periodo = definirPeriodo(j);
			
			cout << "Digite a temperatura de " << diaDaSemana << " do período de "<< periodo <<": " << endl; 
			cin >> temperaturas[i][j];
			
			escrever <<" | \t" << temperaturas[i][j] << "°\t";
		}
		escrever << endl;
	}
	escrever << endl << endl;
	
	*maiorTemp = calcularMaiorTemp(temperaturas);
	*menorTemp = calcularMenorTemp(temperaturas);
	*media = mediaTemperaturas(temperaturas);
	
	escrever << "A maior temperatura foi de " << *maiorTemp << "°C." << endl;
	escrever << "A menor temperatura foi de " << *menorTemp << "°C." << endl;
	escrever << "A média foi de " << *media <<"°C.";
	
	cout<<"Temperaturas registradas no arquivo.";
	
	escrever.close();
	desmontarMatriz(temperaturas);
	delete[] temperaturas;
	temperaturas = nullptr;
	delete menorTemp;
	menorTemp = nullptr;
	delete maiorTemp;
	maiorTemp = nullptr;
	delete media;
	media = nullptr;
	return 0;
}

void montarMatriz(float *temperaturas[]){
	for(int i = 0; i < 7; i++){
		temperaturas[i] = new float[3];
	}
} 

void desmontarMatriz(float *temperaturas[]){
	for(int i = 0; i < 7; i++){
		delete[] temperaturas[i];
	}
}

string definirDiaDaSemana(int i){
	switch(i){
		case 0:
			return "Segunda";
			break;
		case 1:
			return "Terça";
			break;
		case 2:
			return "Quarta";
			break;
		case 3:
			return "Quinta";
			break;
		case 4:
			return "Sexta";
			break;
		case 5:
			return "Sábado";
			break;
		case 6:
			return "Domingo";
			break;
	}
}

string definirPeriodo(int j){
	if(j == 0){
		return "Manhã";
	}
	if(j == 1){
		return "Tarde";
	}
	if(j == 2){
		return "Noite";
	}
}

float calcularMaiorTemp(float *temperaturas[]){
	float maiorTemp = -9999;
	
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(maiorTemp < temperaturas[i][j])
			{
				maiorTemp = temperaturas[i][j];
				
			}
		}
	}
	return maiorTemp;
}

float calcularMenorTemp(float *temperaturas[]){
	float menorTemp = 9999;
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 3; j++){
			if(menorTemp > temperaturas[i][j]){
				menorTemp = temperaturas[i][j];
			}
		}
	}
	return menorTemp;
}

float somarTemperaturas(float *temperaturas[]){
	float soma;
	for(int i = 0; i < 7; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			soma += temperaturas[i][j];
		}
	}
	
	return soma;
}

float mediaTemperaturas(float *temperaturas[]){
	float media = somarTemperaturas(temperaturas);
	return media / (7 * 3);
}

	


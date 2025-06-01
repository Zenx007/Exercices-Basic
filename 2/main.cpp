#include <iostream>
#include <fstream>

using namespace std;


struct Aluno{
	float notas[3];
	
	void registrarNotas();
	float calcularMedia();
};

void registrarNotasAlunos(Aluno* alunos);

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Aluno* alunos = new Aluno[10];
	ofstream escrever;
	escrever.open("NotasAlunos.txt");
	
	registrarNotasAlunos(alunos);
	
	for(int i = 0; i < 10; i++){
		 
		escrever << "Aluno " << i + 1 << ": " << endl;
		
		for(int j = 0; j < 3; j++){
			escrever << "Nota " << j + 1 <<": " << alunos[i].notas[j] <<" | ";
		}
		
		float media = alunos[i].calcularMedia();
		
		escrever << "Média: " << media << endl << endl;
	}
	
	cout<<"Notas registradas no arquivo";
	
	
	delete[] alunos;
	alunos = nullptr;
	
	escrever.close();
	
	
	return 0;
}

void Aluno::registrarNotas(){
	for(int i = 0; i < 3; i++){
		cout << "Digite a " << i + 1 << "° nota: " << endl;
		cin >> notas[i];
		if(notas[i] < 0 || notas[i] > 10){
			cout << "Erro, digite valor de 0 a 10"<<endl;
			return Aluno::registrarNotas();
		}
	}
}
float Aluno::calcularMedia(){
	float soma = 0;
	
	for(int i = 0; i < 3; i++){
		soma += notas[i];
	}
		
	return soma / 3;
}

void registrarNotasAlunos(Aluno *alunos){
	for(int i = 0; i < 10; i++){
		cout<<"Aluno " << i + 1 << ": "<<endl;
		alunos[i].registrarNotas();
	}
}


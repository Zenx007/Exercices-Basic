#include <iostream>
using namespace std;

int main() {
    int m, n;

    cout << "Digite o número de alunos: ";
    cin >> m;
    cout << "Digite o número de disciplinas: ";
    cin >> n;


    int** notas = new int*[m];

    for (int i = 0; i < m; i++) {
        notas[i] = new int[n];
    }

    for (int i = 0; i < m; i++) {
        cout << "Digite as notas do aluno " << i + 1 << ":\n";
        for (int j = 0; j < n; j++) {
            cout << "Nota da disciplina " << j + 1 << ": ";
            cin >> notas[i][j];
        }
    }

    cout << "\nMédia dos alunos:\n";
    for (int i = 0; i < m; i++) {
        int soma = 0;
        for (int j = 0; j < n; j++) {
            soma += notas[i][j]; 
        }
        float media = static_cast<float>(soma) / n;  
        cout << "Média do aluno " << i + 1 << ": " << media << endl;
    }

    for (int i = 0; i < m; i++) {
        delete[] notas[i]; 
    }
    delete[] notas; 

    return 0;
}

#include <iostream>

using namespace std;

#define TAM 3

int main() {
    int caixas[TAM];
    int inicio = 0;
    int fim = 0;
    int tamanho = 0;

    cout << "=== Armazém com 3 Caixas ===\n";

    for (int i = 0; i < TAM; i++) {
        cout << "Digite o código do produto " << i + 1 << ": ";
        cin >> caixas[fim];
        fim = (fim + 1) % TAM;
        tamanho++;
    }

    cout << "\nLiberando a caixa com produto: " << caixas[inicio] << endl;
    inicio = (inicio + 1) % TAM;
    tamanho--;

    cout << "\nDigite o código do novo produto: ";
    cin >> caixas[fim];
    fim = (fim + 1) % TAM;
    tamanho++;

    cout << "\nSituação atual das caixas:\n";
    for (int i = 0; i < tamanho; i++) {
        cout << "Caixa " << (inicio + i) % TAM + 1 << ": Produto "
            << caixas[(inicio + i) % TAM] << endl;
    }

    return 0;
}
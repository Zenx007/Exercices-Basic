#include <iostream>
#include <stack>
#include <string>

using namespace std;

string converterParaBinario(int numero) {
    stack<int> pilhaBits;
 
    if (numero == 0) {
        return "0";
    }
    
    while (numero > 0) {
        pilhaBits.push(numero % 2);
        numero /= 2;
    }
    
    string binario;
    while (!pilhaBits.empty()) {
        binario += to_string(pilhaBits.top());
        pilhaBits.pop();
    }
    
    return binario;
}

int main() {
    int repeticoes, numero;
    stack<int> pilhaNumerosDecimais;
    
    cout << "Quantos numeros decimais voce gostaria de transformar em binarios?" << endl;
    cin >> repeticoes;
    
    for (int i = 0; i < repeticoes; i++) {
        cout << "Digite o numero: ";
        cin >> numero;
        
        if (numero >= 0) {
            pilhaNumerosDecimais.push(numero);
        } else {
            cout << "Digite um numero valido (nao negativo)" << endl;
            i--; 
        }
    }
    
    cout << "Os numeros convertidos ficaram:" << endl;
    
    while (!pilhaNumerosDecimais.empty()) {
        int num = pilhaNumerosDecimais.top();
        cout << "Numero decimal: " << num << endl;
        cout << "Numero binario: " << converterParaBinario(num) << endl;
        pilhaNumerosDecimais.pop();
    }
    
    return 0;
}
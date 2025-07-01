#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>

using namespace std;

void exibir_forca(int erros_cometidos) {
    cout << "  _____" << endl;
    cout << " |     |" << endl;
    cout << " |     " << (erros_cometidos > 0 ? "O" : "") << endl;
    cout << " |    " << (erros_cometidos > 2 ? "/" : "") << (erros_cometidos > 1 ? "|" : "") << (erros_cometidos > 3 ? "\\" : "") << endl;
    cout << " |    " << (erros_cometidos > 4 ? "/" : "") << " " << (erros_cometidos > 5 ? "\\" : "") << endl;
    cout << " |" << endl;
    cout << "_|___" << endl;
    cout << endl;
}

void exibir_palavra_oculta(const string& palavra_secreta, const vector<char>& letras_adivinhadas) {
    for (char letra : palavra_secreta) {
        bool encontrada = false;
        for (char adivinhada : letras_adivinhadas) {
            if (tolower(letra) == tolower(adivinhada)) {
                cout << letra << " ";
                encontrada = true;
                break;
            }
        }
        if (!encontrada) {
            cout << "_ ";
        }
    }
    cout << endl;
}

int main() {
    vector<string> palavras = {"programacao", "computador", "algoritmo", "desenvolvimento", "variavel", "linguagem"};

    random_device dispositivo_aleatorio;
    mt19937 gerador(dispositivo_aleatorio());
    uniform_int_distribution<> distribuicao(0, palavras.size() - 1);

    string palavra_secreta = palavras[distribuicao(gerador)];

    vector<char> letras_adivinhadas;
    int erros_cometidos = 0;
    const int maximo_erros = 6;

    bool jogo_ganho = false;
    bool jogo_perdido = false;

    cout << "Bem-vindo ao Jogo da Forca!" << endl;

    while (!jogo_ganho && !jogo_perdido) {
        exibir_forca(erros_cometidos);
        exibir_palavra_oculta(palavra_secreta, letras_adivinhadas);

        cout << "Letras ja tentadas: ";
        for (char letra : letras_adivinhadas) {
            cout << letra << " ";
        }
        cout << endl;

        char palpite_do_usuario;
        cout << "Digite uma letra: ";
        cin >> palpite_do_usuario;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        palpite_do_usuario = tolower(palpite_do_usuario);

        bool letra_ja_tentada = false;
        for (char letra_tentada : letras_adivinhadas) {
            if (palpite_do_usuario == letra_tentada) {
                letra_ja_tentada = true;
                cout << "Voce ja tentou essa letra. Tente outra!" << endl;
                break;
            }
        }

        if (letra_ja_tentada) {
            continue;
        }

        letras_adivinhadas.push_back(palpite_do_usuario);

        bool acerto_na_letra = false;
        for (char letra_da_palavra : palavra_secreta) {
            if (tolower(letra_da_palavra) == palpite_do_usuario) {
                acerto_na_letra = true;
                break;
            }
        }

        if (acerto_na_letra) {
            cout << "Acerto!" << endl;
        } else {
            cout << "Erro!" << endl;
            erros_cometidos++;
        }

        jogo_ganho = true;
        for (char letra_da_palavra : palavra_secreta) {
            bool encontrada_na_adivinhada = false;
            for (char adivinhada : letras_adivinhadas) {
                if (tolower(letra_da_palavra) == tolower(adivinhada)) {
                    encontrada_na_adivinhada = true;
                    break;
                }
            }
            if (!encontrada_na_adivinhada) {
                jogo_ganho = false;
                break;
            }
        }

        if (erros_cometidos >= maximo_erros) {
            jogo_perdido = true;
        }
    }

    exibir_forca(erros_cometidos);
    exibir_palavra_oculta(palavra_secreta, letras_adivinhadas);

    if (jogo_ganho) {
        cout << "Parabens! Voce adivinhou a palavra '" << palavra_secreta << "'!" << endl;
    } else {
        cout << "Que pena! Voce foi enforcado. A palavra era '" << palavra_secreta << "'." << endl;
    }

    return 0;
}
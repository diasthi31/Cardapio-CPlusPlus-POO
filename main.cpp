#include <iostream>
#include <iomanip>

using namespace std;

const int MAX = 20;

class Produto {
private:
    int codigo;
    double preco;
    string produto;

public:
    void ler();
    int getCodigo();
    double& getPreco();
    string getProduto();
};

class Cardapio {
private:
    Produto vetor[MAX];
    int quantidade = 0;

public:
    Cardapio();
    int menu();
    void inserir(Produto produto);
    void remover();
    void consultarPreco();
    void atualizarPreco();
    void listar();
};

void Produto::ler() {
    cin >> codigo;
    cin.ignore();
    getline(cin, produto);
    cin >> preco;
}

int Produto::getCodigo() {
    return codigo;
}

double& Produto::getPreco() {
    return preco;
}

string Produto::getProduto() {
    return produto;
}

Cardapio::Cardapio() {
    quantidade = 0;
}

int Cardapio::menu() {
    int opcao;

    do {
        cout << "1 - inserir" << endl;
        cout << "2 - remover" << endl;
        cout << "3 - consultar" << endl;
        cout << "4 - alterar" << endl;
        cout << "5 - listar" << endl;
        cout << "6 - sair" << endl;
        cout << "Entre com a sua escolha:" << endl;
        cin >> opcao;
    } while(opcao < 1 || opcao > 6);

    return opcao;
}

void Cardapio::inserir(Produto produto) {
    vetor[quantidade] = produto;
    quantidade++;
}

void Cardapio::remover() {
    int codigo, i, j;
    bool removeu = false;

    cin >> codigo;

    for(i = 0; i < quantidade; i++) {
        if(vetor[i].getCodigo() == codigo) {
            for(j = i; j < quantidade - 1; j++) {
                vetor[j] = vetor[j + 1];
            }

            quantidade--;
            removeu = true;
        }
    }
}

void Cardapio::consultarPreco() {
    int codigo, i;
    bool encontrou = false;
    cin >> codigo;

    cout << setprecision(2) << fixed;
    for(i = 0; i < quantidade; i++) {
        if(codigo == vetor[i].getCodigo()) {
            cout << "R$ " << vetor[i].getPreco() << endl;
            encontrou = true;
        }
    }

    if(encontrou == false) {
        cout << "R$ 0.00" << endl;
    }
}

void Cardapio::atualizarPreco() {
    int i, codigo;
    double novoPreco;

    cin >> codigo >> novoPreco;

    for(i = 0; i < quantidade; i++) {
        if(vetor[i].getCodigo() == codigo) {
            vetor[i].getPreco() = novoPreco;
        }
    }
}

void Cardapio::listar() {
    cout << left << setw(7) << "Codigo" << setw(33) << setfill(' ') << "Nome" << setw(5) << setfill(' ') << "Preco" << endl;
    cout << setprecision(2) << fixed;

    cout << setprecision(2) << fixed;
    for(int i = 0; i < quantidade; i++) {
        cout << right << setw(5) << setfill('0') << vetor[i].getCodigo() << "  " << left << setw(30) << setfill(' ') << vetor[i].getProduto() << "R$  " << setw(2) << setfill(' ') << vetor[i].getPreco() << endl;
    }
}

int main() {
    Produto produto;
    Cardapio cardapio;
    bool terminou = false;

    while(!terminou) {
        switch (cardapio.menu()) {
            case 1:
                produto.ler();
                cardapio.inserir(produto);
                break;

            case 2:
                cardapio.remover();
                break;

            case 3:
                cardapio.consultarPreco();
                break;

            case 4:
                cardapio.atualizarPreco();
                break;

            case 5:
                cardapio.listar();
                break;

            case 6:
                cout << "Programa encerrado!" << endl;
                terminou = true;
                break;
        }
    }

    return 0;
}
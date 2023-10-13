#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iomanip>

using namespace std;

class Produto {
private:
    string nome;
    double preco;
    int codigo;

public:
    Produto(const string& nome, double preco, int codigo) : nome(nome), preco(preco), codigo(codigo) {}

    string getNome() const {
        return nome;
    }

    double getPreco() const {
        return preco;
    }

    int getCodigo() const {
        return codigo;
    }
};

class Estoque {
private:
    // implementar
public:
    // implementar
};

class CarrinhoDeCompras {
private:
    //implementar

public:
    // implementar
};

int main() {
    //implementar

    return 0;
}

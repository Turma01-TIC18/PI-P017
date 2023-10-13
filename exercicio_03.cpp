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
    map<int, int> quantidadeProdutos;

public:
    void adicionarProduto(const Produto& produto, int quantidade) {
        quantidadeProdutos[produto.getCodigo()] += quantidade;
    }

    void removerProduto(const Produto& produto, int quantidade) {
        quantidadeProdutos[produto.getCodigo()] -= quantidade;
        if (quantidadeProdutos[produto.getCodigo()] < 0) {
            quantidadeProdutos[produto.getCodigo()] = 0;
        }
    }

    int getQuantidadeProduto(const Produto& produto) const {
        auto it = quantidadeProdutos.find(produto.getCodigo());
        if (it != quantidadeProdutos.end()) {
            return it->second;
        }
        return 0;
    }
};

class CarrinhoDeCompras {
private:
    //implementar

public:
    // implementar
};

int main() {

    Produto p1("Maçã", 2.5, 1);
    Produto p2("Arroz", 10.0, 2);
    Produto p3("Leite", 4.0, 3);



    return 0;
}
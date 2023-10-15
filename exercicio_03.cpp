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
    Produto(string _nome, double _preco, int _codigo){ 
        nome = _nome;
        preco = _preco;
        codigo = _codigo;

    }

    string getNome() {
        return nome;
    }

    double getPreco() {
        return preco;
    }

    int getCodigo() {
        return codigo;
    }
};

class Estoque {
private:
    map<int, int> quantidadeProdutos;

public:
    void adicionarProduto( Produto& produto, int quantidade) {
        quantidadeProdutos[produto.getCodigo()] += quantidade;
    }

    void removerProduto(Produto& produto, int quantidade) {
        quantidadeProdutos[produto.getCodigo()] -= quantidade;
        if (quantidadeProdutos[produto.getCodigo()] < 0) {
            quantidadeProdutos[produto.getCodigo()] = 0;
        }
    }

    int getQuantidadeProduto(Produto& produto) const {
        auto it = quantidadeProdutos.find(produto.getCodigo());
        if (it != quantidadeProdutos.end()) {
            return it->second;
        }
        return 0;
    }
};

class CarrinhoDeCompras {
private:
    vector<pair<Produto, int>> itensCarrinho;

public:
    void adicionarProduto(Produto& produto, int quantidade) {
        for (auto& item : itensCarrinho) {
            if (item.first.getCodigo() == produto.getCodigo()) {
                item.second += quantidade;
                return;
            }
        }
        itensCarrinho.push_back(make_pair(produto, quantidade));
    }

    void removerProduto(Produto& produto, int quantidade) {
        for (auto& item : itensCarrinho) {
            if (item.first.getCodigo() == produto.getCodigo()) {
                item.second -= quantidade;
                if (item.second < 0) {
                    item.second = 0;
                }
                return;
            }
        }
    }

    double calcularValorTotal() {
        double valorTotal = 0.0;
        for (auto& item : itensCarrinho) {
            valorTotal += item.first.getPreco() * item.second;
        }
        return valorTotal;
    }

    void esvaziarCarrinho() {
        itensCarrinho.clear();
    }

    int getQuantidadeProduto(Produto& produto) {
        for (auto& item : itensCarrinho) {
            if (item.first.getCodigo() == produto.getCodigo()) {
                return item.second;
            }
        }
        return 0;
    }

    void exibirCarrinho() {
        cout << "Carrinho de Compras:" << endl;
        for (auto& item : itensCarrinho) {
            cout << "- " << item.first.getNome() << " (" << item.first.getPreco() << ") x " << item.second << endl;
        }
    }
};

int main() {
    Produto p1("Maçã", 2.5, 1);
    Produto p2("Arroz", 10.0, 2);
    Produto p3("Leite", 4.0, 3);

    CarrinhoDeCompras carrinho;
    carrinho.adicionarProduto(p1, 3);
    carrinho.adicionarProduto(p2, 2);
    carrinho.adicionarProduto(p3, 1);

    double valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total da compra: " << valorTotal << endl;

    carrinho.removerProduto(p2, 1);
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total após remoção: " << valorTotal << endl;

    carrinho.esvaziarCarrinho();
    valorTotal = carrinho.calcularValorTotal();
    cout << "Valor total após esvaziar o carrinho: " << valorTotal << endl;

    Produto p4("Chocolate", 3.0, 4);
    carrinho.adicionarProduto(p4, 10);

    int quantidadeChocolate = carrinho.getQuantidadeProduto(p4);
    cout << "Quantidade de chocolates no carrinho: " << quantidadeChocolate << endl;

    carrinho.adicionarProduto(p1, 2);
    carrinho.adicionarProduto(p2, 3);
    carrinho.adicionarProduto(p3, 1);
    carrinho.adicionarProduto(p4, 2);

    carrinho.exibirCarrinho();
    return 0;

}
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Produto{
    public:
    string nome;
    double preco;
    string codigo;

    public:
    Produto (string _nome, double _preco, string _codigo){
        nome = _nome;
        preco = _preco;
        codigo = _codigo;
    }

    string getNome(){
        return nome;
    }

    double getPreco(){
        return preco;
    }

    string getCodigo(){
        return codigo;
    }

};

class Estoque : public Produto {
    public:
    vector<Produto> produtos;
    vector<int> quantidades;

    public:
        void acicionarProduto(Produto _produto, int _quantidade){
            produtos.push_back(_produto);
            quantidades.push_back(_quantidade);
        }

        void exibirEstoque(){
            for(size_t i = 0; i < produtos.size(); i++){
                cout << "Produto: " << produtos[i].getNome() << "\tQuantidade: "
                << quantidades[i] << endl; 
            }

        }
};

class CarrinhoDeCompras : public Produto {
    public:
    vector<Produto> produtoCarrinho;

    public:

    void adcionarCarrinho(Produto _produto){
        produtoCarrinho.push_back(_produto);
    }

    void excluirProduto(Produto produto){
        //to do
    }

    double calcularPrecoCarrinho(Produto produto){
        double totalPreco = 0;
        for (Produto produto : produtoCarrinho){
            totalPreco += produto.getPreco();
        }
    return totalPreco;
    }

    void exibirConteudoCarrinho(){
        for(Produto produto : produtoCarrinho){
           cout << "Produto: " << produto.getNome() << "Preco: "
           << fixed << setprecision(1) << produto.getPreco() << endl;
        }

    }

};

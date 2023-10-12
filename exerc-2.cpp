#include <iostream>
#include <cmath> 
using namespace std;

class Ponto {
private:
    double x;
    double y;

public:
    
    Ponto() : x(0.0), y(0.0) {}

    Ponto(double xCoord, double yCoord) : x(xCoord), y(yCoord) {}

    void setCoordenadas(double xCoord, double yCoord) {
        x = xCoord;
        y = yCoord;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double calcularDistanciaOrigem() const {
        return sqrt(x * x + y * y);
    }
};

int main() {
    
    Ponto ponto1; 
    Ponto ponto2(3.0, 4.0);

    cout << "Coordenadas do ponto1: (" << ponto1.getX() << ", " << ponto1.getY() << ")" << endl;
    cout << "Coordenadas do ponto2: (" << ponto2.getX() << ", " << ponto2.getY() << ")" << endl;

    cout << "Distancia ate a origem para ponto1: " << ponto1.calcularDistanciaOrigem() << endl;
    cout << "Distancia ate a origem para ponto2: " << ponto2.calcularDistanciaOrigem() << endl;

    return 0;
}
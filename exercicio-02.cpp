#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

class Ponto{
    private:
        double x;
        double y;
    public:
        Ponto() {
            x = 0;
            y = 0;
        }
        Ponto(double _x, double _y) {
            x = _x;
            y = _y;
        }
            
        
        double getX(){
            return x;
        }

        double getY(){
            return y;
        }


        void setCoordenadas(double _a, double _b) {
            x = _a;
            y = _b;
            
        }

        double calcularDistancia() {
        
            return sqrt(x * x + y * y);
             
        }       
        
};



int main(){
    Ponto pontos[3];

    Ponto p1(3.0,4.0);
    Ponto p2(-2.0,7.0);
    Ponto p3(0.0,3.0);
    Ponto p4(4.0,0.0);
    
    double distancia_p1 = p1.calcularDistancia();

    p2.setCoordenadas(1.0,1.0);
    double distancia_p2 = p2.calcularDistancia();
    
    double distancia_p3 = p3.calcularDistancia();
    double distancia_p4 = p4.calcularDistancia();


    pontos[0].setCoordenadas(2,2);
    pontos[1].setCoordenadas(-1,5);
    pontos[2].setCoordenadas(0,0);

      for (int i = 0; i < 3; i++) {
        double distancia = pontos[i].calcularDistancia();       
        cout << "A distância do ponto " << i + 1 << " até a origem: aproximadamente " << distancia << endl;
    }


    cout << "A distância do ponto (3,4) até a origem é aproximadamente " << distancia_p1 << endl;
    cout << "A distância do ponto (1,1) até a origem é aproximadamente " << distancia_p2 << endl;
    cout << "A distância do ponto (0,3) até a origem é aproximadamente " << distancia_p3 << endl;
    cout << "A distância do ponto (4,0) até a origem é aproximadamente " << distancia_p4 << endl;
    return 0;
} 

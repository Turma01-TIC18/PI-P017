#include <iostream>
#include <cmath>

using namespace std; 

class Ponto{
    public:
    double x, y, distancia;

    Ponto() : x(0), y(0) {}

    Ponto (double x,  double y) : x(x), y(y){}

    void setCoordenadas(double x, double y){
        this-> x = x;
        this-> y = y;
    }
    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    float distanciaPontosOrigem(){
        return sqrt((x*x)+ (y*y));
    }
    

}; 


int main (){


    Ponto p1  (3,4);
    Ponto p2  (-2,7);
    Ponto p3  (0,3);
    Ponto p4  (4,0);
    Ponto pontos [3];
  

    cout << "A distancia do ponto ("<< p1.getX() << ", " << p1.getY() 
    << ") ate a origem eh aproximadamente: " <<p1.distanciaPontosOrigem() << endl;

    p2.setCoordenadas(1,1);
   
    cout << "A distancia do ponto ("<< p2.getX() << ", " << p2.getY() 
    << ") ate a origem eh aproximadamente: " <<p2.distanciaPontosOrigem() << endl;
  
    cout << "A distancia do ponto ("<< p3.getX() << ", " << p3.getY() 
    << ") ate a origem eh " <<p3.distanciaPontosOrigem() <<
    " e do ponto ponto ("<< p4.getX()<< ", " << p4.getY() << 
    ") ate a origem eh " << p4.distanciaPontosOrigem() << endl;

    pontos[0].setCoordenadas(2, 2);
    pontos[1].setCoordenadas(-1, 5);
    pontos[2].setCoordenadas(0, 0);

    for (int i = 0; i < 3; i++){
        double distancia = pontos [i].distanciaPontosOrigem();
        cout << "Distancia do ponto " << i + 1 << ": " << distancia << endl;
    }

return 0;
}
/*
Feito em uma tarde.
Me basieei no código do carro, o que facilitou.
Precisei mudar o tipo da variavel q estava sendo passada em div, para float.
*/

#include <iostream>
#include <sstream>
#include <iomanip>
#include <aux.hpp>

using namespace std;

struct Calculator {
    int batteryMax;
    int battery;
    float display;

    //Inicia os atributos, battery e display começam com o zero.
    Calculator(int x) { // todo
        
        batteryMax = x;
        battery =0;
        display =0;
        
    }

    //Aumenta a bateria, porém não além do máximo.
    void chargeBattery(int x) { // todo 
        
        battery += x;
        if (battery > batteryMax) battery = batteryMax;
        
    }

    //Tenta gastar uma unidade da bateria e emite um erro se não conseguir.
    bool useBattery() {
        if (battery == 0) cout << "fail: bateria insuficiente\n";
        return {}; // todo 
    }

    //Se conseguir gastar bateria, armazene a soma no atributo display.
    void sum(int a, int b) { // todo 
        if (battery == 0){
            cout << "fail: bateria insuficiente\n";
        }
        else {
            display = a + b;
            battery -=1;
            if (battery < 0) battery = 0;
        }
    }

    //Se conseguir gastar bateria e não for divisão por 0.
    void division(float num, float den) { // todo
        if (den == 0){
            battery -= 1;
            cout << "fail: divisao por zero\n";
        } 
        else if (battery == 0){
            cout << "fail: bateria insuficiente\n"; 
            battery -=1;
        }  else {
            battery -= 1;
            display = num / den;
        } 
        if (battery<0)battery =0;
        
    }

    //Retorna o conteúdo do display com duas casas decimais.
    sstring str() { 
        stringstream ss;
        ss << "display = " << std::fixed << std::setprecision(2) << this->display;
        ss << ", battery = " << this->battery;
        return ss.str();
    }
};

std::ostream& operator<<(std::ostream& os, Calculator c) {
    return (os << c.str());
}

int main() {
   
}

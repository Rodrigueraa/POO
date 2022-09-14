#include <iostream> 
#include <vector>
#include <sstream>

using namespace std;

struct carro{

    int pass = 0;
    int passmax = 2;
    int gas = 0;
    int gasmax = 100;
    int km = 0;

    entrar(){
        if (pass == passmax) cout << "capacidade maxima\n";
        else pass+=1;
    }

    sair (){
        if (pass == 0) cout << "nao ha ninguem\n";
        else pass -=1;
    }

    abastecer(int x){
        gas += x;
        if (gas > gasmax) gas = gasmax;
    }

    dirigir(int dis){
        if (pass == 0) cout << "fail: nao ha ninguem no carro\n";
        else if (gas == 0) cout << "fail: tanque vazio\n";
        else {
            gas -= dis;
        if(gas < 0){
            cout << "fail: tanque vazio apos andar " << dis + gas << " km\n";
            km += dis + gas;
            gas = 0;
        }
        else
            km += dis;
        }
    
    }
    

    string str(){

        stringstream ss;
        ss << "pass: " << pass << ", gas: " << gas << ", km: " << km << "\n";
        return ss.str();
    }

};

int main(){

    carro car;
    car.abastecer(25);
    cout << car.str();
    car.dirigir(30);
    cout << car.str();

}

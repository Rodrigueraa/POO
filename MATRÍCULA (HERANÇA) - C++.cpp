#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class classe{
    bool matriculado = {false};
    int matricula = rand() % 1000;
public:
    virtual bool isMatriculado(){
        return matriculado;
    }
    virtual void matricular(){
        matriculado = true;
    }
    virtual void removerMatricula(){
        matriculado = false;
    }
    virtual string str(){
        return string (matriculado ? "{Matriculado - " + to_string(matricula) +"}" + "\nMatriculado com sucesso!\n" : "{Nao matriculado}\nNao foi possivel matricular o aluno\n");
    } 
};

class escola : public classe{
    string nome;
    int idd;
    int maxIdd = {17};
public:

    escola(string nome, int idd) : nome(nome), idd(idd) {}

    virtual void matricular(){
        if (idd <= maxIdd) classe::matricular();
    }
    virtual string str(){
        return nome + " " + to_string(idd) + " " + classe::str();
    }
};

class universidade : public classe{
    string nome;
    int idd;
    int minIdd = {18};
public:

    universidade(string nome, int idd) : nome(nome), idd(idd) {}

    virtual void matricular(){
        if (idd >= minIdd) classe::matricular();
    }
    virtual string str(){
        return nome + " " + to_string(idd) + " " + classe::str();
    }
};


int main(){

    vector <shared_ptr<classe>> sistema;

    sistema.push_back(make_shared<escola>("Pedro", 16));
    sistema.push_back(make_shared<escola>("Joao", 17));
    sistema.push_back(make_shared<escola>("Maria", 12));
    sistema.push_back(make_shared<universidade>("Jose", 22));
    sistema.push_back(make_shared<universidade>("Ana", 17));
    sistema.push_back(make_shared<universidade>("Paulo", 18));

    for (auto classe : sistema){
        classe->matricular();
    }
    for (auto classe : sistema){
        cout << classe->str() << endl;
    }
}   

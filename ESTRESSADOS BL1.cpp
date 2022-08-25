#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

bool existe(vector <int> vet, int num){
    //ok
    for (auto i : vet)
        if (i == num) return true;
    return false;
}

int Posi_Primeira_Vez_Aparece(vector <int> vet, int num){
    //ok
    for (int i = 0; i < (int) vet.size(); i++){
        if (vet[i] == num) return i;
    }
    return -1;
}

int Posi_Primeiro_Homem(vector <int> vet){
    //ok
    for (int i = 0; i < (int) vet.size(); i++){
        if (vet[i] > 0) return i;
    }
    return -1;
}

int Posi_Menor_Valor(vector <int> vet){
    //ok
    int num = 0;
    for (int i = 0; i < (int) vet.size(); i++){
        if (vet[i] < vet[num]){
            num = i;
        }
    }
    return num;
}

int Posi_Homem_Mais_Calmo(vector <int> vet){
    //ok
    int x = -1;
    for(int i = 0; i < (int)vet.size(); i++)
        if(vet[i] > 0 && vet[i] < vet[x])
            x = i;
    return x;
}

int Quantas_Vezes_Aparece(vector <int> vet, int num){
    //ok
    int con = 0;  
    
    for (auto i : vet)
        if (i == num) con++;
    return con;
}

float Media_Stress (vector <int> vet){
    //ok
    float con = 0;
    for (auto i : vet){
        if (i < 0) con += -i;
        else con += i;
    }
    return con / vet.size();
}

string Metade_Stress(vector <int> vet){ //Qual metade é mais estressada
    //ok
    if ((int) vet.size() == 0) return "-1";
    
    int m1= 0;
    int m2= 0;

    //i percorre primeira metade, j segunda metade
    for (int i = 0, j = (int) vet.size() / 2; i < (int) vet.size() / 2; i++, j++){

        if (vet[i] < 0) vet[i] *= -1;
        if (vet[j] < 0) vet[j] *= -1;

        m1 += vet[i];
        m2 += vet[j];
    }

    if (m1 == m2) return "Draw"; 
    if (m1 > m2) return "First";
    return "Second";
}

string Mais_HouM(vector <int> vet){

    if ((int) vet.size() == 0) return "-1";

    int h= 0, m= 0;

    //verifica cada elemento do vetor e ve se é h ou m
    for (auto i : vet){
        if (i > 0) h++; // vet[i]?
        else m++;
    }

    if (h == m) return "Draw";
    if (h > m) return "Men";
    return "Women";
}

string GP_Mais_Stress (vector <int> vet){

    int sh = 0;
    int sm = 0;

    for (auto i : vet){
        if (vet[i] > 0) sh += i;
        else sm += i * -1;
    }

    if (sh == sm) return "Draw";
    return sh > sm ? "Men" : "Women";
}

int main(){

    int tam, num;
    cin >> tam >> num;

    vector <int> vetor (tam);
    for (int i = 0; i < tam; i++){
        cin >> vetor[i];
    }

    cout << "\nBLOCO 1:\n";                                                          
    cout << "\nFIND:\n\n";   

    cout << (existe(vetor, num) ? "Sim ---- Existe? \n" : "Nao ---- Existe? \n");
    cout << Posi_Primeira_Vez_Aparece(vetor, num) << " -- Primeira vez que aparece\n";
    cout << Posi_Primeiro_Homem(vetor) << " -- Posi primeiro homem\n";
    cout << Posi_Menor_Valor(vetor) << " -- Posi menor valor\n";
    cout << Posi_Homem_Mais_Calmo(vetor) << " -- Posi homem mais calmo";

    cout << "\n\nCOUNT:\n\n";
    cout << Quantas_Vezes_Aparece(vetor, num) << " -- Aparece quantas vezes? \n";
    cout << Media_Stress(vetor) << " -- Media stress\n";
    cout << Metade_Stress(vetor) << " - Qual metade? \n";
    cout << Mais_HouM(vetor) << " -- Mais homem ou mulher?\n";
    cout << GP_Mais_Stress(vetor) << " -- Qual grupo e mais estressado?\n"; 

}

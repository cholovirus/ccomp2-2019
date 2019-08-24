#include <iostream>

using namespace std;

void vuelto(float var){

    int entero= var; 
    float decimal= var*10; int decimal_entero=(entero*10)-decimal; 

    int monedas[8]={200,100,50,20,10,5,2,1};
    int centimos[3]={5,2,1};
    
    int contador=0;
    
    
    for(int i=0;i<8;i++){
        contador=entero/monedas[i];
        entero=entero%monedas[i];
        cout<<"moneda: "<<monedas[i]<<"--"<<contador<<endl;
        if(!entero){break;}
    }
    for(int i=0;i<3;i++){
        contador=decimal_entero/centimos[i];
        decimal_entero%=centimos[i];
        cout<<"centimo: "<<centimos[i]<<"--"<<contador<<endl;
    }
    
    
}
int main(){
    float a;
    cin>>a;
    vuelto(a);
}
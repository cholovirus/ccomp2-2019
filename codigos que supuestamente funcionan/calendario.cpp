#include <iostream>

using namespace std;

int congruenciazeller(int agno, int mes){
    int a= (14-mes)/12;
    int y= (agno-a);
    int m= mes+12*a-2;
    int dia=1;
    int d=(dia+y+y/4-y/100+y/400+(31*m)/12)%7;
    return d; 
}

int viciesto(int agno){
    if( !(agno%4) && agno%100 || !(agno%400)){return 29;}
    else{return 28;}
}

int diaMes(int agno, int mes){
    
    for(int i=1;i<12;i+=2){
        int j=i+5;
        if(mes == i || mes == j){return 31;}
    }
    if(mes == 2 ){ return viciesto(agno);}
    return 30;
}

void calendario(int agno, int mes){
    string meses[12]={"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Setiembre","Octubre","Noviembre","Diciembre"};
    cout<<endl;
    cout<<meses[mes-1]<<" de "<<agno<<endl;
    cout<<"Dom Lun Mar Mir Jue Vie Sab"<<endl;
    int zeller=congruenciazeller(agno,mes);
        for(int j=0;j<zeller;j++){
            cout<<"    ";
        }
    for(int i=1; i<=diaMes(agno,mes);i++){
        
        printf("%3d ",i);
        zeller++;
        if(!(zeller%7)){cout<<endl;}
    }
}
int main(){
    int mes,agno;

    cout<<"Escriba un agno: "; cin>>agno;
    if(1>agno){ cout<<"Utilice un numero mayor a 0";return 0;}

    cout<<"Escriba un mes del agno: "; cin>>mes;
    if(1>mes || mes>12){ cout<<"Utilice un numero del 1 al 12"<<endl; return 0;}

    //cout<<diaMes(agno,mes);
    //cout<<viciesto(agno);
    calendario(agno, mes);
}
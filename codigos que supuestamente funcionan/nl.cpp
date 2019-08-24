#include <iostream>
#include <string>

using namespace std;

void numeroletra(int i){
    if(i==0){cout<<"cero"<<endl;return;}
    if(i<0 || i>1000000000){cout<<"Escriba un numero del 1 al 1000000000:";int aux; cin>>aux; return numeroletra(aux);}

    string num[101]={"","uno","dos","tres","cuatro","cinco","seis","siete","ocho","nueve","diez"
    ,"once","doce","trece","catorce","quince","diesiseis","diesisiete","dieciocho","diecinueve","veinte"
    ,"veintiuno","veintidos","veintitres","veinticuatro","veinticinco","veintiseis","veintisiete","veintiocho","veintinueve","treinta"
    ,"treinta y uno","treinta y dos","treinta y tres","treinta y cuatro","treinta y cinco","treinta y seis","treinta y siete","treinta y ocho"
    ,"treinta y nueve","cuarenta","cuarenta y uno","cuarenta y dos","cuarenta y tres","cuarenta y cuartro","cuarenta y cinco","cuarenta y seis"
    ,"cuarenta y siete","cuarenta y ocho","cuarenta y nueve","cincuenta","cincuenta y uno","cincuenta y dos","cincuenta y tres","cincuenta y cuatro"
    ,"cincuenta y cinco","cincuenta y seis","cincuenta y siete","cincuenta y ocho","cincuenta y nueve","sesenta","sesenta y uno","sesenta y dos"
    ,"sesenta y tres","sesenta y cuatro","sesenta y cinco","sesenta y seis","sesenta y siete","sesenta y ocho","sesenta y nueve","setenta"
    ,"setenta y uno","setenta y dos","setenta y tres","setenta y cuatro","setenta y cinco","setenta y seis","setenta y siete","setenta y ocho"
    ,"setenta y nueve","ochenta","ochenta y uno","ochenta y dos","ochenta y tres","ochenta y cuatro","ochenta y cinco","ochenta y seis","ochenta y siete"
    ,"ochenta y ocho","ochenta y nueve","noventa","noventa y uno","noventa y dos","noventa y tres","noventa y cuatro","noventa y cinco"
    ,"noventa y seis","noventa y siete","noventa y ocho","noventa y nueve","cien"};
    
    string numd[10]={"","ciento","doscientos","trecientos","cuatrocientos","quinientos","seiscientos","setecientos","ochocientos","novecientos"};
    //arreglar cuando termine en uno con 21000   
    if(i == 1000000000){cout<<"mil millones"<<endl;}
    if(i>=1000000 && i<1000000000){
        int millon=i/1000000;
        int centena=millon/100;
        int decena=millon%100;

        //if(millon != 1 && millon !=100){cout<<numd[centena]<<" "<<num[decena]<<" "<<"millones ";}
        if(millon != 1 && millon != 100){
            if(centena >= 1 && decena == 1){cout<<numd[centena]<<" un millones ";}
            else if(decena%10 == 1 && decena/10 == 2){cout<<numd[centena]<<" "<<"veinti un millones ";}
            else if(decena%10 ==1 && decena/10 > 2){cout<<numd[centena]<<" "<<num[decena-1]<<" y un millones ";}
            else{cout<<numd[centena]<<" "<<num[decena]<<" millones ";}
        }
        else if(millon == 100){cout<<num[millon]<<" millones ";}
        else{cout<<"un millon ";}
        i%=1000000;       
    }

    if(i>=1000 && i<1000000){
        int millar=i/1000;
        int centena=millar/100;
        int decena=millar%100;

        
        if(millar != 1 && millar != 100){
            if(centena >= 1 && decena == 1){cout<<numd[centena]<<" un mil ";}
            else if(decena%10 == 1 && decena/10 == 2){cout<<numd[centena]<<" "<<"veinti un mil ";}
            else if(decena%10 ==1 && decena/10 > 2){cout<<numd[centena]<<" "<<num[decena-1]<<" y un mil ";}
            else{cout<<numd[centena]<<" "<<num[decena]<<" mil ";}
        }
        else if(millar == 100){cout<<num[millar]<<" mil ";}
        else{cout<<"mil ";}

        i%=1000;
    }

    if(i>100 && i<1000){
        int decena=i%100;
        int centena=i/100;
        cout<<numd[centena]<<" "<<num[decena]<<endl;
    }
    if(i<=100){cout<<num[i]<<endl;}
    
}

int main(){
    int numero; 
    cout<<"Escriba un numero : "; cin>>numero;
    numeroletra(numero);
}
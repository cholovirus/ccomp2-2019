#include <iostream>
#include <string>

using namespace std;

int romanoDecimal(string romano){
    
    //1,10,100,1000
    int cont[4]={0,0,0,0};
    //-1,-100,-100
    int contN[3]={0,0,0};
    //5,50,500
    int d5[3]={0,0,0};
    //-5,-50,-500
    int d5N[3]={0,0,0};

    bool crap= true;

    int size_=romano.size();
    
    int total=0;
    //81 ARREGLAR
    for(int i=0;i<size_;i++){
        if(romano[i]!= 'I'&& romano[i]!= 'V' && romano[i]!= 'X' && romano[i]!= 'L'&&romano[i]!= 'C'&& romano[i]!= 'D'&& romano[i]!= 'M'){crap=false;break;}
        
        if(romano[i] == 'M'){
            if(romano[i-2] == 'C' && romano[i-1] == 'C'){crap=false;break;}
            if(romano[i-1] == 'I' || romano[i-1] == 'V' || romano[i-1] =='L'){crap=false;break;}
            if(romano[i-1] == 'C' && romano[i+1] == 'C'){crap=false;break;}

            if(romano[0]== 'M' || romano[0] == 'C'){
                if(romano[i-1] == 'C'){total+=800; contN[2]-=1;continue;}
                total+=1000,cont[3]+=1;continue;}
            else{crap=false;break;}
        }

        if(romano[i] == 'D'){
            if(romano[i-2] == 'C' && romano[i-1] == 'C'){crap=false;break;}
            if(romano[i-1] == 'C' && romano[i+1]== 'C'){crap=false;break;}

            if(romano[0]== 'D' || romano[0] == 'C'){
                if(romano[i-1] == 'C'){total+=300;d5[2]+=1;continue;}
                total+=500;d5[2]+=1;continue;}
            else{crap=false;break;}
        }
        if(romano[i] == 'C'){
            
            if(romano[i-1] == 'I' || romano[i-1] == 'V' || romano[i-1] =='L'){crap=false;break;}
            if(romano[i-1] == 'X' && romano[i+1] == 'X'){crap=false;break;}

            if(romano[0]== 'C' || romano[0] == 'X'||romano[0] =='D' || romano[0] == 'M'){
                if(romano[i-1] == 'X'){total+=80; contN[1]-=1;continue;}
                total+=100,cont[2]+=1;continue;}
            else{crap=false;break;}
            
        }

        if(romano[i]== 'L'){
            if(romano[i-1] == 'X' && romano[i+1] == 'X'){cont[1]=10;break;}
            if(romano[i-1] == 'X' && size_==2 ){total=40;d5[1]+=1;contN[1]-=1;continue;}
            if(romano[i-1] == 'X' ){total+=30;d5[1]+=1;contN[1]-=1;if(romano[i-2]== 'X'){crap=false;} continue;}
            if(romano[i-1] == 'V' ){d5N[0]-=1;break;}
            if(romano[i-1] == 'I'){crap=false;break;}
           
            total+=50;d5[1]+=1;
        }     

        if(romano[i] == 'X'){
            for(int j=i+1;j<size_;j++){
                if(romano[j]!='X' && cont[1]<3 && romano[j] != 'I' && romano[j] != 'V'){contN[1]=cont[1]*-1;continue;} 
            }
            if(romano[i-1] == 'V' ){d5N[0]-=1;break;}
            if(romano[i-1] == 'I' && size_ == 2 ){total=9;cont[1]+=1;contN[0]-=1;continue;}
            if(romano[i-1] == 'I' ){total+=8;d5[0]+=1;contN[0]-=1;continue;}
            
            total+=10;cont[1]+=1;
        }

        if(romano[i]== 'V'){
            if(romano[i-1] == 'I' && romano[i+1] == 'I'){contN[0]=-10;break;}
            if(romano[i-1] == 'I' ){total+=3;d5[0]+=1;contN[0]-=1;continue;}
            
            total+=5;d5[0]+=1;
        }

        if(romano[i] == 'I'){
            for(int j=i+1;j<size_;j++){
                if(romano[j]!='I' && cont[0]<3 ){contN[0]=cont[0]*-1;continue;}
                }

            total+=1;cont[0]+=1;
        }
        
    }

    if((crap && contN[0] >= -1 && cont[0]<= 3) && (d5N[0]> -1 && d5[0]<2 ) && (contN[1]>= -1 && cont[1]<=3) && (d5[1]<2) && (cont[2]<=3) && (d5[2]<2) 
    && cont[3]<=3)
        cout<<total<<endl;
    else{cout<<"gg profe"<<endl;}
    
}

int main(){
    string Nromano;
    cin>>Nromano;
    romanoDecimal(Nromano);

}
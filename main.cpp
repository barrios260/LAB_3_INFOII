#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;
//crear usuarios
void create_user(string);
//validar clave
void validate_pass(string);
//funcion a binario
string TextToBinaryString(string words);

int main()
{
    int choose;
    cout<<"---elija como quiere ingresar.---"<<endl;
    cout<<"1. como administrador."<<endl;
    cout<<"2. como usuario."<<endl;
    cin>>choose;

    switch(choose){
    case 1:{
        string cedula;
        create_user(cedula);

    }


        break;
    case 2:{
    }
        break;
    }
}

//funcion que permite al administrador crear un usuario
void create_user(string){

    string cedula,saldo,clave,id,pass,mon,datos1;
    int i=0;
    try {                                       //try catch que valida solo el ingreso de numeros en la cedula
        cout<<"ingrese el numero de cedula: ";
        cin>>cedula;
        while(cedula[i]){
            if(isalpha(cedula[i]))throw'1';
            i++;
        }
        char c=',',p='.';
        cedula.append(1,c );//add a la cedula una coma al final para codificar el archivo
        id=TextToBinaryString(cedula);
        cout<<"digite la clave para el usuario: "<<cedula<<endl;
        cin>>clave;
        clave.append(1,c);//add a la clave coma al final para codificar archivo
        pass=TextToBinaryString(clave);
        cout<<"digite el saldo para el usuario: "<<cedula<<endl;
        cin>>saldo;

        saldo.append(1,p);
        mon=TextToBinaryString(saldo);
    }
    catch(char c) {
        if(c=='1')
        cout<<"sr. admin solo puede ingresar numeros en la cedula..."<<endl;
    }
datos1=id+pass+mon;
cout<<datos1<<endl;
}

void validate_pass(string){

}
string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    return binaryString;
}


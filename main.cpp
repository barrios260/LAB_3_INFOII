#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;
//crear usuarios
void create_user(string);
//validar clave
void validate_pass(string);

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

    string cedula,saldo,clave;
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
        cout<<"digite la clave para el usuario: "<<cedula<<endl;
        cin>>clave;
        clave.append(1,c);//add a la clave coma al final para codificar archivo
        cout<<"digite el saldo para el usuario: "<<cedula<<endl;
        cin>>saldo;

        saldo.append(1,p);
        cout<<"los datos ingresados fueron: "<<endl<<cedula<<clave<<saldo<<endl;
    }
    catch(char c) {
        if(c=='1')
        cout<<"sr. admin solo puede ingresar numeros en la cedula..."<<endl;
    }

}
void validate_pass(string){

}

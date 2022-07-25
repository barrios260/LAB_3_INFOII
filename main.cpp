#include <iostream>
#include <string.h>
#include <fstream>
#include <sstream>


using namespace std;
//crear usuarios
void create_user(int );
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
        int cedula;
        create_user(cedula);

    }


        break;
    case 2:{
    }
        break;
    }
}
void create_user(int){
    cout<<"ingrese el numero de cedula: ";
    int cedula;
    cin>>cedula;
    try{
    if(isalpha(cedula))
       cout<<"cedula ingresada correctamente. ";
    }
    catch(int cedula){
        cout<<"solo debes ingresar numeros...";
    }
}

void validate_pass(string){

}

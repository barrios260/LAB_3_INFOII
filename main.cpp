#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;
//crear usuarios
void create_user(string);
//funcion a binario
string TextToBinaryString(string);
//funcion para encriptar
void encrypted();
//funcion que retorna el archivo txt leido
string return_read();

int main()
{
    int choose;
    cout<<"***** elija como quiere ingresar ****"<<endl;
    cout<<"1. como administrador."<<endl;
    cout<<"2. como usuario."<<endl;
    cin>>choose;

    switch(choose){

    case 1:{
        //encrypted();
        string linea,aux,clave;
        ifstream archivo("sudo.txt");
        getline(archivo,linea);//linea extraida desde el archivo sudo.txt
        aux=linea;//aux quedara con el valor de la clave
        cout<<"ingrese la clave de administrador: ";
        cin>>clave;
        while(clave!=aux){//si la clave ingresada es diferente se pedira la clave
            cout<<"ingrese la clave de administrador: ";
            cin>>clave;
    }

        archivo.close();

        cout<<"***ingreso exitoso al sistema como usuario administrador*** "<<endl;
        cout<<"------------------------------------------------"<<endl;
        cout<<"digite los datos para crear los usuarios "<<endl;
        string cedula;
        create_user(cedula);
        //return_read();
        //validate_pass();
    }
        break;
    case 2:{
    }
        break;
    }
}

//funcion que permite al administrador crear un usuario
void create_user(string){
    string cedula,clave,id,pass,mon,datos1,saldoo;//datos pedidos para crear usuario
    char c=',',p='.';
    int i=0,saldo;
    bool finalizo=true;
    while(finalizo){
    try {                                       //try catch que valida solo el ingreso de numeros en la cedula
        cout<<"ingrese el numero de cedula: ";
        cin>>cedula;
        while(cedula[i]){
            if(isalpha(cedula[i]))throw'1';
            i++;
        }
        finalizo=false;
    }
    catch(char b) {
        if(b=='1')
        cout<<"sr. admin solo puede ingresar numeros en la cedula..."<<endl;
    }
    }
finalizo=true;
    cedula.append(1,c );//añade una coma para separar en el archivo
    id=TextToBinaryString(cedula);
     while(finalizo){
     try{//cacth que permite
        cout<<"digite la clave solo debe usar 4 caracteres: "<<endl;
        cin>>clave;
        if(clave.length()>4 and clave.length()<3){
            throw'2';
        }
        finalizo=false;
        }
        catch(char c){
            if (c=='2')
                cout<<"la clave solo debe contener 4 caracteres..."<<endl;
        }
     }
     finalizo=true;
        clave.append(1,c);//add a la clave coma al final para codificar archivo
        pass=TextToBinaryString(clave);
    while(finalizo){
        try{
        cout<<"digite el saldo para el usuario: "<<endl;
        cin>>saldo;
        if(saldo<0){
            throw'3';
        }
        finalizo=false;
         }
        catch(char d){
            if(d=='3')
                cout<<"el dinero solo puede ser mayor o igual que cero..."<<endl;

        }
}
        to_string(saldo);
        saldoo.append(1,p);
        mon=TextToBinaryString(saldoo);

//datos1=id+pass+mon;
//cout<<datos1<<endl;
}

/*
 * funcion que realiza la conversion de caracteres ascci a
 * binario para la encriptacion de la contraseña del admin
*/
string TextToBinaryString(string words) {
    string binaryString = "";
    for (char& _char : words) {
        binaryString +=bitset<8>(_char).to_string();
    }
    return binaryString;
}
/*funcion que realizara la encriptacion de la contraseña del admin*/
void encrypted(){
    string aux,linea;
    ifstream archivo("sudo.txt");
    ofstream archivo1("sudo.txt");
    getline(archivo,linea);//linea extraida desde el archivo sudo.txt
    aux=TextToBinaryString(linea);

    archivo1<<aux;

    archivo1.close();
    archivo.close();

}



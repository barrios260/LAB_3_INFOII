#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstring>
#include <bitset>
using namespace std;
/*//crear usuarios
void create_user(string);
//funcion a binario
string TextToBinary(string);
//funcion para encriptar
string BinaryToText(string);
//funcion para encriptar
string encrypted(int n,string text);
//funcion que desencripta
string desencrypted(int n,string binario);
//funcion que retorna el archivo txt leido
string return_read();
string manejo_txt();
void bin_read();
void write(string contenido, string txt);
void cod_write();*/

class manejo_txt
{
public:
    manejo_txt();

    string Str_Bin(string contenido);//
    /*En el metodo Str_bin se encarga de cambiar una varible string a un numero
     * binario, ya puede ser una cadena de texto o un caracter
    */

    string codificar(int n, string archiEnt);//
    /*En el metodo codificar se encarga de codificar el string archiEnt por el metodo de
     * convertir el archivo a binario, luego se separa en bloques de n bits. Cada bit
     * dentro de un grupo se desplaza una posiciÃ³n, de manera que el primer bit del grupo
     * codificado corresponde al Ãºltimo bit del grupo sin codificar, el segundo bit
     * codificado corresponde alprimero sin codificar y asÃ­ sucesivamente hasta que el Ãºltimo
     * corresponde al penÃºltimo sincodificar.
    */

    string decodificar(int n, string CadBinario);//
    /*En el metodo decodificar se encarga de hacer el proceso inverso del metodo codificar
     * primero decofica segun el metodo utilizado y despues cambia el numero binario decodificado
     * a string
    */

    string Bin_Str(string CadCode);//
    /*En el metodo Bin_Str se encarga de cambiar una varible binarioa un string
     * ya puede ser una cadena de texto o un caracter
    */

    void Bin_lectura();//
    /*En el metodo Bin_lectura se encarga de leer el archivo.txt, hacer el proceso de
     * decodificacion y despues modificar el contenido de un string con tosa la informacion
     * que se encuentra en el txt
    */

    void codi_escritura();//
    /*En el metodo codi:escritura se encarga de cambiar el contenido de la variable string
     * que posee la informacion por la misma informacion pero codificada y despues
     * pasa a escribir toda la variable en un txt
    */

    string LectuArchi();
    /*En el metodo LectuArchi se encarga de leer un archivo.txt y colocarlo todo
     *  en una variable tipo string
    */


    void escribir( string contenido,string txt);
    /*En el metodo escribir se encarga de escribir un archivo.txt con la informacion correspondiente
     *  en una variable tipo string
    */


    string getArchivo() const;
    void setArchivo(const string &value);

private:
    string txt="users.txt";

    string archivo;

    int n=4;

};

class Usu_Admin
{
public:
    Usu_Admin();

    bool confirAdmin( string claveAdmin);
    /*En el metodo confirAdmin se encarga de verificar si la contraseÃ±a ingresada por el
     *  administrador coincide en con la contraseÃ±a en la base de datos
    */

    int confirUsu(string claveUsuario);
    /*En el metodo confirUsu se encarga de verificar si la contraseÃ±a ingresada por el
     *  usuario coincide en con la contraseÃ±a en la base de datos
    */

    string NuevoUsu();
    /*En el metodo NuevoUsu se encarga de ingresar en un txt el nuevo usuario del cajero
     *
    */

    int Dinero();
    /*En el metodo dinero se encarga de sacar el dinero del usuario encontrado
     *  en la variable tipo string

    */

    string CambioDinero();
    /*En el metodo CambioDinero se encarga de cambiar la informacion del dinero despues del
     * retiro o el descuento por la cuota de manejo en la variable string
    */

    string getArchivo() const;
    void setArchivo(const string &value);

    unsigned int getCash() const;
    void setCash(unsigned int value);

private:
    string NuevoUsuario;

    string claveUsuario;

    unsigned int dinero, cash=0;

    string archivo;

    int A=0;
};



int main()
{
    class manejo_txt archiv;
    Usu_Admin Usuari;
    string B;
    //ingresa usuario


    archiv.Bin_lectura();
    Usuari.setArchivo(archiv.getArchivo());
    unsigned int opcion = 0 ,opcion2 = 0;
    int dinero=0,i;
    string cedula,clave,claveAdmin,claveUsuario;

    cout<<"Bienvenido!!"<<endl;
    cout<<"introduzca el numero que le aparece en pantalla para ingresar: "<<endl;
    cout<<"0.Administrador"<<endl;
    cout<<"1.Usuario"<<endl;
    cout<<"2.Salir"<<endl;
    cout<<">>";
    cin>>opcion;
    cout<<"////////////////////////////////////////////////////////////"<<endl;
    switch(opcion){
        case 0:
            cout<<"por favor introduzca la contraseña:"<<endl;
            cout<<">>";
            cin>>claveAdmin;
            cout<<"////////////////////////////////////////////////////////////"<<endl;

            if (Usuari.confirAdmin(claveAdmin)){
                int opc=0;
                cout<<"Bienvenido administrador"<<endl;
                cout<<"Ingrese el numero correspondiente: "<<endl;
                cout<<"0.ingresar nuevo usuario"<<endl;
                cout<<"1.salir"<<endl;
                cout << " >> ";
                cin>>opc;
                cout<<"////////////////////////////////////////////////////////////"<<endl;

                if (opc ==0){
                    archiv.setArchivo(Usuari.NuevoUsu());
                    archiv.codi_escritura();
                }
                else{
                    break;
                }
            }
            else{
                cout<<"Contrasenia incorrecta, ingreso no permitido"<<endl;
            }
        break;

        case 1:
            cout<<"por favor introduzca la contrasenia :"<<endl;
            cout<<"ingreselo de la siguente forma:"<<endl;
            cout<<"cedula: ";
            cout<<"clave: ";
            cin>>clave;
            claveUsuario=cedula+clave;
            cout<<"////////////////////////////////////////////////////////////"<<endl;

            if (Usuari.confirUsu(claveUsuario)){
                cout<<"Bienvenido!!"<<endl;
                cout<<"Ingrese el numero correspondiente: "<<endl;
                cout<<"0. consultar saldo"<<endl;
                cout<<"1.retirar dinero"<<endl;
                cout<<"2.salir"<<endl;
                cout<<">>";
                cin>>opcion2;

                cout<<"////////////////////////////////////////////////////////////"<<endl;

                switch(opcion2){

                    case 0:

                        if (Usuari.Dinero() >1000){
                            cout<<"su saldo es de "<<Usuari.getCash()<<endl;
                            Usuari.setCash((Usuari.getCash())-1000);
                            archiv.setArchivo(Usuari.CambioDinero());
                            archiv.codi_escritura();
                        }
                        else{
                            cout<<"la opcion no es permitida"<<endl;
                            cout<<"¡Vuelva pronto!";
                        }
                        cout<<"////////////////////////////////////////////////////////////"<<endl;
                        break;
                    case 1:
                        cout<<"ingrese la cantidad de dinero a retirar:"<<endl;
                        cout<<">>";
                        cin>>dinero;

                        cout<<"////////////////////////////////////////////////////////////"<<endl;
                        if (Usuari.Dinero() > (1000+dinero)){
                            Usuari.setCash((Usuari.getCash())-dinero);
                            cout<<"Gracias por usar el cajero, vuelva pronto"<<endl;
                            cout<<"Su saldo restante es de "<<Usuari.getCash()<<endl;
                            Usuari.setCash((Usuari.getCash())-1000);;
                            archiv.setArchivo(Usuari.CambioDinero());
                            archiv.codi_escritura();
                        }
                        else{
                            cout<<"la opcion no es permitida, no cuenta con suficiente dinero"<<endl;
                        }
                        break;

                    case 2:
                        break;
                    }
                }
            }
    return 0;
}


/*funciones para el administrador
 * funcion para crear un usuario
 * funcion para convertir caracteres a binario
 * funcion para convertir binario a caracteres
 * funcion para encriptar
 * funcion para desencriptar*/
/*
void create_user(string){
    string cedula,clave,id,pass,mon,datos1,saldoo;//datos pedidos para crear usuario
    char p='.';
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
    cedula.append(1,p);//aniade un punto
    id=TextToBinary(cedula);
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
        clave.append(1,p);//add a la clave coma al final para codificar archivo
        pass=TextToBinary(clave);
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
        mon=TextToBinary(saldoo);
}


string TextToBinary(string words) {
    string binary = "";
    for (char& _char : words) {
        binary +=bitset<8>(_char).to_string();
    }
    return binary;
}

string BinaryToText(string n){
    int tam=n.length(),multiplicador=1,decimal=0;
    string text;
    for(int i=0;i<tam/8;i++){
        //multiplicador;
        //decimal;
        for(int j=0,palbin=(i+1)*8-1;j<8;j++,palbin--){
            if(n[palbin]=='1'){
                decimal+=multiplicador;
            }
            multiplicador=multiplicador*2;
        }
        text+=decimal;
    }
return text;
}

string encrypted(int n,string text){
    string letra,binario;
    int esp=0,sup,largo=binario.length();
    binario=TextToBinary(text);

    for(int i=0;i<largo;i++){
        letra+='.';
    }
    if(largo%n != 0){
        esp++;
    }
    sup=esp==1?(largo/n)+1:largo/n;
    for(int j=0;j<sup;j++){
        esp=largo%n;
        if(j==largo/n){
            letra[j*n]=binario[(j*n+esp)-1];
            for(int k=n*j;k<(j*n+esp-1);k++){
                text[k+1]=binario[k];
            }
        }
        else{
            letra[j]=binario[n*(j+1)-1];
            for(int k=n*j;k<(n*(j+1)-1);k++){
                text[k+1]=binario[k];
            }
        }
    }
    return text;
}

string return_read(){
    string data;
    // Abre el archivo en modo lectura
       ifstream infile;

       // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
       infile.open("sudo.txt");

       // Se comprueba si el archivo fue abierto exitosamente
       if (!infile.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }

       cout << "Leyendo el archivo" << endl;
       infile >> data;

       // Se escribe el dato en la pantalla
       cout << data << endl;

       string linea;
       int contador =0;
       while(!infile.eof()){
           contador++;

           if (contador>1){
               data+='\n';
           }
           getline(infile,linea);
           data+=linea;

       }

       // Se cierra el archivo abierto
       infile.close();
       return data;
}
string desencrypted(int n,string binario){
    string CadCode;
        string CadTxt;



        int Especial=0, PartSup;

        int Longitud=binario.length();

        for(int elem = 0; elem<Longitud;elem++){
            CadCode += ' ';
        }

        if (Longitud%n != 0){
            Especial++;
        }
        PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
        for(int NLego = 0 ;NLego < PartSup; NLego ++){
            Especial=Longitud%n;
            if(NLego==Longitud/n){
                CadCode[(NLego*n + Especial)-1] = binario[NLego*n];
                for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                    CadCode[i]=binario[i+1];
                }
            }
            else{
                CadCode[n*(NLego+1)-1]=binario[NLego*n];
                for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                    CadCode[i]=binario[i+1];
                }

            }
        }

        CadTxt=BinaryToText(CadCode);
        return CadTxt;

}

string manejo_txt(){
       string archi2 = return_read();
       string copiaArch,C,txtBin;
       int longitud2 = archi2.length();


       for(int i=0;i<longitud2;i++){
           if (archi2[i]=='\n' or archi2[i]==' '){
               C=encrypted(4,copiaArch);
               txtBin+=C;
               if (archi2[i]=='\n'){
                   txtBin+='\n';
               }
               else{
                   txtBin+=' ';
               }
               copiaArch="";
           }
           else {
               copiaArch+=archi2[i];

           }
       }
       C=encrypted(4,copiaArch);
       txtBin+=C;
       archi2=txtBin;
       return archi2;
}
void bin_read(){
    string archi2 = manejo_txt();
        string copiaArch,C,txtBin;
        int longitud2 = archi2.length();


        for(int i=0;i<longitud2;i++){
            if (archi2[i]=='\n' or archi2[i]==' '){
                C=encrypted(4,copiaArch);
                txtBin+=C;
                if (archi2[i]=='\n'){
                    txtBin+='\n';
                }
                else{
                    txtBin+=' ';
                }
                copiaArch="";
            }
            else {
                copiaArch+=archi2[i];

            }
        }
        C=desencrypted(4,copiaArch);
        txtBin+=C;
        archi2=txtBin;

}

void write(string contenido){
    ofstream archi;

        archi.open("sudo.txt");

        if (!archi.is_open())
           {
             cout << "Error abriendo el archivo" << endl;
             exit(1);
           }
        archi << contenido;

        archi.close();
}

void cod_write(){
     string copiaArch,C,txtBin,archivo=manejo_txt();
    int longitud=archivo.length();

    for(int i=0;i<longitud;i++){
        if (archivo[i]=='\n' or archivo[i]==' '){
            C=encrypted(4,copiaArch);
            txtBin+=C;
            if (archivo[i]=='\n'){
                txtBin+='\n';
            }
            else{
                txtBin+=' ';
            }
            copiaArch="";
        }
        else {
            copiaArch+=archivo[i];

        }
    }
    C=encrypted(4,copiaArch);
    txtBin+=C;
    write(txtBin,"sudo.txt");

}
*/
Usu_Admin::Usu_Admin()
{

}
bool Usu_Admin::confirAdmin( string claveAdmin){
    //validar contraseña Administrador
    int longitud=archivo.length();
    string copiContraArchi;
    for (int i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            copiContraArchi+=archivo[i];
        }
        else{
            break;
        }
    }
    if (copiContraArchi == claveAdmin){
        cout<<"ingreso permitido"<<endl;
        return true;
    }
    else{
        return false;
    }
}

int Usu_Admin::confirUsu(string claveUsuario){
    int longitud=archivo.length();
    string copiContraArchi;
    int contEspa=0, i;
    for (i =0;i< longitud;i++){
        if (archivo[i] != '\n' ){
            if (archivo[i]== ' ' and contEspa <2){
                contEspa++;
            }
            if(contEspa==2 and claveUsuario== copiContraArchi){
                cout<<"ingreso usuario permitido"<<endl;

                return A;
            }
            copiContraArchi+=archivo[i];
        }
        else{
            copiContraArchi="";
            A++;
        }
    }

    cout<<"ingreso Usuario No permitido"<<endl;
    return 0;

}
string Usu_Admin::CambioDinero(){
    int longitud=archivo.length();
    string copiaArchi;
    int contador=0,contaEsp=0;
    for (int i =0;i< longitud;i++){
        if (archivo[i] == '\n' ){
            contador++;
        }
        if (contador==A and archivo[i]==' '){
            contaEsp++;
        }
        if(contador==A and contaEsp==2){
            copiaArchi+=' ';
            copiaArchi+=to_string(cash);
            contaEsp++;

        }
        else if (contador==A and contaEsp==3){
        }
        else{

            copiaArchi+=archivo[i];
        }
    }
    return copiaArchi;
}


string Usu_Admin::getArchivo() const
{
    return archivo;
}

void Usu_Admin::setArchivo(const string &value)
{
    archivo = value;
}

unsigned int Usu_Admin::getCash() const
{
    return cash;
}

void Usu_Admin::setCash(unsigned int value)
{
    cash = value;
}



string Usu_Admin::NuevoUsu(){
    int i;
    int sal;
    string cedula,clave,saldo;

    cout<<"ingreselo de la siguente forma:"<<endl;
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
while(finalizo){
    try{
    cout<<"digite el saldo para el usuario: "<<endl;
    cin>>saldo;
    sal=stoi(saldo);
    if(sal<0){
        throw'3';
    }
    finalizo=false;
     }
    catch(char d){
        if(d=='3')
            cout<<"el dinero solo puede ser mayor o igual que cero..."<<endl;

    }
}
    string usuNuev=cedula+" "+clave+" "+saldo;
    archivo+='\n';
    archivo+=usuNuev;
    return archivo;
}

int Usu_Admin::Dinero(){
    int longitud=archivo.length();
    string copiContraArchi;
    int contaEsp = 0, contUsu=0;
    for (int i =0;i < longitud;i++){
        if (archivo[i] != '\n' ){

            if (contaEsp==2 and contUsu ==A){
                copiContraArchi+=archivo[i];
            }
            if (archivo[i] == ' ' and contUsu == A){
                contaEsp++;}
        }
        else{
            contUsu++;
            if (contUsu ==(A+1)){
                cash=(stoi(copiContraArchi));
                return cash;
            }
            else{
            copiContraArchi="";
            }
        }
    }

    cash=(stoi(copiContraArchi));
    return cash;
}

manejo_txt::manejo_txt()
{

}

string manejo_txt::Str_Bin(string contenido)
{

    int tamCad = contenido.length();

    string cadBinario;
    for(int i=0;i < tamCad*8;i++){
        cadBinario += ' ';
    }
    int carac=0;
    for(int cont=0;cont<tamCad;cont++){
        carac = (int)contenido[cont];
            for(int elem=0, palBin=(cont + 1)*8-1 ; elem<8 ; elem++,palBin--){
                cadBinario[palBin]=(char)(carac%2+48);
                carac/=2;
            }
    }
    return cadBinario;
}

string manejo_txt::Bin_Str(string CadCode)
{
  int tamCad= CadCode.length(),multiplicador=1;
  int decimal=0;

  string CadTxt;

  for(int cont=0;cont<tamCad/8;cont++){
      multiplicador=1;
      decimal=0;
        for(int elem=0, palBin=(cont + 1)*8-1 ; elem<8 ; elem++,palBin--){
            if (CadCode[palBin] == '1'){
                decimal += multiplicador;
            }
            multiplicador = multiplicador*2;
        }
        CadTxt+=decimal;
  }
  return CadTxt;
}


string manejo_txt::codificar(int n, string CadText)
{
    string CadBinario;
    string CadCode;


    CadBinario = Str_Bin(CadText);

    int Especial=0, PartSup;

    int Longitud=CadBinario.length();


    for(int elem = 0; elem<Longitud;elem++){
        CadCode += ' ';
    }

    if (Longitud%n != 0){
        Especial++;
    }
    PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
    for(int NLego = 0 ;NLego < PartSup; NLego ++){
        Especial=Longitud%n;
        if(NLego==Longitud/n){
            CadCode[NLego*n] = CadBinario[(NLego*n + Especial)-1];
            for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                CadCode[i+1]=CadBinario[i];
            }
        }
        else{
            CadCode[NLego*n]=CadBinario[n*(NLego+1)-1];
            for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                CadCode[i+1]=CadBinario[i];
            }
        }
    }
    return CadCode;

}
string manejo_txt::decodificar(int n, string CadBinario)
{

    string CadCode;
    string CadTxt;



    int Especial=0, PartSup;

    int Longitud=CadBinario.length();

    for(int elem = 0; elem<Longitud;elem++){
        CadCode += ' ';
    }

    if (Longitud%n != 0){
        Especial++;
    }
    PartSup = Especial == 1 ? (Longitud/n)+1 : Longitud/n;
    for(int NLego = 0 ;NLego < PartSup; NLego ++){
        Especial=Longitud%n;
        if(NLego==Longitud/n){
            CadCode[(NLego*n + Especial)-1] = CadBinario[NLego*n];
            for (int i = n*NLego ;i < (NLego*n + Especial-1) ; i++){
                CadCode[i]=CadBinario[i+1];
            }
        }
        else{
            CadCode[n*(NLego+1)-1]=CadBinario[NLego*n];
            for (int i = n*NLego ;i < (n*(NLego+1)-1); i++){
                CadCode[i]=CadBinario[i+1];
            }

        }
    }

    CadTxt=Bin_Str(CadCode);
    return CadTxt;

}
string manejo_txt::LectuArchi(){
   string data;

   // Abre el archivo en modo lectura
   ifstream infile;

   // Se pone de manera explicita la ruta relativa donde se encuentra el archivo
   infile.open(txt);

   // Se comprueba si el archivo fue abierto exitosamente
   if (!infile.is_open())
   {
     cout << "Error abriendo el archivo" << endl;
     exit(1);
   }

   cout << "Leyendo el archivo" << endl;
   infile >> data;

   // Se escribe el dato en la pantalla
  // cout << data << endl;

   string linea;
   int contador =0;
   while(!infile.eof()){
       contador++;

       if (contador>1){
           data+='\n';
       }
       getline(infile,linea);
       data+=linea;

   }

   // Se cierra el archivo abierto
   infile.close();
   return data;
}

void manejo_txt::Bin_lectura(){

    string archi2 = LectuArchi();
    string copiaArch,C,txtBin;
    int longitud2 = archi2.length();


    for(int i=0;i<longitud2;i++){
        if (archi2[i]=='\n' or archi2[i]==' '){
            C=decodificar(4,copiaArch);
            txtBin+=C;
            if (archi2[i]=='\n'){
                txtBin+='\n';
            }
            else{
                txtBin+=' ';
            }
            copiaArch="";
        }
        else {
            copiaArch+=archi2[i];

        }
    }
    C=decodificar(4,copiaArch);
    txtBin+=C;
    archivo=txtBin;
}
void manejo_txt::escribir(string contenido,string txt)
{
    ofstream archi;

    archi.open(txt);

    if (!archi.is_open())
       {
         cout << "Error abriendo el archivo" << endl;
         exit(1);
       }
    archi << contenido;

    archi.close();
}

string manejo_txt::getArchivo() const
{
    return archivo;
}

void manejo_txt::setArchivo(const string &value)
{
    archivo = value;
}


void manejo_txt::codi_escritura(){

    int longitud=archivo.length();
    string copiaArch,C,txtBin;
    for(int i=0;i<longitud;i++){
        if (archivo[i]=='\n' or archivo[i]==' '){
            C=codificar(4,copiaArch);
            txtBin+=C;
            if (archivo[i]=='\n'){
                txtBin+='\n';
            }
            else{
                txtBin+=' ';
            }
            copiaArch="";
        }
        else {
            copiaArch+=archivo[i];

        }
    }
    C=codificar(4,copiaArch);
    txtBin+=C;
    escribir(txtBin,txt);
}




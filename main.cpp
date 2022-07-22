#include <iostream>

using namespace std;
class marcador{
    private:
        char *color;
        unsigned short int cant_tinta;
        float alto;
        float grosor;
        char *material_externo;
        bool tapita;
    public:
        marcador();
        ~marcador();

        bool destapar_por_voz(char *palabra);
        char *getColor() const;
        void setColor(char *newColor);

};
int main()
{
    marcador sharpie;//crear instancia del objeto
    marcador berol;
    cout<<sharpie.getColor()<<endl;
    sharpie.setColor("fucsia");
    cout<<sharpie.getColor()<<endl;
     cout<<berol.getColor()<<endl;
    return 0;
}
/*
 * objeto marcador
 * caracteristicas estructurales-->atributes
 * color --> char*
 * tamaño **> alto y grosor
 * cantidad de tinta --> int
 * material externo --> metal,plastico,carton
 * tapita-->bool
 * caracteristicas funcionales
 * se tapa y destapa por voz--> bool destapar por voz(char *palabra);
 *
 * */

marcador::marcador()
{
    cout<<"ejecutando constructor de clase marcador "<<endl;
    color="negro";

}

marcador::~marcador()
{
    cout<<"ejectuando destructor de clase marcador"<<endl;
}

char *marcador::getColor() const
{
    return color;
}

void marcador::setColor(char *newColor)
{
    color = newColor;
}

#ifndef CIVILIZACION_H
#define CIVILIZACION_H
#include "aldeano.h"
#include <list>

using namespace std;

// computadora.h
class Civilizacion 
{
    string nombre;
    list <Aldeano> aldeanos;
    float ubicacion_x;
    float ubicacion_y;
    float puntuacion;
    

public:
    Civilizacion ();
    Civilizacion (const string &nombre, float ubicacion_x, float ubicacion_y, float puntuacion);
    void setNombre (const string &v);
    string getNombre ();
    void setUbicacion_x (float v);
    float getUbicacion_x ();
    void setUbicacion_y (float v);
    float getUbicacion_y ();
    void setPuntuacion (float v);
    float getPuntuacion ();

    void respaldar_aldeanos(const Civilizacion &p);
    void recuperar_aldeanos(const Civilizacion &p);

            void agregarFinal(const Aldeano&j);
            void agregarInicio(const Aldeano &j);

            void eliminarNombre(const string &nombre);
            void eliminarEdad();
            void eliminarSalud(int salud);

            void ordenarNombre();
            void ordenarEdad();
            void ordenarSalud();
            void mostrar();
            Aldeano* buscar(const Aldeano &j);
            Aldeano* modificar (Aldeano &j);
            
    friend ostream& operator<<(ostream&out, const Civilizacion &p)
    {       
            out << left ; // Para que todo este  alineado          
            out << setw(20) << p.nombre;
            out << setw(20) << p.ubicacion_x;
            out << setw(10) << p.ubicacion_y;
            out << setw(18) << p.puntuacion;
            out << endl;
            return out;
    }

    friend istream& operator>>(istream&in, Civilizacion &p)
    {
            cout << "Nombre: ";
            getline (cin, p.nombre);

            cout << "Ubicacion en X: ";
            cin >> p.ubicacion_x;

            cout << "Ubicacion en Y: ";
            cin >> p.ubicacion_y;

            cout << "Puntuacion: ";
            cin >> p.puntuacion;

            return in;
    }
    bool operator==(const Civilizacion& p)
    {
        return nombre == p.nombre;
    }
    bool operator==(const Civilizacion& p) const
    {
        return nombre == p.nombre;
    }

    bool operator<(const Civilizacion& p)
    {
        return 2;
    }
    bool operator<(const Civilizacion& p) const
    {
        return nombre < p.nombre;
    }

}; 
#endif
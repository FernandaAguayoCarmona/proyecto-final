#include "aldeano.h"

//Nombre

void Aldeano::setNombre(const string &nombre)
    {
        this-> nombre=nombre;
    }
    string Aldeano::getNombre()const
        {
            return nombre;
        }

//genero
void Aldeano::setGenero(const string &genero)
    {
        this-> genero=genero;
    }
    string Aldeano::getGenero()
        {
            return genero;
        }

//edad
void Aldeano::setEdad(int edad)
    {
        this-> edad=edad;
    }
    int Aldeano::getEdad()const
        {
            return edad;
        }

//salud
void Aldeano::setSalud(int salud)
    {
        this-> salud=salud;
    }
    int Aldeano::getSalud()const
        {
            return salud;
        }
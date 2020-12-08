
#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

//  Clase Administradora.h
class VideoGame
{

    string nombre_videogame;
    vector<Civilizacion> civilizaciones;

public:
    VideoGame ();
    void agregarcivilizacion (const Civilizacion &p);
    void mostrar ();
    void insertar(const Civilizacion &p, size_t pos);
    size_t size();
    void inicializar(const Civilizacion &p, size_t n);
    void eliminar(size_t pos);
    void ordenarNombre ();
    void ordenarUbicacion_x ();
    void ordenarUbicacion_y ();
    void ordenarPuntuacion ();
    void primera();
    void ultimo();
    void setNombre_Videogame (const string &nombre_videogame);
    string getNombre_Videogame();

    void recuperar();
    void push_back( const Civilizacion &p );
    void respaldar();

    Civilizacion* buscar(const Civilizacion &p);
    Civilizacion* modificar(Civilizacion &p);
    friend VideoGame& operator<< (VideoGame&v, const Civilizacion &p)
    {
        v.agregarcivilizacion (p);
        return v;
    }

};
#endif
#include <iostream>
#include <iomanip> 
#include <fstream> 
#include <vector>
#include <algorithm>
#include "videogame.h"
#include "menualdeano.h"

using namespace std;


//main.cpp
int main () 
{
    vector <string> cadenas;
    VideoGame v;
    string op;

    while (true)
    {
        cout << "=============== M E N U ===============" << endl;
        cout << "1) Nombre de Usuario" << endl;
        cout << "2) Agregar Civilizacion" << endl;
        cout << "3) Insertar Civilizacion" << endl;
        cout << "4) Crear Civilizaciones" << endl;
        cout << "5) Primera Civilizacion" << endl;
        cout << "6) Ultima Civilizacion" << endl;
        cout << "7) Ordenar" << endl;
        cout << "8) Eliminar Civilizacion" << endl;
        cout << "9) Buscar" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Respaldar" << endl;
        cout << "13) Recuperar" << endl;
        cout << "14) Salir" << endl;
        getline(cin, op);

        if (op == "1") 
        {
                string nombre_videogame;
                cout << "Dame el nombre de usuario" << endl;
                getline(cin, nombre_videogame);
                v.setNombre_Videogame(nombre_videogame);
                cout << "===  " << v.getNombre_Videogame() << "  ===" << endl;
                system ("pause");
        } 

// Agregar civilizacion
        else if (op == "2") 
        {
            cout << "=========== Agregar civilizacion ===========" << endl;
            Civilizacion p;

            cin >> p;

            v.agregarcivilizacion(p); 
            cin.ignore();
        } 

// Insertar civilizacion
        else if (op == "3") 
        {
            cout << "=========== Insertar civilizacion ===========" << endl;
            Civilizacion p;
            cin >> p;

            size_t pos;
            cout << "Posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posicion no válida" << endl;
            }
            else {
                v.insertar(p, pos);
            }
        } 

// Inicializar
        else if (op == "4") 
        {
            cout << "=========== Inicializar ===========" << endl;
            Civilizacion p;
            cin >> p;

            size_t n;
            cout << "Numero de veces a inicializar: ";
            cin >> n; cin.ignore();

            v.inicializar(p, n);
        }

// Primera civilizacion
         else if (op == "5")
            {
                cout << "=========== Primera Civilizacion ===========" << endl;
                v.primera ();
            }

// Ultima civilizacion 
        else if (op == "6")
            {
                cout << "=========== Ultima Civilizacion ===========" << endl;
                v.ultimo ();
            }

// Ordenar
        else if (op == "7") 
        {  
            while (true)
            {
                cout << "=============== Menu de Ordenar ===============" << endl;
                cout << "1) Ordenar por Nombre" << endl;
                cout << "2) Ordenar por Ubicacion en X" << endl;
                cout << "3) Ordenar por Ubicacion en Y" << endl;
                cout << "4) Ordenar por Puntuacion - Descendente" << endl;
                getline(cin, op);

                if (op == "1")
                {
                    v.ordenarNombre();
                    break;
                }

                if (op == "2")
                {
                    v.ordenarUbicacion_x ();
                    break;
                }

                if (op == "3")
                {
                    v.ordenarUbicacion_y ();
                    break;
                }

                if (op == "4")
                {
                    v.ordenarPuntuacion();
                    break;
                }
            }     
        }

// Eliminar
        else if (op == "8") 
            {
                cout << "=========== Eliminar ===========" << endl;
                size_t pos;
                cout << "Posicion: ";
                cin >> pos; cin.ignore();

                if (pos >= v.size()) 
                {
                 cout << "Posicion no válida" << endl;
                }
                else 
                {
                 v.eliminar(pos);
                }
            }

// Buscar
        else if (op == "9") 
            {
                cout << "=========== Buscar ===========" << endl;
                Civilizacion p;
                cin >> p; cin.ignore();

                Civilizacion *ptr = v.buscar(p);

                if (ptr == nullptr) {
                    cout << "no encontrado" << endl;
                }
                else {
                    cout << "Civilizacion encontrada: " << endl;
                    cout << *ptr << endl;
                    menu(*ptr);
                }
            }

// Modificar
        else if (op == "10")
            {
                cout << "=========== Modificar ===========" << endl;
                Civilizacion p;

                cout << "Inserte los datos de la Civilizacion a modificar: " << endl;
                cin >> p; cin.ignore();

                Civilizacion *ptr = v.buscar(p);

                if (ptr == nullptr) 
                    {
                        cout << "Civilizacion no encontrada" << endl;
                        system ("pause");
                    }
                else 
                    {
                        cout << "Civilizacion encontrada: " << endl;
                        cout << *ptr << endl;
                        v.modificar(*ptr);
                    }
            }

// Resumen / mostrar
        else if (op == "11")
            {
                cout << "=========== Resumen ===========" << endl;
                v.mostrar();
            }    

//Respaldar
        else if (op=="12")
            {
                v.respaldar();
            }
//Recuperar
        else if (op=="13")
            {
                v.recuperar();
            }
// Salir 
        else if (op == "14") 
            {
                cout << "Usted ha salido del programa" << endl;
                break;
            }

//Opcion invalida
        else if (op < "1" || op > "14")
            {
                cout << "Opcion Invalida, intentelo de nuevo"<< endl;
            }    
    } 
    return 0;
}
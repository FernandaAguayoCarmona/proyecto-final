#ifndef ALDEANO_H
#define ALDEANO_H

#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
using namespace std;

class Aldeano
    {
            string nombre;
            int edad;
            string genero;
            int salud;

        public:
            Aldeano (){}
            Aldeano (const string &nombre, const string &genero, 
            int edad, int salud)
            : nombre(nombre), edad(edad), genero(genero), salud(salud){}

            void setNombre(const string &nombre);
            string getNombre()const;

            void setEdad(int edad);
            int getEdad()const;  

            void setGenero(const string &genero);
            string getGenero();       

            void setSalud(int salud);
            int getSalud()const;
        
            friend ostream& operator<<(ostream &out,const Aldeano&j)
                {
                    out << left;
                    out << setw(10) << j.nombre;
                    out << setw(5) << j.edad;
                    out << setw(10) << j.genero;
                    out << setw(5) << j.salud;

                    return out;
                }
            friend istream& operator>>( istream &i, Aldeano &a )
                {
                    cout << "Nombre: ";
                    getline(cin, a.nombre);
                    cout << "Edad: ";
                    cin >> a.edad; cin.ignore();
                    cout << "Género: ";
                    getline(cin,a.genero);
                    cout << "Salud: ";
                    cin >> a.salud; cin.ignore();
                    return i;
                }
// Ordenar los nombres de los aldeanos
        bool operator==(const Aldeano &a) const
            {
                return nombre == a.nombre;
            }

        bool operator<(const Aldeano &a) const
        {
            return nombre < a.nombre;
        }

    };
#endif

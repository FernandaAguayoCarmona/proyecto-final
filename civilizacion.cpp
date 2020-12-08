#include "civilizacion.h"
//computadora.cpp

Civilizacion :: Civilizacion ()
{
}

//respaldar
void Civilizacion::respaldar_aldeanos( const Civilizacion &p)
{
    ofstream villa( getNombre() + ".txt", ios::out );
    if ( villa.is_open() )
    {
        for ( auto it = aldeanos.begin() ; it != aldeanos.end(); it++ )
        {
            Aldeano &j = *it;
            villa << j.getNombre() << endl;
            villa << j.getEdad() << endl;
            villa << j.getGenero() << endl;
            villa << j.getSalud() << endl;
        }
    }
    villa.close();
}
//recuperar
void Civilizacion::recuperar_aldeanos( const Civilizacion &p )
{
    ifstream villa( getNombre() + ".txt" );
    if ( villa.is_open() )
    {
        while ( !villa.eof() )
        {
            Aldeano j;
            int edad, salud;
            string temp;
            getline(villa,temp);
            if ( villa.eof() )
                {
                break;
                }
            j.setNombre(temp);

            getline(villa,temp);
            edad = stoi(temp);
            j.setEdad(edad);

            getline(villa,temp);
            j.setGenero(temp);

            getline(villa,temp);
            salud = stoi(temp);
            j.setSalud(salud);
            agregarFinal(j);
        }
    }
    villa.close();
}

Civilizacion::Civilizacion(const string &nombre, float ubicacion_x, float ubicacion_y, float puntuacion)
{
    this -> nombre = nombre;
    this -> ubicacion_x = ubicacion_x;
    this -> ubicacion_y = ubicacion_y;
    this -> puntuacion = puntuacion;
}
//          nombre
void Civilizacion::setNombre(const string &v)
    {
        nombre = v;
    }
    string Civilizacion :: getNombre()
{
    return nombre;
}
//          ubicacion x
void Civilizacion::setUbicacion_x(float v)
    {
        ubicacion_x = v;
    }
    float Civilizacion :: getUbicacion_x()
{
    return ubicacion_x;
}
//          ubicacion y
void Civilizacion::setUbicacion_y(float v)
    {
        ubicacion_y = v;
    }
    float Civilizacion :: getUbicacion_y()
{
    return ubicacion_y;
}
//          puntuacion
void Civilizacion::setPuntuacion(float v)
    {
        puntuacion = v;
    }
    float Civilizacion :: getPuntuacion()
{
    return puntuacion;
}


// Aldeanos

void Civilizacion::agregarFinal(const Aldeano &j)
    {   //Inserta al final el "aldeano" que recibe
        aldeanos.push_back(j);
    }

void Civilizacion::agregarInicio(const Aldeano &j)
    {   //Inserta al final el "aldeano" que recibe
        aldeanos.push_front(j);
    }

//Encontramos el nombre del aldeano y lo eliminamos
void Civilizacion::eliminarNombre(const string &nombre)
    {
        for (auto it=aldeanos.begin(); it!= aldeanos.end(); it++)
        {
            Aldeano &j = *it;
            if (nombre==j.getNombre())
                {
                    aldeanos.erase(it);
                    break;
                }
        }
    }

// Comparara y eliminara a todos los aldeanos con edad mayor o igual a 60
bool comparador(const Aldeano &j)
    {
        //remover aldeanos si su salud es (mayor o igual a 60)
        return j.getEdad()>=60; 
    }

void Civilizacion::eliminarEdad()
    {
        aldeanos.remove_if(comparador);
    }

void Civilizacion::eliminarSalud(int salud)
    {   //funcion lambda
        aldeanos.remove_if([salud](const Aldeano &j){return j.getSalud()<salud;});
    }

void Civilizacion::ordenarNombre()
    {
        aldeanos.sort();
    }

bool comparadorEdad(const Aldeano &j1, const Aldeano &j2)
    {   //lo ordena de mayor a menor
        return j1.getEdad() > j2.getEdad();
    }
void Civilizacion::ordenarEdad()
    {
        aldeanos.sort(comparadorEdad);
    }
     
void Civilizacion::ordenarSalud()
    {
        aldeanos.sort([](const Aldeano &j1, const Aldeano &j2){return j1.getSalud() > j2.getSalud();});
    }


void Civilizacion::mostrar()
    {

        cout << endl;
        cout << left;
        cout << setw(10) << "Nombre";
        cout << setw(5) << "Edad";
        cout << setw(10) << "Genero";
        cout << setw(5) << "Salud";
        cout << endl << endl;
        for ( auto it = aldeanos.begin() ; it != aldeanos.end() ; it++ )
            {
                Aldeano &j = *it;
                cout << j << endl;
            }
    }

Aldeano* Civilizacion::buscar(const Aldeano &j)
    {
        // vector<Personaje>::iterator
        auto it = find(aldeanos.begin(), aldeanos.end(), j);

        if (it == aldeanos.end()) {
            return nullptr;
        }
        else {
            return &(*it);
        }
    }

Aldeano* Civilizacion::modificar(Aldeano &j)
    {
        int op;
        string nuevo_nombre, nuevo_genero;
        float nuevo_salud, nuevo_edad;
        cout << "=============== Menu de Modificar ===============" << endl;
        cout << "1) Modificar el Nombre" << endl;
        cout << "2) Modificar el genero" << endl;
        cout << "3) Modificar la Edad" << endl;
        cout << "4) Modificar la salud" << endl;
        cout << "Selecciona el dato que desee modificar: " << endl;
        cin >> op; 
        cin.ignore();

        switch(op)
            {
              case 1:
                    {
                        cout << "Escribe el nuevo nombre" << endl;
                        getline(cin,nuevo_nombre);
                        j.setNombre(nuevo_nombre); 
                        cout << "Nombre actualizado" << endl;     
                        system ("pause");
                        break;
                    }

                case 2:
                    {   
                        cout << "Escribe el nuevo genero" << endl;
                        getline(cin,nuevo_genero);
                        j.setGenero(nuevo_genero); 
                        cout << "Nombre actualizado" << endl;     
                        system ("pause");
                        break;
                    }

                case 3:
                    {
                        cout << "Escribe la nueva Edad" << endl;
                        cin >> nuevo_edad; cin.ignore();
                        j.setEdad(nuevo_edad);        
                        system ("pause");
                        break;
                    }

                case 4:
                    {
                        cout << "Escribe la nueva Salud" << endl;
                        cin >> nuevo_salud; cin.ignore();
                        j.setSalud(nuevo_salud);                               
                        system ("pause");
                        break;
                    }  
            }
        return nullptr;   
    }


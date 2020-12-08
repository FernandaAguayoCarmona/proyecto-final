
#include "videogame.h"

//  Clase Administradora.cpp
VideoGame::VideoGame ()
    {

    }

void VideoGame::agregarcivilizacion (const Civilizacion &p)
    {
        civilizaciones.push_back(p);
    }

//Imprimira los datos que hayas ingresado, no necesariamente los 5 elementos.
void VideoGame::mostrar ()
    {   
        cout << left ;
        cout << endl;
        cout << setw (20) << "Nombre- ";
        cout << setw (20) << "Ubicacion X- ";
        cout << setw (10) << "Ubicacion Y- ";
        cout << setw (18) << "Puntuacion- ";
        cout << endl;

        for (size_t i = 0; i < civilizaciones.size(); i++)
        {   
            Civilizacion &p = civilizaciones [i];
            cout << p;
        }
    }   

void VideoGame::setNombre_Videogame( const string &n ){
    nombre_videogame = n;
}
string VideoGame::getNombre_Videogame(){
    return nombre_videogame;
}


void VideoGame::primera ()
    {
        if (civilizaciones.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else 
                {
                    cout << civilizaciones.front() << endl;
                }
    }

void VideoGame::ultimo ()
    {
        if (civilizaciones.empty())
            {
                cout << "Vector esta vacio" << endl;
            }
            else 
                {
                    cout << civilizaciones.back() << endl;
                }
    }

void VideoGame::insertar(const Civilizacion &p, size_t pos)
    {
        civilizaciones.insert(civilizaciones.begin()+pos, p);
    }

size_t VideoGame::size()
    {
        return civilizaciones.size();
    }

void VideoGame::inicializar(const Civilizacion &p, size_t n)
    {
        civilizaciones = vector<Civilizacion>(n, p);
    }

void VideoGame::eliminar(size_t pos)
    {
        civilizaciones.erase(civilizaciones.begin()+pos);
    }

// FUNCION LAMBDA
// ascendente "<" descendente ">".

void VideoGame::ordenarNombre()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getNombre() < p2.getNombre();});
    }
void VideoGame::ordenarUbicacion_x()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getUbicacion_x() < p2.getUbicacion_x();});
    }
void VideoGame::ordenarUbicacion_y()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getUbicacion_y() < p2.getUbicacion_y();});
    }
void VideoGame::ordenarPuntuacion()
    {
        sort(civilizaciones.begin(), civilizaciones.end(), 
        [] (Civilizacion p1, Civilizacion p2) { return p1.getPuntuacion() > p2.getPuntuacion();});
    }


Civilizacion* VideoGame::buscar(const Civilizacion &p)
    {
        // vector<Personaje>::iterator
        auto it = find(civilizaciones.begin(), civilizaciones.end(), p);

        if (it == civilizaciones.end()) {
            return nullptr;
        }
        else {
            return &(*it);
        }
    }



Civilizacion* VideoGame::modificar(Civilizacion &p)
    {
        int op;
        string nuevo_nombre;
        float nuevo_x, nuevo_y, nuevo_puntuacion;
        cout << "=============== Menu de Modificar ===============" << endl;
        cout << "1) Modificar el Nombre" << endl;
        cout << "2) Modificar la Ubicacion en X" << endl;
        cout << "3) Modificar la Ubicacion en Y" << endl;
        cout << "4) Modificar la Puntuacion" << endl;
        cout << "Selecciona el dato que desee modificar: " << endl;
        cin >> op; 
        cin.ignore();

        switch(op)
            {
              case 1:
                    {
                        cout << "Escribe el nuevo nombre" << endl;
                        getline(cin,nuevo_nombre);
                        p.setNombre(nuevo_nombre); 
                        cout << "Nombre actualizado" << endl;     
                        system ("pause");
                        break;
                    }

                case 2:
                    {   
                        cout << "Escribe la nueva Ubicacion x" << endl;
                        cin >> nuevo_x; cin.ignore();
                        p.setUbicacion_x(nuevo_x);
                        cout << "X actualizado" << endl;    
                        system ("pause");
                        break;
                    }

                case 3:
                    {
                        cout << "Escribe la nueva Ubicacion y" << endl;
                        cin >> nuevo_y; cin.ignore();
                        p.setUbicacion_y(nuevo_y);        
                        system ("pause");
                        break;
                    }

                case 4:
                    {
                        cout << "Escribe la nueva Puntuacion" << endl;
                        cin >> nuevo_puntuacion; cin.ignore();
                        p.setPuntuacion(nuevo_puntuacion);                               
                        system ("pause");
                        break;
                    }  
            }
        return nullptr;   
    }

void VideoGame::respaldar()
{
    ofstream fichero( "civilizaciones.txt", ios::out );
    if ( fichero.is_open() )
    {
        for ( size_t it = 0 ; it < civilizaciones.size() ; it++ )
        {

            Civilizacion &p = civilizaciones[it];
            fichero << p.getNombre() << endl;
            fichero << p.getUbicacion_x() << endl;
            fichero << p.getUbicacion_y() << endl;
            fichero << p.getPuntuacion() << endl;

            p.respaldar_aldeanos(p);
        }
    }
    fichero.close();
}

void VideoGame::recuperar()
{

    ifstream fichero( "civilizaciones.txt");
    if ( fichero.is_open() )
    {
        while ( true )
        {
            Civilizacion p;
            string temp;
            float x, y, punt;
            getline(fichero,temp);
            if ( fichero.eof() )
            {
                break;
            }
            p.setNombre(temp);

            getline(fichero,temp);
            x = stof(temp);
            p.setUbicacion_x(x);

            getline(fichero,temp);
            y = stof(temp);
            p.setUbicacion_y(y);

            getline(fichero,temp);
            punt = stof(temp);
            p.setPuntuacion(punt);

            p.recuperar_aldeanos(p);
            
            push_back(p);
        }
    }
    fichero.close();
}
void VideoGame::push_back( const Civilizacion &p ){
    
    civilizaciones.push_back(p);

}
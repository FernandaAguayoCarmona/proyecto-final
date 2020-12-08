#include "civilizacion.h"
#include "videogame.h"

Aldeano capturar()
{   // crea aldeano y pide informacion
    Aldeano j;
    string nombre;
    string genero;
    size_t edad;
    size_t salud;

    system ("cls");
    cout << "===== AGREGAR ALDEANO =====" << endl;
    cout << "Nombre: ";
    getline (cin, nombre);
    j.setNombre(nombre);

    cout << "Genero: ";
    getline (cin, genero);
    j.setGenero(genero);

    cout << "Edad: ";
    cin >> edad;
    j.setEdad(edad);    

    cout << "Salud: ";
    cin >> salud;
    j.setSalud(salud); 

    return j;
}


void menu(Civilizacion &p)
    {   // submenu para editar a poblacion
        string opcion;
        while(true)
        {   system ("cls");
            cout << "===== MENU ALDEANO =====" << endl;
            cout << "1.- Agregar Aldeano" << endl;
            cout << "2.- Eliminar Aldeano" << endl;
            cout << "3.- Clasificar Aldeanos" << endl;
            cout << "4.- Buscar Aldeano" << endl;
            cout << "5.- Modificar Aldeano" << endl;
            cout << "6.- Mostrar" << endl;
            cout << "0.- Salir de Menu Aldeano"<< endl;
            cout << "Opcion: ";
            getline (cin, opcion);
            
            //Agregar
            if (opcion=="1")
            {   
                system ("cls");
                int opcion;
                cout << "===== AGREGAR ALDEANO =====" << endl;
                cout << "1.- Agregar el objeto aldeano al inicio" << endl;
                cout << "2.- Agregar el objeto aldeano al final" << endl;
                cout << "Opcion: ";
                cin >> opcion; cin.ignore();
                switch(opcion)
                    {   
                        case 1:
                        p.agregarInicio(capturar());
                        break;

                        case 2:
                        p.agregarFinal(capturar());
                        break;

                        default:
                        cout << "Opcion invalida, pruebe de nuevo...";
                        system("pause");
                        break;
                    }
            } 

            // eliminar
            else if (opcion == "2")
            {   string nombre;
                size_t salud;
                int opcion;
                system ("cls");
                cout << "===== ELIMINAR ALDEANO =====" << endl;
                cout << "1.- Eliminar por nombre" << endl;
                cout << "2.- Eliminar aldeanos donde su salud sea menor a x" << endl;
                cout << "3.- Eliminar aldeanos donde su edad sea mayor igual a 60" << endl;
                cout << "Opcion: ";
                cin >> opcion; cin.ignore();
                switch(opcion)
                    {
                        case 1:
                        cout << "Ingrese el nombre del Aldeano a eliminar: ";
                        getline(cin,nombre);

                        p.eliminarNombre(nombre);
                        break;

                        case 2:
                        cout << "Eliminar por Salud" << endl;
                        cout << "Salud: ";
                        cin >> salud; cin.ignore();

                        p.eliminarSalud(salud);
                        break;

                        case 3:
                        p.eliminarEdad();
                        break;

                        default:
                        cout << "Opcion invalida, pruebe de nuevo...";
                        system("pause");
                        break;
                    }

            } 
            
            // clasificar
            else if (opcion == "3")
            {
                int opcion;
                system ("cls");
                cout << "===== CLASIFICAR ALDEANO =====" << endl;
                cout << "1.- Clasificar la lista de aldeanos por nombre" << endl;
                cout << "2.- Clasificar la lista de aldeanos por edad " << endl;
                cout << "3.- Clasificar la lista de aldeanos por salud " << endl;
                cout << "Opcion: ";
                cin >> opcion; cin.ignore();
                switch(opcion)
                    {
                        case 1:
                            p.ordenarNombre();
                        break;

                        case 2:
                            p.ordenarEdad();
                        break;

                        case 3:
                            p.ordenarSalud();
                        break;

                        default:
                        cout << "Opcion invalida, pruebe de nuevo...";
                        system("pause");
                        break;
                    }
                
            } 
            
            // buscar
            else if (opcion == "4")
            {
                cout << "=========== Buscar ===========" << endl;
                Aldeano j;
                cin >> j; cin.ignore();

                Aldeano *ptr = p.buscar(j);

                if (ptr == nullptr) 
                {
                    cout << "no encontrado" << endl;
                }
                else 
                {
                    cout << "Civilizacion encontrada: " << endl;
                    cout << *ptr << endl;
                    system("pause");
                }
            } 
            
            // modificar
            else if (opcion == "5")
            {
                cout << "=========== Modificar ===========" << endl;
                Aldeano j;

                cout << "Inserte los datos de el Aldeano a modificar: " << endl;
                cin >> j; cin.ignore();

                Aldeano *ptr = p.buscar(j);

                if (ptr == nullptr) 
                {
                    cout << "no encontrado" << endl;
                }
                else 
                {
                    cout << "Civilizacion encontrada: " << endl;
                    cout << *ptr << endl;
                    p.modificar(*ptr);
                }
            } 
            
            // mostrar
            else if (opcion == "6")
            {   
                system ("cls");
                p.mostrar();
                system ("pause");
            }

            else if (opcion == "0")
            {
                cout << "Usted ha salido del menu Aldeano" << endl;
                break;
            }

            else if (opcion > "6")
            {
                cout << "Opcion Invalida, intentelo de nuevo" << endl;
            }

        }
    }
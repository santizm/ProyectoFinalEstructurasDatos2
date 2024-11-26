#include <iostream> 
#include "Artista.h"
#include "arbolArtista.h"

using namespace std;

//Instancia Global del arbol
arbolArtista arbol;

void mostrarMenuInicial() {
    cout << "\n--- Opciones ---\n";
    cout << "Bienvenido CenfoEstudiante, digite la opcion de interes\n";
    cout << "1. Menú Cursos\n";
    cout << "2. Menú Artistas\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}


void mostarMenuArtista() {
    cout << "\n--- Opciones ---\n";
    cout << "1. Agregar artista\n";
    cout << "2. Eliminar artista, de acuerdo con el número de cedula\n";
    cout << "3. Desplegar la lista de artistas en forma ascendente\n";
    cout << "4. Desplegar la lista de artistas en forma descendente\n";
    cout << "5. Consultar datos de un artista.Se indica el número de cedula se muestran el detalle\n";
    cout << "6. Consultar para un artista, la lista de compañeros con los que ha compartido un curso.\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

void mostrarMenuCurso() {
    cout << "\n--- Opciones ---\n";
    cout << "1. Agregar curso\n";
    cout << "2. Desplegar lista de cursos en forma ascendente\n";
    cout << "3. Desplegar lista de cursos en forma descendente\n";
    cout << "4. Consultar datos de un curso.Se indica el código del curso y se muestra el código y nombre del curso.\n";
    cout << "5. Agregar estudiantes a un curso.\n";
    cout << "6. Consultar para un estudiante, los nombres de los estudiantes con los que comparte al menos un curso.\n";
    cout << "7. Listar los nombres de los estudiantes que han compartido una cantidad específica o más cursos en común.\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";

}

void accionesCursos() {
    int opcion;
    do {
        mostrarMenuCurso();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            cout << "Agregar curso\n";
            break;
        }

        case 2: {
            cout << "Desplegar lista de cursos en forma ascendente\n";
            break;
        }

        case 3: {
            cout << "Desplegar lista de cursos en forma descendente\n";
            break;
        }

        case 4: {
            cout << "Consultar datos de un curso.Se indica el código del curso y se muestra el código y nombre del curso.\n";
            break;
        }

        case 5: {
            cout << "Agregar estudiantes a un curso.\n";
            break;
        }

        case 6: {
            cout << "Consultar para un estudiante, los nombres de los estudiantes con los que comparte al menos un curso.\n";
            break;
        }

        case 7: {
            cout << "Listar los nombres de los estudiantes que han compartido una cantidad específica o más cursos en común.\n";
            break;
        }

        default:
            cout << "Opcion no v lida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}


void accionesArtistas() {
    int opcion;
    do {
        mostarMenuArtista();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            // Agregar artista
            std::string cedula, apellido, nombre, telefono, email, provincia, canton, barrio;
            cout << "Ingrese cedula: "; cin >> cedula;
            cout << "Ingrese apellido: "; cin >> apellido;
            cout << "Ingrese nombre: "; cin >> nombre;
            cout << "Ingrese telefono: "; cin >> telefono;
            cout << "Ingrese email: "; cin >> email;
            cout << "Ingrese provincia: "; cin >> provincia;
            cout << "Ingrese canton: "; cin >> canton;
            cout << "Ingrese barrio: "; cin >> barrio;
            arbol.addArtista(Artista(cedula, apellido, nombre, telefono, email, provincia, canton, barrio));
            break;
        }
        case 2: {
            // Eliminar artista
            std::string cedula;
            cout << "Ingrese la cedula del artista a eliminar: ";
            cin >> cedula;
            arbol.removeArtista(cedula);
            break;
        }
        case 3: {
            // Mostrar artistas en orden ascendente
            cout << "Lista de artistas en orden ascendente:\n";
            arbol.showAscending();
            break;
        }
        case 4: {
            // Mostrar artistas en orden descendente
            cout << "Lista de artistas en orden descendente:\n";
            arbol.showDescending();
            break;
        }
        case 5: {
            // Consultar artista por cédula
            std::string cedula;
            cout << "Ingrese la cedula del artista: ";
            cin >> cedula;
            arbol.searchArtista(cedula);
            break;
        }
        case 6: {
            // Funcionalidad adicional: Lista de compañeros
            cout << "Consultar para un artista, la lista de compañeros con los que ha compartido un curso.\n";
            // Aquí podrías implementar una nueva funcionalidad si tienes esa lógica en otro módulo.
            break;
        }
        case 0:
            cout << "Saliendo del menu de artistas.\n";
            break;
        default:
            cout << "Opcion no válida. Intente de nuevo.\n";
        }
    } while (opcion != 0);
}

int main() {
    int opcion;

    do {
        mostrarMenuInicial();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            accionesCursos();
            break;
        }

        case 2: {
            accionesArtistas();
            break;
        }
        default:
            cout << "Opcion no v lida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
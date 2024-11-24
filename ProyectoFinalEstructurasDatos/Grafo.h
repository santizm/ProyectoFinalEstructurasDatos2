#ifndef GRAFO_ARTISTAS_H
#define GRAFO_ARTISTAS_H

#include "Artista.h"
#include <vector>

class Grafo {
private:
    std::vector<Artista*> artistas;  // Lista de artistas
    std::vector<std::pair<int, int>> relaciones;  // Relaciones de cursos (�ndices de artistas)

    int encontrarIndicePorCedula(const std::string& cedula) {
        for (int i = 0; i < artistas.size(); ++i) {
            if (artistas[i]->getCedula() == cedula)
                return i;
        }
        return -1;
    }

public:
    // Agregar un artista
    void agregarArtista(Artista* artista) {
        artistas.push_back(artista);
    }

    // Crear una relaci�n entre dos artistas
    void agregarRelacion(const std::string& cedula1, const std::string& cedula2) {
        int indice1 = encontrarIndicePorCedula(cedula1);
        int indice2 = encontrarIndicePorCedula(cedula2);

        if (indice1 != -1 && indice2 != -1) {
            relaciones.push_back(std::make_pair(indice1, indice2));
        }
        else {
            std::cout << "Uno o ambos artistas no existen en el grafo.\n";
        }
    }

    void mostrarRelaciones(const std::string& cedula) {
        int indice = encontrarIndicePorCedula(cedula);
        if (indice == -1) {
            std::cout << "Artista no encontrado.\n";
            return;
        }

        std::cout << "Artistas con los que " << artistas[indice]->getNombre()
            << " (C�dula: " << artistas[indice]->getCedula() << ") ha compartido curso:\n";

        bool tieneRelaciones = false; // Variable para verificar si existen relaciones

        for (auto& relacion : relaciones) {
            if (relacion.first == indice) {
                std::cout << "- Cedula: " << artistas[relacion.second]->getCedula()
                    << ", Nombre: " << artistas[relacion.second]->getNombre() << std::endl;
                tieneRelaciones = true;
            }
            else if (relacion.second == indice) {
                std::cout << "- Cedula: " << artistas[relacion.first]->getCedula()
                    << ", Nombre: " << artistas[relacion.first]->getNombre() << std::endl;
                tieneRelaciones = true;
            }
        }

        // Si no se encontraron relaciones, muestra el mensaje
        if (!tieneRelaciones) {
            std::cout << "No se encontraron artistas con los que haya compartido curso.\n";
        }
    }


    // Destructor
    ~Grafo() {
        for (auto& artista : artistas) {
            delete artista;
        }
    }
};

#endif // GRAFO_ARTISTAS_H
#pragma once

#pragma once
#ifndef ARTISTA_H
#define ARTISTA_H

#include <string>
#include <iostream>

class Artista {
private:
    std::string cedula;
    std::string apellido;
    std::string nombre;
    std::string telefono;
    std::string email;
    std::string provincia;
    std::string canton;
    std::string barrio;

public:
    // Constructor
    Artista(std::string ced, std::string ape, std::string nom, std::string tel, std::string mail,
        std::string prov, std::string cant, std::string bar)
        : cedula(ced), apellido(ape), nombre(nom), telefono(tel), email(mail),
        provincia(prov), canton(cant), barrio(bar) {}

    // Getters
    std::string getCedula() const { return cedula; }
    std::string getApellido() const { return apellido; }
    std::string getNombre() const { return nombre; }
    std::string getTelefono() const { return telefono; }
    std::string getEmail() const { return email; }
    std::string getProvincia() const { return provincia; }
    std::string getCanton() const { return canton; }
    std::string getBarrio() const { return barrio; }

    // Setters
    void setCedula(const std::string& ced) { cedula = ced; }
    void setApellido(const std::string& ape) { apellido = ape; }
    void setNombre(const std::string& nom) { nombre = nom; }
    void setTelefono(const std::string& tel) { telefono = tel; }
    void setEmail(const std::string& mail) { email = mail; }
    void setProvincia(const std::string& prov) { provincia = prov; }
    void setCanton(const std::string& cant) { canton = cant; }
    void setBarrio(const std::string& bar) { barrio = bar; }

    void mostrarArtista() const {
        std::cout << "C�dula: " << cedula << ", Apellido: " << apellido << ", Nombre: " << nombre
            << ", Tel�fono: " << telefono << ", Email: " << email
            << ", Provincia: " << provincia << ", Cant�n: " << canton
            << ", Barrio: " << barrio << std::endl;
    }
};

#endif // ARTISTA_H

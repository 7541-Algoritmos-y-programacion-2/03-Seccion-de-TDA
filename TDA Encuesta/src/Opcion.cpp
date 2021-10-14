#include "Opcion.h"

Opcion::Opcion(unsigned int numero) {

    this->numero = numero;
    this->votos = 0;
}

unsigned int Opcion::obtenerNumero() {

    return this->numero;
}

std::string Opcion::obtenerDescripcion() {

    return this->descripcion;
}

void Opcion::cambiarDescripcion(std::string descripcion) {

    this->descripcion = descripcion;
}

void Opcion::votar() {

    this->votos++;
}

unsigned int Opcion::contarVotos() {

    return this->votos;
}


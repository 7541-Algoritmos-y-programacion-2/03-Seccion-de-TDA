#include "Encuesta.h"

using namespace std;

Encuesta::Encuesta(string pregunta, unsigned int cantidadDeOpciones) {

    this->pregunta = pregunta;

    if (cantidadDeOpciones > 1) {

        this->cantidadDeOpciones = cantidadDeOpciones;

    } else {

        /* utiliza la mínima cantidad de opciones */
        this->cantidadDeOpciones = 2;
    }

    this->opciones = new Opcion*[this->cantidadDeOpciones];

    for (unsigned int i = 0; i < this->cantidadDeOpciones; i++) {
        this->opciones[i] = NULL;
    }
}

string Encuesta::obtenerPregunta() {

    return this->pregunta;
}

unsigned int Encuesta::contarOpciones() {

    return this->cantidadDeOpciones;
}

Opcion* Encuesta::obtenerOpcion(unsigned int numero) {

    Opcion* opcion = NULL;

    if ((numero > 0) && (numero <= this->contarOpciones())) {

        opcion = this->opciones[numero - 1];

        /* si la opcion aún no fue creada, la crea y la guarda */
        if (opcion == NULL) {

            opcion = new Opcion(numero);
            this->opciones[numero - 1] = opcion;
        }
    }

    return opcion;
}

unsigned int Encuesta::contarVotosTotales() {

    unsigned int votos = 0;

    for (int numero = 1; numero <= this->contarOpciones(); numero++) {

        votos += this->obtenerOpcion(numero)->contarVotos();
    }

    return votos;
}

Encuesta::~Encuesta() {

    for (int i = 0; i < this->contarOpciones(); i++) {

        Opcion * opcion = this->opciones[i];

        if (opcion != NULL) {

            delete opcion;
        }
    }

    delete [] this->opciones;
}


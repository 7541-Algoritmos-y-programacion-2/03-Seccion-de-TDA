#ifndef ENCUESTA_H_
#define ENCUESTA_H_

#include <string>

#include "Opcion.h"

/*
 * Una Encuesta es una pregunta que ofrece múltiples opciones para responderla y que contabiliza los votos recibidos.
 *
 * Toda Encuesta posee como mínimo 2 Opciones. Una Opción se identifica dentro de la Encuesta por su número
 * de orden.
 *
 * Ejemplo:
 *
 *  "Qué libro de la trilogía: Fundación, de Isaac Asimov le resultó más interesante?"
 *
 *  1) Fundación
 *  2) Fundación e Imperio
 *  3) Segunda Fundación
 *
 *
 */
class Encuesta {

    private:

        std::string pregunta;

        Opcion** opciones;

        unsigned int cantidadDeOpciones;

    public:

        /*
         * pre : cantidadDeOpciones es mayor a 1.
         * post: la Encuesta queda inicializada con la pregunta indicada y con
         *       cantidadDeOpciones Opciones disponibles.
         */
        Encuesta(std::string pregunta, unsigned int cantidadDeOpciones);

        /*
         * post: devuelve el enunciado de la pregunta que tiene la Encuesta.
         */
        std::string obtenerPregunta();

        /*
         * post: devuelve la cantidad de Opciones que tiene la Encuesta.
         */
        unsigned int contarOpciones();

        /*
         * pre : numero está en el rango [1, contarOpciones()]
         * post: devuelve la Opción que corresponde con el número indicado.
         */
        Opcion* obtenerOpcion(unsigned int numero);

        /*
         * post: devuelve la cantidad total de votos de la encuesta,
         *       es decir la sumatoria de votos que cada una de sus Opciones recibió.
         */
        unsigned int contarVotosTotales();

        /*
         * post: libera todos los recursos asociados con la instancia.
         */
        ~Encuesta();
};

#endif /* ENCUESTA_H_ */

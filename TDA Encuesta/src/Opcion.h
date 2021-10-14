#ifndef OPCION_H_
#define OPCION_H_

#include <string>

/**
 * Una Opción es una de las alternativas para responder una Encuesta.
 *
 */
class Opcion {

    private:

        unsigned int numero;

        std::string descripcion;

        unsigned int votos;


    public:

        /*
         * pre : numero es un valor mayor a 0.
         * post: la Opción queda inicializada con el número indicado,
         *       con una descripción vacía y sin votos.
         */
        Opcion(unsigned int numero);

        /*
         * post: devuelve el número de Opción.
         */
        unsigned int obtenerNumero();

        /*
         * post: devuelve la descripción asociada a la Opción.
         */
        std::string obtenerDescripcion();

        /*
         * post: cambia la descripción de la Opción.
         */
        void cambiarDescripcion(std::string descripcion);

        /*
         * post: acumula un voto.
         */
        void votar();

        /*
         * post: devuelve la cantidad de votos acumulados.
         */
        unsigned int contarVotos();

};

#endif /* OPCION_H_ */

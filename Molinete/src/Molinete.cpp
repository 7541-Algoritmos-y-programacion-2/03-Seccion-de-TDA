#include "Molinete.h"

Molinete::Molinete() {

	personasQueEntraron = 0;
	personasQueSalieron = 0;
	limiteDePersonasDentro = LIMITE_DE_PERSONAS_DENTRO;
	maximaCantidadDePersonasDentro = 0;
}

Molinete::Molinete(int cantidadLimiteDePersonasDentro) {

	if (cantidadLimiteDePersonasDentro < 0) {

		cantidadLimiteDePersonasDentro = LIMITE_DE_PERSONAS_DENTRO;
	}

	personasQueEntraron = 0;
	personasQueSalieron = 0;
	limiteDePersonasDentro = cantidadLimiteDePersonasDentro;
	maximaCantidadDePersonasDentro = 0;
}

void Molinete::dejarEntrar() {

	if (cabenMasPersonasDentro()) {

		personasQueEntraron++;

		actualizarMaximaCantidadDePersonasDentro();
	}
}

void Molinete::actualizarMaximaCantidadDePersonasDentro() {

	if (contarPersonasDentro() > maximaCantidadDePersonasDentro) {

		maximaCantidadDePersonasDentro = contarPersonasDentro();
	}
}

void Molinete::dejarSalir() {

	if (existenPersonasDentro()) {

		personasQueSalieron++;
	}
}

int Molinete::contarPersonasDentro() {

	return personasQueEntraron - personasQueSalieron;
}

bool Molinete::existenPersonasDentro() {

	return (contarPersonasDentro() > 0);
}

bool Molinete::cabenMasPersonasDentro() {

	return (contarPersonasDentro() < limiteDePersonasDentro);
}

int Molinete::obtenerMaximaCantidadDePersonasDentro() {

	return maximaCantidadDePersonasDentro;
}

// definir proteccion de inclusion
#ifndef CATALOGO_H
#define CATALOGO_H

// incluir list
#include <list>
// incluir string
#include <string>
// incluir iostream para imprimir
#include <iostream>
// incluir planera
#include "Planeta.h"

// declarar clase catalogo
class Catalogo {
    // declarar contenedor lista doblemente ligada
    std::list<Planeta> planetas;

public:
    // declarar metodo cargar desde csv
    bool cargarCSV(const std::string& ruta, bool saltarHeader = true);
    // declarar metodo agregar planeta
    void agregar(const Planeta& p);
    // declarar metodo imprimir
    void imprimir(int maxFilas = -1) const;

    // declarar metodos de ordenamiento
    void ordenarPorAnioAsc();
    // declarar metodos de ordenamiento
    void ordenarPorAnioDesc();
    // declarar metodos de ordenamiento
    void ordenarPorDistanciaAsc();
    // declarar metodos de ordenamiento
    void ordenarPorDistanciaDesc();
    // declarar metodos de ordenamiento
    void ordenarPorMasaAsc();
    // declarar metodos de ordenamiento
    void ordenarPorRadioAsc();
};

#endif

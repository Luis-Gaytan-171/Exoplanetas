// definir proteccion de inclusion
#ifndef CATALOGO_H
#define CATALOGO_H

// incluir dependencias
#include <vector>
#include <string>
#include <functional>
#include "Planeta.h"

// declarar clase catalogo
class Catalogo {
    // declarar contenedor de planetas
    std::vector<Planeta> planetas;

    // declarar mergesort generico estable sobre vector y comparador
    static void mergeSort(std::vector<Planeta>& a,
                          int l,
                          int r,
                          const std::function<bool(const Planeta&, const Planeta&)>& cmp);

    // declarar funcion merge estable
    static void merge(std::vector<Planeta>& a,
                      int l,
                      int m,
                      int r,
                      const std::function<bool(const Planeta&, const Planeta&)>& cmp);

public:
    // declarar carga desde csv
    bool cargarCSV(const std::string& ruta, bool saltarHeader = true);

    // declarar alta de planeta
    void agregar(const Planeta& p);

    // declarar obtener referencia del vector
    const std::vector<Planeta>& getTodos() const;

    // declarar impresion en consola
    void imprimir(int maxFilas = -1) const;

    // declarar ordenamientos por distintos criterios
    void ordenarPorAnioAsc();
    void ordenarPorAnioDesc();
    void ordenarPorDistanciaAsc();
    void ordenarPorDistanciaDesc();
    void ordenarPorMasaAsc();
    void ordenarPorRadioAsc();
};

#endif // CATALOGO_H

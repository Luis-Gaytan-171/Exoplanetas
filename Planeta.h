// definir proteccion de inclusion
#ifndef PLANETA_H
#define PLANETA_H

// incluir string
#include <string>

// declarar la clase planeta
class Planeta {
    // declarar atributos
    std::string nombre;
    // declarar atributos
    int anio;
    // declarar atributos
    double distancia;
    // declarar atributos
    double masa;
    // declarar atributos
    double radio;
    // declarar atributos
    std::string metodo;

public:
    // declarar constructor por defecto
    Planeta();
    // declarar constructor con parametros
    Planeta(const std::string& nombre,
            int anio,
            double distancia,
            double masa,
            double radio,
            const std::string& metodo);

    // declarar metodos getters
    const std::string& getNombre() const;
    // declarar metodos getters
    int getAnio() const;
    // declarar metodos getters
    double getDistancia() const;
    // declarar metodos getters
    double getMasa() const;
    // declarar metodos getters
    double getRadio() const;
    // declarar metodos getters
    const std::string& getMetodo() const;

    // declarar metodo para texto legible
    std::string hacerTextoLegible() const;

    // declarar metodo para crear objeto desde csv
    static Planeta crearDesdeCSV(const std::string& linea);
};

// terminar proteccion de inclusion
#endif

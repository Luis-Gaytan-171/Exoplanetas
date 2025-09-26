#ifndef PLANETA_H
#define PLANETA_H

#include <string>

// declarar la clase planeta
class Planeta {
    // declarar atributos
    std::string nombre;
    int anio;
    double distancia;
    double masa;
    double radio;
    std::string metodo;

public:
    // declarar constructores
    Planeta();
    Planeta(const std::string& nombre,
            int anio,
            double distancia,
            double masa,
            double radio,
            const std::string& metodo);

    // declarar metodos getters
    const std::string& getNombre() const;
    int getAnio() const;
    double getDistancia() const;
    double getMasa() const;
    double getRadio() const;
    const std::string& getMetodo() const;

    // declarar metodo para texto legible
    std::string hacerTextoLegible() const;

    // declarar metodo para crear objeto desde csv
    static Planeta crearDesdeCSV(const std::string& linea);
};

#endif // PLANETA_H

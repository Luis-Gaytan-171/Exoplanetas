#include "Planeta.h"
#include <sstream>
#include <iomanip>

// definir constructor por defecto
Planeta::Planeta() : nombre(""), anio(0), distancia(0), masa(0), radio(0), metodo("") {}

// definir constructor con parametros
Planeta::Planeta(const std::string& n, int a, double d, double m, double r, const std::string& me)
    : nombre(n), anio(a), distancia(d), masa(m), radio(r), metodo(me) {}

// definir metodos getters
const std::string& Planeta::getNombre() const { return nombre; }
int Planeta::getAnio() const { return anio; }
double Planeta::getDistancia() const { return distancia; }
double Planeta::getMasa() const { return masa; }
double Planeta::getRadio() const { return radio; }
const std::string& Planeta::getMetodo() const { return metodo; }

// definir metodo para texto legible
std::string Planeta::hacerTextoLegible() const {
    std::ostringstream out;
    out << nombre
        << " | anio " << anio
        << " | distancia " << std::fixed << std::setprecision(2) << distancia << " al"
        << " | masa " << std::fixed << std::setprecision(2) << masa << " mt"
        << " | radio " << std::fixed << std::setprecision(2) << radio << " rt"
        << " | metodo " << metodo;
    return out.str();
}

// definir metodo para crear desde csv
Planeta Planeta::crearDesdeCSV(const std::string& linea) {
    std::stringstream ss(linea);

    // variables temporales
    std::string nombre, anioS, distS, masaS, radioS, metodo;

    // leer datos separados por coma
    std::getline(ss, nombre, ',');
    std::getline(ss, anioS, ',');
    std::getline(ss, distS, ',');
    std::getline(ss, masaS, ',');
    std::getline(ss, radioS, ',');
    std::getline(ss, metodo, ',');

    // convertir strings a numeros
    int anio = anioS.empty() ? 0 : std::stoi(anioS);
    double distancia = distS.empty() ? 0.0 : std::stod(distS);
    double masa = masaS.empty() ? 0.0 : std::stod(masaS);
    double radio = radioS.empty() ? 0.0 : std::stod(radioS);

    // regresar planeta construido
    return Planeta(nombre, anio, distancia, masa, radio, metodo);
}

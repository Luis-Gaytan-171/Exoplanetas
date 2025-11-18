// incluir header de planeta
#include "Planeta.h"
// incluir sstream para parseo
#include <sstream>
// incluir iomanip para formato
#include <iomanip>

// definir constructor por defecto
Planeta::Planeta() : nombre(""), anio(0), distancia(0), masa(0), radio(0), metodo("") {}

// definir constructor con parametros
Planeta::Planeta(const std::string& n, int a, double d, double m, double r, const std::string& me)
    : nombre(n), anio(a), distancia(d), masa(m), radio(r), metodo(me) {}

// definir getter nombre
const std::string& Planeta::getNombre() const { return nombre; }
// definir getter anio
int Planeta::getAnio() const { return anio; }
// definir getter distancia
double Planeta::getDistancia() const { return distancia; }
// definir getter masa
double Planeta::getMasa() const { return masa; }
// definir getter radio
double Planeta::getRadio() const { return radio; }
// definir getter metodo
const std::string& Planeta::getMetodo() const { return metodo; }

// definir metodo para texto legible
std::string Planeta::hacerTextoLegible() const {
    // crear stream de salida
    std::ostringstream out;
    // escribir nombre
    out << nombre
        // escribir anio
        << " | anio " << anio
        // escribir distancia
        << " | distancia " << std::fixed << std::setprecision(2) << distancia << " al"
        // escribir masa
        << " | masa " << std::fixed << std::setprecision(2) << masa << " mt"
        // escribir radio
        << " | radio " << std::fixed << std::setprecision(2) << radio << " rt"
        // escribir metodo
        << " | metodo " << metodo;
    // regresar cadena
    return out.str();
}

// definir metodo para crear desde csv
Planeta Planeta::crearDesdeCSV(const std::string& linea) {
    // crear stream con la linea
    std::stringstream ss(linea);
    // variables temporales de texto
    std::string nombreS;
    // variables temporales de texto
    std::string anioS;
    // variables temporales de texto
    std::string distS;
    // variables temporales de texto
    std::string masaS;
    // variables temporales de texto
    std::string radioS;
    // variables temporales de texto
    std::string metodoS;

    // leer nombre
    std::getline(ss, nombreS, ',');
    // leer anio
    std::getline(ss, anioS, ',');
    // leer distancia
    std::getline(ss, distS, ',');
    // leer masa
    std::getline(ss, masaS, ',');
    // leer radio
    std::getline(ss, radioS, ',');
    // leer metodo
    std::getline(ss, metodoS, ',');

    // convertir anio
    int anioV = anioS.empty() ? 0 : std::stoi(anioS);
    // convertir distancia
    double distanciaV = distS.empty() ? 0.0 : std::stod(distS);
    // convertir masa
    double masaV = masaS.empty() ? 0.0 : std::stod(masaS);
    // convertir radio
    double radioV = radioS.empty() ? 0.0 : std::stod(radioS);

    // crear y regresar planeta
    return Planeta(nombreS, anioV, distanciaV, masaV, radioV, metodoS);
}

// definir metodo para convertir a csv
std::string Planeta::convertirACsv() const {
    // crear stream de salida
    std::ostringstream out;
    // escribir campos separados por coma
    out << nombre << "," << anio << "," << distancia << "," << masa << "," << radio << "," << metodo;
    // regresar linea csv
    return out.str();
}

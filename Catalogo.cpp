// incluir header de catalogo
#include "Catalogo.h"
// incluir fstream para archivos
#include <fstream>

// definir metodo cargar desde csv
bool Catalogo::cargarCSV(const std::string& ruta, bool saltarHeader) {
    // abrir archivo en lectura
    std::ifstream fin(ruta);
    // validar apertura
    if (!fin.is_open()) {
        // regresar falso en error
        return false;
    }

    // variable para lineas
    std::string linea;

    // opcional saltar encabezado
    if (saltarHeader && std::getline(fin, linea)) {
        // encabezado omitido
    }

    // limpiar lista actual
    planetas.clear();

    // leer linea por linea
    while (std::getline(fin, linea)) {
        // ignorar lineas vacias
        if (linea.empty()) continue;
        // crear planeta desde csv
        Planeta p = Planeta::crearDesdeCSV(linea);
        // agregar a la lista
        planetas.push_back(p);
    }

    // cerrar archivo
    fin.close();
    // regresar exito
    return true;
}

// definir metodo agregar
void Catalogo::agregar(const Planeta& p) {
    // insertar al final
    planetas.push_back(p);
}

// definir metodo imprimir
void Catalogo::imprimir(int maxFilas) const {
    // contador de filas impresas
    int count = 0;
    // calcular limite
    int limite = maxFilas < 0 ? static_cast<int>(planetas.size()) : maxFilas;
    // recorrer lista
    for (const auto& p : planetas) {
        // imprimir linea legible
        std::cout << p.hacerTextoLegible() << std::endl;
        // aumentar contador
        ++count;
        // romper si alcanzamos limite
        if (count >= limite) break;
    }
}

// definir metodo buscar por nombre
bool Catalogo::buscarPorNombre(const std::string& nombre, Planeta& encontrado) const {
    // recorrer lista
    for (const auto& p : planetas) {
        // comparar nombre
        if (p.getNombre() == nombre) {
            // copiar planeta encontrado
            encontrado = p;
            // regresar verdadero
            return true;
        }
    }
    // regresar falso si no se encontro
    return false;
}

// definir metodo guardar en csv
bool Catalogo::guardarCSV(const std::string& ruta, bool incluirHeader) const {
    // abrir archivo en escritura
    std::ofstream fout(ruta);
    // validar apertura
    if (!fout.is_open()) {
        // regresar falso en error
        return false;
    }

    // escribir encabezado opcional
    if (incluirHeader) {
        // escribir header
        fout << "nombre,anio,distancia,masa,radio,metodo\n";
    }

    // recorrer lista
    for (const auto& p : planetas) {
        // escribir linea csv
        fout << p.convertirACsv() << "\n";
    }

    // cerrar archivo
    fout.close();
    // regresar exito
    return true;
}

// definir ordenar por anio ascendente
void Catalogo::ordenarPorAnioAsc() {
    // aplicar sort con comparador
    planetas.sort([](const Planeta& a, const Planeta& b){
        // comparar anio
        return a.getAnio() < b.getAnio();
    });
}

// definir ordenar por anio descendente
void Catalogo::ordenarPorAnioDesc() {
    // aplicar sort con comparador
    planetas.sort([](const Planeta& a, const Planeta& b){
        // comparar anio descendente
        return a.getAnio() > b.getAnio();
    });
}

// definir ordenar por distancia ascendente
void Catalogo::ordenarPorDistanciaAsc() {
    // aplicar sort con comparador
    planetas.sort([](const Planeta& a, const Planeta& b){
        // comparar distancia
        return a.getDistancia() < b.getDistancia();
    });
}

// definir ordenar por distancia descendente
void Catalogo::ordenarPorDistanciaDesc() {
    // aplicar sort con comparador
    planetas.sort([](const Planeta& a, const Planeta& b){
        // comparar distancia descendente
        return a.getDistancia() > b.getDistancia();
    });
}

// definir ordenar por masa ascendente
void Catalogo::ordenarPorMasaAsc() {
    // aplicar sort con comparador
    planetas.sort([](const Planeta& a, const Planeta& b){
        // comparar masa
        return a.getMasa() < b.getMasa();
    });
}

// definir ordenar por radio ascendente
void Catalogo::ordenarPorRadioAsc() {
    // aplicar sort con comparador
    planetas.sort([](const Planeta& a, const Planeta& b){
        // comparar radio
        return a.getRadio() < b.getRadio();
    });
}

// incluir header de catalogo
#include "Catalogo.h"

// incluir iostream y fstream
#include <iostream>
#include <fstream>

// definir cargar csv
bool Catalogo::cargarCSV(const std::string& ruta, bool saltarHeader) {
    // abrir archivo
    std::ifstream fin(ruta);
    // validar apertura
    if (!fin.is_open()) return false;

    // leer linea por linea
    std::string linea;
    // saltar encabezado si aplica
    if (saltarHeader && std::getline(fin, linea)) { /* header omitido */ }

    // procesar lineas
    while (std::getline(fin, linea)) {
        // ignorar lineas vacias
        if (linea.empty()) continue;
        // crear planeta
        Planeta p = Planeta::fromCSV(linea);
        // agregar al vector
        planetas.push_back(p);
    }

    // cerrar archivo
    fin.close();
    return true;
}

// definir agregar
void Catalogo::agregar(const Planeta& p) {
    // insertar al final
    planetas.push_back(p);
}

// definir getTodos
const std::vector<Planeta>& Catalogo::getTodos() const {
    // retornar referencia constante
    return planetas;
}

// definir imprimir
void Catalogo::imprimir(int maxFilas) const {
    // calcular limite
    int limite = (maxFilas < 0 || maxFilas > (int)planetas.size()) ? (int)planetas.size() : maxFilas;

    // recorrer y mostrar
    for (int i = 0; i < limite; ++i) {
        // imprimir linea formateada
        std::cout << planetas[i].toString() << std::endl;
    }
}

// definir mergesort publico por criterios
void Catalogo::ordenarPorAnioAsc() {
    // definir comparador por anio ascendente
    auto cmp = [](const Planeta& a, const Planeta& b){ return a.getAnio() < b.getAnio(); };
    // aplicar mergesort
    mergeSort(planetas, 0, (int)planetas.size() - 1, cmp);
}

void Catalogo::ordenarPorAnioDesc() {
    // definir comparador por anio descendente
    auto cmp = [](const Planeta& a, const Planeta& b){ return a.getAnio() > b.getAnio(); };
    // aplicar mergesort
    mergeSort(planetas, 0, (int)planetas.size() - 1, cmp);
}

void Catalogo::ordenarPorDistanciaAsc() {
    // definir comparador por distancia ascendente
    auto cmp = [](const Planeta& a, const Planeta& b){ return a.getDistancia() < b.getDistancia(); };
    // aplicar mergesort
    mergeSort(planetas, 0, (int)planetas.size() - 1, cmp);
}

void Catalogo::ordenarPorDistanciaDesc() {
    // definir comparador por distancia descendente
    auto cmp = [](const Planeta& a, const Planeta& b){ return a.getDistancia() > b.getDistancia(); };
    // aplicar mergesort
    mergeSort(planetas, 0, (int)planetas.size() - 1, cmp);
}

void Catalogo::ordenarPorMasaAsc() {
    // definir comparador por masa ascendente
    auto cmp = [](const Planeta& a, const Planeta& b){ return a.getMasa() < b.getMasa(); };
    // aplicar mergesort
    mergeSort(planetas, 0, (int)planetas.size() - 1, cmp);
}

void Catalogo::ordenarPorRadioAsc() {
    // definir comparador por radio ascendente
    auto cmp = [](const Planeta& a, const Planeta& b){ return a.getRadio() < b.getRadio(); };
    // aplicar mergesort
    mergeSort(planetas, 0, (int)planetas.size() - 1, cmp);
}

// definir mergesort recursivo
void Catalogo::mergeSort(std::vector<Planeta>& a,
                         int l,
                         int r,
                         const std::function<bool(const Planeta&, const Planeta&)>& cmp) {
    // caso base
    if (l >= r) return;

    // calcular punto medio
    int m = l + (r - l) / 2;

    // ordenar mitad izquierda
    mergeSort(a, l, m, cmp);
    // ordenar mitad derecha
    mergeSort(a, m + 1, r, cmp);
    // combinar de forma estable
    merge(a, l, m, r, cmp);
}

// definir merge estable
void Catalogo::merge(std::vector<Planeta>& a,
                     int l,
                     int m,
                     int r,
                     const std::function<bool(const Planeta&, const Planeta&)>& cmp) {
    // crear copias temporales
    std::vector<Planeta> left(a.begin() + l, a.begin() + m + 1);
    std::vector<Planeta> right(a.begin() + m + 1, a.begin() + r + 1);

    // indices
    int i = 0, j = 0, k = l;

    // fusion estable
    while (i < (int)left.size() && j < (int)right.size()) {
        // elegir de manera estable
        if (cmp(left[i], right[j]) || (!cmp(right[j], left[i]))) {
            a[k++] = left[i++];
        } else {
            a[k++] = right[j++];
        }
    }

    // copiar remanentes izquierda
    while (i < (int)left.size()) a[k++] = left[i++];

    // copiar remanentes derecha
    while (j < (int)right.size()) a[k++] = right[j++];
}

// incluir iostream
#include <iostream>

// incluir catalogo
#include "Catalogo.h"

// funcion para mostrar menu
void mostrarMenu() {
    // imprimir opciones
    std::cout << "\n";
    std::cout << "1 cargar csv\n";
    std::cout << "2 mostrar planetas\n";
    std::cout << "3 ordenar por anio asc\n";
    std::cout << "4 ordenar por anio desc\n";
    std::cout << "5 ordenar por distancia asc\n";
    std::cout << "6 ordenar por distancia desc\n";
    std::cout << "7 ordenar por masa asc\n";
    std::cout << "8 ordenar por radio asc\n";
    std::cout << "9 salir\n";
    std::cout << "opcion: ";
}

// funcion principal
int main() {
    // crear catalogo
    Catalogo cat;

    // variables
    int opcion = 0;
    std::string ruta;

    // ciclo de menu
    while (true) {
        // mostrar menu
        mostrarMenu();

        // leer opcion
        if (!(std::cin >> opcion)) break;

        // ejecutar opcion
        if (opcion == 1) {
            // pedir ruta
            std::cout << "ruta del csv: ";
            std::cin >> ruta;
            // cargar archivo
            bool ok = cat.cargarCSV(ruta, true);
            // informar resultado
            std::cout << (ok ? "carga exitosa\n" : "no se pudo abrir el archivo\n");
        } else if (opcion == 2) {
            // imprimir todos
            cat.imprimir();
        } else if (opcion == 3) {
            // ordenar por anio asc
            cat.ordenarPorAnioAsc();
            std::cout << "orden listo\n";
        } else if (opcion == 4) {
            // ordenar por anio desc
            cat.ordenarPorAnioDesc();
            std::cout << "orden listo\n";
        } else if (opcion == 5) {
            // ordenar por distancia asc
            cat.ordenarPorDistanciaAsc();
            std::cout << "orden listo\n";
        } else if (opcion == 6) {
            // ordenar por distancia desc
            cat.ordenarPorDistanciaDesc();
            std::cout << "orden listo\n";
        } else if (opcion == 7) {
            // ordenar por masa asc
            cat.ordenarPorMasaAsc();
            std::cout << "orden listo\n";
        } else if (opcion == 8) {
            // ordenar por radio asc
            cat.ordenarPorRadioAsc();
            std::cout << "orden listo\n";
        } else if (opcion == 9) {
            // salir del programa
            break;
        } else {
            // opcion invalida
            std::cout << "opcion no valida\n";
        }
    }

    // terminar
    return 0;
}

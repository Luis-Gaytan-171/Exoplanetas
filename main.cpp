// incluir iostream
#include <iostream>
// incluir string
#include <string>
// incluir catalogo
#include "Catalogo.h"

// declarar funcion para mostrar menu
void mostrarMenu() {
    // salto de linea
    std::cout << "\n";
    // imprimir opcion
    std::cout << "1 cargar csv\n";
    // imprimir opcion
    std::cout << "2 mostrar planetas\n";
    // imprimir opcion
    std::cout << "3 ordenar por anio asc\n";
    // imprimir opcion
    std::cout << "4 ordenar por anio desc\n";
    // imprimir opcion
    std::cout << "5 ordenar por distancia asc\n";
    // imprimir opcion
    std::cout << "6 ordenar por distancia desc\n";
    // imprimir opcion
    std::cout << "7 ordenar por masa asc\n";
    // imprimir opcion
    std::cout << "8 ordenar por radio asc\n";
    // imprimir opcion
    std::cout << "9 salir\n";
    // imprimir invitacion
    std::cout << "opcion ";
}

// funcion principal
int main() {
    // crear catalogo
    Catalogo cat;

    // declarar opcion
    int opcion = 0;
    // declarar ruta
    std::string ruta;

    // ciclo principal
    while (true) {
        // mostrar menu
        mostrarMenu();

        // leer opcion
        if (!(std::cin >> opcion)) {
            // terminar por error de entrada
            break;
        }

        // evaluar opcion
        if (opcion == 1) {
            // solicitar ruta
            std::cout << "ruta del csv ";
            std::cin.ignore();
            std::getline(std::cin, ruta);
            // cargar archivo
            bool ok = cat.cargarCSV(ruta, true);
            // imprimir resultado
            std::cout << (ok ? "carga exitosa\n" : "no se pudo abrir el archivo\n");
        } else if (opcion == 2) {
            // imprimir todos
            cat.imprimir();
        } else if (opcion == 3) {
            // ordenar por anio asc
            cat.ordenarPorAnioAsc();
            // confirmar
            std::cout << "orden listo\n";
        } else if (opcion == 4) {
            // ordenar por anio desc
            cat.ordenarPorAnioDesc();
            // confirmar
            std::cout << "orden listo\n";
        } else if (opcion == 5) {
            // ordenar por distancia asc
            cat.ordenarPorDistanciaAsc();
            // confirmar
            std::cout << "orden listo\n";
        } else if (opcion == 6) {
            // ordenar por distancia desc
            cat.ordenarPorDistanciaDesc();
            // confirmar
            std::cout << "orden listo\n";
        } else if (opcion == 7) {
            // ordenar por masa asc
            cat.ordenarPorMasaAsc();
            // confirmar
            std::cout << "orden listo\n";
        } else if (opcion == 8) {
            // ordenar por radio asc
            cat.ordenarPorRadioAsc();
            // confirmar
            std::cout << "orden listo\n";
        } else if (opcion == 9) {
            // salir del programa
            break;
        } else {
            // opcion no valida
            std::cout << "opcion no valida\n";
        }
    }

    // terminar ejecucion
    return 0;
}

// incluir iostream
#include <iostream>
// incluir string
#include <string>
// incluir limits
#include <limits>
// incluir catalogo
#include "Catalogo.h"

// declarar funcion para mostrar menu
void mostrarMenu() {
    // salto de linea
    std::cout << "\n";
    // imprimir opcion
    std::cout << "1 cargar archivo csv\n";
    // imprimir opcion
    std::cout << "2 mostrar planetas\n";
    // imprimir opcion
    std::cout << "3 ordenar por anio asc y mostrar\n";
    // imprimir opcion
    std::cout << "4 ordenar por anio desc y mostrar\n";
    // imprimir opcion
    std::cout << "5 ordenar por distancia asc y mostrar\n";
    // imprimir opcion
    std::cout << "6 ordenar por distancia desc y mostrar\n";
    // imprimir opcion
    std::cout << "7 ordenar por masa asc y mostrar\n";
    // imprimir opcion
    std::cout << "8 ordenar por radio asc y mostrar\n";
    // imprimir opcion
    std::cout << "9 buscar planeta por nombre\n";
    // imprimir opcion
    std::cout << "10 guardar catalogo en csv\n";
    // imprimir opcion
    std::cout << "11 salir\n";
    // imprimir invitacion
    std::cout << "opcion ";
}

// funcion principal
int main() {
    // crear catalogo
    Catalogo cat;

    // intentar carga automatica
    bool cargadoAuto = cat.cargarCSV("exoplanetas.csv", true);
    // informar resultado de carga automatica
    if (cargadoAuto) {
        // mensaje de exito
        std::cout << "archivo exoplanetas.csv cargado automaticamente\n";
    } else {
        // mensaje de aviso
        std::cout << "no se encontro exoplanetas.csv usa la opcion 1 para cargar un archivo\n";
    }

    // declarar opcion
    int opcion = 0;

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
            // limpiar salto de linea
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // solicitar ruta
            std::cout << "ruta del csv ";
            // leer ruta completa
            std::string ruta;
            std::getline(std::cin, ruta);
            // cargar archivo
            bool ok = cat.cargarCSV(ruta, true);
            // imprimir resultado
            std::cout << (ok ? "carga exitosa\n" : "no se pudo abrir el archivo\n");
        } else if (opcion == 2) {
            // mostrar planetas
            cat.imprimir();
        } else if (opcion == 3) {
            // ordenar por anio asc
            cat.ordenarPorAnioAsc();
            // mostrar resultado
            cat.imprimir();
        } else if (opcion == 4) {
            // ordenar por anio desc
            cat.ordenarPorAnioDesc();
            // mostrar resultado
            cat.imprimir();
        } else if (opcion == 5) {
            // ordenar por distancia asc
            cat.ordenarPorDistanciaAsc();
            // mostrar resultado
            cat.imprimir();
        } else if (opcion == 6) {
            // ordenar por distancia desc
            cat.ordenarPorDistanciaDesc();
            // mostrar resultado
            cat.imprimir();
        } else if (opcion == 7) {
            // ordenar por masa asc
            cat.ordenarPorMasaAsc();
            // mostrar resultado
            cat.imprimir();
        } else if (opcion == 8) {
            // ordenar por radio asc
            cat.ordenarPorRadioAsc();
            // mostrar resultado
            cat.imprimir();
        } else if (opcion == 9) {
            // limpiar salto de linea
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // pedir nombre a buscar
            std::cout << "nombre del planeta ";
            // leer nombre completo
            std::string nombre;
            std::getline(std::cin, nombre);
            // variable para resultado
            Planeta encontrado;
            // realizar busqueda
            bool ok = cat.buscarPorNombre(nombre, encontrado);
            // mostrar resultado
            if (ok) {
                // imprimir planeta encontrado
                std::cout << "planeta encontrado\n";
                std::cout << encontrado.hacerTextoLegible() << "\n";
            } else {
                // mensaje de no encontrado
                std::cout << "no se encontro el planeta\n";
            }
        } else if (opcion == 10) {
            // limpiar salto de linea
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // pedir nombre de archivo de salida
            std::cout << "nombre del archivo de salida ";
            // leer ruta de salida
            std::string ruta;
            std::getline(std::cin, ruta);
            // guardar archivo
            bool ok = cat.guardarCSV(ruta, true);
            // informar resultado
            std::cout << (ok ? "archivo guardado correctamente\n" : "no se pudo guardar el archivo\n");
        } else if (opcion == 11) {
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

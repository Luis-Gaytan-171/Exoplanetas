# Exoplanetas

este proyecto trata de un sistema para **guardar y organizar información de exoplanetas** (planetas fuera del sistema solar).  
la idea es poder ver los datos ordenados por distintos criterios: **año de descubrimiento**, **distancia a la tierra**, **masa** o **radio**.

---

## idea general del proyecto
cada planeta que registremos va a tener datos como:  
- nombre  
- año de descubrimiento  
- distancia a la tierra (años luz)  
- masa (en relación a la tierra)  
- radio (en relación a la tierra)  
- método de descubrimiento  

lo que queremos es poder **ordenar y ver estos planetas de diferentes formas**, mostrando cómo cambia la lista según el criterio que elijamos.

---

## describe tu avance de proyecto (avance 2)

para este avance estamos incluyendo:  
- la clase `planeta`, que guarda la info básica de cada exoplaneta.  
- la clase `catalogo`, que almacena todos los planetas y expone funciones para cargar, mostrar y ordenar.  
- funciones para leer desde un archivo `.csv` (con `crearDesdeCSV`) y para imprimir “bonito” cada planeta (con `hacerTextoLegible`).  
- **ordenamiento con mergesort estable** aplicado al contenedor de planetas.  

> nota: en el avance anterior empezamos con `vector<planeta>`. en este avance **migramos a `std::list<planeta>`** (lista doblemente ligada) para almacenar los datos de forma más natural y poder ordenar con el `sort()` propio de la lista (que es **estable** y de complejidad **O(n log n)**).

---

## cómo se usa el programa
1. al arrancar, el programa solicita la ruta al archivo `exoplanetas.csv` (por ejemplo `./exoplanetas.csv`).  
2. se cargan los datos a la estructura del catálogo.  
3. desde el menú, el usuario puede:
   - **mostrar** la lista de planetas,  
   - **ordenar** por año (asc/desc), distancia, masa o radio.  
4. el programa imprime los resultados con formato legible.

### cómo compilar y ejecutar

```bash
g++ -std=c++17 main.cpp Catalogo.cpp Planeta.cpp -o exoplanetas
./exoplanetas

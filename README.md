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

## descripción del avance 1
en el primer avance hicimos lo siguiente:
- la clase `planeta`, que guarda la info básica de cada exoplaneta.  
- la clase `catalogo`, que almacena todos los planetas y expone funciones para cargar, mostrar y ordenar.  
- funciones que cargan los planetas desde un archivo `.csv` mediante `crearDesdeCSV`.  
- funciones que nos permiten ordenar los planetas por **año, distancia, masa o radio**.  
- **estructura de datos inicial**: `vector<planeta>` como contenedor principal.  
- **ordenamiento**: usamos **mergesort** (implementación propia) como algoritmo principal por su complejidad **O(n log n)** y su **estabilidad**.

---

## descripción del avance 2 (cambios respecto al avance 1)
en este segundo avance hicimos mejoras para que el sistema almacene, ordene y acceda a los datos de forma más “natural”:

1. **migración de `vector<planeta>` a `std::list<planeta>`**  
   ahora usamos una **lista doblemente ligada** de la librería estándar. esto nos da:
   - inserciones/eliminaciones en extremos en **O(1)**,  
   - recorridos secuenciales simples con iteradores,  
   - y, lo más importante, la posibilidad de usar **`list::sort()`**, que es **estable** y está especificado para ejecutarse en **O(n log n)** (usa una variante de **mergesort** interna).

2. **ordenamiento estable con `list::sort`**  
   seguimos con **mergesort**, pero aprovechando la versión estable de la lista (evitamos re-implementar y aseguramos el comportamiento esperado por estándar).

3. **sección de compilación/ejecución agregada**  
   (esto corrige la falta detectada en la retroalimentación).

4. **explicación formal de por qué elegimos mergesort**  
   ahora describimos **qué significa “estable”** y **por qué su complejidad se mantiene en O(n log n) sin importar el estado inicial**, además de comparar con quicksort/bubble/selection con base en complejidades (no solo “rápido/lento”).

5. **entradas y salidas del avance**  
   agregamos secciones claras de **entradas** (formato del `.csv`) y **salidas** (qué imprime el programa).

---

## cómo se usa el programa
1. al arrancar, el programa pide la ruta del archivo `exoplanetas.csv` (por ejemplo `./exoplanetas.csv`).  
2. se cargan los datos a la estructura del catálogo (lista doblemente ligada).  
3. desde el menú, el usuario puede:
   - **mostrar** la lista de planetas,  
   - **ordenar** por año (asc/desc),  
   - **ordenar** por distancia, masa o radio.  
4. el programa imprime los resultados con formato legible (usando `hacerTextoLegible`).

### cómo compilar y ejecutar

```bash
g++ -std=c++17 main.cpp Catalogo.cpp Planeta.cpp -o exoplanetas
./exoplanetas

si el compilador te pide ruta absoluta o estás en windows, ajusta `./exoplanetas` por `exoplanetas.exe`.
```
---

## descripción de las **entradas** del avance de proyecto
el programa requiere un archivo `exoplanetas.csv` con el siguiente formato (cabecera + valores separados por coma):

nombre,anio,distancia,masa,radio,metodo
Kepler-452b,2015,1400,5.0,1.60,transito
Proxima Centauri b,2016,4.25,1.27,1.10,velocidad radial
TRAPPIST-1e,2017,39.6,0.62,0.92,transito


- `anio`: entero  
- `distancia`, `masa`, `radio`: números reales  
- `metodo`: texto (ej. tránsito, velocidad radial, imagen directa)

> **mecanismo de lectura**: leemos línea a línea con `std::getline`, separamos por comas con `std::stringstream`, convertimos strings a `int`/`double` cuando aplica y construimos un `planeta` con `crearDesdeCSV`. las líneas vacías se ignoran.

---

## descripción de las **salidas** del avance de proyecto
el programa imprime en consola:

1) **lista de planetas** en el orden actual del contenedor o del criterio aplicado, con formato legible (ejemplo): Proxima Centauri b | anio 2016 | distancia 4.25 al | masa 1.27 mt | radio 1.10 rt | metodo velocidad radial


2) **confirmaciones** al ordenar (ej. “orden listo”), o al cargar archivo (ej. “carga exitosa” / “no se pudo abrir el archivo”).

3) **errores amables** si el archivo no existe o el formato no es válido (líneas vacías, etc.).

---

## selección y análisis de algoritmos de ordenamiento

### por que **mergesort** (y qué significa “estable” aquí)
- **complejidad garantizada O(n log n)** en **mejor, promedio y peor caso**.  
  esto ocurre porque mergesort **siempre**:
  1) **divide** la colección en mitades (log₂ n niveles), y  
  2) **fusiona** pares de sublistas ordenadas (costo **lineal** por nivel).  
  el trabajo total es proporcional a `n` por nivel × `log n` niveles → **O(n log n)**, **independiente** de si los datos vienen ya ordenados, reversos o aleatorios.

- **algoritmo estable**: si dos planetas empatan en el atributo de orden (p. ej. mismo `anio`), **conservan su orden relativo anterior**.  
  esto es clave cuando **encadenamos criterios** (p. ej. primero ordenamos por `anio` y luego por `distancia`; los que comparten `anio` quedarán ordenados por `distancia` **sin romper** el orden previo entre los demás atributos).

- **espacio extra O(n)**: durante la fusión se usan buffers temporales para mezclar las mitades. esa memoria adicional es como la penalizacion de la estabilidad y de mantener O(n log n) **siempre**.

> en la implementación usamos `std::list::sort()`, que por especificación es **estable**(como ya explicamos anteriormente) y basado en una variante de **mergesort**, por lo que conserva exactamente estas propiedades.

### comparación formal con otros algoritmos (por qué NO son principales)

**quicksort**  
- **promedio**: O(n log n)  
- **peor caso**: **O(n²)** (pivotes repetidamente malos, p. ej. datos ya ordenados con cierta estrategia de pivote)   
- pros: poca memoria extra;  
- contras: **no** estable y existe un **peor caso cuadrático**, lo cual no queremos para un flujo que encadena criterios y busca comportamiento predecible.

**bubble sort**  
- **promedio/peor**: O(n²)  
- **mejor**: O(n) si la lista ya está casi ordenada (con bandera de “sin swap”)  
- contras: ineficiente en general; útil solo para aprender a implementar algoritmos de ordenamiento o con listas muy pequeñas/casi ordenadas.

**selection sort**  
- **todos los casos**: O(n²)   
- pros: pocos swaps;  
- contras: no adaptativo (aunque esté casi ordenada, sigue tardando O(n²)).

**conclusión**  
usamos **mergesort** (vía `list::sort`) para asegurar **complejidad consistente** y **encadenamiento de criterios** sin perder orden relativo.

---






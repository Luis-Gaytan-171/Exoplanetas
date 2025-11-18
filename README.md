# Proyecto: Exoplanetas
este proyecto trata de un sistema para **guardar y organizar información de exoplanetas** (planetas fuera del sistema solar).  
la idea es poder ver los datos ordenados por distintos criterios: **año de descubrimiento**, **distancia a la tierra**, **masa** o **radio**, y ahora también poder **buscar** y **guardar** la información procesada en un nuevo archivo.

---

## Descripción del avance 1
en el primer avance hicimos lo siguiente:
- la clase `planeta`, que guarda la info básica de cada exoplaneta.  
- la clase `catalogo`, que almacena todos los planetas y expone funciones para cargar, mostrar y ordenar.  
- funciones que cargan los planetas desde un archivo `.csv` mediante `crearDesdeCSV`.  
- funciones que nos permiten ordenar los planetas por **año, distancia, masa o radio**.  
- **estructura de datos inicial**: `vector<planeta>` como contenedor principal.  
- **ordenamiento**: usamos **mergesort** (implementación propia) como algoritmo principal por su complejidad **O(n log n)** y su **estabilidad**.

---

## Descripción del avance 2
en el segundo avance hicimos mejoras para que el sistema almacene, ordene y acceda a los datos de forma más “natural”:

- migramos de `vector<planeta>` a `std::list<planeta>`, una **lista doblemente ligada** de la librería estándar.
- esto nos dio:
  - inserciones/eliminaciones en extremos en **O(1)**,  
  - recorridos secuenciales simples con iteradores,  
  - y, lo más importante, la posibilidad de usar **`list::sort()`**, que es **estable** y está especificado para ejecutarse en **O(n log n)** porque utiliza una variante de **mergesort** interna.
- mantuvimos el algoritmo de ordenamiento principal como **mergesort estable**, pero aprovechando la implementación ya optimizada de la lista.

### Cambios sobre el primer avance
1. **cambio de `vector` a `std::list`**  
   razón del cambio: la lista doblemente ligada se adapta mejor al tipo de operaciones que hacemos en el catálogo, donde necesitamos recorridos y reordenamientos frecuentes, y no tanto acceso por índice. además, `std::list` provee un `sort()` estable con complejidad O(n log n) en todos los casos, lo que simplifica el código y mantiene el análisis de complejidad claro.
2. **uso de `list::sort` en lugar de nuestra propia implementación de mergesort**  
   razón del cambio: la versión de `sort()` para listas ya está optimizada y definida para usar un algoritmo tipo mergesort estable. esto reduce posibles errores de implementación y mantiene la garantÍa formal de O(n log n) en mejor, promedio y peor caso, además de conservar la estabilidad que necesitamos para encadenar criterios de ordenamiento.

---

## Descripción del avance 3
en este tercer avance cerramos el proyecto agregando **usabilidad**, **persistencia de datos** y un **análisis de complejidad completo de todos los componentes**:

- se implementó **carga automática** del archivo `exoplanetas.csv` al iniciar el programa. si el archivo está en la misma carpeta que el ejecutable, se carga sin que el usuario tenga que escribir la ruta.
- se mantuvo la opción de **cargar otro archivo** desde el menú, en caso de que el usuario quiera trabajar con un csv distinto.
- se mejoró la usabilidad del menú:
  - después de seleccionar un ordenamiento, el programa **muestra de inmediato** la lista ya ordenada, en lugar de solo decir “orden listo”.
  - se agregó una opción para **buscar un planeta por nombre** dentro del catálogo.
- se implementó un mecanismo de **escritura de archivos**:
  - ahora se puede **guardar el catálogo actual** en un nuevo archivo csv usando la opción del menú correspondiente.  
  - este guardado usa un formato compatible con el archivo original, incluyendo encabezado y los mismos campos.
- se hizo un **análisis de complejidad** no solo de los algoritmos de ordenamiento y de las estructuras de datos, sino también de:
  - lectura de archivos,  
  - escritura de archivos,  
  - búsqueda por nombre,  
  - impresión de resultados y del ciclo principal del menú,  
  y se determinó la **complejidad final del programa**.

### Cambios sobre el segundo avance
1. **carga automática de `exoplanetas.csv` al iniciar**  
   razón del cambio: para mejorar la usabilidad, ahora el usuario puede simplemente ejecutar el programa y empezar a usarlo sin tener que escribir la ruta cada vez. si el archivo no se encuentra, el programa avisa y permite cargar uno manualmente.
2. **mostrar inmediatamente la lista ordenada al seleccionar un criterio**  
   razón del cambio: antes solo se mostraba un mensaje de “orden listo”. ahora, al elegir un ordenamiento, el usuario ve directamente el resultado, lo que hace más fluida la interacción y más clara la relación entre la acción y la salida.
3. **búsqueda por nombre**  
   razón del cambio: se agregó un mecanismo explícito para consultar la información almacenada en la estructura a partir del nombre del planeta. esto refuerza la competencia de “consultar información de las estructuras” y hace el programa más útil.
4. **escritura de archivo csv de salida**  
   razón del cambio: era necesario implementar la persistencia de los datos procesados para cumplir con el criterio de “mecanismos de escritura de archivos” y para que el catálogo ordenado o modificado se pueda reutilizar en futuras ejecuciones o en otras herramientas.

---

## Instrucciones para compilar el avance de proyecto
ejecuta el siguiente comando en la terminal (desde la carpeta donde están los archivos `.cpp` y el `exoplanetas.csv`):
```bash
g++ -std=c++17 main.cpp Catalogo.cpp Planeta.cpp -o exoplanetas
```

Si el archivo exoplanetas.csv está en la misma carpeta que el ejecutable, se cargará automáticamente al inicio. si no se encuentra, el programa avisará y podrás cargar otro archivo desde el menú.


## Descripción de las entradas del avance de proyecto
el programa requiere un archivo exoplanetas.csv con el siguiente formato (cabecera + valores separados por coma):
...
nombre,anio,distancia,masa,radio,metodo
Kepler-452b,2015,1400,5.0,1.60,transito
Proxima Centauri b,2016,4.25,1.27,1.10,velocidad radial
TRAPPIST-1e,2017,39.6,0.62,0.92,transito
...
anio: entero
distancia, masa, radio: números reales
metodo: texto (por ejemplo tránsito, velocidad radial, imagen directa)
mecanismo de lectura: leemos línea a línea con std::getline, separamos por comas con std::stringstream, convertimos strings a int y double cuando aplica y construimos un objeto planeta con Planeta::crearDesdeCSV. las líneas vacías se ignoran.
para la escritura, el usuario puede elegir un nombre de archivo de salida (por ejemplo salida_ordenada.csv), que se genera con el mismo formato de columnas.

## Descripción de las salidas del avance de proyecto
el programa imprime en consola:
1.- lista de planetas en el orden actual del contenedor o del criterio aplicado, con formato legible, por ejemplo:

Proxima Centauri b | anio 2016 | distancia 4.25 al | masa 1.27 mt | radio 1.10 rt | metodo velocidad radial

2.- confirmaciones al ordenar (por ejemplo “orden listo por anio ascendente”), al cargar archivo (“carga exitosa” o “no se pudo abrir el archivo”) y al guardar archivo (“archivo guardado correctamente” o “no se pudo guardar el archivo”).

3.- búsqueda por nombre:
si encuentra el planeta, muestra su información en el mismo formato legible.
si no lo encuentra, muestra un mensaje indicando que no hubo coincidencias.

4.- archivo csv de salida generado desde el menú:
contiene todos los planetas actualmente almacenados en el catálogo, en el orden en que se encuentren (por ejemplo, ya ordenados por año o distancia).
el archivo de salida puede volver a usarse como entrada en futuras ejecuciones.

---

## Desarrollo de competencias

## SICT0301: Evalúa los componentes

### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

el algoritmo de ordenamiento principal del proyecto es mergesort, implementado a través de std::list::sort() en la clase Catalogo. según la especificación de la librería estándar, list::sort() está implementado como un algoritmo de tipo mergesort estable, con complejidad:

O(n log n) en el mejor caso, en su caso promedio y en el peor caso, porque siempre:
divide la lista en mitades (log₂ n niveles), y
fusiona sublistas ya ordenadas en un paso lineal por nivel.

el trabajo total es proporcional a n elementos por cada uno de los log n niveles, así que el costo final es O(n log n) sin importar si los datos están ya ordenados, parcialmente ordenados o totalmente desordenados.

además, el algoritmo es estable: si dos planetas coinciden en el atributo que se usa para ordenar (por ejemplo, el mismo anio), ambos conservan su orden relativo anterior. esto es importante porque a veces encadenamos ordenamientos por diferentes atributos, y la estabilidad garantiza que no se rompa o falle el orden previo cuando hay coincidencias.

en el código, esta competencia se observa en las funciones:

Catalogo::ordenarPorAnioAsc, ordenarPorAnioDesc,
ordenarPorDistanciaAsc, ordenarPorDistanciaDesc,
ordenarPorMasaAsc, ordenarPorRadioAsc,

todas ellas llaman a planetas.sort(lambda) y comparten este mismo análisis de complejidad.

como comparación, se consideraron otros algoritmos:
quicksort: O(n log n) promedio pero O(n²) en el peor caso y no es estable.
bubble sort y selection sort: O(n²) en todos los casos o casi todos, y no son adecuados para listas grandes.
por estas razones, mergesort (vía list::sort) fue elegido y analizado como la mejor opción para este problema.

### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

la estructura de datos principal es std::list<Planeta>, una lista doblemente ligada. las operaciones que usamos y su complejidad son:

- inserción al final con push_back → O(1)
se usa cuando cargamos planetas desde el archivo (Catalogo::cargarCSV) o cuando agregamos uno nuevo manualmente.

- recorrido de la lista → O(n)
aparece al imprimir todos los planetas (Catalogo::imprimir), al buscar por nombre (Catalogo::buscarPorNombre) y al recorrer para escribir en archivo (Catalogo::guardarCSV).

- ordenamiento con list::sort → O(n log n)
ya analizado arriba como mergesort estable.

- tamaño de la lista → se usa de forma implícita al recorrer, pero no se consulta de manera costosa; cada recorrido completo es O(n).

otras estructuras que aparecen son:

- std::string, para almacenar nombre, método y valores leídos. las operaciones principales usadas son concatenación simple y comparación, que en este contexto se consideran O(longitud de la cadena), pero como son textos relativamente cortos (nombres y métodos), el costo principal lo domina el número de planetas n.

- std::ifstream y std::ofstream, usados para lectura y escritura de archivos: cada lectura/escritura por línea es O(longitud de la línea), y al trabajar con n planetas el proceso completo es O(n).

con esto se cubre el análisis de complejidad de la estructura de datos principal y de su uso en las funciones relevantes del programa.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

además del ordenamiento y de la estructura principal, analizamos los demás componentes:

   lectura de archivo (Catalogo::cargarCSV):
   
      leemos el archivo línea por línea con std::getline → O(n) líneas.

      para cada línea, se separan los campos con std::stringstream y se convierten a tipos numéricos (stoi, stod) → O(1) por línea.

      se construye un Planeta y se inserta con push_back → O(1) por línea.

      complejidad total de carga → O(n).

   impresión de la lista (Catalogo::imprimir):

      recorre toda la lista y llama hacerTextoLegible para cada planeta.
      hacerTextoLegible trabaja con una cantidad constante de campos → O(1) por planeta.
      recorrido completo → O(n).

   búsqueda por nombre (Catalogo::buscarPorNombre):

      recorre la lista hasta encontrar coincidencia o terminar → en el peor caso recorre todos los elementos.
      complejidad → O(n).

   escritura de archivo (Catalogo::guardarCSV):

      recorre la lista y escribe una línea por planeta usando convertirACsv.

      operación O(1) por planeta, O(n) en total.

   ciclo del menú en main:

      cada iteración realiza operaciones O(1), O(n) o O(n log n) dependiendo de la opción:

      mostrar planetas → O(n),

      buscar → O(n),

      ordenar → O(n log n) y luego mostrar → O(n).
   
la complejidad final del programa, considerando las operaciones principales que puede elegir el usuario, está dominada por los ordenamientos, que son O(n log n).
las otras operaciones (carga, impresión, búsqueda, escritura) son O(n). por lo tanto, la complejidad global del sistema puede resumirse como:

O(n) para cargar, imprimir, buscar y guardar. como caso promedio

O(n log n) cuando se realiza un ordenamiento, que es el caso promedio

## SICT0302: Toma decisiones
      
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

el algoritmo de ordenamiento principal del proyecto es mergesort, implementado a través de std::list::sort() en la clase Catalogo. según la especificación de la librería estándar, list::sort() está implementado como un algoritmo de tipo mergesort estable, con complejidad:

O(n log n) en el mejor, promedio y peor caso, porque siempre:
divide la lista en mitades (log₂ n niveles), y fusiona sublistas ya ordenadas en un paso lineal por nivel.

el trabajo total es proporcional a n elementos por cada uno de los log n niveles, así que el costo final es O(n log n) sin importar si los datos están ya ordenados, parcialmente ordenados o totalmente desordenados.

además, el algoritmo es estable: si dos planetas empatan en el atributo que se usa para ordenar (por ejemplo, el mismo anio), ambos conservan su orden relativo anterior. esto es importante porque a veces encadenamos ordenamientos por diferentes atributos, y la estabilidad garantiza que no se “rompa” el orden previo cuando hay empates.

en el código, esta competencia se observa en las funciones:

- Catalogo::ordenarPorAnioAsc, ordenarPorAnioDesc,
- ordenarPorDistanciaAsc, ordenarPorDistanciaDesc,
- ordenarPorMasaAsc, ordenarPorRadioAsc,

todas ellas llaman a planetas.sort(lambda) y comparten este mismo análisis de complejidad

como comparación, se consideraron otros algoritmos:

**quicksort**: O(n log n) promedio pero O(n²) en el peor caso y no es estable.

**bubble sort** y selection sort: O(n²) en todos los casos o casi todos, y no son adecuados para listas grandes.

por estas razones, mergesort (vía list::sort) fue elegido y analizado como la mejor opción para este problema.

### Hace un análisis de complejidad correcto y completo de todas las estructuras de datos y cada uno de sus usos en el programa.

la estructura de datos principal es std::list<Planeta>, una lista doblemente ligada. las operaciones que usamos y su complejidad son:

inserción al final con push_back → O(1)
se usa cuando cargamos planetas desde el archivo (Catalogo::cargarCSV) o cuando agregamos uno nuevo manualmente.

recorrido de la lista → O(n)
aparece al imprimir todos los planetas (Catalogo::imprimir), al buscar por nombre (Catalogo::buscarPorNombre) y al recorrer para escribir en archivo (Catalogo::guardarCSV).

ordenamiento con list::sort → O(n log n)
ya analizado arriba como mergesort estable.

tamaño lógico de la lista → se usa de forma implícita al recorrer, pero no se consulta de manera costosa; cada recorrido completo es O(n).

otras estructuras que aparecen son:

std::string, para almacenar nombre, método y valores leídos. las operaciones principales usadas son concatenación simple y comparación, que en este contexto se consideran O(longitud de la cadena), pero como son textos relativamente cortos (nombres y métodos), el costo principal lo domina el número de planetas n.

std::ifstream y std::ofstream, usados para lectura y escritura de archivos: cada lectura/escritura por línea es O(longitud de la línea), y al trabajar con n planetas el proceso completo es O(n).

con esto se cubre el análisis de complejidad de la estructura de datos principal y de su uso en las funciones relevantes del programa.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

además del ordenamiento y de la estructura principal, analizamos los demás componentes:

lectura de archivo (Catalogo::cargarCSV):

leemos el archivo línea por línea con std::getline → O(n) líneas.
para cada línea, se separan los campos con std::stringstream y se convierten a tipos numéricos (stoi, stod) → O(1) por línea.
se construye un Planeta y se inserta con push_back → O(1) por línea.
complejidad total de carga → O(n).

impresión de la lista (Catalogo::imprimir):
recorre toda la lista y llama hacerTextoLegible para cada planeta.
hacerTextoLegible trabaja con una cantidad constante de campos → O(1) por planeta.
recorrido completo → O(n).

búsqueda por nombre (Catalogo::buscarPorNombre):
recorre la lista hasta encontrar coincidencia o terminar → en el peor caso recorre todos los elementos.
complejidad → O(n).

escritura de archivo (Catalogo::guardarCSV):
recorre la lista y escribe una línea por planeta usando convertirACsv.
operación O(1) por planeta, O(n) en total.

ciclo del menú en main:
cada iteración realiza operaciones O(1), O(n) o O(n log n) dependiendo de la opción:
mostrar planetas → O(n),

buscar → O(n),
ordenar → O(n log n) y luego mostrar → O(n).

la complejidad final del programa, considerando las operaciones principales que puede elegir el usuario, está dominada por los ordenamientos, que son O(n log n).
las otras operaciones (carga, impresión, búsqueda, escritura) son O(n). por lo tanto, la complejidad global del sistema puede resumirse como:

O(n) para cargar, imprimir, buscar y guardar.

O(n log n) cuando se realiza un ordenamiento, que es el caso dominante.

## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.

el algoritmo de ordenamiento elegido para este proyecto es mergesort, aplicado a través de std::list::sort(). la elección se basó en:

complejidad O(n log n) garantizada en mejor, promedio y peor caso, porque siempre divide la lista y fusiona sublistas, sin depender del estado inicial de los datos.

estabilidad: al ordenar por un atributo, los elementos con valores iguales mantienen su orden relativo original. esto es útil cuando queremos encadenar criterios de ordenamiento (por ejemplo, primero por año y luego por distancia) sin “romper” la organización ya lograda.

comparación con otros algoritmos:

quicksort tiene O(n log n) promedio pero O(n²) en el peor caso y no es estable.
bubble sort y selection sort tienen O(n²) y solo son razonables para listas muy pequeñas o casi ordenadas.

en el código, el uso correcto se observa en las funciones de Catalogo que ordenan por distintos atributos y luego muestran los resultados de inmediato, verificando así que el criterio se aplicó correctamente.

### Selecciona una estructura de datos adecuada al problema y la usa correctamente.

la estructura principal es std::list<Planeta>. se eligió porque:

representa de forma natural una colección encadenada de planetas, donde las operaciones más frecuentes son recorrer, ordenar y agregar al final.
permite inserciones y eliminaciones en extremos en O(1), sin realocaciones ni movimientos de bloques de memoria como en un vector.
está integrada con un sort() estable y con la complejidad adecuada O(n log n) para listas.

su uso correcto se refleja en:

Catalogo::cargarCSV (inserciones con push_back),

Catalogo::imprimir (recorrido con for-each),

Catalogo::ordenarPor... (uso de list::sort),

Catalogo::buscarPorNombre (recorrido lineal para consulta).

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos.

para consultar la información almacenada en la estructura, el programa incluye:

-la función Catalogo::imprimir, que recorre la lista y usa Planeta::hacerTextoLegible para mostrar cada registro en un formato claro y consistente.
-la función Catalogo::buscarPorNombre, que permite encontrar un planeta a partir de su nombre. si se encuentra, el programa muestra sus datos; si no, despliega un mensaje indicándolo.
-el menú en main ofrece opciones específicas para ver toda la lista, ordenarla y realizar búsquedas, lo que permite interactuar de forma directa con la estructura de datos.

estos mecanismos están conectados con la estructura std::list<Planeta> de manera correcta y respetando sus complejidades O(n) para recorridos y consultas lineales.

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.

la lectura de archivos se implementa en Catalogo::cargarCSV y cumple con:

validación de apertura del archivo: si no se puede abrir, la función regresa false y el programa muestra un mensaje de error.

- lectura línea por línea con std::getline, ignorando líneas vacías.
- uso de std::stringstream para separar los campos por comas.
- conversión de tipos (stoi, stod) para los campos numéricos.
- construcción del objeto Planeta mediante Planeta::crearDesdeCSV.
- inserción del planeta en la lista con push_back.

además, en el avance 3 se agregó la carga automática de exoplanetas.csv al inicio del programa, lo que hace más natural el uso del mecanismo de lectura.

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta

para la escritura de archivos se implementó la función Catalogo::guardarCSV, que:

-abre un archivo de salida con std::ofstream y valida que se haya abierto correctamente.
-escribe una línea de encabezado con los nombres de las columnas.
-recorre la lista de planetas y, para cada uno, llama Planeta::convertirACsv para generar una línea en formato csv.
-escribe todas las líneas y cierra el archivo al final.
-desde el menú en main, el usuario puede escoger la opción de guardar catálogo en csv, ingresar el nombre del archivo de salida, y el programa confirma si el archivo se guardó correctamente.

con esto se cubre el criterio de escritura de archivos, permitiendo que los datos organizados en la estructura de datos se conserven fuera de la ejecución del programa y se reutilicen posteriormente.







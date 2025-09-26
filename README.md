# Exoplanetas

Este proyecto trata de un sistema para **guardar y organizar información de exoplanetas** (planetas fuera del sistema solar).  
la idea es que podamos ver los datos de manera ordenada según diferentes criterios, por ejemplo, por año de descubrimiento, por distancia a la tierra o por características físicas como masa y radio.  

---

## Idea general del proyecto
cada planeta que registremos va a tener datos como:  
- nombre  
- año de descubrimiento  
- distancia a la tierra (años luz)  
- masa (en relación a la tierra)  
- radio (en relación a la tierra)  
- método de descubrimiento  

lo que queremos es poder **ordenar y ver estos planetas de diferentes formas**, mostrando cómo cambia la lista según el criterio que elijamos.

---

## Avance del proyecto
para este avance estamos incluyendo:  
- la clase `planeta`, que guarda toda la info básica de cada exoplaneta.  
- un `vector<planeta>` que usamos como lista para tener guardados a todos los planetas.  
- funciones que cargan los planetas desde un archivo `.csv`.  
- funciones que nos permiten ordenar los planetas ya sea por año, distancia, masa o radio.  

---

## Cómo se usa el programa
1. cuando arranca, el programa lee un archivo `exoplanetas.csv` con datos ya guardados.  
2. el usuario puede pedir que se muestre la lista de planetas o que se ordene por algún criterio.  
3. el programa aplica el algoritmo de ordenamiento seleccionado (por defecto usamos mergesort).  
4. finalmente, muestra en pantalla la lista de planetas ya ordenada.  

---

## Selección y análisis de algoritmos de ordenamiento

### mergesort
- complejidad: O(n log n) en todos los casos.  
- espacio extra: O(n).  
- estable: sí.  
- por qué lo elegimos: es el más seguro porque siempre va a ser rápido, no importa cómo estén los datos, y además mantiene el orden cuando hay empates (muy útil si ordenamos por un campo y luego por otro).  

### quicksort
- complejidad: O(n log n) promedio, O(n²) en el peor caso.  
- espacio extra: O(log n) por recursión.  
- estable: no.  
- por qué no lo usamos como principal: suele ser rápido, pero puede caer en O(n²) si sale mal el pivote y además no mantiene el orden estable.  

### bubble sort
- complejidad: O(n²) promedio y peor caso, O(n) si la lista ya está casi ordenada.  
- espacio extra: O(1).  
- estable: sí.  
- para qué sirve: es muy fácil de programar y puede ser útil si la lista ya está casi ordenada, pero para listas grandes no funciona bien.  

### selection sort
- complejidad: O(n²) en todos los casos.  
- espacio extra: O(1).  
- estable: no.  
- por qué no lo usamos: siempre tarda mucho y además no mantiene el orden estable. solo lo consideramos como comparación o ejemplo básico.  

---

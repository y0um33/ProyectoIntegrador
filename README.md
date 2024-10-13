# TC1031 (Programación de estructuras de datos y algoritmos fundamentales (Gpo 602))
Este proyecto es una dulcería. Cada dulce tendrá un constructor por defecto con los siguientes atributos: Nombre del producto, Origen y Calorías. El cliente podrá ver todos los productos disponibles en la dulcería y organizar los productos en el orden de menor a mayor cantidad de calorías. El vendedor podrá agregar nuevos dulces y consultar la lista de productos.

## SICT0301: Evalúa los componentes
### Análisis de coplejidad correcto y completo para los algoritmos de ordeamiento usandos en el programa
- Ordenamiento por caloría -> ordenamiento de burbuja: complejidad temporal peor caso O(n^2) y complejidad espacial peor caso O(1)
- Ordenamiento por origen -> ordenamiento de burbuja: complejidad temporal peor caso O(n^2) y complejidad espacial peor caso O(1)

### Análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa
- Array de los dulces (can)-> array: complejidad temporal pero caso para acceso O(1) y peor caso para inserción O(n) y complejidad espacial peor caso O(n)

### Análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa
- Acceso a datos: muestra_dulce O(n) va leer los elementos dentro del arreglo
- Inserción en datos: agrega_dulce, crea_dulce O(n) va agregar dulces en el arreglo
- Ordenamiento de burbuja: sort_calorie, sort origin O(n^2) va ir corriendo las veces necesarias para que todos los elementos esten en su lugar correspondiente.
## SICT0302: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema
El algoritmo de ordenamiento utilizado en este programa es el ordenamiento por burbuja, que se emplea para ordenar los orígenes de los dulces en orden alfabético ascendente y las calorías de los dulces en orden numérico ascendente. El ordenamiento por burbuja tiene una complejidad temporal en el peor caso de O(n^2) y una complejidad espacial en el peor caso de O(1). La razón por la que escogí este algoritmo es que el número de elementos es pequeño(cantidad fija de la caloría y origen) y también ordena los elementos dentro del arreglo original, sin requerir espacio adicional en la memoria.

### Selecciona una estructura de datos adecuada al problema
La estructura de datos que consideré más adecuada para el problema es la lista doblemente encadenada (Doubly-Linked List). El problema implica la inserción (insertar dulces) y eliminación de objetos (eliminar dulces), y la lista doblemente encadenada tiene un caso peor de O(1) para la inserción y eliminación, y O(n) para el acceso. Entonces, comparado a otras estructuras, es la más eficiente y rápida.

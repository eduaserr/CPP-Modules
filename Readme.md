instanciable = publico
no instancaible = privado 

member function = funcion miembro, miembro de una clase

std::list: (lista doblemente enlazada)

std::map: (matriz, clave/valor) cuando necesitas buscar datos asociados a una clave y mantenerlos ordenados (fechas → precios).

std::stack: (pila de datos) cuando solo trabajas con el último elemento insertado (LIFO), como en una calculadora RPN.

std::vector: (array dinámico) cuando quieres acceso rápido por índice y recorrer muchos datos eficientemente.

std::deque: cuando necesitas un comportamiento parecido al de un vector, pero con inserciones eficientes también al principio.

ex00 lógica principal (uso de std::map, búsqueda con lower_bound(), validación de fechas y valores, y continuación tras errores)
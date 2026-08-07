instanciable = publico
no instancaible = privado 

member function = funcion miembro, miembro de una clase

std::list: (lista doblemente enlazada)

std::map: (matriz, clave/valor) cuando necesitas buscar datos asociados a una clave y mantenerlos ordenados (fechas → precios).

std::stack: (pila de datos) cuando solo trabajas con el último elemento insertado (LIFO), como en una calculadora RPN.

std::vector: (array dinámico) cuando quieres acceso rápido por índice y recorrer muchos datos eficientemente.

std::deque: cuando necesitas un comportamiento parecido al de un vector, pero con inserciones eficientes también al principio.

ex00 lógica principal (uso de std::map, búsqueda con lower_bound(), validación de fechas y valores, y continuación tras errores)

ex02 

1 - formar parejas
2 - ordenar cada pareja . Ej.: (av[a], av[a + 1]; av[a + 2], av[a + 3]);
3 - separar mayores y menores 
4 - ordenar recursivamente los mayores
5 - insertar los menores (Main Chain)
5.1 - Insertar Straggler

Merge-Insertion Sort:

Step 1: Divide the keys into ⌈n / 2⌉ pairs, leaving one key out if n is odd. Call the larger key of the i‑th pair aᵢ and the smaller bᵢ.

Step 2: Sort the ⌈n / 2⌉ aᵢ’s recursively with the Ford–Johnson algorithm. Keep the pair correspondence — if aᵢ is renamed aⱼ, re‑index bᵢ as bⱼ.

Step 3: We now have a known partial order captured essentially by the inequalities.
# minado_agil
Añade una secuencia de 8 caracteres en hexadecimal y el nombre opcional del minero o grupo de mineros al final del fichero input.txt. El resultado es guardado en minado.txt
- Descarga: Clonar la rapo o descargar como .zip
- Resumen MD5 **md5.cpp** 7a9ef3a8f7404e5280506e7ceedf809c 
- Resumen MD5 **md5.h**: 1f07a5b45df297e702aba01c1a43c7b0
- Resumen MD5 **minado.cpp**: 6717073c7ca286255c6631b7d6e0a092
- Resumen MD5 **minado_par.cpp**: 0ef8c5272847c65e0d46f340bbad0aaa

## Version en serie
- Compilación: ```$g++ minado.cpp md5.cpp -o minado```
- Ejecución: ```$./minado <input.txt> <numero_ceros> <opcional_nombre_grupo>```

## Version en paralelo - multithreading
- Compilación: ```g++ minado_par.cpp md5.cpp -o minado_par -fopenmp```
- Ejecución: ```$./minado_par <input.txt> <numero_ceros> <opcional_nombre_grupo>```

## Author

* **Aitor Belenguer** 

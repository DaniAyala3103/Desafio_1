#ifndef MEMORIA_H
#define MEMORIA_H

int calcularbytes(int filas, int columnas);
unsigned char* reservarMemoria(int filas, int columnas);
unsigned char* agregarFila(unsigned char* memoria, int filas,int columnas, int filaInsertar, int *capacidadBytes);
unsigned char *eliminarFila(unsigned char* memoria, int filas,int columnas, int filaEliminar, int *capacidadBytes);
unsigned char* agregarColumna(unsigned char* memoria, int filas,int columnas, int columnaInsertar, int *capacidadBytes);
unsigned char* eliminarColumna(unsigned char* memoria, int filas,int columnas, int columnaEliminar, int *capacidadBytes);


#endif // MEMORIA_H

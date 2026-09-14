#ifndef COMBINACIONES_H
#define COMBINACIONES_H

bool *crearMarcas(int filas, int columnas);
void liberarMarcas(bool *marcas);
void marcasHorizontales(unsigned char* memoria, int filas, int columnas, bool *marcas);
void marcasVerticales(unsigned char* memoria, int filas, int columnas, bool* marcas);
bool hayCombinaciones(bool* marcas, int filas, int columnas);

#endif // COMBINACIONES_H

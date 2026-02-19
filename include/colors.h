#ifndef COLORS_H
#define COLORS_H


/**
 * @file colors.h
 * @brief Definición de códigos ANSI para colores en la terminal.
 * 
 * Este archivo contiene macros que representan secuencias de escape ANSI
 * utilizadas para imprimir texto con diferentes colores y estilos en la
 * terminal. Se emplea para mejorar la legibilidad de los mensajes de la
 * shell, resaltando errores, advertencias y estados del sistema.
 * 
 * @note Funciona únicamente en terminales que soporten códigos ANSI
 * (Linux, macOS y la mayoría de terminales modernas).
 */

#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define RESET   "\033[0m"

#endif

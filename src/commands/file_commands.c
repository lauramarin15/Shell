/**
 * @file file_commands.c
 * @brief Comandos para manipulación y visualización de archivos.
 * 
 * Implementa funcionalidades similares a 'ls' (listar) y 'cat' (leer) de Unix,
 * interactuando con las APIs del sistema de archivos.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // Librería POSIX para manejo de directorios
#include "commands.h"
#include "colors.h"

/**
 * @brief Comando LISTAR (ls)
 * 
 * Abre el directorio actual (".") e itera sobre sus entradas para mostrar los nombres.
 * 
 * @param args Argumentos del comando (ignorados en esta versión simple).
 */
void cmd_listar(char **args) {
    DIR *d;               // Puntero al flujo del directorio
    struct dirent *dir;   // Estructura que representa una entrada (archivo/carpeta)

    // opendir(): Abre un flujo de directorio correspondiente al directorio dado.
    d = opendir(".");
    
    if (d) {
        printf("Archivos en el directorio actual:\n");
        // readdir(): Lee la siguiente entrada del directorio. Retorna NULL al final.
        while ((dir = readdir(d)) != NULL) {
            // Filtramos las entradas especiales "." (actual) y ".." (padre) para limpiar la salida
            if (strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") != 0) {
                printf("  %s\n", dir->d_name);
            }
        }
        // closedir(): Cierra el flujo y libera recursos asociados.
        closedir(d);
    } else {
        // perror(): Imprime un mensaje de error descriptivo basado en el valor global 'errno'
        perror(RED"Error al abrir directorio"RESET);
    }
    (void)args;
}

/**
 * @brief Comando LEER (cat)
 * 
 * Abre un archivo en modo lectura, lee su contenido caracter por caracter
 * y lo imprime en la terminal.
 * 
 * @param args args[1] debe contener la ruta o nombre del archivo a leer.
 */
void cmd_leer(char **args) {
    // Validación básica: ¿El usuario pasó el nombre del archivo?
    if (args[1] == NULL) {
        printf(RED"Error: Debes especificar un archivo para leer.\n"RESET BLUE"Uso: leer <nombre_archivo>\n"RESET);
        return;
    }

    // fopen(): Abre el archivo especificado en modo lectura ("r").
    // Retorna un puntero a FILE o NULL si falla (ej. archivo no existe).
    FILE *fp = fopen(args[1], "r");
    if (fp == NULL) {
        printf(RED"Error: No se pudo abrir el archivo '%s'. Verifique que exista.\n"RESET, args[1]);
        return;
    }

    char ch;
    // fgetc(): Lee el siguiente caracter del flujo.
    // El bucle continúa hasta encontrar EOF (End Of File).
    while ((ch = fgetc(fp)) != EOF) {
        // putchar(): Escribe un caracter en la salida estándar (consola).
        putchar(ch);
    }
    printf("\n"); // Salto de línea estético al final

    // fclose(): Es crítico cerrar los archivos para evitar fugas de recursos.
    fclose(fp);
}

void cmd_crear(char **args) {
    // Validación básica: ¿El usuario pasó el nombre del archivo a crear?
    if (args[1] == NULL) {
        printf(RED"Error: Debes especificar un nombre para el nuevo archivo.\n"RESET BLUE"Uso: crear <nombre_archivo>\n"RESET);
        return;
    }

    // fopen() con modo "w" crea un nuevo archivo o sobrescribe uno existente.
    FILE *fp = fopen(args[1], "w");
    if (fp == NULL) {
        printf(RED"Error: No se pudo crear el archivo '%s'. Verifique permisos y espacio en disco.\n"RESET, args[1]);
        return;
    }

    printf("Archivo '%s' creado exitosamente.\n", args[1]);
    fclose(fp); // Cerrar el archivo después de crearlo
}
void cmd_eliminar(char **args) {
    // Validación básica: ¿El usuario pasó el nombre del archivo a eliminar?
    if (args[1] == NULL) {
        printf(RED"Error: Debes especificar un archivo para eliminar.\n"RESET BLUE"Uso: eliminar <nombre_archivo>\n"RESET);
        return;
    }

    // remove(): Elimina el archivo especificado. Retorna 0 si tiene éxito, -1 si falla.
    if (remove(args[1]) == 0) {
        printf("Archivo '%s' eliminado exitosamente.\n", args[1]);
    } else {
        printf(RED"Error: No se pudo eliminar el archivo '%s'. Verifique que exista y tenga permisos.\n"RESET, args[1]);
    }
}

void cmd_renombrar(char **args) {
    // Validación básica: ¿El usuario pasó el nombre actual y el nuevo nombre?
    if (args[1] == NULL || args[2] == NULL) {
        printf(RED"Error: Debes especificar el nombre actual y el nuevo nombre del archivo.\n"RESET BLUE"Uso: renombrar <nombre_actual> <nuevo_nombre>\n"RESET);
        return;
    }

    // rename(): Cambia el nombre de un archivo. Retorna 0 si tiene éxito, -1 si falla.
    if (rename(args[1], args[2]) == 0) {
        printf("Archivo '%s' renombrado a '%s' exitosamente.\n", args[1], args[2]);
    } else {
        printf(RED"Error: No se pudo renombrar el archivo '%s'. Verifique que exista y tenga permisos.\n"RESET, args[1]);
    }
}
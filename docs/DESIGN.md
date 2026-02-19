# 🧩 Diseño del Sistema

**Objetivo**: Documentar las decisiones arquitectónicas, diagramas de flujo y estructuras de datos clave utilizadas en el desarrollo del kernel y la shell.

## Contenido (Planeado)
1. **Ciclo de Vida de la Shell**: Diagrama del bucle REPL.
- Mostrar prompt
- Leer entrada del usuario
- Parsear la línea en tokens
- Identificar comando
- Ejecutar comando
- Liberar memoria temporal
- Repetir ciclo

2. **Gestión de Memoria**: 
Cada iteración del REPL crea memoria dinámica únicamente para:

-Línea ingresada
-Arreglo de tokens
-Argumentos del comando
-Al finalizar la ejecución del comando:
-free(line)
-free(tokens)
-free(args)


Esto garantiza:
-No acumulación de memoria
-Comportamiento estable a largo plazo
-Simulación del comportamiento de shells reales
-No se utilizan buffers globales dinámicos persistentes.

3. **Modularidad**: Explicación de la división `core` vs `commands`.


***Core (núcleo de control)***
    Responsabilidades:
    Control del REPL
    Parser
    Dispatcher
    Manejo de errores
    Flujo principal del programa


***Commands (módulos funcionales)***
    Cada comando es un módulo independiente:
    src/commands/
        listar.c
        leer.c
        crear.c
        borrar.c
    Cada archivo implementa una única función:
    void cmd_nombre(char **args);
    Los comandos se registran en una tabla:
    Comando comandos[];
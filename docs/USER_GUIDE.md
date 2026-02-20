# 📖 Guía de Usuario

**Objetivo**: Explicar cómo instalar, configurar y utilizar **EAFITos** desde la perspectiva de un usuario final, sin entrar en detalles técnicos del código.

Esta guía explica cómo instalar, ejecutar y utilizar el sistema sin necesidad de conocimientos de programación.

---

### 1. Instalación: Cómo compilar con `make`.
**Requisitos**

Debes tener instalado:

* gcc (compilador de C)
* make

### macOS

```bash
brew install gcc make
```
---

### Compilar el sistema

Desde la carpeta del proyeto

```bash
make
```

Si funciona se genera:

```
build/sistema_os
```

---

### 2. rimeros Pasos: Ejecución básica.

EN shell:

```bash
./build/sistema_os
o
make run

```
Si funciona verá

```
EAFITos >
```

Ahora puedes escribir comandos.

---

### 3. Manual de Comandos: Explicación detallada de cada comando disponible (`calc`, `listar`, etc.) con ejemplos de uso.

Todos los comandos siguen la forma:

```
comando [argumentos]
```

---

### listar

Muestra los archivos del directorio actual.

```bash
listar
```

---

### leer

Muestra el contenido de un archivo.

```bash
leer archivo.txt
```

---

### calc

Realiza operaciones matemáticas básicas.

```bash
calc 5 + 3
calc 8 * 7
calc 20 / 4
```

---

### tiempo

Muestra la hora actual del sistema.

```bash
tiempo
```

---

### crear

Crea un archivo vacío.

```bash
crear notas.txt
```

---

### eliminar

Elimina un archivo.

```bash
eliminar notas.txt
```

---

### renombrar

Cambia el nombre de un archivo.

```bash
renombrar viejo.txt nuevo.txt
```

---

### ayuda

Muestra la lista de comandos disponibles.

```bash
ayuda
```

---

### salir

Cierra la shell.

```bash
salir
```
---

## 💡 Consejos de Uso

* Los nombres distinguen mayúsculas y minúsculas
* Evita espacios en nombres de archivo
* Usa `ayuda` cuando tengas dudas
* Los errores no cierran la shell

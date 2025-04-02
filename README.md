# Minitalk

Minitalk es un programa que permite la comunicación entre procesos en sistemas Unix utilizando señales. Consiste en dos componentes principales: un **servidor** y un **cliente**. El cliente descompone el mensaje en bianrio y lo envía al servidor, el cual los recibe lo reconstruye y lo muestra.

## Tabla de Contenidos

- [Instalación](#instalación)
- [Uso](#uso)
- [Ejemplo de Ejecución](#ejemplo-de-ejecución)
- [Autores](#autores)
- [Licencia](#licencia)

## Instalación

Para instalar y compilar Minitalk, sigue estos pasos:

1. **Clona el repositorio:**

   ```bash
   git clone https://github.com/theposi/minitalk.git
   ```

2. **Navega al directorio del proyecto:**

   ```bash
   cd minitalk
   ```

3. **Compila el proyecto:**

   ```bash
   make
   ```

   Esto generará los ejecutables `server` y `client`.

## Uso

1. **Inicia el servidor:**

   Ejecuta el siguiente comando para iniciar el servidor:

   ```bash
   ./server
   ```

   El servidor mostrará su PID en la terminal. Necesitarás este PID para que el cliente pueda enviarle mensajes.

2. **Envía un mensaje desde el cliente:**

   En una nueva terminal, utiliza el cliente para enviar un mensaje al servidor. Reemplaza `<PID_DEL_SERVIDOR>` con el PID mostrado por el servidor y `"Tu mensaje aquí"` con el mensaje que deseas enviar:

   ```bash
   ./client <PID_DEL_SERVIDOR> "Tu mensaje aquí"
   ```

## Ejemplo de Ejecución

**1. Iniciar el servidor:**

```bash
$ ./server
Servidor iniciado. PID: 12345
```

**2. Enviar un mensaje desde el cliente:**

```bash
$ ./client 12345 "Hola, Minitalk!"
```

**3. Salida esperada en el servidor:**

```bash
Mensaje recibido: Hola, Minitalk!
```

## Autores

- [@theposi](https://www.linkedin.com/in/cristian-zapata-arias-6733a6220/).

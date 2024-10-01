# Born2beRoot - Guía de Configuración

![Born2beRoot](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/cabezeraBorn.png)

Este proyecto te guiará en la configuración de un servidor utilizando **VirtualBox** con **Rocky Linux** o **Debian**, siguiendo reglas estrictas de seguridad y buenas prácticas de administración de sistemas. A lo largo del proceso, aprenderás a configurar particiones cifradas, gestionar usuarios, activar y configurar servicios clave como **SSH** y **SELinux**, y crear scripts para monitorear tu sistema.

## Tabla de Contenidos

1. [Requisitos Previos](#requisitos-previos)
2. [Configuración del Entorno](#configuración-del-entorno)
3. [Particionado y Cifrado de Disco](#particionado-y-cifrado-de-disco)
4. [Instalación del Sistema](#instalación-del-sistema)
5. [Configuración de SELinux y Firewall](#configuración-de-selinux-y-firewall)
6. [Gestión de Usuarios y Políticas de Contraseña](#gestión-de-usuarios-y-políticas-de-contraseña)
7. [Configuración de SSH](#configuración-de-ssh)
8. [Creación del Script `monitoring.sh`](#creación-del-script-monitoringsh)
9. [Verificación y Evaluación Final](#verificación-y-evaluación-final)

---

## Requisitos Previos

Antes de comenzar, asegúrate de tener lo siguiente:

- **VirtualBox** instalado en tu máquina local.
- ISO de **Rocky Linux 9.4** o **Debian**.
- Conocimiento básico de administración de servidores y comandos de terminal.

![BRocky](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/rocky_minimal.png)

## Configuración del Entorno

### Paso 1: Crear una Máquina Virtual en VirtualBox

1. **Crear una nueva VM en VirtualBox** con los siguientes ajustes:
    - **Nombre**: `Born2beRoot_VM`
    - **Tipo**: Linux
    - **Versión**: Red Hat (64-bit) o Debian (64-bit)
    - **RAM**: Al menos 2 GB
    - **Disco duro virtual**: 20 GB (preferiblemente en formato VDI)

2. **Configurar la red** como NAT para acceso a internet, y habilitar la red host-only para gestionar conexiones SSH.

![Configuración de la red](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/virtualB2b.png)

## Particionado y Cifrado de Disco

### Paso 2: Particionado Manual

Durante la instalación del sistema operativo, selecciona la opción de **Particionado Manual** y realiza las siguientes configuraciones:

1. **/boot**: Partición primaria no cifrada, tamaño 512 MB, formato `ext4`.
2. **Volumen LVM cifrado**:
    - Crear un grupo de volúmenes LVM.
### Estructura de particiones:
  ```plaintext
NAME          MAJ:MIN RM  SIZE RO TYPE MOUNTPOINT
sda             8:0    0   20G  0 disk
├─sda1          8:1    0  512M  0 part /boot (minino rocky)
├─sda2          8:2    0    1k  0 part 
└─sda5          8:3   0 19.5G  0 part
  └─lvm_crypt  254:0    0 19.5G  0 crypt
    ├─root     254:1    0   2.8G 0 lvm  /
    ├─swap     254:2    0    976 0 lvm  [SWAP]
    └─home     254:3    0   3.8G 0 lvm  /home
  ```
![particiones](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/particiones2.png)
## Instalación del Sistema

### Paso 3: Instalar Rocky 

1. Selecciona la instalación mínima (sin interfaz gráfica) para optimizar el uso del servidor.
2. Sigue las instrucciones para completar la instalación, asegurándote de que el disco cifrado se monte correctamente al inicio.

## Configuración de SELinux y Firewall

### Paso 4: Configuración de SELinux

1. **Activar SELinux** y establecerlo en modo **enforcing**:
    ```bash
    sudo setenforce 1
    sudo sed -i 's/SELINUX=permissive/SELINUX=enforcing/' /etc/selinux/config
    ```

2. Verifica el estado:
    ```bash
    sestatus
    ```

![Estado de SELinux](https://user-images.githubusercontent.com/XXX/selinux_status.png)
![Estado de SELinux](https://user-images.githubusercontent.com/XXX/setstatus2.png)


### Paso 5: Configuración de Firewall

1. Habilitar **firewalld** y abrir el puerto 4242 para SSH:
    ```bash
    sudo firewall-cmd --permanent --add-port=4242/tcp
    sudo firewall-cmd --reload
    sudo systemctl enable firewalld
    sudo systemctl start firewalld
    ```

## Gestión de Usuarios y Políticas de Contraseña

### Paso 6: Crear Usuarios y Configurar Políticas

1. **Crear un usuario con tu login** (por ejemplo, `ybeltran42`) y asignarlo a los grupos `user42` y `sudo`:
    ```bash
    sudo useradd -m -G sudo,user42 ybeltran42
    sudo passwd ybeltran42
    ```

2. **Configurar políticas de contraseña**:
    - Contraseña de mínimo 10 caracteres.
    - Expiración cada 30 días.
    - Aviso de 7 días antes de expirar.

    Edita el archivo `/etc/login.defs`:
    ```bash
    PASS_MAX_DAYS 30
    PASS_MIN_DAYS 2
    PASS_WARN_AGE 7
    ```

## Configuración de SSH

### Paso 7: Configurar SSH en Puerto 4242

1. Modifica la configuración de **SSH** para ejecutar en el puerto 4242:
    ```bash
    sudo sed -i 's/#Port 22/Port 4242/' /etc/ssh/sshd_config
    sudo systemctl restart sshd
    ```

2. **Deshabilitar login root** vía SSH:
    ```bash
    sudo sed -i 's/PermitRootLogin yes/PermitRootLogin no/' /etc/ssh/sshd_config
    sudo systemctl restart sshd
    ```

## Creación del Script `monitoring.sh`

### Paso 8: Crear el Script de Monitoreo

Crea un script llamado `monitoring.sh` que muestre información importante del sistema cada 10 minutos usando `cron`. El script debe mostrar:

- Arquitectura y versión del kernel
- Número de CPUs físicas y virtuales
- Uso de memoria RAM y núcleos
- Número de conexiones activas y usuarios
- Estado de LVM y uso de `sudo`

```bash
#!/bin/bash
echo "#Architecture: $(uname -a)"
echo "#CPU physical: $(nproc --all)"
echo "#Memory Usage: $(free -m | grep Mem | awk '{print $3}')MB"
# Más líneas de monitoreo...
```

## Verificación y Evaluación Final
### Paso 9: Verificación y Documentación
1. Verifica que SELinux esté activo, el firewall esté configurado correctamente, y el servicio SSH esté corriendo en el puerto 4242.
2. Prueba el acceso SSH desde otra máquina para asegurarte de que todo esté funcionando.
3. Crea el archivo signature.txt en la raíz del proyecto, incluyendo la firma del disco virtual (VMDK o VDI).

```bash
md5sum /path/to/disk.vdi > signature.txt
```
4. Entrega el proyecto incluyendo el archivo signature.txt en el repositorio según las instrucciones proporcionadas.

### Autor
**Nombre:** Ybeltran
**Proyecto:** Born2beRoot
**Contacto:** gianmarcobeltran@gmail.com
**Institución:** 42 Network
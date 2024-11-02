# Born2beRoot - Guía de Configuración

![Born2beRoot](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/cabezeraBorn.png)

Este proyecto te guiará en la configuración de un servidor utilizando **VirtualBox** con **Debian**, siguiendo reglas estrictas de seguridad y buenas prácticas de administración de sistemas. A lo largo del proceso, aprenderás a configurar particiones cifradas, gestionar usuarios, activar y configurar servicios clave como **SSH** y **SELinux**, y crear scripts para monitorear tu sistema.

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
- <a href="https://www.debian.org/distrib/index.es.html">ISO de **Debian**</a>.
- Conocimiento básico de administración de servidores y comandos de terminal.

![BRocky](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/debian.png)

## Configuración del Entorno

### Paso 1: Crear una Máquina Virtual en VirtualBox

1. **Crear una nueva VM en VirtualBox** con los siguientes ajustes:
    - **Nombre**: `Born2beRoot_VM`
    - **Tipo**: Linux
    - **Versión**: Red Hat (64-bit) o Debian (64-bit)
    - **RAM**: Al menos 2 GB
    - **Disco duro virtual**: 20 GB (preferiblemente en formato VDI)






# Born2beRoot - Guía de Configuración y Seguridad

![Born2beRoot](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/cabezeraBorn.png)

Este proyecto proporciona una guía paso a paso para configurar y asegurar un servidor Linux en un entorno virtualizado, cumpliendo con los estándares de seguridad exigidos en el programa 42. Se utilizará **VirtualBox** con **Rocky Linux 9.4** o **Debian**, y se aplicarán prácticas recomendadas de administración de sistemas, como el particionado cifrado, gestión de usuarios, configuración de SSH y SELinux, y monitoreo del sistema.

## Tabla de Contenidos

1. [Requisitos Previos](#requisitos-previos)
2. [Configuración del Entorno](#configuración-del-entorno)
3. [Particionado y Cifrado de Disco](#particionado-y-cifrado-de-disco)
4. [Instalación del Sistema](#instalación-del-sistema)
5. [Configuración de SELinux y Firewall](#configuración-de-selinux-y-firewall)
6. [Gestión de Usuarios y Políticas de Contraseña](#gestión-de-usuarios-y-políticas-de-contraseña)
7. [Configuración de SSH en el Puerto 4242](#configuración-de-ssh-en-el-puerto-4242)
8. [Creación del Script de Monitoreo (`monitoring.sh`)](#creación-del-script-de-monitoreo-monitoringsh)
9. [Automatización del Monitoreo con Crontab](#automatización-del-monitoreo-con-crontab)
10. [Generación del Archivo `signature.txt`](#generación-del-archivo-signaturetxt)
12. [Autor](#autor)

---

## 1. Requisitos Previos

Antes de comenzar, asegúrate de cumplir con los siguientes requisitos:

- **VirtualBox** instalado en tu máquina local.
- ISO de **Rocky Linux 9.4** o **Debian**.
- Conocimiento básico en administración de servidores y comandos de terminal.

> **Nota:** Para usuarios de Mac M1, se recomienda usar UTM como alternativa a VirtualBox, ya que UTM es compatible con la arquitectura ARM.

![Rocky Linux](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/rocky_minimal.png)

---

## 2. Configuración del Entorno

### Paso 1: Crear una Máquina Virtual en VirtualBox

1. Abre **VirtualBox** y crea una nueva VM con los siguientes ajustes:
   - **Nombre**: `Born2beRoot_VM`
   - **Tipo**: Linux
   - **Versión**: Red Hat (64-bit) o Debian (64-bit)
   - **RAM**: Al menos 2 GB
   - **Disco duro virtual**: 20 GB (preferiblemente en formato VDI)

2. Configura la red:
   - **NAT** para el acceso a internet.
   - **Red host-only** para gestionar conexiones SSH desde la máquina host.

![Configuración de red](https://github.com/ciberzerone/Campus42_Barcelona_Cursus/blob/main/born2beroot/img/virtualB2b.png)

---

## 3. Particionado y Cifrado de Disco

### Paso 2: Particionado Manual

Durante la instalación del sistema operativo, selecciona la opción de **Particionado Manual** y configura las siguientes particiones:

1. **/boot**: Partición primaria no cifrada de 512 MB, formato `ext4`.
2. **Volumen LVM cifrado**:
   - Crea un grupo de volúmenes LVM para alojar las particiones cifradas de `/`, `/home` y `swap`.

### Estructura de particiones recomendada:
```plaintext
NAME          MAJ:MIN RM  SIZE RO TYPE MOUNTPOINT
sda             8:0    0   20G  0 disk
├─sda1          8:1    0  512M  0 part /boot
└─sda5          8:3    0  19.5G 0 part
  └─lvm_crypt  254:0   0  19.5G 0 crypt
    ├─root     254:1   0   2.8G 0 lvm /
    ├─swap     254:2   0   976M 0 lvm [SWAP]
    └─home     254:3   0   3.8G 0 lvm /home
```
---

## 4. Instalación del Sistema

### Paso 3: Instalar el Sistema Operativo

1. Selecciona la instalación mínima (sin interfaz gráfica) para optimizar el rendimiento del servidor.
2. Completa la instalación asegurándote de que el disco cifrado se monte correctamente al inicio.

> **Consejo:** Utiliza Debian si tienes experiencia previa con esta distribución o si es un requisito de tu campus.

---

## 5. Configuración de SELinux y Firewall

### Paso 4: Configuración de SELinux

1. Activa SELinux y establece el modo **enforcing**:
   ```bash
   sudo setenforce 1
   sudo sed -i 's/SELINUX=permissive/SELINUX=enforcing/' /etc/selinux/config
   ```
2. Verifica el estado:
   ```bash
    sestatus
   ```
Paso 5: Configuración de Firewall

1. Habilita firewalld y abre el puerto 4242 para SSH:
```bash
sudo firewall-cmd --permanent --add-port=4242/tcp
sudo firewall-cmd --reload
sudo systemctl enable firewalld
sudo systemctl start firewalld
  ```


### Autor
**Nombre:** Ybeltran
**Proyecto:** Born2beRoot
**Contacto:** gianmarcobeltran@gmail.com
**Institución:** 42 Network

# Write-up

Este laboratorio/mini-CTF consiste en 5 retos/5 pistas, las cuales llevarán a encontrar el nombre de un personaje.

## Pista 1: Esteganografía
La primera parte es este correo que tiene una imagen en un archivo comprimido.

![](/docs/01.png)
![](/docs/02.png)

Una vez que se descomprime el archivo, ya se puede abrir la imagen, se abre con GIMP, que es un editor de imágenes para poder editar o ajustar los parámetros de la imagen como la saturación, la exposición, luces y sombras, brillo y contraste, etc.

![](/docs/03.png)

En la pestaña de colores, al bajar el brillo a -99 y subirle el contraste a 120 aproximadamente, se puede observar un mensaje oculto que corresponde a un dominio.

![](/docs/04.png)

## Pista 2: Consulta DNS
Se hace la consulta del registro TXT del dominio con el comando `dig`, y aquí se encuentra el siguiente reto/la siguiente parte del reto.

![](/docs/05.png)

También se puede realizar con ayuda de las utilidad [PowerTool de PowerDMARC](https://powerdmarc.com/es/power-dmarc-toolbox/), indicando el tipo de búsqueda y el dominio.

![](/docs/06.png)

## Pista 3: Codificación base64
La página que nos muestra es la siguiente:

![](/docs/07.png)

Al inspeccionar el elemento, se observa una metadato que parece estar codificado en base64, lo probamos con el comando `base64`.

![](/docs/08.png)

Para convertir la cadena de base64 a texto plano se utiliza `echo “Q3VhcnRhIHBpc3RhOiBodHRwczovL2RyaXZlLmdvb2dsZS5jb20vZmlsZS9kLzFrSGY0LWZkS0VVVkhxaTdEMnJraEJRN1Qwd0thRS1heC92aWV3P3VzcD1zaGFyaW5n” | base64 -d`, donde el parámetro `-d` es para decodificar. De no ponerlo, estaremos codificando (de nuevo).

![](/docs/09.png)

Si no tenemos acceso a una terminal, también se puede hacer con la página de CyberChef. A partir de esto se obtiene la cuarta pista, que es un enlace a un ejecutable Linux.

## Pista 4: Buffer overflow
Se cambian los permisos del ejecutable con `chmod +x pista4.out`.

![](/docs/10.png)

## Pista 5: Imagen de disco
Al ejecutar el programa pide ingresar 3 parámetros, donde el número mayor que cabe en un byte (sin signo) son 255 caracteres, por lo tanto, ocurre un desbordamiento. A partir de esto, se obtiene el último archivo, donde se encuentra la respuesta final.

![](/docs/11.png)

Como ya sabemos, la imagen de disco contiene una copia de la partición de un disco físico (información en bytes), y para buscar una palabra dentro de la imagen de disco se utiliza el comando `grep -a clave <imagen>`, donde el parámetro `-a` le indica a grep que también procese archivos binarios. Finalmente obtenemos el nombre del personaje.

![](/docs/12.png)

También tomando como pista la página web, se pueden buscar los nombres de los personajes de la serie de Candy Candy.

![](/docs/13.png)

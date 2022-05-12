# VidaSana

El siguiente programa fue creado con el fin de brindar orientación en el tema de las dietas 
de una persona y los diferentes costos que presenta un producto para encontrar la mejor relación
ganancia-precio, para alcanzar la meta del usurario.

## Proceso de instalación

Primeramente se debe tener en cuenta que el programa fue realizado en el lenguaje de programación C++,
además este programa fue diseñado en el editor Visual Studio Code. Se recomienda utilizar este editor 
por la comodidad que ofrece y las distintas extensiones que tiene de por medio, además de la facilidad
que otorga manejar distintos lenguajes de programación en un mismo editor. No obstante, el usuario puede
manejar el editor de su preferencia.

### Requisitos de software

Los requisitos esenciales para poder ejecutar el programa son los siguientes:

#### 1.- Tener instalado un compilador para C++ (DEV C++) 
Si no tiene instalado el compilador puede observar el sigueinte video para su 
correcta instalación: https://www.youtube.com/watch?v=0B_Ly0A3RV0

#### 2.- Tener un editor funcional que acepte C++
En este caso Visual Studio Code, si no tiene instaladoun editor puede observar el 
siguiente video para su correcta instalación: https://www.youtube.com/watch?v=X_Z7d04x9-E

#### 3.- Instalar extensiones
Una vez instalado VS Code debe instalar las sigueintes extensiones: C/C++, C/C++ Extension Pack, Code Runner.
Estas extensiones se pueden instalar dese el menu de acciones del lado izquierdo del editor VS Code.

![imagen](https://user-images.githubusercontent.com/90929324/167324671-19222b16-e4c6-44a7-99a0-9e8ffef3c957.png)

Continuando con el proceso de instalación debemos realizar las siquientes acciones:

#### 1.- Crear Carpeta
Se debe crear una carpeta en donde se almacenaran los archivos del programa asignandole el nombre que desee.


![imagen](https://user-images.githubusercontent.com/90929324/167324711-262b7616-05a9-4383-8dcf-d4c44d313be8.png)


#### 2.- Importar Archivos
Se debe descargar el archivo ZIP del repositorio de GitHub, seguidamente en el explorador de archivos buscamos el directorio 
de nuestra carpeta ya creada y dentro de esta descomprimimos el archivo ZIP. Terminados una vez estos pasos nos aparecerán 
los archivos del programa en el editor (VS Code).


![imagen](https://user-images.githubusercontent.com/90929324/167324597-9da71de3-f413-42c5-ba30-7cc98a5113ff.png)


Una vez terminados todos estos pasos tendremos listo el programa para ejecutarse.
(Todas estas instrucciones fueron evaluadas para un Sistema Operativo de 64 bits,
si usted tiene un Sistema operativo de 32 bits puede revisar los siguientes links: 
https://www.youtube.com/watch?v=RfebFlu2CcM , https://www.youtube.com/watch?v=5grPpOZSr_c, para VS Code y el compilador de C++
respectivamente luego se podrian seguir los pasos de manera análoga).


#### 3.- Ejecutar el programa
Una vez que se tenga todo funcional, se puede proceder a compilar el programa, primero en el archivo in.txt itroducimos 
la entrada que se desee del 1 al 6 (el 7 es para salir del programa).
Luego se va al archivo vida_sana.cpp y ejecutamos el programa en la flecha de compilación al lado superior derecho del editor (VS Code). 


![imagen](https://user-images.githubusercontent.com/90929324/167505358-5001ffde-f964-436d-880b-d96c80fb738d.png)


Finalmente podremos observar el resultado en el output del editor VS Code.


## Definición del Problema
Para el desarrollo del programa se planteó el siguiente problema, un usuario quiere alcanzar una meta fisica implementando una dieta,
teniendo como opción subir masa muscular, bajar de peso o entrar en definición, pero solo se tiene cierta cantidad de dinero para poder 
obtener los resultados deseados. Entonces lo que se busca resolver con el programa es poder hallar la mejor dieta que otorgue proteinas para 
subir masa muscular, baja en calorias para definición y baja en proteinas para bajar de peso, así mismo, encontrar el precio más económico, teniendo 
una relación de ganancia-precio. Tenemos solamente 10 productos que estamos tomando en cuenta para realizar este análisis, los cuales son:
Pollo, huevo, pescado, avena, linasa, quinua, te verde, yogurt griego, palta, y frutos secos. 
Cada uno de estos productos obviamente tiene su respectiva valoración en los parámetros de calorias y proteinas.


## Explicación del Algoritmo


## Conclusión 
Para finalizar este proyecto podemos decir que el precio de nuestra alimentación puede variar demasiado dependiendo 
nuestra meta, con este algoritmo podriamos escoger de acuerdo a nuestras nececidades y posibilidades lo más adecuado 
y accesible para una persona de cualquier estatus social. 
Por lo tanto, se ha llegado a la conclusión que este algoritmo nos ayuda a resolver problemas utilizando Knapsack 
siendo el proceso muy eficiente debido a la facilidad que nos otorga este, y por lo tanto es uno de los algoritmos
más utilizados. Así mismo se uso programación dinamica para tener resultados más precisos y óptimos además de la obtención de 
datos adicionales que nos ayudan a desarrollar mejor la solución al problema. Obteniendo de este modo un resultado exitoso 
con el programa "vida_sana" y resolviendo todo el problema planteado anteriormente. 








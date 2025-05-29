[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19574433&assignment_repo_type=AssignmentRepo)
# Lab04: Comunicación UART en PIC18F45K22

## Integrantes

Sergio Caicedo 

Jhon Franco 

David Sierra

## Documentación

1. Introducción
En el desarrollo de sistemas embebidos es común la necesidad de monitorear y visualizar parámetros eléctricos como el voltaje en tiempo real. Este tipo de aplicaciones es especialmente útil en sistemas de control, automatización y diagnóstico, donde es necesario presentar la información tanto de forma local como remota. El presente proyecto tiene como objetivo implementar un sistema que permita la lectura, visualización y transmisión de un valor de voltaje utilizando un microcontrolador PIC18F45K22.

El sistema cuenta con dos formas de mostrar la información: la primera es mediante una pantalla LCD conectada por protocolo I2C, que permite una visualización local del dato. La segunda, más orientada a la supervisión remota, utiliza comunicación UART para enviar los datos a una computadora, donde un script en lenguaje Python se encarga de procesar y graficar el voltaje recibido en tiempo real. Esta solución demuestra la integración efectiva de hardware y software para lograr un sistema de monitoreo de bajo costo, eficiente y de fácil implementación.

2. Metodología
La implementación del proyecto se llevó a cabo en tres etapas fundamentales: la comunicación I2C con la pantalla LCD, la transmisión de datos por UART al computador y la visualización gráfica de dichos datos mediante un programa en Python.

En primer lugar, se desarrolló una librería en lenguaje C para el manejo del bus I2C del PIC18F45K22. Para ello se configuraron adecuadamente los registros del módulo MSSP en modo maestro, activando los pines RC3 (SCL) y RC4 (SDA) como entradas digitales y desactivando su función analógica. El protocolo I2C fue utilizado para enviar comandos y caracteres a una pantalla LCD 16x2, la cual cuenta con un módulo convertidor I2C incorporado. Se implementaron funciones para iniciar la pantalla, posicionar el cursor y mostrar cadenas de texto.

En la segunda etapa se trabajó con el módulo UART del PIC. Aunque en el fragmento de código presentado no se incluye directamente la configuración UART, se asume su implementación para enviar datos en formato de texto plano al computador, utilizando una línea con el formato “Voltaje: X.XX”. Esta transmisión se realiza desde el microcontrolador hacia el puerto serie de la PC, permitiendo así la captura de datos en tiempo real.

Finalmente, se implemeto todo lo anterior en nuestro proyecto final  para verificar el nivel de voltaje que esta ingresando por el MQ3 

3. Resultados

Una vez integrado el sistema, se realizaron pruebas funcionales para verificar su correcto desempeño. La pantalla LCD mostró exitosamente el mensaje de bienvenida “Hola mundo PIC18F!”, indicando que la comunicación I2C fue configurada y ejecutada correctamente. La comunicación con la PC también se estableció de forma estable, permitiendo recibir los datos de voltaje por el puerto serial sin pérdidas ni errores de transmisión.

El programa en Python fue capaz de interpretar las cadenas recibidas, extraer los valores numéricos correspondientes al voltaje y representarlos gráficamente en una ventana actualizada cada segundo. Esta gráfica mostraba claramente los cambios de voltaje producidos al girar el potenciómetro, confirmando que el sistema respondía dinámicamente a los cambios de entrada analógica.

Durante las pruebas se observó que el sistema era capaz de operar de forma continua durante largos periodos de tiempo, manteniendo la estabilidad en la comunicación y en la visualización. Se obtuvo una buena sincronización entre el microcontrolador y el computador, gracias a una adecuada configuración del baudrate y al manejo correcto del buffer UART.

4. Diagrama de Bloques
<div align="center">
 <img src="/69169b80-c897-4e8f-be83-360c4b46123b-0.jpg" alt="uart" width="550" />
 </div>

4. Evidencia de Implementacion en proyecto 
<div align="center">
 <img src="/implementacion de proyecto.mp4" alt="evidencia aurt proyecto" width="550" />
 </div>

6. Funcionamiento y conclusiones 
La implementación física del sistema requirió la conexión del microcontrolador PIC18F45K22 con una pantalla LCD de 16x2 con módulo I2C, y un conversor USB-TTL para establecer la comunicación UART con la computadora. Se utilizó un potenciómetro para simular una señal de voltaje variable que el microcontrolador podía leer y enviar. El sistema fue alimentado con una fuente de 5V regulada y se utilizaron resistencias de pull-up en las líneas I2C para garantizar una señal limpia y confiable.

Uno de los desafíos más relevantes durante la implementación fue asegurar la compatibilidad de voltajes y sincronización entre el envío de datos desde el microcontrolador y la recepción en la PC. Sin embargo, estos retos fueron superados mediante la configuración adecuada de los registros UART y el uso de retardos temporales estratégicos.

En conclusión, el sistema propuesto cumplió con los objetivos establecidos, permitiendo la lectura, visualización y transmisión de valores de voltaje de forma precisa y eficiente. La modularidad del código y la integración entre hardware y software permiten extender este proyecto a aplicaciones más complejas.


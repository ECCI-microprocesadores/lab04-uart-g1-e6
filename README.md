[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=19574433&assignment_repo_type=AssignmentRepo)
# Lab04: Comunicación UART en PIC18F45K22

## Integrantes

Sergio Caicedo 

Jhon Franco 

David Sierra

## Documentación

1. Introducción

En el desarrollo de sistemas embebidos es común la necesidad de monitorear y visualizar parámetros eléctricos como el voltaje en tiempo real. Este tipo de aplicaciones es especialmente útil en sistemas de control, automatización y diagnóstico, donde es necesario presentar la información tanto de forma local como remota. El presente laboratorio tuvo como objetivo implementar un sistema que permita la lectura, visualización y transmisión de un valor de voltaje utilizando un microcontrolador PIC18F45K22.

El sistema  utiliza comunicación UART para enviar los datos a una computadora, donde un script en lenguaje Python se encarga de procesar y graficar el voltaje recibido en tiempo real. Esta solución demuestra la integración efectiva de hardware y software para lograr un sistema de monitoreo de bajo costo, eficiente y de fácil implementación.

2. Metodología
La implementación del proyecto se llevó a cabo en tres etapas fundamentales: la lectura del voltaje mediante el conversor analógico-digital del microcontrolador, la transmisión de datos por UART al computador y la visualización gráfica de dichos datos mediante un programa en Python, esto ultimo no se logro implemetar,pero se lo logro mediante el programa putty.

Finalmente, se implementó todo lo anterior en nuestro proyecto final de alarma de gas, donde se utilizó el sensor MQ-3 para simular la presencia de gases usando alcohol. Dependiendo del nivel de alcohol detectado, el sistema encendía una alarma y un ventilador. Además, se mostraba en pantalla el nivel de voltaje y la clasificación del nivel de alcohol como bajo, medio, alto o peligro. Esta misma información que se presentaba en la pantalla también era enviada por UART, permitiendo su monitoreo remoto en tiempo real.

3. Resultados

Una vez integrado el sistema, se realizaron pruebas funcionales para verificar su correcto desempeño. La comunicación con la PC se estableció correctamente, permitiendo recibir los datos de voltaje por el puerto serial sin pérdidas ni errores de transmisión.

El programa putty fue capaz de interpretar las cadenas recibidas, extraer los valores numéricos correspondientes al voltaje y representarlos  en una ventana actualizada cada segundo. Estos datos mostraba claramente los cambios de voltaje producidos al girar el potenciómetro y recibir los valores obtenidos por el mq3, confirmando que el sistema respondía dinámicamente a los cambios de entrada analógica.

Durante las pruebas se observó que el sistema era capaz de operar de forma continua durante largos periodos de tiempo, manteniendo la estabilidad en la comunicación y en la visualización. Se obtuvo una buena sincronización entre el microcontrolador y el computador, gracias a una adecuada configuración del baudrate y al manejo correcto del buffer UART.

Este mismo funcionamiento fue validado en el proyecto final de alarma de gas, donde los niveles de voltaje provenientes del sensor MQ-3 se interpretaban como niveles de alcohol en el ambiente. Según el nivel, el sistema mostraba el estado correspondiente (bajo, medio, alto, peligro), activaba dispositivos como alarmas o ventiladores, y transmitía esta misma información por UART para su monitoreo remoto.

4. Diagrama de Bloques
<div align="center">
 <img src="/69169b80-c897-4e8f-be83-360c4b46123b-0.jpg" alt="uart" width="550" />
 </div>

4. Evidencia de Implementacion en proyecto 
<div align="center">
  <video width="550" controls>
    <source src="/implementacion de proyecto.mp4" type="video/mp4">
    Tu navegador no soporta la reproducción de video.
  </video>
</div>

6. Funcionamiento y conclusiones 

Uno de los desafíos más relevantes durante la implementación fue asegurar la compatibilidad de voltajes y sincronización entre el envío de datos desde el microcontrolador y la recepción en la PC. Sin embargo, estos retos fueron superados mediante la configuración adecuada de los registros UART y el uso de retardos temporales estratégicos.

En conclusión, el sistema propuesto cumplió con los objetivos establecidos, permitiendo la lectura, visualización y transmisión de valores de voltaje de forma precisa y eficiente. La modularidad del código y la integración entre hardware y software permiten extender este proyecto a aplicaciones más complejas.


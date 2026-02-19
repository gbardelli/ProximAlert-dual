# ProximAlert Dual

Versión mejorada de ProximAlert. Detector de proximidad con sistema de alerta 
visual dual utilizando Arduino UNO R3 y sensor ultrasónico HC-SR04. LED rojo 
para objetos a menos de 10 cm (peligro) y LED verde para objetos a más de 10 cm 
(seguro). Incluye manejo de lecturas inválidas.
Desarrollado en C++ con Arduino IDE.

## Componentes
- Arduino UNO R3
- Sensor ultrasónico HC-SR04
- LED rojo
- LED verde
- Resistor 220 Ω
- Cables jumper

## Conexiones
| Componente | Arduino |
|------------|---------|
| HC-SR04 VCC | 5V     |
| HC-SR04 GND | GND    |
| HC-SR04 TRIG | Pin 7 |
| HC-SR04 ECHO | Pin 6 |
| LED rojo    | Pin 13 |
| LED verde   | Pin 11 |

## Lógica del sistema
| Distancia      | LED rojo | LED verde |
|----------------|----------|-----------|
| < 10 cm        | ON       | OFF       |
| ≥ 10 cm        | OFF      | ON        |
| Lectura inválida | OFF    | OFF       |

## Uso
1. Cargar el código en Arduino IDE
2. Conectar los componentes según la tabla
3. Abrir el monitor serial a 9600 baudios

## Relación con ProximAlert
Este repositorio es una mejora de [ProximAlert](https://github.com/gbardelli/ProximAlert),
incorporando un segundo LED y manejo de lecturas inválidas.

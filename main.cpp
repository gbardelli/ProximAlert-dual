/*
 * ProximAlert Dual
 * 
 * Autores:
 *   - Giovanni Bardelli Darcourt
 *   - Camila del Pilar Berrocal Falconi
 *   - Maurice Brossard Fernández
 *   - Gabriel Joaquin Moscoso Serin
 *   - Marcela Verde Frech
 * 
 * Universidad de Lima - Facultad de Ingeniería
 * Inteligencia Artificial Aplicada - Sección 318
 * Febrero 2026
 */
const int trigPin = 7;   // Pin de disparo del HC-SR04
const int echoPin = 6;   // Pin de eco del HC-SR04
const int ledRojo = 13;  // LED de alerta (objeto cercano)
const int ledVerde = 11; // LED de seguridad (objeto lejano)

long duracion;   // Tiempo de retorno del pulso en microsegundos
int distancia;   // Distancia calculada en centímetros

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(ledRojo, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    Serial.begin(9600); // Inicialización del monitor serial a 9600 baudios
}

void loop() {
    // Asegurar pulso limpio antes de la medición
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    // Enviar pulso ultrasónico de 10 microsegundos
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Medir tiempo de retorno del eco
    duracion = pulseIn(echoPin, HIGH);

    // Convertir tiempo a distancia: d = (t * velocidad_sonido) / 2
    distancia = duracion * 0.034 / 2;

    // Mostrar distancia en monitor serial
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    if (distancia > 0 && distancia < 10) {
        // Alerta: objeto detectado dentro del umbral de 10 cm
        digitalWrite(ledRojo, HIGH);
        digitalWrite(ledVerde, LOW);
    } else if (distancia >= 10) {
        // Seguro: objeto fuera del umbral
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, HIGH);
    } else {
        // Lectura inválida: distancia igual o menor a cero
        digitalWrite(ledRojo, LOW);
        digitalWrite(ledVerde, LOW);
    }

    delay(200); // Espera 200ms entre mediciones
}

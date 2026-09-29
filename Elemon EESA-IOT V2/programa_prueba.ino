#include "WiFi.h"

void setup() {
    // Inicializamos el monitor serie a 115200 baudios
    Serial.begin(115200);
    delay(1000);
    // Configuramos el módulo en modo Estación (cliente WiFi)

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);

    Serial.println("¡Módulo ESP32 de Elemon listo!");
}
    
void loop() {
    Serial.println("Iniciando escaneo de redes WiFi cercanas...");
    
    // WiFi.scanNetworks retorna el número de redes encontradas
    int n = WiFi.scanNetworks();    
    Serial.println("Escaneo finalizado.");
    
    if (n == 0) {
        Serial.println("No se encontraron redes WiFi abiertas o cercanas.");
    } else {
        Serial.print(n);
        Serial.println(" redes encontradas:");
    
        for (int i = 0; i < n; ++i) {
            // Imprime el nombre (SSID) y la potencia de la señal (RSSI) de
            cada red
            Serial.print(i + 1);
            Serial.print(": ");
            Serial.print(WiFi.SSID(i));
            Serial.print(" (");
            Serial.print(WiFi.RSSI(i));
            Serial.print("dBm)");
            Serial.println((WiFi.encryptionType(i) == WIFI_AUTH_OPEN) ? "
            [Abierta]" : " [Protegida]");
            delay(10);
        }
    }

    Serial.println("---------------------------------------------");
    // Espera 5 segundos antes de volver a escanear
    delay(5000);
}
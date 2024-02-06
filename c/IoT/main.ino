/**
 * @file main.ino
 * @author Miyajima, Andrew Jules R.
 * @brief
 *      NOTE: Everything here is subject to change cause I don't have actual
 * hardware base on this code.
 *
 * @version 0.1
 * @date 2023-12-21
 *
 */

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#include <stdint.h>
#include <string>

#define FIREBASE_HOST "#" // Firebase database url
#define FIREBASE_AUTH "#" // Firebase auth key
#define WIFI_SSID "#"     // WiFi SSID or WiFi name
#define WIFI_PASSWORD "#" // WiFi password

#define RAIN_SENSOR_PIN A0
#define ULTRASONIC_TRIGGER_PIN D2
#define ULTRASONIC_ECHO_PIN D3

uint_fast64_t lastUpdateTime = 0;

void setup() {
  Serial.begin(115200);
  WiFi.persistent(true);       // Save WiFi credentials to memory flash
  WiFi.setAutoReconnect(true); // Auto reconnect when WiFi gone
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  }

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  uint_fast64_t currentTime = millis();
  if (currentTime - lastUpdateTime >= 1000) {
    lastUpdateTime = currentTime;

    // Read sensor data
    uint32_t rainValue = getRainValue();
    uint32_t ultrasonicDistance = getUltrasonicDistance();

    // Send data to Firebase
    sendDataToFirebase("rainValue", rainValue);
    sendDataToFirebase("ultrasonicDistance", ultrasonicDistance);
  }
}

void sendDataToFirebase(const std::string &path, const int32_t &value) {
  uint8_t attempts = 0;
  while (Firebase.failed() && attempts < 3) {
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    attempts++;
  }

  if (Firebase.failed()) {
    return;
  }
  Firebase.setInt(path, value);
}

uint16_t getRainValue() {
  delayMicroseconds(10);
  return analogRead(RAIN_SENSOR_PIN);
}

uint32_t getUltrasonicDistance() {
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER_PIN, LOW);

  uint32_t duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  uint32_t distance = (duration * 0.034f / 2) * 10; // measuring by Millimeter

  return distance;
}
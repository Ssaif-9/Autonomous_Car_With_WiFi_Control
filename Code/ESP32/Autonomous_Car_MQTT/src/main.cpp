#include <Arduino.h>
#include <HardwareSerial.h>
#include <WiFi.h>
#include <PubSubClient.h>

char Navigation;
char Disition;
String message;

const char *ssid = "TE DATA";
const char *password = "S9S26#s25s1";

const char *mqtt_server = "b37.mqtt.one";

const char *mqtt_topic_to_subscribe = "250hlo4503/navigation";
const char *mqtt_topic_to_publish = "250hlo4503/distance";

const char *mqtt_username = "250hlo4503";
const char *mqtt_password = "69dfhklnrw";
const int mqtt_port = 1883;

#define uartRxPin  16 // UART2 RX pin
#define uartTxPin  17 // UART2 TX pin
#define BuadRate 9600

HardwareSerial SerialUART(2); // Use UART2 instance

#define BuildinLedPin 2

WiFiClient espClient;
PubSubClient client(espClient);

void setLed()
{
  pinMode(BuildinLedPin, OUTPUT);
}

void setup_wifi() {
  digitalWrite(BuildinLedPin, HIGH);
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");
}

void setup_UART2() {
  SerialUART.begin(BuadRate,SERIAL_8N1,uartRxPin,uartTxPin);
}

void reconnect() {
  // Loop until we're reconnected to MQTT
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("Attempting MQTT connection as %s.\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Connected to MQTT broker");
      digitalWrite(BuildinLedPin, LOW);
      client.subscribe(mqtt_topic_to_subscribe);
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Try again in 5 seconds");
      digitalWrite(BuildinLedPin, LOW);
      delay(1000);
      digitalWrite(BuildinLedPin, HIGH);
      delay(4000);
    }
  }
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.println("Message arrived in topic: " + String(topic));

  // Send the received message via UART
  for (int i = 0; i < length; i++) {
    Serial.write(payload[i]);
    Navigation = payload[i];
    SerialUART.print(Navigation);
  }
}

void setup() {
  Serial.begin(115200);
  setLed();
  setup_wifi();
  setup_UART2();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
/*
  if (SerialUART.available())
  {
    Disition = SerialUART.read();
    message = String(Disition);
    client.publish(mqtt_topic_to_publish,message.c_str());
  }
  */
}

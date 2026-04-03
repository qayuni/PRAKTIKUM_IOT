#include <WiFi.h>
#include <ThingerESP32.h>

#define USERNAME "Yunew"
#define DEVICE_ID "posttest1"
#define DEVICE_CREDENTIAL "$CZ4&1wSNH56_fYU"

#define SSID "Universitas Mulawarman"
#define SSID_PASSWORD ""

ThingerESP32 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

#define MQ_AOUT 34
#define LED1 16
#define LED2 17
#define LED3 18

int gasValue = 0;

// fungsi kedip
void blinkLED(int pin, int detik) {
  for (int i = 0; i < detik; i++) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(500);
  }
}

void setup() {
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  pinMode(MQ_AOUT, INPUT);

  thing.add_wifi(SSID, SSID_PASSWORD);

  thing["gas"] >> [](pson &out) {
    out = analogRead(MQ_AOUT);
  };

  Serial.println("Warming up...");
  delay(60000); // lebih aman 1 menit
}

void loop() {
  thing.handle();

  gasValue = analogRead(MQ_AOUT);
  Serial.println(gasValue);

  // reset LED
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);

  if (gasValue == 0) {
    // nanti bisa ditambah kontrol IoT
    Serial.println("Tidak ada gas");
  }
  else if (gasValue <= 201) {
    blinkLED(LED3, 3);
  }
  else if (gasValue <= 500) {
    blinkLED(LED2, 5);
  }
  else {
    blinkLED(LED1, 7);
  }

  delay(500);
}


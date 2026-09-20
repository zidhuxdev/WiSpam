/*
 * ============================================================
 *   WiSpam
 *   Developer : zidhuxd
 *   GitHub    : https://github.com/zidhuxdev
 * ============================================================
 *
 * ESP32 WiFi Beacon Spammer
 * Broadcasts fake phone-model hotspot SSIDs (phantom networks).
 *
 * For educational / authorized testing only.
 * Do NOT use on networks you do not own or have permission to test.
 * ============================================================
 */

#include <WiFi.h>
#include <esp_wifi.h>

// ===================================================================
//  Low-level 802.11 TX
// ===================================================================
extern "C" int esp_wifi_80211_tx(wifi_interface_t ifx,
                                 const void *buffer, int len, bool en_sys_seq);

// ===================================================================
//  Fake SSID list
// ===================================================================
const int numSSIDs = 30;

const char* ssidList[numSSIDs] = {
  "iPhone 15 Pro Max","iPhone 15","iPhone 14 Pro","iPhone 13",
  "iPhone 12 mini","iPhone SE","Samsung A25","Samsung A54",
  "Samsung S24 Ultra","Samsung S23","Samsung M14","Redmi Note 13 Pro",
  "Redmi 12C","Xiaomi 14","Poco X6","OnePlus 12",
  "OnePlus Nord CE3","Realme 11 Pro","Vivo V29","Oppo Reno 11",
  "Nothing Phone 2","Google Pixel 8 Pro","Motorola Edge 40","Honor X9b",
  "Asus ROG Phone 7","iPhone 16 Pro","Samsung S25","Redmi K70",
  "iQOO Neo 9","Infinix Zero 30"
};

// ===================================================================
//  Beacon frame template
// ===================================================================
uint8_t beaconPacket[128] = {
  0x80,0x00, 0x00,0x00,
  0xff,0xff,0xff,0xff,0xff,0xff,
  0x01,0x02,0x03,0x04,0x05,0x06,
  0x01,0x02,0x03,0x04,0x05,0x06,
  0x00,0x00,
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
  0x64,0x00,
  0x01,0x04,
  0x00
};

// ===================================================================
//  BEACON BROADCASTING
// ===================================================================
void broadcastSSID(const char* ssid) {
  int channel = random(1, 12);
  esp_wifi_set_channel(channel, WIFI_SECOND_CHAN_NONE);
  delay(1);

  for (int i = 10; i <= 21; i++) beaconPacket[i] = random(256);

  int ssidLen = strlen(ssid);
  beaconPacket[37] = ssidLen;
  memcpy(&beaconPacket[38], ssid, ssidLen);

  uint8_t postSSID[] = {
    0x01,0x08,0x82,0x84,0x8b,0x96,0x24,0x30,0x48,0x6c,
    0x03,0x01,channel
  };
  memcpy(&beaconPacket[38 + ssidLen], postSSID, sizeof(postSSID));

  int packetLen = 36 + 2 + ssidLen + 13;
  esp_wifi_80211_tx(WIFI_IF_STA, beaconPacket, packetLen, false);
}

// ===================================================================
//  SETUP / LOOP
// ===================================================================
void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_MODE_STA);
  esp_wifi_start();

  Serial.println();
  Serial.println("================================");
  Serial.println("            WiSpam");
  Serial.println("     by zidhuxd | github.com/zidhuxdev");
  Serial.println("--------------------------------");
  Serial.print  ("Chip MAC  : ");
  Serial.println(WiFi.macAddress());
  Serial.print  ("Broadcast : ");
  Serial.print  (numSSIDs);
  Serial.println(" phantom SSIDs");
  Serial.println("================================");
}

void loop() {
  for (int i = 0; i < numSSIDs; i++) {
    broadcastSSID(ssidList[i]);
    delay(30);
  }
  delay(100);
}

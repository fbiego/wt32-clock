/*
   MIT License

  Copyright (c) 2022 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                              /____/

*/

#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>
#include <BLE2902.h>

uint8_t type[] = {0xAB, 0x00, 0x11, 0xFF, 0x92, 0xC0, 0x01, 0x01, 0x38, 0x81, 0x10, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0xA2, 0x00, 0x80};  // id for DT78 app

#define SERVICE_UUID              "6e400001-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID_RX    "6e400002-b5a3-f393-e0a9-e50e24dcca9e"
#define CHARACTERISTIC_UUID_TX    "6e400003-b5a3-f393-e0a9-e50e24dcca9e"

static BLECharacteristic* pCharacteristicTX;
static BLECharacteristic* pCharacteristicRX;

static bool deviceConnected = false;
static int id = 0;
long timeout = 10000, timer = 0, scrTimer = 0;
bool rotate = false, flip = false, hr24 = true, notify = false, screenOff = false, scrOff = false, b1;
int scroll = 0, bat = 0, lines = 0, msglen = 0;
char msg[126];

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;

    }
    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
      pServer->startAdvertising();
      id = 0;
    }
};

class MyCallbacks: public BLECharacteristicCallbacks {

    void onStatus(BLECharacteristic* pCharacteristic, Status s, uint32_t code) {
      Serial.print("Status ");
      Serial.print(s);
      Serial.print(" on characteristic ");
      Serial.print(pCharacteristic->getUUID().toString().c_str());
      Serial.print(" with code ");
      Serial.println(code);
    }

    void onNotify(BLECharacteristic *pCharacteristic) {
      uint8_t* pData;
      std::string value = pCharacteristic->getValue();
      int len = value.length();
      pData = pCharacteristic->getData();
      if (pData != NULL) {
        Serial.print("Notify callback for characteristic ");
        Serial.print(pCharacteristic->getUUID().toString().c_str());
        Serial.print(" of data length ");
        Serial.println(len);
        Serial.print("TX  ");
        for (int i = 0; i < len; i++) {
          Serial.printf("%02X ", pData[i]);
        }
        Serial.println();
      }
    }

    void onWrite(BLECharacteristic *pCharacteristic) {
      uint8_t* pData;
      std::string value = pCharacteristic->getValue();
      int len = value.length();
      pData = pCharacteristic->getData();
      if (pData != NULL) {
        Serial.print("Write callback for characteristic ");
        Serial.print(pCharacteristic->getUUID().toString().c_str());
        Serial.print(" of data length ");
        Serial.println(len);
        Serial.print("RX  ");
        for (int i = 0; i < len; i++) {
          Serial.printf("%02X ", pData[i]);
        }
        Serial.println();

        if (pData[0] == 0xAB) {
          switch (pData[4]) {
            case 0x93:
              rtc.setTime(pData[13], pData[12], pData[11], pData[10], pData[9], pData[7] * 256 + pData[8]);
              break;
            case 0x7C:
              hr24 = pData[6] == 0;
              break;
            case 0x78:
              rotate = pData[6] == 1;
              break;
            case 0x74:
              flip = pData[10] == 1;
              break;
            case 0x7B:
              if (pData[6] >= 5 && pData[6] <= 30) {
                timeout = pData[6] * 1000;
              }

              break;
            case 0x23:
              screenOff = pData[6] == 1;
              break;
            case 0x91:
              bat = pData[7];
              break;
            case 0x72:
              timer = millis();
              msglen = pData[2] - 5;
              lines = ceil(float(msglen) / 21);
              scroll = 0;
              msg[msglen] = 0;
              scrOff = false;
              if (pData[6] == 1) {
                //call
                timer = millis() + 15000;
                for (int x = 0; x < len; x++) {
                  msg[x] = char(pData[x + 8]);
                }
              } else if (pData[6] == 2) {
                //cancel call
                timer = millis() - timeout;
                scrOff = true;
              } else {
                //notification
                notify = true;
                for (int x = 0; x < len; x++) {
                  msg[x] = char(pData[x + 8]);
                  
                }

              }
              break;
          }

        } else {
          switch (pData[0]) {
            case 0:
              for (int x = 0; x < len - 1; x++) {
                msg[x + 12] = char(pData[x + 1]);
              }
              break;
            case 1:
              for (int x = 0; x < len - 1; x++) {
                msg[x + 31] = char(pData[x + 1]);
              }
              break;
            case 2:
              for (int x = 0; x < len - 1; x++) {
                msg[x + 50] = char(pData[x + 1]);
              }
              break;
            case 3:
              for (int x = 0; x < len - 1; x++) {
                msg[x + 69] = char(pData[x + 1]);
              }
              break;
            case 4:
              for (int x = 0; x < len - 1; x++) {
                msg[x + 88] = char(pData[x + 1]);
              }
              break;
            case 5:
              for (int x = 0; x < len - 1; x++) {
                msg[x + 107] = char(pData[x + 1]);
              }
              break;
          }
        }


      }

    }


};

void initBLE() {
  BLEDevice::init("WT32 Clock");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(SERVICE_UUID);
  pCharacteristicTX = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY );
  pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE | BLECharacteristic::PROPERTY_WRITE_NR);
  pCharacteristicRX->setCallbacks(new MyCallbacks());
  pCharacteristicTX->setCallbacks(new MyCallbacks());
  pCharacteristicTX->addDescriptor(new BLE2902());
  pCharacteristicTX->setNotifyProperty(true);
  pService->start();


  // BLEAdvertising *pAdvertising = pServer->getAdvertising();  // this still is working for backward compatibility
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(true);
  pAdvertising->setMinPreferred(0x06);  // functions that help with iPhone connections issue
  pAdvertising->setMinPreferred(0x12);
  BLEDevice::startAdvertising();
  Serial.println("Characteristic defined! Now you can read it in your phone!");
}

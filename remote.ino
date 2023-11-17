/*
 * Specify which protocol(s) should be used for decoding.
 * If no protocol is defined, all protocols (except Bang&Olufsen) are active.
 * This must be done before the #include <IRremote.hpp>
 */
//#define DECODE_DENON        // Includes Sharp
//#define DECODE_JVC
//#define DECODE_KASEIKYO
//#define DECODE_PANASONIC    // alias for DECODE_KASEIKYO
//#define DECODE_LG
#define DECODE_NEC          // Includes Apple and Onkyo
//#define DECODE_SAMSUNG
//#define DECODE_SONY
//#define DECODE_RC5
//#define DECODE_RC6

//#define DECODE_BOSEWAVE
//#define DECODE_LEGO_PF
//#define DECODE_MAGIQUEST
//#define DECODE_WHYNTER
//#define DECODE_FAST

//#define DECODE_DISTANCE_WIDTH // Universal decoder for pulse distance width protocols
//#define DECODE_HASH         // special decoder for all protocols

//#define DECODE_BEO          // This protocol must always be enabled manually, i.e. it is NOT enabled if no protocol is defined. It prevents decoding of SONY!

//#define DEBUG               // Activate this for lots of lovely debug output from the decoders.

//#define RAW_BUFFER_LENGTH  180  // Default is 112 if DECODE_MAGIQUEST is enabled, otherwise 100.


#include <Arduino.h>
#include "PinDefinitionsAndMore.h"
#include <BleKeyboard.h>
#include <IRremote.hpp>

char* imp = "inThIsworLDth3reaReshiTTYp30ple";
const int LED_BUILTIN = 2;

int brightness = 0;
int fadeAmount = 5;

BleKeyboard bleKeyboard;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.print(F("Ready to receive IR signals of protocols: "));
  printActiveIRProtocols(&Serial);
  Serial.println(F("at pin " STR(IR_RECEIVE_PIN)));
}

void loop() {
  if (bleKeyboard.isConnected()) {
    if (IrReceiver.decode()) {
      IrReceiver.printIRResultShort(&Serial);
      IrReceiver.printIRSendUsage(&Serial);
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        Serial.println(F("Received noise or an unknown (or not yet enabled) protocol"));
        IrReceiver.printIRResultRawFormatted(&Serial, true);
      }
      Serial.println();
      digitalWrite(LED_BUILTIN,1);
      delay(25);
      IrReceiver.resume();
      digitalWrite(LED_BUILTIN,0);
      if (IrReceiver.decodedIRData.address == 0x4) {
        if (IrReceiver.decodedIRData.command == 0x2F) {
          bleKeyboard.write(KEY_MEDIA_MUTE);
          delay(150);
        } /*1*/
        else if (IrReceiver.decodedIRData.command == 0x8) {
          bleKeyboard.press(KEY_LEFT_GUI);
          delay(50);
          bleKeyboard.write('l');
          delay(50);
          bleKeyboard.releaseAll();
        } /*2*/
        else if (IrReceiver.decodedIRData.command == 0xEC) {
          const char* cmd = "cmd";
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.write('r');
          bleKeyboard.releaseAll();
          delay(150);
          for (int i = 0; i < 3; i++) {
            bleKeyboard.write(cmd[i]);
            delay(5);
          }
          delay(150);
          bleKeyboard.write(KEY_RETURN);
        } /*3*/
        else if (IrReceiver.decodedIRData.command == 0xEB) {
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.press(KEY_LEFT_SHIFT);
          bleKeyboard.press(KEY_ESC);
          bleKeyboard.releaseAll();
          delay(150);
        } /*4*/
        else if (IrReceiver.decodedIRData.command == 0xEA) {
          bleKeyboard.press(KEY_LEFT_ALT);
          bleKeyboard.press(KEY_TAB);
          bleKeyboard.releaseAll();
          delay(150);
        } /*5*/
        else if (IrReceiver.decodedIRData.command == 0x6F) {
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.write('c');
          bleKeyboard.releaseAll();
        } /*6*/
        else if (IrReceiver.decodedIRData.command == 0xFB) {
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.write('a');
          delay(100);
          bleKeyboard.releaseAll();
        } /*7*/
        else if (IrReceiver.decodedIRData.command == 0xEE) {
        } /*8*/
        else if (IrReceiver.decodedIRData.command == 0x49) {
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.write('z');
          delay(200);
          bleKeyboard.releaseAll();
        } /*9*/
        else if (IrReceiver.decodedIRData.command == 0x4F) {
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.write('y');
          delay(200);
          bleKeyboard.releaseAll();
        } /*10*/
        else if (IrReceiver.decodedIRData.command == 0x45) {
          bleKeyboard.write(KEY_MEDIA_VOLUME_UP);
          delay(50);
        } /*11*/
        else if (IrReceiver.decodedIRData.command == 0x47) {
          bleKeyboard.write(KEY_MEDIA_PREVIOUS_TRACK);
          delay(100);
        } /*12*/
        else if (IrReceiver.decodedIRData.command == 0x44) {
          bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
          delay(300);
        } /*13*/
        else if (IrReceiver.decodedIRData.command == 0x48) {
          bleKeyboard.write(KEY_MEDIA_NEXT_TRACK);
          delay(100);
        } /*14*/
        else if (IrReceiver.decodedIRData.command == 0x46) {
          bleKeyboard.write(KEY_MEDIA_VOLUME_DOWN);
          delay(50);
        } /*15*/
        else if (IrReceiver.decodedIRData.command == 0x4A) {
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.write('i');
          bleKeyboard.releaseAll();
        } /*16*/
        else if (IrReceiver.decodedIRData.command == 0x1B) {
          for (int i = 0; i < 31; i++) {
            bleKeyboard.write(imp[i]);
            delay(5);
          }
          delay(50);
          bleKeyboard.write(KEY_RETURN);
        } /*17*/
        else if (IrReceiver.decodedIRData.command == 0x2) {
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.write('e');
          bleKeyboard.releaseAll();
        } /*18*/
        else if (IrReceiver.decodedIRData.command == 0x39) {
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.releaseAll();
        } /*19*/
        else if (IrReceiver.decodedIRData.command == 0x0) {
          bleKeyboard.write(KEY_BACKSPACE);
          delay(250);
        } /*20*/
        else if (IrReceiver.decodedIRData.command == 0x2D) {
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.write('d');
          bleKeyboard.releaseAll();
        } /*21*/
        else if (IrReceiver.decodedIRData.command == 0x3) {
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.press(KEY_TAB);
          bleKeyboard.releaseAll();
        } /*22*/
        else if (IrReceiver.decodedIRData.command == 0x67) {
          bleKeyboard.write(KEY_UP_ARROW);
          delay(150);
        } /*23*/
        else if (IrReceiver.decodedIRData.command == 0x1) {
          bleKeyboard.press(KEY_LEFT_ALT);
          bleKeyboard.press(KEY_RETURN);
          bleKeyboard.releaseAll();
        } /*24*/
        else if (IrReceiver.decodedIRData.command == 0x9) {
          bleKeyboard.write(KEY_LEFT_ARROW);
          delay(150);
        } /*25*/
        else if (IrReceiver.decodedIRData.command == 0x1A) {
          bleKeyboard.write(KEY_RIGHT_ARROW);
          delay(150);
        } /*26*/
        else if (IrReceiver.decodedIRData.command == 0x11) {
          bleKeyboard.write('v');
          delay(250);
        } /*27*/
        else if (IrReceiver.decodedIRData.command == 0x12) {
          bleKeyboard.write(KEY_DOWN_ARROW);
          delay(150);
        } /*28*/
        else if (IrReceiver.decodedIRData.command == 0x13) {
          bleKeyboard.write('b');
          delay(150);
        } /*29*/
        else if (IrReceiver.decodedIRData.command == 0x14) {
          bleKeyboard.write(KEY_TAB);
          delay(150);
        } /*30*/
        else if (IrReceiver.decodedIRData.command == 0x15) {
          bleKeyboard.write(KEY_RETURN);
          delay(150);
        } /*31*/
        else if (IrReceiver.decodedIRData.command == 0x16) {
          bleKeyboard.write(KEY_CAPS_LOCK);
          delay(150);
        } /*32*/
        else if (IrReceiver.decodedIRData.command == 0x17) {
          bleKeyboard.press(KEY_LEFT_CTRL);
          bleKeyboard.write('v');
          bleKeyboard.releaseAll();
        } /*33*/
        else if (IrReceiver.decodedIRData.command == 0x18) {
          bleKeyboard.write(KEY_F5);
        } /*34*/
        else if (IrReceiver.decodedIRData.command == 0x19) {
          bleKeyboard.write(KEY_F11);
        } /*35*/
        else if (IrReceiver.decodedIRData.command == 0x77) {
          bleKeyboard.press(KEY_LEFT_GUI);
          bleKeyboard.write(KEY_PRTSC);
          bleKeyboard.releaseAll();
        } /*36*/
        else if (IrReceiver.decodedIRData.command == 0x10) {
          bleKeyboard.print(" ");
          delay(150);
        } /*37*/
        else if (IrReceiver.decodedIRData.command == 0xFF) {
          bleKeyboard.press(KEY_LEFT_ALT);
          delay(50);
          bleKeyboard.press(KEY_F4);
          delay(100);
          bleKeyboard.releaseAll();
          delay(50);
          //bleKeyboard.write(KEY_RETURN);
        } /*38*/
      }
    }
  }
  else{
    analogWrite(LED_BUILTIN, brightness);
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(20);
  }
}

#include <SoftwareSerial.h>

SoftwareSerial bt_serial(4, 5); // 소프트웨어 시리얼 (TX, RX)

/*
 * AT+HELP: AT Command 목록 출력
 * AT+DEFAULT: 모듈 공장 초기화
 * AT+RESET: BLE 모듈 리셋
 * AT: AT모드 응답 확인
 * AT+UUID or AT+UUIDxxxx: SERVER_UUID 확인 및 설정
 * AT+CHAR or AT+UUIDxxxx: CHAR_UUID 확인 및 설정
 * AT+ADVI5: 신호를 5초마다 송출. 신호 송출 간격
 * AT+NAMExxx: HM-10 이름 설정
 */

//String Command[] = {"AT+RENEW", "AT+RESET", "AT", "AT+MARJ0x1234", "AT+MINO0xFA01", "AT+ADVI5", "AT+NAMEBUS", "AT+ADTY3", "AT+IBEA1", "AT+DELO2"};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");
  bt_serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  while(bt_serial.available()) {
    byte data = bt_serial.read();
    Serial.write(data);
  }

  while(Serial.available()) {
    byte data = Serial.read();
    bt_serial.write(data);
  }
}

//Código TinkerCad 
#include <Servo.h>
#include <LiquidCrystal.h>

Servo myServo;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int PinLed = 8;
int servoPin = 9;
int PinBuzzer = 10;
int PinBotao = 7;

const int intervaloMedicamento = 8* 60 * 60 * 1000; // Intervalo de 8 horas
const int intervaloMedicamento2 = 7 * 1000; // para começar a simulação
const int intervaloAlerta = 3 * 1000;   // Intervalo de 3 segundos após a primeira alerta

unsigned long proximaDose = 0;
bool alertaAtivo = false;


void setup() {
  lcd.begin(16, 2);
  pinMode(servoPin, OUTPUT);
  myServo.attach(servoPin);
  pinMode(PinLed, OUTPUT);
  pinMode(PinBuzzer, OUTPUT);
  pinMode(PinBotao, INPUT);
  proximaDose = millis() + intervaloMedicamento2; // Configura a próxima dose inicial
  myServo.write(0);
  Serial.begin(9600);
}

void loop() {
  if (medicamentoProgramado()) {
    //abrirCompartimento();
    alertaSonoro();
    aguardarConfirmacao();
    fecharCompartimento();
  }
  atualizarLCD();
}

bool medicamentoProgramado() {
  if (millis() >= proximaDose) {
    proximaDose = millis() + intervaloMedicamento; // Configura a próxima dose
    alertaAtivo = true;                             // Ativa o alerta após cada dose programada
    return true;
  }
  return false;
}
//void abrirCompartimento() {
  //myServo.write();
  //delay(1000);
//}

void alertaSonoro() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("HORA DO MEDICAMENTO");
  myServo.write(90);
  tone(PinBuzzer, 1000, 1000);
  delay(intervaloAlerta); // Aguarda 3 segundos antes do próximo alerta
  alertaAtivo = false;    // Desativa o alerta após o intervalo
}

void aguardarConfirmacao() {
  lcd.setCursor(0, 1);
  lcd.print("Pressione o botao");
  while (digitalRead(PinBotao) == HIGH) {
  }
  noTone(PinBuzzer);
  while (digitalRead(PinBotao) == LOW) {
    tone(PinBuzzer, 1000,1000);
    delay(1000);
  }
  noTone(PinBuzzer);
}

void fecharCompartimento() {
  myServo.write(0);
  delay(1000);
}

void atualizarLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Proxima dose em:");

  unsigned long tempoRestante = proximaDose - millis();
  int horas = tempoRestante / 3600000; // 1 hora em milissegundos
  int minutos = (tempoRestante % 3600000) / 60000; // 1 minuto em milissegundos

  lcd.setCursor(0, 1);
  lcd.print(horas);
  lcd.print("h ");
  lcd.print(minutos);
  lcd.print("min");

  delay(1000);
}
#include <Servo.h> ///libreria del servo
Servo miServo;   ///creaamos el objeto para controlar el servo 
int pinServo = 9; ///definir pin digital (debe ser PWM preferiblemente)
void setup(){
miServo.attach(pinServo);///Vinculamos el objeto servo al pin fisico  
miServo.write(0);///opcional:Ir a posicion inicial conocida
}
void loop (){
// Mover el servo a 0 grados
  miServo.write(0);
  delay(1000); // Esperamos a que el servo llegue físicamente

  // Mover el servo a 90 grados
  miServo.write(90);
  delay(1000);
}
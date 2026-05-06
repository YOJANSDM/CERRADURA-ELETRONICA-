#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//--configuracion dde keypad//
const byte FILAS = 4;
const byte COLUMNAS = 4;
//--mapa de teclas (tal cual se ve en el keypad)//
char keys [FILAS][COLUMNAS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
//pines donde se conecta el keypad en el mega //
byte pinesFilas[FILAS] = {22, 23, 24, 25};
byte pinesColumnas[COLUMNAS]={26, 27, 28, 29};
Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);
//Variables para guardar la fecha ingresa o valores de entrada //
String fechaIngresada = "";//Aqui se guarda los numeros que van pulsando 

const String FECHA_JESSE= "1023";//EJEMPLO:octuber
const String FECHA_CRAYSI= "0221";//EJEMPLO:febrero

void setup()
{
lcd.begin(16,2);
lcd.print("INGRESE FECHA:");
lcd.setCursor(0,1); ///pone el cursor abajo para escribir 
}
void loop()
{
char tecla = teclado.getKey();//leemos si se preciono una tecla 
if (tecla) { ///si hay una tecla precionada..
if(tecla=='D')
{
  fechaIngresada = "";
  lcd.clear();
  lcd.print("INGRESE FECHA:");
  lcd.setCursor(0,1);
}
///si el numero  lo agregamos a la pantalla y a la memoria 
else{
  fechaIngresada +=tecla; //guardamos el numero 
  lcd.print(tecla);       //lo mostramos el el LCD para ver que escribimos 

  //LOGICA :verificamos si ya escribieron 4 numero 
  if (fechaIngresada.length()==4){
    delay(500);// pequeña espera para drama 
    lcd.clear();

    if (fechaIngresada == FECHA_JESSE) {
      lcd.setCursor(0,0);
      lcd.print("BIENVENIDO");
      lcd.setCursor(0,1);
      lcd.print("HELLO JESSE");
    }
    else if(fechaIngresada == FECHA_CRAYSI){
      lcd.setCursor(0,0);
      lcd.print("BIENVENIDO");
      lcd.setCursor(0,1);
      lcd.print("HELLO CRAYSI");
    }
    else{
      lcd.print("FECHA INCORRECTA");
    }
    //esperamos 3 segundos y reiniciamos para el siguente usuario 
    delay(3000);
    fechaIngresada ="";//limpiamos la variable 
    lcd.clear();
    lcd.print("INGRESE FECHA:");
    lcd.setCursor(0,1);
   }
  }
 }
} 
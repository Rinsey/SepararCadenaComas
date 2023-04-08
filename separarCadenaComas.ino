
float valores[8]; //Aqui se guardan los valores que vengan de la raspberry el orden esta por decidir Distancia,Angulo,Circulo,Lock
int longitud = 8;
String cadena = "asd,23.4,123.2,123.33,23.0,hola,2323.978,434.0"; //Cadena con 8 valores para extraer

void setup() {
  Serial.begin(115200);
}

void loop() {
  
  separarCadena(cadena);

  Serial.println("-=-=-=-=-=-=-=-=-=-=-");
  for (int x=0; x<8; x++){
    Serial.println(valores[x]);
  }
  delay(5000);
  
}

void separarCadena(String cadena) {
  
  int inicio = 0;
  int fin = 0;
  int i = 0;

  while (fin >= 0 && i < longitud) {
    fin = cadena.indexOf(',', inicio);
    if (fin == -1) {
      fin = cadena.length();
    }
    String valorStr = cadena.substring(inicio, fin);
    inicio = fin + 1;
    float valor = valorStr.toFloat();
    if (!isnan(valor)) {
      valores[i] = valor;
      i++;
    }
  }
  
}


//Ejemplo xd

float valores[8]; //Aqui se guardan los valores que vengan de la raspberry el orden esta por decidir Distancia,Angulo,Circulo,Lock
int longitud = 8; //Aqui se pone lo que mide el arreglo
String cadena = "asd,23.4,123.2,123.33,23.0,hola,2323.978,434.0"; //Cadena con 8 valores para extraer

void setup() {
  
  Serial.begin(115200); 
  
}

void loop() {
  
  separarCadena(cadena); //Separamos la cadena de ejemplo

  Serial.println("-=-=-=-=-=-=-=-=-=-=-");
  for (int x=0; x<8; x++){
    Serial.println(valores[x]); //Mostramos los valores guardados.
  }
  delay(5000);
  
}

void separarCadena(String cadena) {
  
  int inicio = 0; //Importante para encontrar cada coma en la sentencia
  int finall = 0; // Para marcar la siguiente coma
  int contador = 0; // para insertar el dato ya convertido en su posicion correspondiente es contador

  while (finall >= 0 && contador < longitud) { //Se puede cambiar por un for 
    finall = cadena.indexOf(',', inicio); // Encontramos la posicion de una coma, desde el punto de inicio el cual cambia dependiendo de las comas encontradas
    if (finall == -1) { //Esto es en caso de que ya no se encuentre ninguna coma
      finall = cadena.length(); //Si no se encuentra ninguna coma, el fin para el substring seria el final de la cadena o sea su longitud de caracteres
    }
    
    String valorStr = cadena.substring(inicio, finall); //Se extrae el valor entre dos comas.
    inicio = finall + 1; //se establece un nuevo inicio para empezar a buscar las comas y para extraer valores
    float valor = valorStr.toFloat(); //Se convierte a float, aqui pasa algo chido si no se puede regresa un nan el cual se puede comprobar 
    if (!isnan(valor)) { //Aqui comprobamos si el valor se pudo convertir, en caso de que no pues se ignora y se añade un 0
      valores[contador] = valor; //Si el valor si es valido se almacena
      contador++;// se recorre la posicion en la que se guarda el valor.
    }
  }
  
}

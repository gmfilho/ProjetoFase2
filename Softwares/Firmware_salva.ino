import processing.serial.*; 
Serial mySerial; 
PrintWriter output; 

void setup() {
  String portName = Serial.list()[0]; 
  mySerial = new Serial(this, portName, 9600); 
  output = createWriter( "data.txt" ); 
}

void draw() { 
  if (mySerial.available() > 0 ) { 
    String value = mySerial.readStringUntil('\n'); //Le o valor recebido
    if ( value != null ) { 
      output.print(hour()); //Escreve no arquivo as horas e os minutos atuais seguido do valor lido pelo sensor
      output.print(":");
      output.print(minute());
      output.print("->");
      output.println(value); 
      output.flush();
    }
  }
}

void keyPressed() { 
  output.flush(); // Termina de escrever os dados pro arquivo
  output.close(); // Fecha o arquivo
  exit(); // Para o programa
}

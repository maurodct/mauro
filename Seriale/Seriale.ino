int x = 0;
int row = 0;
void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial.println("CLEARDATA");
  Serial.println("LABEL,Time,x,sin(x),pippo");  //LABEL serve ad indicare che trattasi di intestazione, mentre gli altri valori costituiranno l'intestazione del foglio di stile.
}


void loop() {
  Serial.print("DATA,TIME,"); Serial.print(x); Serial.print(","); Serial.print(sin(x*PI/180)); Serial.print(","); Serial.println("pippo");  //Determina il contenuto di una riga del file excel. 
                                                                                                                                            //In pratica la virgola serve per separare i vari campi e, per terminarla occorre andare a capo (println).
                                                                                                                                            //Ovviamente, nel tuo caso, non scriverai x, sin(x*PI/180) e pippo, ma solamente ciò che ti occorre: ad esempio la temperatura.
  row++;  //serve per incrementare la riga
  x++;  //Serve per incrementare il valore di x, ma dubito che, nel tuo caso, possa essere utile.
  if (row > 800) //Dopo 800 righe ricomincia da capo e sovrascrive le celle precedenti. Puoi inserire qualsissi numero <= 65534. Questo perchè il numero di righe in excel può essere, al massimo 65536.
   {
    row=0;
    Serial.println("ROW,SET,2");
   }
  delay(100);
}



int inf,result;
byte num;
void setup() {                 
  Serial.begin(9600);
  pinMode(13, OUTPUT);    //pin modumuzu 13 olarak ayarladık.
}

void loop() {
  if(Serial.available()>0){   // c den okunabilir bir değer alabildik mi diye kontrol ettik.
    inf=Serial.read();
    if(inf=='1'){   // c den aldığımız input değeri
      digitalWrite(13, HIGH);  // ledi yaktık
    }
    else if(inf=='2'){
      digitalWrite(13, LOW);  // ledi söndürdük
    }
    else if(inf=='3'){
      for(int i=0;i<3;i++){       //for döngüsü ile ledi 3 kez yakıp söndürdük.
        digitalWrite(13, HIGH);
        delay(1000);
        digitalWrite(13, LOW);
        delay(1000);
      }
    }
    else if(inf=='4'){
        delay(10000);
        if(Serial.available()>0){
          num=Serial.read();  //c den gelen sayıyı okuduk
          result=sq(num);     //karesini aldık
          Serial.print((String)result + " ");    //sonucu string olarak tuttuk.
          Serial.flush();
          
          }
      
      
      }

    
    }
  }

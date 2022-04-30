
#include <LiquidCrystal.h>
#include <time.h>

#define led_r PD_7
#define led_g PF_4
LiquidCrystal ekran(PB_5,PB_0,PA_5,PA_6,PA_7,PA_2);
int Buton_Bir=PD_0;
int Buton_Ikinci=PD_1;
int Buton_Ucuncu=PD_2;
int Buton_Dorduncu=PD_3;
int Buton_Besinci=PE_1;
int Buton_Bitis=PE_2;
int Buton_Kopukleme=PE_3;
int Buton_Yikama=PC_5;
int Buton_Kurulama=PF_2;
int Buton_Cilalama=PF_3;
int Buton_Bitis2=PB_3;
int Buton_Bilgi=PC_4;
int Buton_Reset=PC_6;
int Bakiye=0;
int yatirilan=0;
int Random;
int Beslik_sayisi=10;
int Beslik_basma_sayisi=0;
int Onluk_sayisi=10;
int Onluk_basma_sayisi=0;
int Yirmilik_sayisi=10;
int Yirmilik_basma_sayisi=0;
int Ellilik_sayisi=10;
int Ellilik_basma_sayisi=0;
int Yuzluk_sayisi=10;
int Yuzluk_basma_sayisi=0;
int kopukleme_sayisi=30;
int kopukleme_basma_sayisi=0;
int yikama_sayisi=50;
int yikama_basma_sayisi=0;
int kurulama_sayisi=100;
int kurulama_basma_sayisi=0;
int cilalama_sayisi=0;
int cilalama_basma_sayisi=0;
int a;
int kasadakiToplamPara=0;

long randNumber;

struct kasa{
int Beslik_sayisi1=10;
int Beslik_basma_sayisi1=0;
int Onluk_sayisi1=10;
int Onluk_basma_sayisi1=0;
int Yirmilik_sayisi1=10;
int Yirmilik_basma_sayisi1=0;
int Ellilik_sayisi1=10;
int Ellilik_basma_sayisi1=0;
int Yuzluk_sayisi1=10;
int Yuzluk_basma_sayisi1=0;
int kopukleme_sayisi1=30;
int kopukleme_basma_sayisi1=0;
int yikama_sayisi1=50;
int yikama_basma_sayisi1=0;
int kurulama_sayisi1=100;
int kurulama_basma_sayisi1=0;
int cilalama_sayisi1=0;
int cilalama_basma_sayisi1=0;  
}kasaBilgisi;

void kasayaYatir(int beslik,int onluk,int yirmilik,int ellilik,int yuzluk){
  Bakiye+=((beslik*5)+(onluk*10)+(yirmilik*20)+(ellilik*50)+(yuzluk*100));
}

void kasadanCek(int Kopukleme,int yikama,int kurulama,int cilalama){
  Bakiye-=((Kopukleme*15)+(yikama*10)+(kurulama*5)+(cilalama*50));
}

int kasadaToplamPara(){
  kasadakiToplamPara=Beslik_sayisi*5+Onluk_sayisi*10+Yirmilik_sayisi*20+Ellilik_sayisi*50+Yuzluk_sayisi*100;
  return kasadakiToplamPara;
}

void kopukleme_hizmetleri(){
  kopukleme_sayisi--;  
}
void yikama_hizmetleri(){
  yikama_sayisi--;
}
void kurulama_hizmetleri(){
  kurulama_sayisi--;
}
void cilalama_hizmetleri(){
  cilalama_sayisi--;
}
int yatirilan_para(int beslik,int onluk,int yirmilik,int ellilik,int yuzluk){
  yatirilan=((beslik*5)+(onluk*10)+(yirmilik*20)+(ellilik*50)+(yuzluk*100));
  return yatirilan;
}


void setup(){
Serial.begin(9600);
pinMode(Buton_Bir,INPUT_PULLUP);
pinMode(Buton_Ikinci,INPUT_PULLUP);
pinMode(Buton_Ucuncu,INPUT_PULLUP);
pinMode(Buton_Dorduncu,INPUT_PULLUP);
pinMode(Buton_Besinci,INPUT_PULLUP);
pinMode(Buton_Bitis,INPUT_PULLUP);
pinMode(Buton_Kopukleme,INPUT_PULLUP);
pinMode(Buton_Yikama,INPUT_PULLUP);
pinMode(Buton_Kurulama,INPUT_PULLUP);
pinMode(Buton_Cilalama,INPUT_PULLUP);
pinMode(Buton_Bitis2,INPUT_PULLUP);
pinMode(Buton_Bilgi,INPUT_PULLUP);
pinMode(Buton_Reset,INPUT_PULLUP);
pinMode(led_g,OUTPUT);
pinMode(led_r,OUTPUT);
randomSeed(analogRead(0));
ekran.begin(16,2);
ekran.clear();

}
void loop(){

 ekran.home();
 ekran.print("BIR BUTONA BAS");
 delay(1000);
 int TL5=digitalRead(Buton_Bir);
 int TL10=digitalRead(Buton_Ikinci);
 int TL20=digitalRead(Buton_Ucuncu);
 int TL50=digitalRead(Buton_Dorduncu);
 int TL100=digitalRead(Buton_Besinci);
 int Bitis=digitalRead(Buton_Bitis);
 int Kopukleme=digitalRead(Buton_Kopukleme);
 int Yikama=digitalRead(Buton_Yikama);
 int Kurulama=digitalRead(Buton_Kurulama);
 int Cilalama=digitalRead(Buton_Cilalama);
 int Bitis2=digitalRead(Buton_Bitis2);
 int Bilgi=digitalRead(Buton_Bilgi);
 int Reset=digitalRead(Buton_Reset);

 if(TL5==0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
  Serial.println("Basilan Buton 5");
  ekran.setCursor(5,1);
  ekran.print("5 TL");
  Beslik_basma_sayisi++;  
  delay(1200); 
  ekran.clear();
 }
 if(TL10==0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
  Serial.println("Basilan Buton 10");
  ekran.setCursor(4,1);
  ekran.print("10 TL");
  Onluk_basma_sayisi++;
  delay(1200);
  ekran.clear();
 }
 if(TL20==0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
  Serial.println("Basilan Buton 20");
  ekran.setCursor(4,1);
  ekran.print("20 TL");
  Yirmilik_basma_sayisi++;
  delay(1200);
  ekran.clear();
 }
 if(TL50==0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
  Serial.println("Basilan Buton 50");
  ekran.setCursor(4,1);
  ekran.print("50 TL");
  Ellilik_basma_sayisi++;
  delay(1200);
  ekran.clear();
 }
 if(TL100==0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
  Serial.println("Basilan Buton 100");
  ekran.setCursor(3,1);
  ekran.print("100 TL");
  Yuzluk_basma_sayisi++;
  delay(1200);
  ekran.clear();
 }
 if(Bitis==0){
  ekran.setCursor(0,0);
  ekran.clear();
  kasayaYatir(Beslik_basma_sayisi,Onluk_basma_sayisi,Yirmilik_basma_sayisi,Ellilik_basma_sayisi,Yuzluk_basma_sayisi);
  ekran.print("Yatirilan Para :");  
    Serial.println("Yatirilan Para :");
    Serial.println(yatirilan_para(Beslik_basma_sayisi,Onluk_basma_sayisi,Yirmilik_basma_sayisi,Ellilik_basma_sayisi,Yuzluk_basma_sayisi));
    Serial.println(" TL");
  ekran.setCursor(3,1);
  ekran.print(yatirilan_para(Beslik_basma_sayisi,Onluk_basma_sayisi,Yirmilik_basma_sayisi,Ellilik_basma_sayisi,Yuzluk_basma_sayisi));
  ekran.print(" TL");
  delay(1200);
  ekran.clear();
  Beslik_basma_sayisi=0;
  Onluk_basma_sayisi=0;
  Yirmilik_basma_sayisi=0;
  Ellilik_basma_sayisi=0;
  Yuzluk_basma_sayisi=0;
 }
 if(Kopukleme==0 && kopukleme_sayisi>0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
  ekran.setCursor(0,1);
  ekran.print("Kopukleme");
  Serial.println("Basilan Buton Kopukleme");
  kopukleme_hizmetleri();
  kopukleme_basma_sayisi++;
  delay(1200);
  ekran.clear();
  Serial.print("kalan kopukleme sayisi ");
   Serial.println(kopukleme_sayisi);
  delay(500);
 }
  else if (Kopukleme==0 && kopukleme_sayisi<=0) {
  Serial.println("Köpükleme hizmeti kalmamıştır");
 }
 if(Yikama==0 && yikama_sayisi>0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
    Serial.println("Basilan Buton Yikama");
  ekran.setCursor(0,1);
  ekran.print("Yikama");
  yikama_hizmetleri();
  yikama_basma_sayisi++;
  delay(1200);
  ekran.clear();
  Serial.print("kalan yikama sayisi ");
 Serial.println(yikama_sayisi);
  
  delay(500);
 }
 else if(Yikama==0 && yikama_sayisi<=0) {
  Serial.println("Yıkama hizmeti kalmamıştır");
 }
  if(Kurulama==0 && kurulama_sayisi>0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
    Serial.println("Basilan Buton Kurulama");
  ekran.setCursor(0,1);
  ekran.print("Kurulama");
  kurulama_hizmetleri();
  kurulama_basma_sayisi++;
  delay(1200);
  ekran.clear();
  Serial.print("kalan kurulama sayisi ");
  Serial.println(kurulama_sayisi);
 
  delay(500);
 }
  else if(Kurulama==0 && kurulama_sayisi<=0){
  Serial.println("Kurulama hizmeti kalmamıştır");
 }
  if(Cilalama==0 && cilalama_sayisi>0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Basilan Buton");
    Serial.println("Basilan Buton Cilalama");
  ekran.setCursor(0,1);
  ekran.print("Cilalama");
  cilalama_hizmetleri();
  cilalama_basma_sayisi++;
  delay(1200);
  ekran.clear();
  Serial.print("kalan cilalama sayisi ");
  Serial.println(cilalama_sayisi);
  delay(500);
 }
 else if(Cilalama==0 && cilalama_sayisi<=0){
  Serial.println("Cilalama hizmeti kalmamıştır");
 }

  if(Bitis2==0){
  ekran.setCursor(2,0);
  ekran.clear();
  
  kasadanCek(kopukleme_basma_sayisi,yikama_basma_sayisi,kurulama_basma_sayisi,cilalama_basma_sayisi);
  
  if(Bakiye>0)
  {
  randNumber = random(1, 5);
  Serial.println(randNumber);
   a=Bakiye;
   int beslik=0,onluk=0 , yirmilik=0 , ellilik=0 , yuzluk=0;
   int x=((kopukleme_basma_sayisi*15)+(yikama_basma_sayisi*10)+(kurulama_basma_sayisi*5)+(cilalama_basma_sayisi*50));
   int y=kopukleme_basma_sayisi;
   int z=yikama_basma_sayisi;
   int u=kurulama_basma_sayisi;
   int t=cilalama_basma_sayisi;
  
   
    if(randNumber==2)
  {
  digitalWrite(led_r,HIGH);
  digitalWrite(led_g,LOW);
  Bakiye+=x;
  kopukleme_sayisi+=y;
  yikama_sayisi+=z;
  kurulama_sayisi+=u;
  cilalama_sayisi+=t;
  Beslik_sayisi;
  Onluk_sayisi;
  Yirmilik_sayisi;
  Ellilik_sayisi;
  Yuzluk_sayisi;
  
  Serial.print("kalan kopukleme sayisi ");
  Serial.println(kopukleme_sayisi);
 Serial.print("kalan yikama sayisi ");
 Serial.println(yikama_sayisi);
  Serial.print("kalan kurulama sayisi ");
  Serial.println(kurulama_sayisi);
  Serial.print("kalan cilalama sayisi ");
  Serial.println(cilalama_sayisi);
   Serial.print("kalan Bakiye ");
  Serial.println(Bakiye);
  Serial.print("kalan 5 tl sayisi ");
  Serial.println(Beslik_sayisi);
  Serial.print("kalan 10 tl sayisi ");
  Serial.println(Onluk_sayisi);
  Serial.print("kalan 20 tl sayisi ");
  Serial.println(Yirmilik_sayisi);
  Serial.print("kalan 50 tl sayisi ");
  Serial.println(Ellilik_sayisi);
  Serial.print("kalan 100 tl sayisi ");
  Serial.println(Yuzluk_sayisi);
  delay(1000);
  }
   else{
    if(Bakiye<=kasadaToplamPara())
    {
 
  digitalWrite(led_r,LOW);
  digitalWrite(led_g,HIGH);
   
   if(a>=100){

    yuzluk=a/100;
    if(yuzluk<=Yuzluk_sayisi)
    {
      a=a%100; 
      Yuzluk_sayisi-=yuzluk;
      ekran.setCursor(0,0);
      ekran.print("VER 100 SAY:");
      ekran.setCursor(0,1);
      ekran.print(yuzluk);  
      delay(2000);   
       ekran.clear();      
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 100 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Yuzluk_sayisi);  
      delay(2000);   
      ekran.clear();  
      a-=Yuzluk_sayisi*100;
      Yuzluk_sayisi=0;
      
     if(a >=50)
     {  
      ellilik=a/50;
      if(ellilik<=Ellilik_sayisi)
    {
      a=a%50; 
      Ellilik_sayisi-=ellilik;
      ekran.setCursor(0,0);
      ekran.print("VER 50 SAY:");
      ekran.setCursor(0,1);
      ekran.print(ellilik);  
      delay(2000);   
      ekran.clear();         
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 50 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Ellilik_sayisi);  
      delay(2000);   
      ekran.clear(); 
      a-=Ellilik_sayisi*50;
      Ellilik_sayisi=0;
      if(a>=20)
      {
      yirmilik=a/20;
      if(yirmilik<=Yirmilik_sayisi)
    {
      a=a%20; 
      Yirmilik_sayisi-=yirmilik;  
      ekran.setCursor(0,0);
      ekran.print("VER 20 SAY:");
      ekran.setCursor(0,1);
      ekran.print(yirmilik);  
      delay(2000);   
      ekran.clear();    
    }else{
       ekran.setCursor(0,0);
      ekran.print("VER 20 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Yirmilik_sayisi);  
      delay(2000);   
      ekran.clear();   
      a-=Yirmilik_sayisi*20;
      Yirmilik_sayisi=0;
      if(a>=10){
       onluk=a/10;
      if(onluk<=Onluk_sayisi)
    {
      a=a%10; 
      Onluk_sayisi-=onluk;   
      ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(onluk);  
      delay(2000);   
      ekran.clear();    
    }
    else{
       ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Onluk_sayisi);  
      delay(2000);   
      ekran.clear();   
      a-=Onluk_sayisi*10;
      Onluk_sayisi=0;
      if(a>=5)
      {
         beslik=a/5;
      if(beslik<=Beslik_sayisi)
    {
      a=a%5; 
      Beslik_sayisi-=beslik;  
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(beslik);  
      delay(2000);   
      ekran.clear();      
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Beslik_sayisi);  
      delay(2000);   
      ekran.clear();  
     a-=Beslik_sayisi*5;
      Beslik_sayisi=0;
      if(a>0){
    ekran.setCursor(0,0);
    ekran.print("KASADA YETERLİ");
    ekran.setCursor(0,1);
    ekran.print("PARA YOKTUR");  
    delay(2000);   
      }   
    }
     }   
    }       
      }
      }    
    }  
    }
   }
   }
   }

   
   if(a<100 && a >=50)
   {
    ellilik=a/50;
      if(ellilik<=Ellilik_sayisi)
    {
      a=a%50; 
      Ellilik_sayisi-=ellilik;    
      ekran.setCursor(0,0);
      ekran.print("VER 50 SAY:");
      ekran.setCursor(0,1);
      ekran.print(ellilik);  
      delay(2000);   
      ekran.clear();         
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 50 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Ellilik_sayisi);  
      delay(2000);   
      ekran.clear();       
      a-=Ellilik_sayisi*50;
      Ellilik_sayisi=0;
      if(a>=20)
      {
      yirmilik=a/20;
      if(yirmilik<=Yirmilik_sayisi)
    {
      a=a%20; 
      Yirmilik_sayisi-=yirmilik;  
      ekran.setCursor(0,0);
      ekran.print("VER 20 SAY:");
      ekran.setCursor(0,1);
      ekran.print(yirmilik);  
      delay(2000);   
      ekran.clear();    
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 20 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Yirmilik_sayisi);  
      delay(2000);   
      ekran.clear(); 
      a-=Yirmilik_sayisi*20;
      Yirmilik_sayisi=0;
      if(a>=10){
       onluk=a/10;
      if(onluk<=Onluk_sayisi)
    {
      a=a%10; 
      Onluk_sayisi-=onluk;  
      ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(onluk);  
      delay(2000);   
      ekran.clear();     
    }
    else{
      ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Onluk_sayisi);  
      delay(2000);   
      ekran.clear(); 
      a-=Onluk_sayisi*10;
      Onluk_sayisi=0;
      if(a>=5)
      {
         beslik=a/5;
      if(beslik<=Beslik_sayisi)
    {
      a=a%5; 
      Beslik_sayisi-=beslik;  
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(beslik);  
      delay(2000);   
      ekran.clear();     
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Beslik_sayisi);  
      delay(2000);   
      ekran.clear();     
     a-=Beslik_sayisi*5;
      Beslik_sayisi=0;
      if(a>0){
    ekran.setCursor(0,0);
    ekran.print("KASADA YETERLİ");
    ekran.setCursor(0,1);
    ekran.print("PARA YOKTUR"); 
    delay(2000); 
     ekran.clear();      
      }   
    }
     }   
    }       
      }
      }    
    }  
    }
   }



   if(a<50 && a >=20);
   {
      yirmilik=a/20;
      if(yirmilik<=Yirmilik_sayisi)
    {
      a=a%20; 
      Yirmilik_sayisi-=yirmilik;   
      ekran.setCursor(0,0);
      ekran.print("VER 20 SAY:");
      ekran.setCursor(0,1);
      ekran.print(yirmilik);  
      delay(2000);   
      ekran.clear();     
    }else{  
      ekran.setCursor(0,0);
      ekran.print("VER 20 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Yirmilik_sayisi);  
      delay(2000);   
      ekran.clear();   
      a-=Yirmilik_sayisi*20;
      Yirmilik_sayisi=0;
      if(a>=10){
       onluk=a/10;
      if(onluk<=Onluk_sayisi)
    {
      a=a%10; 
      Onluk_sayisi-=onluk;  
      ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(onluk);  
      delay(2000);   
      ekran.clear();     
    }
    else{
       ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Onluk_sayisi);  
      delay(2000);   
      ekran.clear();  
      a-=Onluk_sayisi*10;
      Onluk_sayisi=0;
      if(a>=5)
      {
         beslik=a/5;
      if(beslik<=Beslik_sayisi)
    {
      a=a%5; 
      Beslik_sayisi-=beslik;
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(beslik);  
      delay(2000);   
      ekran.clear();      
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Beslik_sayisi);  
      delay(2000);   
      ekran.clear();
     a-=Beslik_sayisi*5;
      Beslik_sayisi=0;
      if(a>0){
    ekran.setCursor(0,0);
    ekran.print("KASADA YETERLİ");
    ekran.setCursor(0,1);
    ekran.print("PARA YOKTUR"); 
    delay(2000);   
     ekran.clear();    
      }   
    }
     }   
    }       
      }
      }    
    }
 
   if(a<20 && a >=10){
    onluk=a/10;
      if(onluk<=Onluk_sayisi)
    {
      a=a%10; 
      Onluk_sayisi-=onluk;  
      ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(onluk);  
      delay(2000);   
      ekran.clear();    
    }
    else{
      ekran.setCursor(0,0);
      ekran.print("VER 10 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Onluk_sayisi);  
      delay(2000);   
      ekran.clear();   
      a-=Onluk_sayisi*10;
      Onluk_sayisi=0;
      if(a>=5)
      {
         beslik=a/5;
      if(beslik<=Beslik_sayisi)
    {
      a=a%5; 
      Beslik_sayisi-=beslik;
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(beslik);  
      delay(2000);   
      ekran.clear();      
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Beslik_sayisi);  
      delay(2000);   
      ekran.clear();   
     a-=Beslik_sayisi*5;
      Beslik_sayisi=0;
      if(a>0){
    ekran.setCursor(0,0);
    ekran.print("KASADA YETERLİ");
    ekran.setCursor(0,1);
    ekran.print("PARA YOKTUR"); 
    delay(2000); 
    ekran.clear();      
      }   
    }
     }   
    }       
      }
       

   if(a<10 && a>=5){
   
        beslik=a/5;
      if(beslik<=Beslik_sayisi)
    {
      a=a%5; 
      Beslik_sayisi-=beslik; 
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(beslik);  
      delay(2000);   
      ekran.clear();      
    }else{
      ekran.setCursor(0,0);
      ekran.print("VER 5 SAY:");
      ekran.setCursor(0,1);
      ekran.print(Beslik_sayisi);  
      delay(2000);   
      ekran.clear();  
     a-=Beslik_sayisi*5;
      Beslik_sayisi=0;
      if(a>0){
    ekran.setCursor(0,0);
    ekran.print("KASADA YETERLİ");
    ekran.setCursor(0,1);
    ekran.print("PARA YOKTUR");  
    delay(2000);  
     ekran.clear();    
      }   
    }
      
   }
  ekran.print("Para Ustu:");
  ekran.print(Bakiye);
  ekran.print("TL");
  ekran.setCursor(0,1);
  delay(2000); 
  ekran.clear(); 
   Serial.print("kalan kopukleme sayisi ");
  Serial.println(kopukleme_sayisi);
 Serial.print("kalan yikama sayisi ");
 Serial.println(yikama_sayisi);
  Serial.print("kalan kurulama sayisi ");
  Serial.println(kurulama_sayisi);
  Serial.print("kalan cilalama sayisi ");
  Serial.println(cilalama_sayisi);
   Serial.print("kalan Bakiye ");
  Serial.println(Bakiye);
  Serial.print("kalan 5 tl sayisi ");
  Serial.println(Beslik_sayisi);
  Serial.print("kalan 10 tl sayisi ");
  Serial.println(Onluk_sayisi);
  Serial.print("kalan 20 tl sayisi ");
  Serial.println(Yirmilik_sayisi);
  Serial.print("kalan 50 tl sayisi ");
  Serial.println(Ellilik_sayisi);
  Serial.print("kalan 100 tl sayisi ");
  Serial.println(Yuzluk_sayisi);
     }
     else{
      ekran.setCursor(0,0);
      ekran.print("KASADA YETERLI");
      ekran.setCursor(0,1);
      ekran.print("PARA YOKTUR");
      delay(1200);
      Bakiye+=x;
      Serial.print("Bakiye: ");
      Serial.println(Bakiye);
     }
   }
     }
     
     else{
    ekran.setCursor(0,0);
    ekran.print("YETERLİ BAKIYEN");
      
    ekran.setCursor(0,1);
    ekran.print("YOKTUR");
    delay(2000); 
   }
    
 ekran.clear();
 kopukleme_basma_sayisi=0;
 yikama_basma_sayisi=0;
 kurulama_basma_sayisi=0;
 cilalama_basma_sayisi=0;
  }
  
  if(Bilgi==0){
  ekran.setCursor(2,0);
  ekran.clear();
  ekran.print("Guncel Bakiye :");
  ekran.setCursor(0,1);
  ekran.print(Bakiye);
  ekran.print(" TL");
  delay(1200);
  ekran.clear();
  Serial.print("kalan 5 tl sayisi ");
  Serial.println(Beslik_sayisi);
  Serial.print("kalan 10 tl sayisi ");
  Serial.println(Onluk_sayisi);
  Serial.print("kalan 20 tl sayisi ");
  Serial.println(Yirmilik_sayisi);
  Serial.print("kalan 50 tl sayisi ");
  Serial.println(Ellilik_sayisi);
  Serial.print("kalan 100 tl sayisi ");
  Serial.println(Yuzluk_sayisi);
 }
 if(Reset==0){
  ekran.setCursor(2,0);
  ekran.clear();
  Beslik_sayisi=kasaBilgisi.Beslik_sayisi1;
  Beslik_basma_sayisi=kasaBilgisi.Beslik_basma_sayisi1;
  Onluk_sayisi=kasaBilgisi.Onluk_sayisi1;
  Onluk_basma_sayisi=kasaBilgisi.Onluk_basma_sayisi1;
  Yirmilik_sayisi=kasaBilgisi.Yirmilik_sayisi1;
  Yirmilik_basma_sayisi=kasaBilgisi.Yirmilik_basma_sayisi1;
  Ellilik_sayisi=kasaBilgisi.Ellilik_sayisi1;
  Ellilik_basma_sayisi=kasaBilgisi.Ellilik_basma_sayisi1;
  Yuzluk_sayisi=kasaBilgisi.Yuzluk_sayisi1;
  Yuzluk_basma_sayisi=kasaBilgisi.Yuzluk_basma_sayisi1;
  kopukleme_sayisi=kasaBilgisi.kopukleme_sayisi1;
  kopukleme_basma_sayisi=kasaBilgisi.kopukleme_basma_sayisi1;
  yikama_sayisi=kasaBilgisi.yikama_sayisi1;
  yikama_basma_sayisi=kasaBilgisi.yikama_basma_sayisi1;
  kurulama_sayisi=kasaBilgisi.kurulama_sayisi1;
  kurulama_basma_sayisi=kasaBilgisi.kurulama_basma_sayisi1;
  cilalama_sayisi=kasaBilgisi.cilalama_sayisi1;
  cilalama_basma_sayisi=kasaBilgisi.cilalama_basma_sayisi1;
  ekran.print("Basilan Buton");
  Serial.println("Basilan Buton");
  Serial.println("Reset");
  ekran.setCursor(3,1);
  ekran.print("Reset");
  Bakiye=0;
  delay(1200);
  ekran.clear();
  digitalWrite(led_r,LOW);
  digitalWrite(led_g,HIGH);
  delay(1000);
 }
}

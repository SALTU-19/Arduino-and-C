#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include"arduino-serial-lib.c"  //arduino için kullandığımız bir kütüphane
#include"arduino-serial-lib.h"
void menu();
int main() {
	int port=serialport_init("/dev/ttyUSB0",9600);  //arduinonun adresini belirttik.
	int choice=1;
	const char* ch1="1";
	const char* ch2="2";
	const char* ch3="3";     //arduinoya göndermek için char belirlerdik.
	const char* ch4="4";
	char buf[256];
	uint8_t num_4;
	
	while(choice!=0){
		menu();
		printf("Please select:");
		scanf("%d",&choice);
		if(choice == 1){
			serialport_write(port,ch1);	//arduino ile c nin iletşimini sağladık.
		}
		else if(choice == 2){
			serialport_write(port,ch2);
		}
		else if(choice == 3){
			serialport_write(port,ch3);
		}
		else if(choice == 4){
			serialport_write(port,ch4);
			printf("Please enter a number:"); // kullanıcıdan sayı aldık.
			scanf("%hhd",&num_4);
			serialport_flush(port); //num4 ten önce gelen dosyaları temizlemek için kullandık.
			serialport_writebyte(port,num_4); //ardunionaya sayı gönderdik(byte olarak).
			serialport_read_until(port,buf,' ',256,10000); //gelen sayıyı okuduk ve listeye attık.
			printf("Square of %hhd:  %s\n",num_4,buf );    //sayımızı bastırdık.
			serialport_flush(port);
		}
		else if(choice == 0){
			printf("closing....\n");

		}
		else{

			printf("Invalid operation...\n");
		}





	}

	serialport_close(port);







	return 0;
}
void menu() {
	printf("WELCOME TO GTU ARDUINO LAB\nSTUDENT NAME: COŞKUN HASAN ŞALTU\nPLEASE SELECT FROM THE FOLLOWING\nMENU :\n(1) TURN ON LED ON ARDUINO\n(2) TURN OFF LED ON ARDUINO\n(3) FLASH ARDUINO LED 3 TIMES\n(4) SEND A NUMBER TO ARDUINO TO COMPUTE SQUARE BY ARDUINO(YOU SHOULD THE NUMBER İN 10 SECOND!)\n(0) EXIT\n");

}

#define rccahblenR *((unsigned volatile int *)0x40023830)//derste yaptigimiz led tanimlamalari//
#define gpiodmask 1<<3
#define gpiodModr *((unsigned volatile int *)0x40020c00)

#define gpiodP14mask 1<<28
#define gpiodP13mask 1<<26
#define gpiodOdr  *((unsigned volatile int *)0x40020c14)
#define gpiodP14onmask 1<<14
#define gpiodP14ofmask 0<<14
#define gpiodP13onmask 1<<13
#define gpiodP13ofmask ~(1<<13)


#define gpiodP12mask 1<<24  //isim=omer=111 109 101 114 =435 mod(4)=3//
#define gpiodP12onmask 1<<12//soyisim=kucuk=107 117 99 117 107  =547 mod(4)=3//
#define gpiodP12ofmask 0<<12

//green 12   turuncu 13  kırmızı 14   mavi 15
//
void init_leds ();
void init_leds(){

	rccahblenR = gpiodmask;
		gpiodModr=gpiodP12mask;//yesil renk//

}

void delayt1();//1 delay//
void delayt1(){

for(int i=0;i<4000000;i++){

}
}

void delayt2();//2 delay//
void delayt2(){
for(int j=0;j<2000000;j++){

}
}

void turn_name_on();
void turn_name_on(){

	gpiodOdr=gpiodP12onmask; //isim ac yesil//
	delayt1();
}

void turn_name_off();
void turn_name_off(){

	gpiodOdr=gpiodP12ofmask; // isim kapa yesil //
	delayt1();
}

void turn_surname_on();
void turn_surname_on(){
	gpiodOdr|=gpiodP12onmask; // soyisim ac yesil //
	delayt2();
}

void turn_surname_off();
void turn_surname_off(){
	gpiodOdr&=gpiodP12ofmask; // soyisim kapa yesil //
	 delayt2();
}



// isim omer 4 kez       soyisim kucuk 5 kez//
int main() {

	int count1=0;
	int count2=0;

			init_leds();

	    delayt1();
	  while(count1<4){
	       turn_name_on();
	       turn_name_off();
	       count1 ++;
	    }

	      delayt2();
	       while(count2<5){
	        turn_surname_on();
	        turn_surname_off();
            count2++;

	    }return 0;
}






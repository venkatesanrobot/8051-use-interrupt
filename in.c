// File Name: interrupt
// Author: R.venkatesan
// lcd 16X2 8bit method 
 // lcd pin connection port0 -data pin (D0-D7)
 // control pin lcd conection  RS=P2^7, R/W=P2^6, E=P2^5
 

# include <reg51.h>
# include <stdio.h>
# include "lcd.h"  // lcd library 
/* if want change the lcd pin connection open lcd file library change the pin as per your aspect 
 And also remain you change busy flag= bf(used name in lcdlibrary ) also for inlcd pin data  lcd file libary  */


void ex_0() interrupt 0
{ 
     lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string(" interrupt 0"); // write your own word in double quotes
		 delay(100); // delay for seen the lcd lines display
}
void ex_2() interrupt 2
{ 
     lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string(" interrupt 1"); // write your own word in double quotes
		 delay(100); // delay for seen the lcd lines displa
	} 


 void main()
 {
  port(); // pulldown the all pin in micro controller
	lcd_initial(); // lcd basic initialization cammand line 
	 
	
	 EA=1; // enable global the interrupt
	 EX0=1;  // use interrupt 0
	 EX1=1; // use interrupt 1
	 
	 // both interrupt are falling edge interrupt
	 
	 while(1)
	 {
	   lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string("wait interrupt"); // write your own word in double quotes
		 
		 lcd_com (0xc0);  // lcd cammand dispaly second line
		 lcd_string("scanning ");  // write your own word in double quotes
		 
		  delay(100); // delay for seen the lcd lines display
		 check(); // checking interrupt occur 
	 }
		 
 }
	
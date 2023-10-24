#include <stdio.h>
#include<stdlib.h>

int main() {

   // Replace these variables with sensor pins and setup environment
      int main_switch;//Replace with GPIO pin connected to switch pin 
      int gas_level;// Replace with the GPIO pin connected to sensor's digital out pin
      int buzzer=0; // Replace with the GPIO pin connected to the buzzer
      int buzzer_reg = buzzer*4;
      int led=0; //Replace with GPIO pin connected to the LED
      int led_reg = led *8;
      int mask1 = 0xFFFFFFF3;
      int test,test1,test2,test3,test4;

  
    	    
 asm volatile(
	
	"and x30, x30, %2\n\t"	 
	"or x30, x30, %0\n\t" 
	"or x30, x30, %1\n\t"
	:
	:"r"(buzzer_reg), "r"(led_reg), "r"(mask1)
	:"x30"
      );


	
	 asm volatile(
		"addi x30, x30, 0\n\t"
		:"=r"(test)
		:
		:"x30"
	);
	
	
 	printf("Test = %d\n",test);
        printf("gas_value = %d, main_switch=%d, buzzer = %d, led=%d\n", gas_level,main_switch, buzzer_reg,led_reg);
        
	printf("Inside while 1\n");
	
	
	
    	
int z;
for(z=0;z<1;z++)

  //while(1) 
  {
 


   

	  asm volatile(
        	"andi %0, x30, 1\n\t"
	        :"=r"(main_switch)
		:
		:
 	);

  

	asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(test1)
    	:
    	:"x30"
    	);
    	printf("test1 = %d\n",test1);
        
	 
	
	 

         main_switch = 1;
      if (main_switch) {

              //gas_level = digital_read(0);

              printf("entering inner if loop\n");

             

		asm volatile(
        		"andi %0, x30, 2\n\t"
			:"=r"(gas_level)
        		:
        		:
	 	);

  
  
 	        asm volatile(
    		  "addi %0, x30, 0\n\t"
    		  :"=r"(test2)
    		  :
    		  :"x30"
    		);
	        printf("test2 = %d\n",test2);
	

 

              gas_level =1;
	        if(gas_level){
              // Simulate activating the buzzer (replace with actual buzzer control)
              // buzzer = digitalwrite(1);
              // led = digitalwrite(1);
            // printf("Buzzer is ON\n");
	
	            buzzer = 1;
	            led = 1;
  	
	  } 

	  
	  else {
          
          
                    
              // Simulate deactivating the buzzer (replace with actual buzzer control)
              // buzzer = digitalWrite(1)
              // led = digitalWrite(1)
              //printf("Buzzer is OFF\n");

	    buzzer = 0;
	    led=0;	
	    
  asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(test3)
    	:
    	:"x30"
    	);
    	printf("test3 = %d\n",test3);
    	
    	
	   
            }
	 
	    
	  


//Correspondingly update registers for buzzer and led
    
	buzzer_reg = buzzer*4;
	led_reg = led*8;


	asm volatile(
	    "and x30, x30, %2\n\t"
	    "or x30, x30, %0 \n\t"
            "or x30, x30, %1 \n\t"
	    :
	    :"r"(buzzer_reg), "r"(led_reg), "r"(mask1)
            :"x30"
          );	 
          
          
          
          
          
  asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(test4)
    	:
    	:"x30"
    	);
    	printf("Test4 = %d\n",test4);
    printf("gas_level = %d, main_switch=%d,buzzer = %d,  led=%d\n",gas_level,main_switch,buzzer_reg,led_reg);



        }

 } 

 return 0;

}
  

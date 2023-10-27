# Gas Leakage Detector



## Problem Statement

LPG is an essential need of every household, its leakage could lead to a disaster. To alert on LPG leakage and prevent any mishaps there is a need to detect the leakage and warn people of the same.  Bursting cylinders and accidental fires have caused lots of harm to the economies in the past. This circuit triggers the alert system when smoke or gas leakage is detected. Here we have developed gas detector alarm. If gas leakage occurs, this system detects it and alerts people by buzing the buzzer attached with the circuit. These kinds of alert systems are used in modern buildings, schools, hotels, hospitals etc for sensing the flammable gases and thus preventing a major accident.

## Aim

Now that the problem is established, the solution would be to design a detector system. This circuit triggers the alert system when smoke or gas leakage is detected. The circuit mainly uses the MQ135 Gas sensor to detect and smoke and gas leak. This MQ135 gas sensor is sensible to LPG, Alcohol, and Methane etc. This is then interfaced with our RISCV processor to make it all the more efficient. 
The functionality is to detect when a  gas leakage occurs, which is done by our sensor and then correspondingly based on the safe value, the processor triggers an alarm (in this case a buzzer) to immediately alert the users of a gas leak. 

## Materials Required

The MQ135 Gas sensor detects the presence of a dangerous LPG leak in your car or in a service station, storage tank environment. The sensor has excellent sensitivity combined with the quick response time. The MQ-3 gas sensor has a lower conductivity to clean the air as a gas sensing material. In the atmosphere we can find polluting gases, but the conductivity of gas sensor increases as the concentration of polluting gas increases. MQ-135 gas sensor can be implemented to detect the smoke, benzene, steam and other harmful gases. It has the potential to detect different harmful gases. It is with low cost and particularly suitable for Air quality monitoring applications.The sensor can also sense iso-butane, propane, LNG, and cigarette smoke etc. Based on the enviroment where this application is needed any of the following sensors in the table below can be utilized.

The digital output pin of the sensor can be used to detect harmful gases in the environment. The sensitivity of the digital pin can be controlled by using the 10k potentiometer. If the gas is detected the indicator LED D0 will turn on and the digital pin will go from logic high to logic low (0V). The LM393 Op-Amp Comparator IC is used to compare the actual gas value with the value set using the potentiometer. If the actual gas value increases than the set value then the digital output pin gets low.

Because of the onboard LM393 comparator IC the MQ135 Gas sensor module can also be used without the need of an external microcontroller. Simply power up the module and set the sensitivity of the digital pin using the potentiometer, then when the module detects the gas the digital pin will go low. This digital pin can directly be used to drive a buzzer or LED with the help of simple transistors.

```

    Model	Object detected	
    MQ-2	Methane, butane, LPG, humus	5V
    MQ-3	alcohol, ethanol, smoke	5V
    MQ-303A	alcohol, ethanol, smoke	0.9V
    MQ-4	Methane, compressed natural gas (CNG)	5V
    MQ-5	Gas natural, GLP	5V
    MQ-6	Butano, GLP	5V
    MQ-306A	Butano, GLP	0.9V
    MQ-7	Carbon monoxide	Alternate 5V and 1.4V
    MQ-307A	Carbon monoxide	Alternate 0.2 and 0.9V
    MQ-8	Hydrogen	5V
    MQ-9	Carbon monoxide, flammable gases	Alternate 5V and 1.5V
    MQ-309A	Carbon monoxide, flammable gases	Alternate 0.2 and 0.9V
    MQ-131	Ozone	6V
    MQ-135	benzene, alcohol, smoke, air quality	5V
    MQ-136	hydrogen sulfide	5V
    MQ-137	Ammonia	5V
    MQ-138	benzene, toluene, alcohol, acetone,
    propane, formaldehyde, hydrogen	5V
    MQ-214	Methane, natural gas	5V
    MQ-216	natural gas, coal gas	6V
    MG-811	Carbon dioxide	6V

```

## Circuit diagrams

The digital pin D0 of the sensor will be used to read data by the processor.
If the gas is detected the indicator LED D0 will turn on and the digital pin will go from logic high to logic low (0V). The LM393 Op-Amp Comparator IC is used to compare the actual gas value with the value set using the potentiometer. If the actual gas value increases than the set value then the digital output pin gets low. This digital pin can directly be used to drive a buzzer or LED.


![GAS SENSOR](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/deef7303-134b-40d8-be01-91071a11c288)



This is the arduino implementation of the same :
![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/4677b269-8b42-47bb-ab7f-14cb14784cae)

But for this project, the implementation would be using a riscv core and as of now we would not be using an LCD module.





## C program

```
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
      //int test,test1,test2,test3,test4;

  
    	    
 asm volatile(
	
	"and x30, x30, %2\n\t"	 
	"or x30, x30, %0\n\t" 
	"or x30, x30, %1\n\t"
	:
	:"r"(buzzer_reg), "r"(led_reg), "r"(mask1)
	:"x30"
      );


	
	/* asm volatile(
		"addi x30, x30, 0\n\t"
		:"=r"(test)
		:
		:"x30"
	);
	
	
 	printf("Test = %d\n",test);
        printf("gas_value = %d, main_switch=%d, buzzer = %d, led=%d\n", gas_level,main_switch, buzzer_reg,led_reg);
        
	printf("Inside while 1\n");
	*/
	
	
    	
//int z;
//for(z=0;z<1;z++)

  //while(1) 
  {
 


   

	  asm volatile(
        	"andi %0, x30, 1\n\t"
	        :"=r"(main_switch)
		:
		:
 	);

  
/*
	asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(test1)
    	:
    	:"x30"
    	);
    	printf("test1 = %d\n",test1);
        
	 */
	
	 

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

  
  
 	     /*   asm volatile(
    		  "addi %0, x30, 0\n\t"
    		  :"=r"(test2)
    		  :
    		  :"x30"
    		);
	        printf("test2 = %d\n",test2);
	
*/
 

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
	    
/*  asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(test3)
    	:
    	:"x30"
    	);
    	printf("test3 = %d\n",test3);
    	
    	*/
	   
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
          
          
          
/*          
          
  asm volatile(
    	"addi %0, x30, 0\n\t"
    	:"=r"(test4)
    	:
    	:"x30"
    	);
    	printf("Test4 = %d\n",test4);
    printf("gas_level = %d, main_switch=%d,buzzer = %d,  led=%d\n",gas_level,main_switch,buzzer_reg,led_reg);

*/

        }

 } 

 return 0;

}
  

  

          
```

This code is tested and verified.

<img width="1440" alt="Screenshot 2023-10-02 at 11 20 47 PM" src="https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8f3a057e-adfb-41c1-93ed-97758767eed4">



## Code conversion to assembly


Commands used to convert C to assembly:
Navigate into the directory where the toolchain is installed ```cd riscv_toolchain```

```

riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib -o ./out gas.c
riscv64-unknown-elf-objdump -d  -r out > gas_assembly.txt

```

Thus this is the obtained assembly code for our program.



```


out:     file format elf32-littleriscv


Disassembly of section .text:

00010054 <main>:
   10054:	fd010113          	addi	sp,sp,-48
   10058:	02812623          	sw	s0,44(sp)
   1005c:	03010413          	addi	s0,sp,48
   10060:	fe042623          	sw	zero,-20(s0)
   10064:	fec42783          	lw	a5,-20(s0)
   10068:	00279793          	slli	a5,a5,0x2
   1006c:	fef42223          	sw	a5,-28(s0)
   10070:	fe042423          	sw	zero,-24(s0)
   10074:	fe842783          	lw	a5,-24(s0)
   10078:	00379793          	slli	a5,a5,0x3
   1007c:	fef42023          	sw	a5,-32(s0)
   10080:	ff300793          	li	a5,-13
   10084:	fcf42e23          	sw	a5,-36(s0)
   10088:	fe442783          	lw	a5,-28(s0)
   1008c:	fe042703          	lw	a4,-32(s0)
   10090:	fdc42683          	lw	a3,-36(s0)
   10094:	00df7f33          	and	t5,t5,a3
   10098:	00ff6f33          	or	t5,t5,a5
   1009c:	00ef6f33          	or	t5,t5,a4
   100a0:	001f7793          	andi	a5,t5,1
   100a4:	fcf42c23          	sw	a5,-40(s0)
   100a8:	fd842783          	lw	a5,-40(s0)
   100ac:	fe078ae3          	beqz	a5,100a0 <main+0x4c>
   100b0:	002f7793          	andi	a5,t5,2
   100b4:	fcf42a23          	sw	a5,-44(s0)
   100b8:	fd442783          	lw	a5,-44(s0)
   100bc:	00078c63          	beqz	a5,100d4 <main+0x80>
   100c0:	00100793          	li	a5,1
   100c4:	fef42623          	sw	a5,-20(s0)
   100c8:	00100793          	li	a5,1
   100cc:	fef42423          	sw	a5,-24(s0)
   100d0:	00c0006f          	j	100dc <main+0x88>
   100d4:	fe042623          	sw	zero,-20(s0)
   100d8:	fe042423          	sw	zero,-24(s0)
   100dc:	fec42783          	lw	a5,-20(s0)
   100e0:	00279793          	slli	a5,a5,0x2
   100e4:	fef42223          	sw	a5,-28(s0)
   100e8:	fe842783          	lw	a5,-24(s0)
   100ec:	00379793          	slli	a5,a5,0x3
   100f0:	fef42023          	sw	a5,-32(s0)
   100f4:	fe442783          	lw	a5,-28(s0)
   100f8:	fe042703          	lw	a4,-32(s0)
   100fc:	fdc42683          	lw	a3,-36(s0)
   10100:	00df7f33          	and	t5,t5,a3
   10104:	00ff6f33          	or	t5,t5,a5
   10108:	00ef6f33          	or	t5,t5,a4
   1010c:	f95ff06f          	j	100a0 <main+0x4c>

```



## Instruction Counter

The Assembly Instruction Counter is a Python script designed to analyze RISC-V assembly code files generated by the RISC-V GNU toolchain. It counts the number of different instructions used in the code and lists those instructions. This tool can be helpful in understanding the diversity of instructions within your assembly code.

Download: Place the sample_assembly.txt assembly code file in the same directory as the Python script (instruction_counter.py).

Run the Script: Open a terminal or command prompt and navigate to the directory containing the script and the assembly code file. Run the following command:
```
  python3 instruction_counter.py
```

Number of different instructions used. The script will process the assembly code file and display the number of different instructions used along with a list of those instructions.

```

Number of different instructions: 10
List of unique instructions:
or
lw
beqz
sw
and
j
slli
li
addi
andi



```


![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/1fd13dd2-5e6b-4ffb-b5b6-2608f53750f9)



## Simulation using Spike 

Simulate the C code as in the ```spike_sim.c``` file using spike simulator with the following commands:

```
riscv64-unknown-elf-gcc -march=rv64i -mabi=lp64 -ffreestanding -o out gas_leak.c
spike pk out
```

__Results:__

When the main switch is on and then the sensor pin is also high, it means that both the buzzer and led should turn on. 
Because of the masking operation being performed, the test4 value is set to 1100 as inputs are being masked; similarly the buffer_reg is 4 or 100 which is due to shiting and masking. By the same logic, the led_reg is 8 or 1000 due to the effects of shifting and masking.

Test is the case where all the input and output pins are reset to 0. 

To obtain test1 value, the while(1) loop is entered but yet no input values are read. 

To obtain test 2 value, the inner if loop of the C code is entered because, the main_switch value was read to be 1. 

To obtain test 3 value, the else condition must be satisfied which as per the inputs given here is not, hence test3 is not displayed. 

Finally the value of test4 is obtained by writing the values into our output pins, which is 11 as per our functionality. Masking the input bits we have 1100 as our test4 value which is in decimal 12


![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/285a7319-7594-419a-bc6f-92867c816eac)

When the main switch is on and then the sensor pin is low it means that both the buzzer and led should turn off as is obtained below. 

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/d8577cce-7781-47c3-a43a-20c24c264fa0)



## Functional Simulation

We will perform functional simulation to test the functionality of the verilog code generated for the processor chip. We have tested the processor and its functionality for various input combinations and compare the output generated with the desired expected output. 

For inputs 11 ie, main_switch and gas_sensor_pin being high the corresponding output is also 11 ie both buzzer and led must turn on.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/d8b3cd90-da08-4c1b-92e7-7a01a3cd47d6)

Since we are performing masking, t the output is first 00 then goes to 01 and finally settles at 11 These intermediateglitches are because of masking process being performed.

For inputs 00, all the output pins are 00 as well.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/5d59e63e-ee02-48b4-8850-1b1a0e3cced4)


For inputs 10, the output pins must still be 00. Because if no gas is detected then both buzzer and led should be off.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/34f45ddd-edb1-450c-af6c-bae2f49c6407)

For inputs 01, the output pins must still be 00. Because if no gas is detected then both buzzer and led should be off.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/28469de5-e22c-437c-a2da-ae268ea1881a)


We have seen a few cases and verified the output. We can observe the instruction decode bit toggling and the input can be seen in the input_gpio_pins the output has been written in the output_gpio_pins. We can also observe the write_done being flagged once the output has been written. After write_done=1, ID is begun and the PC increments. Thus we can conclude the processor code is working as expected and we can now move ahead with the synthesis and Gate level simulations. 


## Verifying Instructions 

The first instruction of our assembly is with the stack pointer ``` addi	sp,sp,-48```. The register file x45 is the stack pointer and we see the addi operation being perfomed on it.
The initial value of SP is FF which changes to CF after performing the operation.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/55649919-dc13-4bb2-b57b-cfc683977730)


Next  we have instruction ``` li	a5,-13``` in the register file x58. Here after this operation is being performed.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/467a3a5c-0c4a-4ac2-ac8a-887cc5a1b567)





## Acknowledgement

### Special Mention

Grateful to Mr Kunal Ghosh, Co-Founder, VLSI SYSTEM DESIGN for providing an excellent platform to learn and expand our skills on a custom RISCV architecture design and ensuring that the learning process remained smooth. 

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Alwin Shaju, IIITB
- Mayank Kabra, IIITB



## References

https://github.com/SakethGajawada/RISCV_GNU

https://circuitdigest.com

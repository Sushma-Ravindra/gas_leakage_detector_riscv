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

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/ba13d7cb-9940-436f-9809-c0055e7e93ca)



This is the arduino implementation of the same :
![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/4677b269-8b42-47bb-ab7f-14cb14784cae)

But for this project, the implementation would be using a riscv core and as of now we would not be using an LCD module.





## C program

```
  void monitorgaslevel();
void detect_gas_level();


 int main() {
      while (1) {

          detect_gas_level();
      }
      return 0;
  }



// Function monitoring gas levels using sensor module
   // Replace these variables with sensor pins and setup environment

  void monitorgaslevel() {
      int gas_level;// Replace with the GPIO pin connected to sensor's digital out pin
      int buzzer=0; // Replace with the GPIO pin connected to the buzzer
      int buzzer_reg = buzzer*2;

  
    	    
  asm volatile(
	"or x30, x30, %0\n\t" 
	:
	:"r"(buzzer_reg)
	:"x30"
	);

  asm volatile(
        "andi %0, x30, 1\n\t"

        :"=r"(gas_level));

   
  
   
  
          if (gas_level == 1) {

              //gas_level = digital_read(0);

	
  
              // buzzer = digitalwrite(1);
              //printf("Buzzer is ON\n");
	
	buzzer = 1;
  	buzzer_reg = buzzer*2;
  	
	asm volatile(
	  "or x30, x30,%0 \n\t"
          :
	  :"r"(buzzer_reg)
          :"x30"
          );
	 





          } else {
          
          
          //gas_level = digital_read(0);

	
          
          
              // Simulate deactivating the buzzer (replace with actual buzzer control)
              // buzzer = digitalWrite(1)
              //printf("Buzzer is OFF\n");

	buzzer = 0;
	buzzer_reg = buzzer*2;
	
	asm volatile(
	"or x30, x30,%0 \n\t"
        :
	:"r"(buzzer_reg)
        :"x30"
        );
	 


          }
      }
  
  
  void detect_gas_level() {
      monitorgaslevel();
  }
  
 
          
```

This code is tested and verified.

<img width="1440" alt="Screenshot 2023-10-02 at 11 20 47 PM" src="https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8f3a057e-adfb-41c1-93ed-97758767eed4">



## Code conversion to assembly


Commands used to convert C to assembly:

```
/home/sushma/riscv32-toolchain/bin/riscv32-unknown-elf-gcc -march=rv32i -mabi=ilp32 -ffreestanding -nostdlib -o ./out gas.c
/home/sushma/riscv32-toolchain/bin/riscv32-unknown-elf-objdump -d -r out > assembly.txt

```

Thus this is the obtained assembly code for our program.



```


out:     file format elf32-littleriscv


Disassembly of section .text:

00010074 <main>:
   10074:	ff010113          	add	sp,sp,-16
   10078:	00112623          	sw	ra,12(sp)
   1007c:	00812423          	sw	s0,8(sp)
   10080:	01010413          	add	s0,sp,16
   10084:	088000ef          	jal	1010c <detect_gas_level>
   10088:	ffdff06f          	j	10084 <main+0x10>

0001008c <monitorgaslevel>:
   1008c:	fe010113          	add	sp,sp,-32
   10090:	00812e23          	sw	s0,28(sp)
   10094:	02010413          	add	s0,sp,32
   10098:	fe042623          	sw	zero,-20(s0)
   1009c:	fec42783          	lw	a5,-20(s0)
   100a0:	00179793          	sll	a5,a5,0x1
   100a4:	fef42423          	sw	a5,-24(s0)
   100a8:	fe842783          	lw	a5,-24(s0)
   100ac:	00ff6f33          	or	t5,t5,a5
   100b0:	001f7793          	and	a5,t5,1
   100b4:	fef42223          	sw	a5,-28(s0)
   100b8:	fe442703          	lw	a4,-28(s0)
   100bc:	00100793          	li	a5,1
   100c0:	02f71263          	bne	a4,a5,100e4 <monitorgaslevel+0x58>
   100c4:	00100793          	li	a5,1
   100c8:	fef42623          	sw	a5,-20(s0)
   100cc:	fec42783          	lw	a5,-20(s0)
   100d0:	00179793          	sll	a5,a5,0x1
   100d4:	fef42423          	sw	a5,-24(s0)
   100d8:	fe842783          	lw	a5,-24(s0)
   100dc:	00ff6f33          	or	t5,t5,a5
   100e0:	01c0006f          	j	100fc <monitorgaslevel+0x70>
   100e4:	fe042623          	sw	zero,-20(s0)
   100e8:	fec42783          	lw	a5,-20(s0)
   100ec:	00179793          	sll	a5,a5,0x1
   100f0:	fef42423          	sw	a5,-24(s0)
   100f4:	fe842783          	lw	a5,-24(s0)
   100f8:	00ff6f33          	or	t5,t5,a5
   100fc:	00000013          	nop
   10100:	01c12403          	lw	s0,28(sp)
   10104:	02010113          	add	sp,sp,32
   10108:	00008067          	ret

0001010c <detect_gas_level>:
   1010c:	ff010113          	add	sp,sp,-16
   10110:	00112623          	sw	ra,12(sp)
   10114:	00812423          	sw	s0,8(sp)
   10118:	01010413          	add	s0,sp,16
   1011c:	f71ff0ef          	jal	1008c <monitorgaslevel>
   10120:	00000013          	nop
   10124:	00c12083          	lw	ra,12(sp)
   10128:	00812403          	lw	s0,8(sp)
   1012c:	01010113          	add	sp,sp,16
   10130:	00008067          	ret
	

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
Number of different instructions: 12
List of unique instructions:
li
sw
lw
or
and
sll
nop
ret
bne
j
add
jal

```

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/e72aa393-9713-485f-a14d-472a6a3ad638)



## Acknowledgement

### Special Mention

Grateful to Mr Kunal Ghosh, Co-Founder, VLSI SYSTEM DESIGN for providing an excellent platform to learn and expand our skills on a custom RISCV architecture design and ensuring that the learning process remained smooth. 

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra, IIITB


## References

https://github.com/SakethGajawada/RISCV_GNU

https://circuitdigest.com

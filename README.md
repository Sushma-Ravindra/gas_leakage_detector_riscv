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

   
  
      while (1) {
  
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
	/home/sushma/riscv32-toolchain/bin/riscv32-unknown-elf-gcc -c -march=rv32i -mabi=ilp32 -ffreestanding -o ./gas.o gas.c

	/home/sushma/riscv32-toolchain/bin/riscv32-unknown-elf-objdump -d  gas.o > gas_assembly.txt

```

Thus this is the obtained assembly code for our program.



```
	    
	gas.o:     file format elf32-littleriscv
	
	
	Disassembly of section .text:
	
	00000000 <main>:
	   0:	ff010113          	add	sp,sp,-16
	   4:	00112623          	sw	ra,12(sp)
	   8:	00812423          	sw	s0,8(sp)
	   c:	01010413          	add	s0,sp,16
	
	00000010 <.L2>:
	  10:	00000097          	auipc	ra,0x0
	  14:	000080e7          	jalr	ra # 10 <.L2>
	  18:	ff9ff06f          	j	10 <.L2>
	
	0000001c <monitorgaslevel>:
	  1c:	fe010113          	add	sp,sp,-32
	  20:	00812e23          	sw	s0,28(sp)
	  24:	02010413          	add	s0,sp,32
	  28:	fe042623          	sw	zero,-20(s0)
	  2c:	fec42783          	lw	a5,-20(s0)
	  30:	00179793          	sll	a5,a5,0x1
	  34:	fef42423          	sw	a5,-24(s0)
	  38:	fe842783          	lw	a5,-24(s0)
	  3c:	00ff6f33          	or	t5,t5,a5
	  40:	001f7793          	and	a5,t5,1
	  44:	fef42223          	sw	a5,-28(s0)
	
	00000048 <.L6>:
	  48:	fe442703          	lw	a4,-28(s0)
	  4c:	00100793          	li	a5,1
	  50:	02f71263          	bne	a4,a5,74 <.L4>
	  54:	00100793          	li	a5,1
	  58:	fef42623          	sw	a5,-20(s0)
	  5c:	fec42783          	lw	a5,-20(s0)
	  60:	00179793          	sll	a5,a5,0x1
	  64:	fef42423          	sw	a5,-24(s0)
	  68:	fe842783          	lw	a5,-24(s0)
	  6c:	00ff6f33          	or	t5,t5,a5
	  70:	fd9ff06f          	j	48 <.L6>
	
	00000074 <.L4>:
	  74:	fe042623          	sw	zero,-20(s0)
	  78:	fec42783          	lw	a5,-20(s0)
	  7c:	00179793          	sll	a5,a5,0x1
	  80:	fef42423          	sw	a5,-24(s0)
	  84:	fe842783          	lw	a5,-24(s0)
	  88:	00ff6f33          	or	t5,t5,a5
	  8c:	fbdff06f          	j	48 <.L6>
	
	00000090 <detect_gas_level>:
	  90:	ff010113          	add	sp,sp,-16
	  94:	00112623          	sw	ra,12(sp)
	  98:	00812423          	sw	s0,8(sp)
	  9c:	01010413          	add	s0,sp,16
	  a0:	00000097          	auipc	ra,0x0
	  a4:	000080e7          	jalr	ra # a0 <detect_gas_level+0x10>
	  a8:	00000013          	nop
	  ac:	00c12083          	lw	ra,12(sp)
	  b0:	00812403          	lw	s0,8(sp)
	  b4:	01010113          	add	sp,sp,16
	  b8:	00008067          	ret     
     

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
	Number of different instructions: 13
	List of unique instructions:
	and
	li
	bne
	or
	sw
	j
	lw
	auipc
	add
	sll
	ret
	nop
	jalr

  

```

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/0c6fb2c5-60c7-4b72-855e-f4e23cd5b565)



## Acknowledgement

### Special Mention

Grateful to Mr Kunal Ghosh, Co-Founder, VLSI SYSTEM DESIGN for providing an excellent platform to learn and expand our skills on a custom RISCV architecture design and ensuring that the learning process remained smooth. 

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra, IIITB


## References

https://github.com/SakethGajawada/RISCV_GNU

https://circuitdigest.com

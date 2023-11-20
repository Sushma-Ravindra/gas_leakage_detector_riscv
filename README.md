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

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/6f57cca9-6d49-405a-96f2-99a211117ab3)


__Here, in the above image note that the output is changing to 11 only after the instructions are being decoded at a specific ID stage as shown below and does not change simultaneously with input change.__
 ``` 1010c:	f95ff06f          	j	100a0 <main+0x4c>```

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


## Gate Level Simulation (GLS) 

### Synthesis

Yosys is a Verilog HDL synthesis tool. This means that it takes a behavioural design description as input and generates an RTL, logical gate or physical gate level description of the design as output. Yosys' main strengths are behavioural and RTL synthesis. Yosys is made use of here to generate the netlist.

The idea of GLS is to generate the simulation output by running test bench which was designed with the initial verilog processor with netlist file generated from synthesis as design under test. Netlist is essentially supposed to be the same as RTL code, therefore, same test bench can be used for it. We perform this to verify logical correctness of the design after synthesizing it. Also ensuring the timing of the design is met. Folllowing are the commands to we need to convert Rtl code to netlist in yosys for that commands are :


```
read_liberty -lib sky130_fd_sc_hd__tt_025C_1v80_256.lib 
read_verilog processor.v 
synth -top wrapper
dfflibmap -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib 
abc -liberty sky130_fd_sc_hd__tt_025C_1v80_256.lib
write_verilog synth_processor_test.v

```


![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/f79f38c8-924f-4d69-b48f-3c28d8dc0ba8)


The logic of the processor (synth_processor_test) will be realizable using gates in the sky130_fd_sc_hd__tt_025C_1v80_256.lib file.

Below is the snippet showing the synthesis results and synthesized circuit for wrapper module in the processor. ```show wrapper```

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/a9d0734f-88ca-4ec4-b918-05a06f8e6d2b)


Verifying the functionality of the newly generated netlist using iverilog.

```
iverilog -o test synth_processor_test.v testbench.v sky130_sram_1kbyte_1rw1r_32x256_8.v sky130_fd_sc_hd.v primitives.v

```

TEST CASE 1: 

INPUT 11: As per function, when main switch and sensor output is high then the buzzer and led must turn on ie Output 11 as seen below and is verified with the functional simulation result.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/de2fa2ce-b2e9-481e-9b74-d41d6a0cdb5b)

Here, note that the output is changing to 11 only after the instructions are being decoded at a specific ID stage as shown below and does not change simultanwously with input change. 

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/6f57cca9-6d49-405a-96f2-99a211117ab3)

TEST CASE 2: 

INPUT 10:  As per function, when main switch is high and sensor output is low then the buzzer and led must turn off ie Output 00 as seen below and is verified with the functional simulation result 

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/d8ea71db-4a3b-49ca-a74f-2cfd52acc054)


## PHYSICAL DESIGN FLOW

ASIC flow: RTL TO GSDII flow: Synthesis -> Floor and PowerPlan -> Placement -> Clock Tree Synthesis -> Routing -> SignOff (Tapeout)

Synthesis: RTL to gate level Netlist. FloorPLan: Patrition and pinrows ets. Powerpin connections to rails PLacement: Alignment- Global and Detailed CTS: Clock Network design Routing: Implement Interconnect using metal layers, Global and deayled routing GDSII: DRC,LVS,STA and tapeout.

Challenges with Open Source Tools: Configuration, Calibration and some missing tools can be encountered while building an ASIC chip which must be effectively dealt with.

OpenLane and STrive Chipsets

Skywater PDK is used. Openlane provides a large number ofdesign examples and can be used to harden macros and chips. It is containerized and tuned for skywater130nm pdk.

OpenLane ASIC flow: To build clean GDSII with no human interaction.



![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/66daa344-29c6-460a-b593-cdbfe9b3b4f2)


```
RTL Design (Register-Transfer Level): At this stage, engineers create a high-level description of the desired chip's functionality using a hardware description language like VHDL or Verilog. This description defines how data moves between registers and logic gates in the chip.

Synthesis: The RTL code is synthesized into a gate-level representation. This step transforms the high-level description into a netlist of logic gates that can be implemented in silicon. Optimization techniques are applied to improve performance, power consumption, and area usage.

Floorplanning: Engineers create a layout plan, or floorplan, that specifies where different functional blocks will be placed on the chip. This step considers factors like power distribution and signal routing.

Placement : The synthesized gates are physically placed on the chip according to the floorplan. This step aims to minimize the physical distance between related gates to improve performance.

Routing: Wires are connected between the gates to establish the logical connections defined in the RTL code. This step involves complex algorithms to optimize for speed, power, and area.

Physical Verification : The design is thoroughly checked for issues like timing violations, manufacturing defects, and design rule violations. Tools ensure that the chip will function correctly and be manufacturable.

Mask Generation: The final layout, or mask, is generated based on the design. This mask provides a blueprint for the semiconductor fabrication process.

Manufacturing: The mask is used to manufacture the physical semiconductor wafer in a semiconductor fabrication facility (fab). This involves a series of intricate processes, including photolithography, etching, and doping, to create the actual chip.

Testing: After fabrication, each chip is rigorously tested to identify defects and ensure functionality.

Packaging: The individual chips are packaged into protective casings that include pins or connectors for interfacing with other electronic components.

GDS2 Format: GDS2 is a file format used to represent the final chip layout and mask data. It contains information about the physical layout of the chip, including the positions of gates, wires, and other elements.


```

### Preparing Design

Add the lib files, lef files, source and run folders in the project folder. Make sure the config.json file is in the appropriate path (inside project folder). 
Launch OpenLane. 
Use command ``` prep -design project -verbose 99 ```  if needed. 
```
make mount
%./flow.tcl -interactive
% package require openlane 0.9
% prep -design project 

```
![Screenshot from 2023-11-14 19-19-19](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/3469dc70-df94-41f0-873b-ffa8ff55b9dc)


### Synthesis 

Synthesis is the process of converting RTL code, typically written in hardware description languages like Verilog or VHDL, into a gate-level netlist. It involves mapping the functionality specified in the RTL code to a library of standard cells, such as NAND, NOR, XOR gates, etc., provided by the target technology.
Inputs : RTL, Technology libraries, Constraints (Environment, clocks, IO delays etc.)
Outputs : Netlist , SDC, Reports etc.
GTECH Mapping – Consists of mapping the HDL netlist to generic gates what are used to perform logical optimization based on AIGERs and other topologies created from the generic mapped netlist.
Technology Mapping – Consists of mapping the post-optimized GTECH netlist to standard cells described in the PDK


 ```
	run_synthesis
 ```
![Screenshot from 2023-11-14 19-19-19](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/9cd7c964-7412-4864-9bdf-16b211ba6996)

__Statistics post Synthesis__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/ec3d101c-9671-4812-bbd1-5341a6bb4083)


### Floorplanning 

Floorplanning is the art of any physical design. A well and perfect floorplan leads to an ASIC design with higher performance and optimum area.
Floorplanning can be challenging in that, it deals with the placement of I/O pads and macros as well as power and ground structure.
Before we are going for the floor planning to make sure that inputs are used for floorplan is prepared properly.

Inputs for floorplan:

Netlist (.v)
Technology file (techlef)
Timing Library files (.lib)
Physical library (.lef)
Synopsys design constraints (.sdc)

Floorplan control parameter:
Aspect ratio:  Aspect ratio will decide the size and shape of the chip. It is the ratio between horizontal routing resources to vertical routing resources (or) ratio of height and width.    Aspect ratio = width/height 
Core utilization:- Utilization will define the area occupied by the standard cells, macros, and other cells.If core utilization is 0.8 (80%) that means 80% of the core area is used for placing the standard cells, macros, and other cells, and the remaining 20% is used for routing purposes. 
core utilization = (macros area + std cell area +pads area)/ total core area
Pad placement:In ASIC design three types of IO Pads: Power,Ground,Signal.Generally pad placement and pin placement is done by Top-Level people. It is critical to the functional operation of an ASIC design to ensure that the pads have adequate power and ground connections and are placed properly in order to eliminate electro-migration and current-switching related problems.




![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8c654aa4-229e-4176-9062-db0decfd696e)


```
run_floorplan

```

![Screenshot from 2023-11-14 19-19-19](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8c7bb616-6d14-4f6c-b3b1-1ff13e53315c)


To view the floorplan: Magic is invoked after moving to the results/floorplan directory,then use the follwing command:

```
 cd OpenLane/designs/project/runs/RUN_2023.11.14_12.18.03/results/floorplan
 magic -T /home/sushma/.volare/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def

```

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/6735c8d8-d1ac-471a-8dee-19b955bee942)

__DIE AND CORE AREA POST FLOORPLAN___

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/cb91606c-92bf-48e5-90db-84c8733c9275)

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/51db5df0-48f9-4c16-842f-12237756d388)



## Placement 

Placement is the process of determining the locations of standard cells present in the Netlist by placing these cells inside the core area.
The cells are logically present in the Netlist. Looking at the physical presence of cells in LEF, tool places at the desired location.
Placement of cells are most challenging and important phase in PnR. Good placement leads to good routing.
As we know there are a number of same kind of cells present in the .lib, the tool looks at the logic present in the netlist and pick the cell by taking care of input constraints to meet the trade-off of the design.
During placement, following three stages happens:
Global Placement
Refine Placement (Legalization)
Detailed Placement
The below placement quality checks need to be done to have a place exit and get a qualitative database of placement.
Congestion
Performance (Timing)
Power
Routability
Placement Runtime



```
    run_placement
    
```

![Screenshot from 2023-11-14 19-18-59](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/bdfd8c8a-f6a1-408d-9ae6-bf7f757e13ab)


Navigate to the placemnet directory and invoke magic

```
magic -T /home/sushma/.volare/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &

```
![Screenshot from 2023-11-14 19-15-21](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/67cb2960-7237-41a0-b934-2e9a67236552)




### CTS 

 Clock is not propagated before CTS so after clock tree build in CTS stage we consider hold timings and try to meet all hold violations.

After placement we have position of all standard cells and macros and in placement we have ideal clock (for simplicity we assume that we are dealing with a single clock for the whole design). At the placement optimization stage buffer insertion and gate sizing and any other optimization techniques are used only for data paths but in the clock path nothing we change.

CTS is the process of connecting the clocks to all clock pin of sequential circuits by using inverters/buffers in order to balance the skew and to minimize the insertion delay. All the clock pins are driven by a single clock source. Clock balancing is important for meeting all the design constraints.


```
run_cts

```
![Screenshot from 2023-11-14 19-18-59](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8516f061-39cd-49ff-8815-36ce49cf3725)


#### REPORTS

__AREA__
![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/1af7e7b5-9f24-4046-a590-3361c4506c7f)


__SKEW__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/9ca6fc0d-ad0a-46be-8aa7-f5248a86338a)


__SLACK__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/08bbf6a3-e34d-46f1-99b6-ee33cfa239d4)


__POWER__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/25dbe20a-b68d-4347-8fb1-3014a2074974)


To generate power network after cts 

```
gen_pdn

```

###  Routing 

Routing in VLSI is making physical connections between signal pins using metal layers. Following Clock Tree Synthesis (CTS) and optimization, the routing step determines the exact pathways for interconnecting standard cells, macros, and I/O pins. The layout creates electrical connections using metals and vias that are determined by the logical connections in the netlist (i.e; logical connectivity converted as physical connectivity).

Each metal layer in a grid-based routing system has its tracks and preferred routing direction, which are described in a unified cell in the standard cell library. Routing activities are divided into four steps:

Global routing Global routes assign nets to particular metal layers and global routing cells. The global route aims to avoid crowded global cells while making as few diversions as possible. Global routes also avoid pre-routed P/G, placement, and routing bottlenecks.
    
Detail Routing etail Routing seeks to repair any DRC violations following track assignment using a set size small region (SBox). The detailed routing goes through the whole design box by box until the routing pass is finished.It also performs timing driven routing .

```
run_routing

```
![Screenshot from 2023-11-14 19-09-28](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/404aa889-1b93-44dd-a7f4-3037d6cf79e5)

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/ee705b5c-28d7-441e-924c-5c362c1e06a2)


Invoke magic after navigating to the routing directory 

```
magic -T /home/sushma/.volare/sky130A/libs.tech/magic/sky130A.tech lef read ../../tmp/merged.nom.lef def read wrapper.def &

```

![Screenshot from 2023-11-14 19-16-10](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/79a9c995-7432-4521-bd00-801c869e6ee8)

![Screenshot from 2023-11-14 19-17-01](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/0c81abe5-5228-4701-8a8d-03895b3dd094)

__Area of the design__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/a9c92ef6-2057-47ca-a6be-999821265a1e)


#### Post timing Reports 

__AREA__
![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/aa08a487-0c6b-450a-b834-d3ba91aae6d4)


__SLACK__
![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/265dfc1c-eda1-4f35-966c-a2b6fe1b8609)


__SKEW__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8fd79745-6ee8-4e76-98d4-913b0fa08450)


__POWER__

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/637b446d-82b3-4473-8796-9462466ff213)


#### DRC Checks 

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/a493ca64-30b3-4196-9764-e9ef0b7a0341)


### Performance Calculation 
```

                             	 	   1
	Max Performance =  	------------------------
				clock period - slack(setup)

```

As per this design, clock period of 70ns has a postive slack of 19.88ns post routing. 
Thus the maximum frequency of opeartion is 0.0199GHz.



### Post Routing Reports 




![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/185671fb-7564-4aea-a059-bbef604adfe2)




### RUNS FOLDER 

The files of pnr can be found in the link below:

[runs_folder](https://iiitbac-my.sharepoint.com/:f:/g/personal/sushma_r_iiitb_ac_in/EjeObeGxd3NFmttgPxIB_4sBtI7tEm62rhyeAWR6KBrJCw?e=huabMm)





### Additional Checks

```
run_magic
run_magic_spice_export
run_magic_drc
run_antenna_check

```


![Screenshot from 2023-11-14 21-52-46](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/d589d18a-5616-4f88-8f98-442f4f119c65)


### ASIC FLOW IN OPENLANE 

```

./flow.tcl -interactive
package require openlane 0.9
prep -design project
run_synthesis
run_floorplan
run_placement
run_cts
gen_pdn
run_routing
run_magic
run_magic_spice_export
run_magic_drc
run_antenna_check

```



## Acknowledgement

### Special Mention

Grateful to Mr Kunal Ghosh, Co-Founder, VLSI SYSTEM DESIGN for providing an excellent platform to learn and expand our skills on a custom RISCV architecture design and ensuring that the learning process remained smooth. 

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Alwin Shaju, IIITB
- Mayank Kabra, Founder, Chipcron Pvt. Ltd



## References

https://github.com/SakethGajawada/RISCV_GNU

https://circuitdigest.com

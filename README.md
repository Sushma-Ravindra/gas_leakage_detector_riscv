# Gas Leakage Detector

## Table of contents

__Problem Statement__

LPG is an essential need of every household, its leakage could lead to a disaster. To alert on LPG leakage and prevent any mishaps there is a need to detect the leakage and warn people of the same.  Bursting cylinders and accidental fires have caused lots of harm to the economies in the past. This circuit triggers the alert system when smoke or gas leakage is detected. Here we have developed gas detector alarm. If gas leakage occurs, this system detects it and alerts people by buzing the buzzer attached with the circuit. These kinds of alert systems are used in modern buildings, schools, hotels, hospitals etc for sensing the flammable gases and thus preventing a major accident.

__Aim__

Now that the problem is established, the solution would be to design a detector system. This circuit triggers the alert system when smoke or gas leakage is detected. The circuit mainly uses the MQ135 Gas sensor to detect and smoke and gas leak. This MQ135 gas sensor is sensible to LPG, Alcohol, and Methane etc. This is then interfaced with our RISCV processor to make it all the more efficient. 
The functionality is to detect when a  gas leakage occurs, which is done by our sensor and then correspondingly based on the safe value, the processor triggers an alarm (in this case a buzzer) to immediately alert the users of a gas leak. 

__Materials Required__

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

__Circuit diagrams__

The digital pin D0 of the sensor will be used to read data by the processor.
If the gas is detected the indicator LED D0 will turn on and the digital pin will go from logic high to logic low (0V). The LM393 Op-Amp Comparator IC is used to compare the actual gas value with the value set using the potentiometer. If the actual gas value increases than the set value then the digital output pin gets low. This digital pin can directly be used to drive a buzzer or LED.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/ba13d7cb-9940-436f-9809-c0055e7e93ca)



This is the arduino implementation of the same :
![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/4677b269-8b42-47bb-ab7f-14cb14784cae)

But for this project, the implementation would be using a riscv core and as of now we would not be using an LCD module.





__ C program __

```
         // Function monitoring gas levels using sensor module
           // Replace these variables with sensor pins and setup environment
        
        
          void monitorgaslevel() {
              int gas_level;// Replace with the GPIO pin connected to sensor's digital out pin
              int buzzer; // Replace with the GPIO pin connected to the buzzer
              int buzzer_reg = buzzer*2;
        
                   
           
          
              while (1) {
          
                  if (gas_level == 1) {
        
                      //gas_level = digital_read(0);
        
        	asm(
        	"andi %0, x30, 1\n\t"
        	:"=r"(gas_level));
        
        
        
                      // buzzer = digitalwrite(1);
                      //printf("Buzzer is ON\n");
        	
        	buzzer =1;
          	buzzer_reg = buzzer*2;
        	asm(
        	"or x30, x30,%0 \n\t"
        	:"=r"(buzzer_reg));
        
        	 
        
        
        
        
        
                  } else {
                      // Simulate deactivating the buzzer (replace with actual buzzer control)
                      // buzzer = digitalWrite(1)
                      //printf("Buzzer is OFF\n");
        
        	buzzer = 0;
        	buzzer_reg = buzzer*2;
        	asm(
        	"or x30, x30,%0 \n\t"
        	:"=r"(buzzer_reg));
        	
        
        
                  }
              }
          }
          
          void detect_gas_level() {
              monitorgaslevel();
          }
          
          int main() {
              while (1) {
        
              int gas_level=0;
              int buzzer=0; 
              int buzzer_reg = buzzer*2;
        
           asm(
        	"or x30, x30, %0\n\t"
        	:"=r"(buzzer_reg));
        
        
        
                  detect_gas_level();
              }
              return 0;
          }

```

This code is tested and verified.

<img width="1440" alt="Screenshot 2023-10-02 at 11 20 47 PM" src="https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/8f3a057e-adfb-41c1-93ed-97758767eed4">



__Code conversion to assembly__

The assembly level code for this function can be obtained by the following commands:

Excecute this command to compile using RISC-V GNU Toolchain
```
riscv64-unknown-elf-gcc -01 -mabi=ilp32 -march=rv32i -o ./sample sample.c

```
  Excecute this command to generate assembly instructions file for the function created in the sample.c 

```
  riscv64-unknown-elf-objdump -d sample.o
```


Thus this is the obtained assembly code for our program.



```
         
        sample.o:     file format elf32-littleriscv
        
        
        Disassembly of section .text:
        
        00010074 <register_fini>:
           10074:	ffff0797          	auipc	a5,0xffff0
           10078:	f8c78793          	addi	a5,a5,-116 # 0 <register_fini-0x10074>
           1007c:	00078863          	beqz	a5,1008c <register_fini+0x18>
           10080:	00000517          	auipc	a0,0x0
           10084:	13850513          	addi	a0,a0,312 # 101b8 <__libc_fini_array>
           10088:	0e80006f          	j	10170 <atexit>
           1008c:	00008067          	ret
        
        00010090 <_start>:
           10090:	00002197          	auipc	gp,0x2
           10094:	d1018193          	addi	gp,gp,-752 # 11da0 <__global_pointer$>
           10098:	c3418513          	addi	a0,gp,-972 # 119d4 <_edata>
           1009c:	c5018613          	addi	a2,gp,-944 # 119f0 <__BSS_END__>
           100a0:	40a60633          	sub	a2,a2,a0
           100a4:	00000593          	li	a1,0
           100a8:	204000ef          	jal	ra,102ac <memset>
           100ac:	00000517          	auipc	a0,0x0
           100b0:	10c50513          	addi	a0,a0,268 # 101b8 <__libc_fini_array>
           100b4:	0bc000ef          	jal	ra,10170 <atexit>
           100b8:	160000ef          	jal	ra,10218 <__libc_init_array>
           100bc:	00012503          	lw	a0,0(sp)
           100c0:	00410593          	addi	a1,sp,4
           100c4:	00000613          	li	a2,0
           100c8:	09c000ef          	jal	ra,10164 <main>
           100cc:	0b80006f          	j	10184 <exit>
        
        000100d0 <__do_global_dtors_aux>:
           100d0:	c341c783          	lbu	a5,-972(gp) # 119d4 <_edata>
           100d4:	04079463          	bnez	a5,1011c <__do_global_dtors_aux+0x4c>
           100d8:	ffff0797          	auipc	a5,0xffff0
           100dc:	f2878793          	addi	a5,a5,-216 # 0 <register_fini-0x10074>
           100e0:	02078863          	beqz	a5,10110 <__do_global_dtors_aux+0x40>
           100e4:	ff010113          	addi	sp,sp,-16
           100e8:	00001517          	auipc	a0,0x1
           100ec:	4a850513          	addi	a0,a0,1192 # 11590 <__FRAME_END__>
           100f0:	00112623          	sw	ra,12(sp)
           100f4:	00000097          	auipc	ra,0x0
           100f8:	000000e7          	jalr	zero # 0 <register_fini-0x10074>
           100fc:	00c12083          	lw	ra,12(sp)
           10100:	00100793          	li	a5,1
           10104:	c2f18a23          	sb	a5,-972(gp) # 119d4 <_edata>
           10108:	01010113          	addi	sp,sp,16
           1010c:	00008067          	ret
           10110:	00100793          	li	a5,1
           10114:	c2f18a23          	sb	a5,-972(gp) # 119d4 <_edata>
           10118:	00008067          	ret
           1011c:	00008067          	ret
        
        00010120 <frame_dummy>:
           10120:	ffff0797          	auipc	a5,0xffff0
           10124:	ee078793          	addi	a5,a5,-288 # 0 <register_fini-0x10074>
           10128:	00078c63          	beqz	a5,10140 <frame_dummy+0x20>
           1012c:	c3818593          	addi	a1,gp,-968 # 119d8 <object.5439>
           10130:	00001517          	auipc	a0,0x1
           10134:	46050513          	addi	a0,a0,1120 # 11590 <__FRAME_END__>
           10138:	00000317          	auipc	t1,0x0
           1013c:	00000067          	jr	zero # 0 <register_fini-0x10074>
           10140:	00008067          	ret
        
        00010144 <monitorgaslevel>:
           10144:	00100713          	li	a4,1
           10148:	001f7693          	andi	a3,t5,1
           1014c:	00e79063          	bne	a5,a4,1014c <monitorgaslevel+0x8>
           10150:	00068793          	mv	a5,a3
           10154:	ff9ff06f          	j	1014c <monitorgaslevel+0x8>
        
        00010158 <detect_gas_level>:
           10158:	ff010113          	addi	sp,sp,-16
           1015c:	00112623          	sw	ra,12(sp)
           10160:	fe5ff0ef          	jal	ra,10144 <monitorgaslevel>
        
        00010164 <main>:
           10164:	ff010113          	addi	sp,sp,-16
           10168:	00112623          	sw	ra,12(sp)
           1016c:	fd9ff0ef          	jal	ra,10144 <monitorgaslevel>
        
        00010170 <atexit>:
           10170:	00050593          	mv	a1,a0
           10174:	00000693          	li	a3,0
           10178:	00000613          	li	a2,0
           1017c:	00000513          	li	a0,0
           10180:	2080006f          	j	10388 <__register_exitproc>
        
        00010184 <exit>:
           10184:	ff010113          	addi	sp,sp,-16
           10188:	00000593          	li	a1,0
           1018c:	00812423          	sw	s0,8(sp)
           10190:	00112623          	sw	ra,12(sp)
           10194:	00050413          	mv	s0,a0
           10198:	28c000ef          	jal	ra,10424 <__call_exitprocs>
           1019c:	c2818793          	addi	a5,gp,-984 # 119c8 <_global_impure_ptr>
           101a0:	0007a503          	lw	a0,0(a5)
           101a4:	03c52783          	lw	a5,60(a0)
           101a8:	00078463          	beqz	a5,101b0 <exit+0x2c>
           101ac:	000780e7          	jalr	a5
           101b0:	00040513          	mv	a0,s0
           101b4:	38c000ef          	jal	ra,10540 <_exit>
        
        000101b8 <__libc_fini_array>:
           101b8:	ff010113          	addi	sp,sp,-16
           101bc:	00812423          	sw	s0,8(sp)
           101c0:	00001797          	auipc	a5,0x1
           101c4:	3dc78793          	addi	a5,a5,988 # 1159c <__init_array_end>
           101c8:	00001417          	auipc	s0,0x1
           101cc:	3d840413          	addi	s0,s0,984 # 115a0 <__fini_array_end>
           101d0:	40f40433          	sub	s0,s0,a5
           101d4:	00112623          	sw	ra,12(sp)
           101d8:	00912223          	sw	s1,4(sp)
           101dc:	40245413          	srai	s0,s0,0x2
           101e0:	02040263          	beqz	s0,10204 <__libc_fini_array+0x4c>
           101e4:	00241493          	slli	s1,s0,0x2
           101e8:	ffc48493          	addi	s1,s1,-4
           101ec:	00f484b3          	add	s1,s1,a5
           101f0:	0004a783          	lw	a5,0(s1)
           101f4:	fff40413          	addi	s0,s0,-1
           101f8:	ffc48493          	addi	s1,s1,-4
           101fc:	000780e7          	jalr	a5
           10200:	fe0418e3          	bnez	s0,101f0 <__libc_fini_array+0x38>
           10204:	00c12083          	lw	ra,12(sp)
           10208:	00812403          	lw	s0,8(sp)
           1020c:	00412483          	lw	s1,4(sp)
           10210:	01010113          	addi	sp,sp,16
           10214:	00008067          	ret
        
        00010218 <__libc_init_array>:
           10218:	ff010113          	addi	sp,sp,-16
           1021c:	00812423          	sw	s0,8(sp)
           10220:	01212023          	sw	s2,0(sp)
           10224:	00001417          	auipc	s0,0x1
           10228:	37040413          	addi	s0,s0,880 # 11594 <__init_array_start>
           1022c:	00001917          	auipc	s2,0x1
           10230:	36890913          	addi	s2,s2,872 # 11594 <__init_array_start>
           10234:	40890933          	sub	s2,s2,s0
           10238:	00112623          	sw	ra,12(sp)
           1023c:	00912223          	sw	s1,4(sp)
           10240:	40295913          	srai	s2,s2,0x2
           10244:	00090e63          	beqz	s2,10260 <__libc_init_array+0x48>
           10248:	00000493          	li	s1,0
           1024c:	00042783          	lw	a5,0(s0)
           10250:	00148493          	addi	s1,s1,1
           10254:	00440413          	addi	s0,s0,4
           10258:	000780e7          	jalr	a5
           1025c:	fe9918e3          	bne	s2,s1,1024c <__libc_init_array+0x34>
           10260:	00001417          	auipc	s0,0x1
           10264:	33440413          	addi	s0,s0,820 # 11594 <__init_array_start>
           10268:	00001917          	auipc	s2,0x1
           1026c:	33490913          	addi	s2,s2,820 # 1159c <__init_array_end>
           10270:	40890933          	sub	s2,s2,s0
           10274:	40295913          	srai	s2,s2,0x2
           10278:	00090e63          	beqz	s2,10294 <__libc_init_array+0x7c>
           1027c:	00000493          	li	s1,0
           10280:	00042783          	lw	a5,0(s0)
           10284:	00148493          	addi	s1,s1,1
           10288:	00440413          	addi	s0,s0,4
           1028c:	000780e7          	jalr	a5
           10290:	fe9918e3          	bne	s2,s1,10280 <__libc_init_array+0x68>
           10294:	00c12083          	lw	ra,12(sp)
           10298:	00812403          	lw	s0,8(sp)
           1029c:	00412483          	lw	s1,4(sp)
           102a0:	00012903          	lw	s2,0(sp)
           102a4:	01010113          	addi	sp,sp,16
           102a8:	00008067          	ret
        
        000102ac <memset>:
           102ac:	00f00313          	li	t1,15
           102b0:	00050713          	mv	a4,a0
           102b4:	02c37e63          	bgeu	t1,a2,102f0 <memset+0x44>
           102b8:	00f77793          	andi	a5,a4,15
           102bc:	0a079063          	bnez	a5,1035c <memset+0xb0>
           102c0:	08059263          	bnez	a1,10344 <memset+0x98>
           102c4:	ff067693          	andi	a3,a2,-16
           102c8:	00f67613          	andi	a2,a2,15
           102cc:	00e686b3          	add	a3,a3,a4
           102d0:	00b72023          	sw	a1,0(a4)
           102d4:	00b72223          	sw	a1,4(a4)
           102d8:	00b72423          	sw	a1,8(a4)
           102dc:	00b72623          	sw	a1,12(a4)
           102e0:	01070713          	addi	a4,a4,16
           102e4:	fed766e3          	bltu	a4,a3,102d0 <memset+0x24>
           102e8:	00061463          	bnez	a2,102f0 <memset+0x44>
           102ec:	00008067          	ret
           102f0:	40c306b3          	sub	a3,t1,a2
           102f4:	00269693          	slli	a3,a3,0x2
           102f8:	00000297          	auipc	t0,0x0
           102fc:	005686b3          	add	a3,a3,t0
           10300:	00c68067          	jr	12(a3)
           10304:	00b70723          	sb	a1,14(a4)
           10308:	00b706a3          	sb	a1,13(a4)
           1030c:	00b70623          	sb	a1,12(a4)
           10310:	00b705a3          	sb	a1,11(a4)
           10314:	00b70523          	sb	a1,10(a4)
           10318:	00b704a3          	sb	a1,9(a4)
           1031c:	00b70423          	sb	a1,8(a4)
           10320:	00b703a3          	sb	a1,7(a4)
           10324:	00b70323          	sb	a1,6(a4)
           10328:	00b702a3          	sb	a1,5(a4)
           1032c:	00b70223          	sb	a1,4(a4)
           10330:	00b701a3          	sb	a1,3(a4)
           10334:	00b70123          	sb	a1,2(a4)
           10338:	00b700a3          	sb	a1,1(a4)
           1033c:	00b70023          	sb	a1,0(a4)
           10340:	00008067          	ret
           10344:	0ff5f593          	andi	a1,a1,255
           10348:	00859693          	slli	a3,a1,0x8
           1034c:	00d5e5b3          	or	a1,a1,a3
           10350:	01059693          	slli	a3,a1,0x10
           10354:	00d5e5b3          	or	a1,a1,a3
           10358:	f6dff06f          	j	102c4 <memset+0x18>
           1035c:	00279693          	slli	a3,a5,0x2
           10360:	00000297          	auipc	t0,0x0
           10364:	005686b3          	add	a3,a3,t0
           10368:	00008293          	mv	t0,ra
           1036c:	fa0680e7          	jalr	-96(a3)
           10370:	00028093          	mv	ra,t0
           10374:	ff078793          	addi	a5,a5,-16
           10378:	40f70733          	sub	a4,a4,a5
           1037c:	00f60633          	add	a2,a2,a5
           10380:	f6c378e3          	bgeu	t1,a2,102f0 <memset+0x44>
           10384:	f3dff06f          	j	102c0 <memset+0x14>
        
        00010388 <__register_exitproc>:
           10388:	c2818793          	addi	a5,gp,-984 # 119c8 <_global_impure_ptr>
           1038c:	0007a703          	lw	a4,0(a5)
           10390:	14872783          	lw	a5,328(a4)
           10394:	04078c63          	beqz	a5,103ec <__register_exitproc+0x64>
           10398:	0047a703          	lw	a4,4(a5)
           1039c:	01f00813          	li	a6,31
           103a0:	06e84e63          	blt	a6,a4,1041c <__register_exitproc+0x94>
           103a4:	00271813          	slli	a6,a4,0x2
           103a8:	02050663          	beqz	a0,103d4 <__register_exitproc+0x4c>
           103ac:	01078333          	add	t1,a5,a6
           103b0:	08c32423          	sw	a2,136(t1) # 101c0 <__libc_fini_array+0x8>
           103b4:	1887a883          	lw	a7,392(a5)
           103b8:	00100613          	li	a2,1
           103bc:	00e61633          	sll	a2,a2,a4
           103c0:	00c8e8b3          	or	a7,a7,a2
           103c4:	1917a423          	sw	a7,392(a5)
           103c8:	10d32423          	sw	a3,264(t1)
           103cc:	00200693          	li	a3,2
           103d0:	02d50463          	beq	a0,a3,103f8 <__register_exitproc+0x70>
           103d4:	00170713          	addi	a4,a4,1
           103d8:	00e7a223          	sw	a4,4(a5)
           103dc:	010787b3          	add	a5,a5,a6
           103e0:	00b7a423          	sw	a1,8(a5)
           103e4:	00000513          	li	a0,0
           103e8:	00008067          	ret
           103ec:	14c70793          	addi	a5,a4,332
           103f0:	14f72423          	sw	a5,328(a4)
           103f4:	fa5ff06f          	j	10398 <__register_exitproc+0x10>
           103f8:	18c7a683          	lw	a3,396(a5)
           103fc:	00170713          	addi	a4,a4,1
           10400:	00e7a223          	sw	a4,4(a5)
           10404:	00c6e633          	or	a2,a3,a2
           10408:	18c7a623          	sw	a2,396(a5)
           1040c:	010787b3          	add	a5,a5,a6
           10410:	00b7a423          	sw	a1,8(a5)
           10414:	00000513          	li	a0,0
           10418:	00008067          	ret
           1041c:	fff00513          	li	a0,-1
           10420:	00008067          	ret
        
        00010424 <__call_exitprocs>:
           10424:	fd010113          	addi	sp,sp,-48
           10428:	c2818793          	addi	a5,gp,-984 # 119c8 <_global_impure_ptr>
           1042c:	01812423          	sw	s8,8(sp)
           10430:	0007ac03          	lw	s8,0(a5)
           10434:	01312e23          	sw	s3,28(sp)
           10438:	01412c23          	sw	s4,24(sp)
           1043c:	01512a23          	sw	s5,20(sp)
           10440:	01612823          	sw	s6,16(sp)
           10444:	02112623          	sw	ra,44(sp)
           10448:	02812423          	sw	s0,40(sp)
           1044c:	02912223          	sw	s1,36(sp)
           10450:	03212023          	sw	s2,32(sp)
           10454:	01712623          	sw	s7,12(sp)
           10458:	00050a93          	mv	s5,a0
           1045c:	00058b13          	mv	s6,a1
           10460:	00100a13          	li	s4,1
           10464:	fff00993          	li	s3,-1
           10468:	148c2903          	lw	s2,328(s8)
           1046c:	02090863          	beqz	s2,1049c <__call_exitprocs+0x78>
           10470:	00492483          	lw	s1,4(s2)
           10474:	fff48413          	addi	s0,s1,-1
           10478:	02044263          	bltz	s0,1049c <__call_exitprocs+0x78>
           1047c:	00249493          	slli	s1,s1,0x2
           10480:	009904b3          	add	s1,s2,s1
           10484:	040b0463          	beqz	s6,104cc <__call_exitprocs+0xa8>
           10488:	1044a783          	lw	a5,260(s1)
           1048c:	05678063          	beq	a5,s6,104cc <__call_exitprocs+0xa8>
           10490:	fff40413          	addi	s0,s0,-1
           10494:	ffc48493          	addi	s1,s1,-4
           10498:	ff3416e3          	bne	s0,s3,10484 <__call_exitprocs+0x60>
           1049c:	02c12083          	lw	ra,44(sp)
           104a0:	02812403          	lw	s0,40(sp)
           104a4:	02412483          	lw	s1,36(sp)
           104a8:	02012903          	lw	s2,32(sp)
           104ac:	01c12983          	lw	s3,28(sp)
           104b0:	01812a03          	lw	s4,24(sp)
           104b4:	01412a83          	lw	s5,20(sp)
           104b8:	01012b03          	lw	s6,16(sp)
           104bc:	00c12b83          	lw	s7,12(sp)
           104c0:	00812c03          	lw	s8,8(sp)
           104c4:	03010113          	addi	sp,sp,48
           104c8:	00008067          	ret
           104cc:	00492783          	lw	a5,4(s2)
           104d0:	0044a683          	lw	a3,4(s1)
           104d4:	fff78793          	addi	a5,a5,-1
           104d8:	04878a63          	beq	a5,s0,1052c <__call_exitprocs+0x108>
           104dc:	0004a223          	sw	zero,4(s1)
           104e0:	fa0688e3          	beqz	a3,10490 <__call_exitprocs+0x6c>
           104e4:	18892783          	lw	a5,392(s2)
           104e8:	008a1733          	sll	a4,s4,s0
           104ec:	00492b83          	lw	s7,4(s2)
           104f0:	00f777b3          	and	a5,a4,a5
           104f4:	00079e63          	bnez	a5,10510 <__call_exitprocs+0xec>
           104f8:	000680e7          	jalr	a3
           104fc:	00492783          	lw	a5,4(s2)
           10500:	f77794e3          	bne	a5,s7,10468 <__call_exitprocs+0x44>
           10504:	148c2783          	lw	a5,328(s8)
           10508:	f92784e3          	beq	a5,s2,10490 <__call_exitprocs+0x6c>
           1050c:	f5dff06f          	j	10468 <__call_exitprocs+0x44>
           10510:	18c92783          	lw	a5,396(s2)
           10514:	0844a583          	lw	a1,132(s1)
           10518:	00f77733          	and	a4,a4,a5
           1051c:	00071c63          	bnez	a4,10534 <__call_exitprocs+0x110>
           10520:	000a8513          	mv	a0,s5
           10524:	000680e7          	jalr	a3
           10528:	fd5ff06f          	j	104fc <__call_exitprocs+0xd8>
           1052c:	00892223          	sw	s0,4(s2)
           10530:	fb1ff06f          	j	104e0 <__call_exitprocs+0xbc>
           10534:	00058513          	mv	a0,a1
           10538:	000680e7          	jalr	a3
           1053c:	fc1ff06f          	j	104fc <__call_exitprocs+0xd8>
        
        00010540 <_exit>:
           10540:	00000593          	li	a1,0
           10544:	00000613          	li	a2,0
           10548:	00000693          	li	a3,0
           1054c:	00000713          	li	a4,0
           10550:	00000793          	li	a5,0
           10554:	05d00893          	li	a7,93
           10558:	00000073          	ecall
           1055c:	00054463          	bltz	a0,10564 <_exit+0x24>
           10560:	0000006f          	j	10560 <_exit+0x20>
           10564:	ff010113          	addi	sp,sp,-16
           10568:	00812423          	sw	s0,8(sp)
           1056c:	00050413          	mv	s0,a0
           10570:	00112623          	sw	ra,12(sp)
           10574:	40800433          	neg	s0,s0
           10578:	00c000ef          	jal	ra,10584 <__errno>
           1057c:	00852023          	sw	s0,0(a0)
           10580:	0000006f          	j	10580 <_exit+0x40>
        
        00010584 <__errno>:
           10584:	c3018793          	addi	a5,gp,-976 # 119d0 <_impure_ptr>
           10588:	0007a503          	lw	a0,0(a5)
           1058c:	00008067          	ret


```





__Instruction Counter__

The Assembly Instruction Counter is a Python script designed to analyze RISC-V assembly code files generated by the RISC-V GNU toolchain. It counts the number of different instructions used in the code and lists those instructions. This tool can be helpful in understanding the diversity of instructions within your assembly code.

Download: Place the sample_assembly.txt assembly code file in the same directory as the Python script (instruction_counter.py).

Run the Script: Open a terminal or command prompt and navigate to the directory containing the script and the assembly code file. Run the following command:
```
  python instruction_counter.py
```

Number of different instructions used. The script will process the assembly code file and display the number of different instructions used along with a list of those instructions.

```
        Number of different instructions: 31
        List of unique instructions:
        jr
        bltz
        ecall
        blt
        neg
        mv
        and
        jal
        addi
        ret
        bne
        sub
        li
        andi
        or
        slli
        beq
        add
        lbu
        lw
        bgeu
        bnez
        beqz
        auipc
        jalr
        sw
        srai
        bltu
        sll
        j
        sb

```



## Acknowledgement

### Special Mention

Grateful to Mr Kunal Ghosh, Co-Founder, VLSI SYSTEM DESIGN for providing an excellent platform to learn and expand our skills on a custom RISCV architecture design and ensuring that the learning process remained smooth. 

- Kunal Ghosh, VSD Corp. Pvt. Ltd.
- Mayank Kabra, IIITB



## References

https://github.com/SakethGajawada/RISCV_GNU

https://circuitdigest.com

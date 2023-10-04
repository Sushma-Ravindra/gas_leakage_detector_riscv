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
    #include <stdio.h>
  
  // Function monitoring gas levels using sensor module
  
  void monitorgaslevel() {
      int gas_level = 0;
  
      // Replace these variables with sensor pins and setup environment
      int gas_sensor = 0; // Replace with the GPIO pin connected to sensor's digital out pin
      int buzzer = 1; // Replace with the GPIO pin connected to the buzzer
  
      
  
      while (1) {
  
          if (gas_level == 1) {
              // Simulate activating the buzzer (replace with actual buzzer control)
              // digitalWrite(buzzerPin, HIGH);
              //printf("Buzzer is ON\n");
  
          } else {
              // Simulate deactivating the buzzer (replace with actual buzzer control)
              // digitalWrite(buzzerPin, LOW);
              //printf("Buzzer is OFF\n");
          }
      }
  }
  
  void detect_gas_level() {
      monitorgaslevel();
  }
  
  int main() {
      while (1) {
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
         sample.o:     file format elf64-littleriscv
        
        
        Disassembly of section .text:
        
        00000000000100b0 <register_fini>:
           100b0:	ffff0797          	auipc	a5,0xffff0
           100b4:	f5078793          	addi	a5,a5,-176 # 0 <register_fini-0x100b0>
           100b8:	00078863          	beqz	a5,100c8 <register_fini+0x18>
           100bc:	00000517          	auipc	a0,0x0
           100c0:	11850513          	addi	a0,a0,280 # 101d4 <__libc_fini_array>
           100c4:	0c80006f          	j	1018c <atexit>
           100c8:	00008067          	ret
        
        00000000000100cc <_start>:
           100cc:	00002197          	auipc	gp,0x2
           100d0:	d1418193          	addi	gp,gp,-748 # 11de0 <__global_pointer$>
           100d4:	f6018513          	addi	a0,gp,-160 # 11d40 <_edata>
           100d8:	f9818613          	addi	a2,gp,-104 # 11d78 <__BSS_END__>
           100dc:	40a60633          	sub	a2,a2,a0
           100e0:	00000593          	li	a1,0
           100e4:	1e0000ef          	jal	ra,102c4 <memset>
           100e8:	00000517          	auipc	a0,0x0
           100ec:	0ec50513          	addi	a0,a0,236 # 101d4 <__libc_fini_array>
           100f0:	09c000ef          	jal	ra,1018c <atexit>
           100f4:	13c000ef          	jal	ra,10230 <__libc_init_array>
           100f8:	00012503          	lw	a0,0(sp)
           100fc:	00810593          	addi	a1,sp,8
           10100:	00000613          	li	a2,0
           10104:	07c000ef          	jal	ra,10180 <main>
           10108:	0980006f          	j	101a0 <exit>
        
        000000000001010c <__do_global_dtors_aux>:
           1010c:	f601c783          	lbu	a5,-160(gp) # 11d40 <_edata>
           10110:	04079463          	bnez	a5,10158 <__do_global_dtors_aux+0x4c>
           10114:	ffff0797          	auipc	a5,0xffff0
           10118:	eec78793          	addi	a5,a5,-276 # 0 <register_fini-0x100b0>
           1011c:	02078863          	beqz	a5,1014c <__do_global_dtors_aux+0x40>
           10120:	ff010113          	addi	sp,sp,-16
           10124:	00001517          	auipc	a0,0x1
           10128:	49c50513          	addi	a0,a0,1180 # 115c0 <__FRAME_END__>
           1012c:	00113423          	sd	ra,8(sp)
           10130:	00000097          	auipc	ra,0x0
           10134:	000000e7          	jalr	zero # 0 <register_fini-0x100b0>
           10138:	00813083          	ld	ra,8(sp)
           1013c:	00100793          	li	a5,1
           10140:	f6f18023          	sb	a5,-160(gp) # 11d40 <_edata>
           10144:	01010113          	addi	sp,sp,16
           10148:	00008067          	ret
           1014c:	00100793          	li	a5,1
           10150:	f6f18023          	sb	a5,-160(gp) # 11d40 <_edata>
           10154:	00008067          	ret
           10158:	00008067          	ret
        
        000000000001015c <frame_dummy>:
           1015c:	ffff0797          	auipc	a5,0xffff0
           10160:	ea478793          	addi	a5,a5,-348 # 0 <register_fini-0x100b0>
           10164:	00078c63          	beqz	a5,1017c <frame_dummy+0x20>
           10168:	f6818593          	addi	a1,gp,-152 # 11d48 <object.5473>
           1016c:	00001517          	auipc	a0,0x1
           10170:	45450513          	addi	a0,a0,1108 # 115c0 <__FRAME_END__>
           10174:	00000317          	auipc	t1,0x0
           10178:	00000067          	jr	zero # 0 <register_fini-0x100b0>
           1017c:	00008067          	ret
        
        0000000000010180 <main>:
           10180:	0000006f          	j	10180 <main>
        
        0000000000010184 <monitorgaslevel>:
           10184:	0000006f          	j	10184 <monitorgaslevel>
        
        0000000000010188 <detect_gas_level>:
           10188:	0000006f          	j	10188 <detect_gas_level>
        
        000000000001018c <atexit>:
           1018c:	00050593          	mv	a1,a0
           10190:	00000693          	li	a3,0
           10194:	00000613          	li	a2,0
           10198:	00000513          	li	a0,0
           1019c:	2040006f          	j	103a0 <__register_exitproc>
        
        00000000000101a0 <exit>:
           101a0:	ff010113          	addi	sp,sp,-16
           101a4:	00000593          	li	a1,0
           101a8:	00813023          	sd	s0,0(sp)
           101ac:	00113423          	sd	ra,8(sp)
           101b0:	00050413          	mv	s0,a0
           101b4:	298000ef          	jal	ra,1044c <__call_exitprocs>
           101b8:	f4818793          	addi	a5,gp,-184 # 11d28 <_global_impure_ptr>
           101bc:	0007b503          	ld	a0,0(a5)
           101c0:	05853783          	ld	a5,88(a0)
           101c4:	00078463          	beqz	a5,101cc <exit+0x2c>
           101c8:	000780e7          	jalr	a5
           101cc:	00040513          	mv	a0,s0
           101d0:	3a0000ef          	jal	ra,10570 <_exit>
        
        00000000000101d4 <__libc_fini_array>:
           101d4:	fe010113          	addi	sp,sp,-32
           101d8:	00813823          	sd	s0,16(sp)
           101dc:	00001797          	auipc	a5,0x1
           101e0:	40478793          	addi	a5,a5,1028 # 115e0 <__fini_array_end>
           101e4:	00001417          	auipc	s0,0x1
           101e8:	3f440413          	addi	s0,s0,1012 # 115d8 <__init_array_end>
           101ec:	408787b3          	sub	a5,a5,s0
           101f0:	00913423          	sd	s1,8(sp)
           101f4:	00113c23          	sd	ra,24(sp)
           101f8:	4037d493          	srai	s1,a5,0x3
           101fc:	02048063          	beqz	s1,1021c <__libc_fini_array+0x48>
           10200:	ff878793          	addi	a5,a5,-8
           10204:	00878433          	add	s0,a5,s0
           10208:	00043783          	ld	a5,0(s0)
           1020c:	fff48493          	addi	s1,s1,-1
           10210:	ff840413          	addi	s0,s0,-8
           10214:	000780e7          	jalr	a5
           10218:	fe0498e3          	bnez	s1,10208 <__libc_fini_array+0x34>
           1021c:	01813083          	ld	ra,24(sp)
           10220:	01013403          	ld	s0,16(sp)
           10224:	00813483          	ld	s1,8(sp)
           10228:	02010113          	addi	sp,sp,32
           1022c:	00008067          	ret
        
        0000000000010230 <__libc_init_array>:
           10230:	fe010113          	addi	sp,sp,-32
           10234:	00813823          	sd	s0,16(sp)
           10238:	01213023          	sd	s2,0(sp)
           1023c:	00001417          	auipc	s0,0x1
           10240:	38840413          	addi	s0,s0,904 # 115c4 <__preinit_array_end>
           10244:	00001917          	auipc	s2,0x1
           10248:	38090913          	addi	s2,s2,896 # 115c4 <__preinit_array_end>
           1024c:	40890933          	sub	s2,s2,s0
           10250:	00113c23          	sd	ra,24(sp)
           10254:	00913423          	sd	s1,8(sp)
           10258:	40395913          	srai	s2,s2,0x3
           1025c:	00090e63          	beqz	s2,10278 <__libc_init_array+0x48>
           10260:	00000493          	li	s1,0
           10264:	00043783          	ld	a5,0(s0)
           10268:	00148493          	addi	s1,s1,1
           1026c:	00840413          	addi	s0,s0,8
           10270:	000780e7          	jalr	a5
           10274:	fe9918e3          	bne	s2,s1,10264 <__libc_init_array+0x34>
           10278:	00001417          	auipc	s0,0x1
           1027c:	35040413          	addi	s0,s0,848 # 115c8 <__init_array_start>
           10280:	00001917          	auipc	s2,0x1
           10284:	35890913          	addi	s2,s2,856 # 115d8 <__init_array_end>
           10288:	40890933          	sub	s2,s2,s0
           1028c:	40395913          	srai	s2,s2,0x3
           10290:	00090e63          	beqz	s2,102ac <__libc_init_array+0x7c>
           10294:	00000493          	li	s1,0
           10298:	00043783          	ld	a5,0(s0)
           1029c:	00148493          	addi	s1,s1,1
           102a0:	00840413          	addi	s0,s0,8
           102a4:	000780e7          	jalr	a5
           102a8:	fe9918e3          	bne	s2,s1,10298 <__libc_init_array+0x68>
           102ac:	01813083          	ld	ra,24(sp)
           102b0:	01013403          	ld	s0,16(sp)
           102b4:	00813483          	ld	s1,8(sp)
           102b8:	00013903          	ld	s2,0(sp)
           102bc:	02010113          	addi	sp,sp,32
           102c0:	00008067          	ret
        
        00000000000102c4 <memset>:
           102c4:	00f00313          	li	t1,15
           102c8:	00050713          	mv	a4,a0
           102cc:	02c37a63          	bgeu	t1,a2,10300 <memset+0x3c>
           102d0:	00f77793          	andi	a5,a4,15
           102d4:	0a079063          	bnez	a5,10374 <memset+0xb0>
           102d8:	06059e63          	bnez	a1,10354 <memset+0x90>
           102dc:	ff067693          	andi	a3,a2,-16
           102e0:	00f67613          	andi	a2,a2,15
           102e4:	00e686b3          	add	a3,a3,a4
           102e8:	00b73023          	sd	a1,0(a4)
           102ec:	00b73423          	sd	a1,8(a4)
           102f0:	01070713          	addi	a4,a4,16
           102f4:	fed76ae3          	bltu	a4,a3,102e8 <memset+0x24>
           102f8:	00061463          	bnez	a2,10300 <memset+0x3c>
           102fc:	00008067          	ret
           10300:	40c306b3          	sub	a3,t1,a2
           10304:	00269693          	slli	a3,a3,0x2
           10308:	00000297          	auipc	t0,0x0
           1030c:	005686b3          	add	a3,a3,t0
           10310:	00c68067          	jr	12(a3)
           10314:	00b70723          	sb	a1,14(a4)
           10318:	00b706a3          	sb	a1,13(a4)
           1031c:	00b70623          	sb	a1,12(a4)
           10320:	00b705a3          	sb	a1,11(a4)
           10324:	00b70523          	sb	a1,10(a4)
           10328:	00b704a3          	sb	a1,9(a4)
           1032c:	00b70423          	sb	a1,8(a4)
           10330:	00b703a3          	sb	a1,7(a4)
           10334:	00b70323          	sb	a1,6(a4)
           10338:	00b702a3          	sb	a1,5(a4)
           1033c:	00b70223          	sb	a1,4(a4)
           10340:	00b701a3          	sb	a1,3(a4)
           10344:	00b70123          	sb	a1,2(a4)
           10348:	00b700a3          	sb	a1,1(a4)
           1034c:	00b70023          	sb	a1,0(a4)
           10350:	00008067          	ret
           10354:	0ff5f593          	andi	a1,a1,255
           10358:	00859693          	slli	a3,a1,0x8
           1035c:	00d5e5b3          	or	a1,a1,a3
           10360:	01059693          	slli	a3,a1,0x10
           10364:	00d5e5b3          	or	a1,a1,a3
           10368:	02059693          	slli	a3,a1,0x20
           1036c:	00d5e5b3          	or	a1,a1,a3
           10370:	f6dff06f          	j	102dc <memset+0x18>
           10374:	00279693          	slli	a3,a5,0x2
           10378:	00000297          	auipc	t0,0x0
           1037c:	005686b3          	add	a3,a3,t0
           10380:	00008293          	mv	t0,ra
           10384:	f98680e7          	jalr	-104(a3)
           10388:	00028093          	mv	ra,t0
           1038c:	ff078793          	addi	a5,a5,-16
           10390:	40f70733          	sub	a4,a4,a5
           10394:	00f60633          	add	a2,a2,a5
           10398:	f6c374e3          	bgeu	t1,a2,10300 <memset+0x3c>
           1039c:	f3dff06f          	j	102d8 <memset+0x14>
        
        00000000000103a0 <__register_exitproc>:
           103a0:	f4818793          	addi	a5,gp,-184 # 11d28 <_global_impure_ptr>
           103a4:	0007b703          	ld	a4,0(a5)
           103a8:	1f873783          	ld	a5,504(a4)
           103ac:	06078063          	beqz	a5,1040c <__register_exitproc+0x6c>
           103b0:	0087a703          	lw	a4,8(a5)
           103b4:	01f00813          	li	a6,31
           103b8:	08e84663          	blt	a6,a4,10444 <__register_exitproc+0xa4>
           103bc:	02050863          	beqz	a0,103ec <__register_exitproc+0x4c>
           103c0:	00371813          	slli	a6,a4,0x3
           103c4:	01078833          	add	a6,a5,a6
           103c8:	10c83823          	sd	a2,272(a6)
           103cc:	3107a883          	lw	a7,784(a5)
           103d0:	00100613          	li	a2,1
           103d4:	00e6163b          	sllw	a2,a2,a4
           103d8:	00c8e8b3          	or	a7,a7,a2
           103dc:	3117a823          	sw	a7,784(a5)
           103e0:	20d83823          	sd	a3,528(a6)
           103e4:	00200693          	li	a3,2
           103e8:	02d50863          	beq	a0,a3,10418 <__register_exitproc+0x78>
           103ec:	00270693          	addi	a3,a4,2
           103f0:	00369693          	slli	a3,a3,0x3
           103f4:	0017071b          	addiw	a4,a4,1
           103f8:	00e7a423          	sw	a4,8(a5)
           103fc:	00d787b3          	add	a5,a5,a3
           10400:	00b7b023          	sd	a1,0(a5)
           10404:	00000513          	li	a0,0
           10408:	00008067          	ret
           1040c:	20070793          	addi	a5,a4,512
           10410:	1ef73c23          	sd	a5,504(a4)
           10414:	f9dff06f          	j	103b0 <__register_exitproc+0x10>
           10418:	3147a683          	lw	a3,788(a5)
           1041c:	00000513          	li	a0,0
           10420:	00c6e633          	or	a2,a3,a2
           10424:	00270693          	addi	a3,a4,2
           10428:	00369693          	slli	a3,a3,0x3
           1042c:	0017071b          	addiw	a4,a4,1
           10430:	30c7aa23          	sw	a2,788(a5)
           10434:	00e7a423          	sw	a4,8(a5)
           10438:	00d787b3          	add	a5,a5,a3
           1043c:	00b7b023          	sd	a1,0(a5)
           10440:	00008067          	ret
           10444:	fff00513          	li	a0,-1
           10448:	00008067          	ret
        
        000000000001044c <__call_exitprocs>:
           1044c:	fb010113          	addi	sp,sp,-80
           10450:	f4818793          	addi	a5,gp,-184 # 11d28 <_global_impure_ptr>
           10454:	01813023          	sd	s8,0(sp)
           10458:	0007bc03          	ld	s8,0(a5)
           1045c:	03313423          	sd	s3,40(sp)
           10460:	03413023          	sd	s4,32(sp)
           10464:	01513c23          	sd	s5,24(sp)
           10468:	01613823          	sd	s6,16(sp)
           1046c:	04113423          	sd	ra,72(sp)
           10470:	04813023          	sd	s0,64(sp)
           10474:	02913c23          	sd	s1,56(sp)
           10478:	03213823          	sd	s2,48(sp)
           1047c:	01713423          	sd	s7,8(sp)
           10480:	00050a93          	mv	s5,a0
           10484:	00058b13          	mv	s6,a1
           10488:	00100a13          	li	s4,1
           1048c:	fff00993          	li	s3,-1
           10490:	1f8c3903          	ld	s2,504(s8)
           10494:	02090863          	beqz	s2,104c4 <__call_exitprocs+0x78>
           10498:	00892483          	lw	s1,8(s2)
           1049c:	fff4841b          	addiw	s0,s1,-1
           104a0:	02044263          	bltz	s0,104c4 <__call_exitprocs+0x78>
           104a4:	00349493          	slli	s1,s1,0x3
           104a8:	009904b3          	add	s1,s2,s1
           104ac:	040b0463          	beqz	s6,104f4 <__call_exitprocs+0xa8>
           104b0:	2084b783          	ld	a5,520(s1)
           104b4:	05678063          	beq	a5,s6,104f4 <__call_exitprocs+0xa8>
           104b8:	fff4041b          	addiw	s0,s0,-1
           104bc:	ff848493          	addi	s1,s1,-8
           104c0:	ff3416e3          	bne	s0,s3,104ac <__call_exitprocs+0x60>
           104c4:	04813083          	ld	ra,72(sp)
           104c8:	04013403          	ld	s0,64(sp)
           104cc:	03813483          	ld	s1,56(sp)
           104d0:	03013903          	ld	s2,48(sp)
           104d4:	02813983          	ld	s3,40(sp)
           104d8:	02013a03          	ld	s4,32(sp)
           104dc:	01813a83          	ld	s5,24(sp)
           104e0:	01013b03          	ld	s6,16(sp)
           104e4:	00813b83          	ld	s7,8(sp)
           104e8:	00013c03          	ld	s8,0(sp)
           104ec:	05010113          	addi	sp,sp,80
           104f0:	00008067          	ret
           104f4:	00892783          	lw	a5,8(s2)
           104f8:	0084b703          	ld	a4,8(s1)
           104fc:	fff7879b          	addiw	a5,a5,-1
           10500:	04878e63          	beq	a5,s0,1055c <__call_exitprocs+0x110>
           10504:	0004b423          	sd	zero,8(s1)
           10508:	fa0708e3          	beqz	a4,104b8 <__call_exitprocs+0x6c>
           1050c:	31092783          	lw	a5,784(s2)
           10510:	008a16bb          	sllw	a3,s4,s0
           10514:	00892b83          	lw	s7,8(s2)
           10518:	00d7f7b3          	and	a5,a5,a3
           1051c:	0007879b          	sext.w	a5,a5
           10520:	00079e63          	bnez	a5,1053c <__call_exitprocs+0xf0>
           10524:	000700e7          	jalr	a4
           10528:	00892783          	lw	a5,8(s2)
           1052c:	f77792e3          	bne	a5,s7,10490 <__call_exitprocs+0x44>
           10530:	1f8c3783          	ld	a5,504(s8)
           10534:	f92782e3          	beq	a5,s2,104b8 <__call_exitprocs+0x6c>
           10538:	f59ff06f          	j	10490 <__call_exitprocs+0x44>
           1053c:	31492783          	lw	a5,788(s2)
           10540:	1084b583          	ld	a1,264(s1)
           10544:	00d7f7b3          	and	a5,a5,a3
           10548:	0007879b          	sext.w	a5,a5
           1054c:	00079c63          	bnez	a5,10564 <__call_exitprocs+0x118>
           10550:	000a8513          	mv	a0,s5
           10554:	000700e7          	jalr	a4
           10558:	fd1ff06f          	j	10528 <__call_exitprocs+0xdc>
           1055c:	00892423          	sw	s0,8(s2)
           10560:	fa9ff06f          	j	10508 <__call_exitprocs+0xbc>
           10564:	00058513          	mv	a0,a1
           10568:	000700e7          	jalr	a4
           1056c:	fbdff06f          	j	10528 <__call_exitprocs+0xdc>
        
        0000000000010570 <_exit>:
           10570:	00000593          	li	a1,0
           10574:	00000613          	li	a2,0
           10578:	00000693          	li	a3,0
           1057c:	00000713          	li	a4,0
           10580:	00000793          	li	a5,0
           10584:	05d00893          	li	a7,93
           10588:	00000073          	ecall
           1058c:	00054463          	bltz	a0,10594 <_exit+0x24>
           10590:	0000006f          	j	10590 <_exit+0x20>
           10594:	ff010113          	addi	sp,sp,-16
           10598:	00813023          	sd	s0,0(sp)
           1059c:	00050413          	mv	s0,a0
           105a0:	00113423          	sd	ra,8(sp)
           105a4:	4080043b          	negw	s0,s0
           105a8:	00c000ef          	jal	ra,105b4 <__errno>
           105ac:	00852023          	sw	s0,0(a0)
           105b0:	0000006f          	j	105b0 <_exit+0x40>
        
        00000000000105b4 <__errno>:
           105b4:	f5818793          	addi	a5,gp,-168 # 11d38 <_impure_ptr>
           105b8:	0007b503          	ld	a0,0(a5)
           105bc:	00008067          	ret


```





__Instruction Counter__

The Assembly Instruction Counter is a Python script designed to analyze RISC-V assembly code files generated by the RISC-V GNU toolchain. It counts the number of different instructions used in the code and lists those instructions. This tool can be helpful in understanding the diversity of instructions within your assembly code.

Download: Place the sample_assembly.txt assembly code file in the same directory as the Python script (instruction_counter.py).

Run the Script: Open a terminal or command prompt and navigate to the directory containing the script and the assembly code file. Run the following command:
```
  python instruction_counter.py
```

Number of different instructions used. The script will process the assembly code file and display the number of different instructions used along with a list of those instructions.

![image](https://github.com/Sushma-Ravindra/gas_leakage_detector_riscv/assets/141133883/0f3b1fdb-3992-44ec-b23a-b14b07cc6fe6)


## Acknowledgement


## References


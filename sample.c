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

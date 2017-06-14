#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include "gyro.h" 
#include <iostream>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>

using namespace std;

int i2c_write_reg(char reg, char value) {
	int file;
	if ((file = open(I2C_BUS, O_RDWR)) < 0){
		cout << "Failed to open L3G4200D fd" << endl;
		return(1);
	}
	if (ioctl(file, I2C_SLAVE,I2C_ADDRESS) < 0){
		cout << "I2C IOCTL Failed" << endl;
		return(2);
	}
		
	char buf[2] = {reg, value};

	if(write(file,buf,2) !=2){
    	cout << "Failed to write to L3G4200D" << endl;
	}
}


char i2c_read_reg(char reg) {
	int file;
	if ((file = open(I2C_BUS, O_RDWR)) < 0){
		cout << "Failed to open L3G4200D fd" << endl;
		return(1);
	}
	if (ioctl(file, I2C_SLAVE,I2C_ADDRESS) < 0){
		cout << "I2C IOCTL Failed" << endl;
		return(2);
	}
		
	char buf[1] = {reg};

	if(write(file,buf,1) !=1){
    	cout << "Failed to write to L3G4200D" << endl;
	}
	    
	int numberBytes = 1;
	char dataBuffer[1];

	int bytesRead = read(file,dataBuffer, numberBytes);
	if (bytesRead == -1){
		cout << "Failure to read from L3G4200D register" << endl; 
	}
	return *dataBuffer;
}
    
int16_t read_Xraw(){
	char LSB;
	char MSB;
	LSB = i2c_read_reg(0x28);
	MSB = i2c_read_reg(0x29);
	int16_t Xraw;
	float X;
	X = MSB << 8 | LSB;
	return X; 
}    
    
float conv_rate(float raw)
{
	float rate;
	rate = raw * 0.00875;
	return rate; 
}
int main(void) {
	using namespace std;
    printf("Hello, world!\n");
    float apple=read_Xraw();
	apple = conv_rate(apple);

    
	cout << apple << endl;	  
  

	
  
    
    char inter;
    inter = i2c_read_reg(0x26);
    
   // printf("%d",inter);
 
  	return 0; 
}
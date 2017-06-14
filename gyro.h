#include <bitset>
#include <iostream>


//REGISTER ADDRESS MAP
#define WHO_AM_I      0x0F //Default = 11010011 (211) 

#define CTRL_REG1     0x20 //Default = 00000111 
#define CTRL_REG2     0x21 //Default = 00000000
#define CTRL_REG3     0x22 //Default = 00000000
#define CTRL_REG4     0x23 //Default = 00000000
#define CTRL_REG5     0x24 //Default = 00000000

#define REFERENCE     0x25 //Default = 00000000

#define OUT_TEMP      0x26 //OUTPUT

#define STATUS_REG    0x27 //OUTPUT

#define OUT_X_L       0x28 //OUTPUT
#define OUT_X_H       0x29 //OUTPUT
#define OUT_Y_L       0x2A //OUTPUT
#define OUT_Y_H       0x2B //OUTPUT
#define OUT_Z_L       0x2C //OUTPUT
#define OUT_Z_H       0x2D //OUTPUT

#define FIFO_CTRL_REG 0x2E //Default = 00000000
#define FIFO_SRC_REG  0x2F //OUTPUT

#define INT1_CFG      0x30 //Default = 00000000
#define INT1_SRC      0x31 //INTERRUPT SOURCE REGISTER - OUTPUT
#define INT1_TSH_XH   0x32 //Default = 00000000
#define INT1_TSH_XL   0x33 //Default = 00000000
#define INT1_TSH_YH   0x34 //Default = 00000000
#define INT1_TSH_YL   0x35 //Default = 00000000
#define INT1_TSH_ZH   0x36 //Default = 00000000
#define INT1_TSH_ZL   0x37 //Default = 00000000
#define INT1_DURATION 0x38 //Default = 00000000

enum CTRL_REG1_BITS {
	Xen = 0;
	Yen = 1;
	Zen = 2;
	PD  = 3;
	BW0 = 4;
	BW1 = 5;
	DR0 = 6;
	DR1 = 7;
}

enum CTRL_REG2_BITS {
	int HPCF0 = 0; 
	int HPCF1 = 1;
	int HPCF2 = 2;
	int HPCF3 = 3; 
	int HPM0  = 4; 
	int HPM1  = 5; 
}

enum CTRL_REG3_BITS {
	int I2_Empty  = 0; 
	int I2_ORun   = 1; 
	int I2_WTM    = 2;
	int I2_DRDY   = 3;
	int PP_OD     = 4; 
	int H_Lactive = 5;
	int I1_Boot   = 6; 
	int I1_Int1   = 7; 
}

enum CTRL_REG4_BITS {
	int SIM = 0;
	int ST0 = 1; 
	int ST1 = 2;
	int FS0 = 4; 
	int FS1 = 5;
	int BLE = 6;
	int BDU = 7;
}

enum CTRL_REG5_BITS {
	int Out_Sel0  = 0; 
	int Out_Sel1  = 1;
	int INT1_Sel0 = 2; 
	int INT1_Sel1 = 3;
	int HPen      = 4;
	int FIFO_EN   = 6;
	int BOOT      = 7;
}

enum FIFO_CTRL_REG_BITS {
	int WTM0 = 0;
	int WTM1 = 1;
	int WTM2 = 2;
	int WTM3 = 3;
	int WTM4 = 4;
	int FM0  = 5;
	int FM1  = 6;
	int FM2  = 7;
}

enum INT1_CFG_BITS {
	int XLIE   = 0;
	int XHIE   = 1;
	int YLIE   = 2;
	int YHIE   = 3;
	int ZLIE   = 4;
	int ZHIE   = 5;
	int LIR    = 6;
	int AND_OR = 7;
}

i2c_eeprom is an application which writes the data to eeprom chip (24LC256) and reads the data written.
 

Chip used:
eeprom 24LC256

Hardware setup:
Make the following connections frm 24LC256 chip pinouts to module.
------------------------------------------------------------------------------------
24LC256		-	I2C signal 	-		Evaluation board 3.1
------------------------------------------------------------------------------------
SCL		-	I2C_SCL 	-		SODIMM_196/I2C_SCL
SDA		-	I2C_SDA		-		SODIMM_194/I2C_SDA
VSS		-			-		GND
VCC		-			-		3.3V
------------------------------------------------------------------------------------


Compiling the application:
In the application directory, run make command preceding machine(module) name.
e.g: MACHINE=colibri-t20 make
Copy the exe to the module either through ethernet and USB.
Ethernet:
scp i2c_eeprom root@10.18.0.162:/home/root
USB:
cp i2c_eeprom /media/USB

Run the application:
./i2c_eeprom

Output:
Output should show the data written into eeprom.


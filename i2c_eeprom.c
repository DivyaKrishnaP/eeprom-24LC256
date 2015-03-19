#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "i2c-dev.h"

#define SLAVE_ADDR 0x50
#define I2C_DEV "/dev/i2c-%d"
#define BUS_NUM 0

int main(int argc, char **argv)
{

	int fd;
	int count=0;
	char dev_path[15] = {0};
	unsigned char txbuffer[10] = {0x00, 0x00, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17};
	char rxbuffer[10] = {0};
	int wt = 0,rt = 0, rd = 0;;
	char testbuff[2] = {0x00, 0x00};
	

	sprintf(dev_path, I2C_DEV, BUS_NUM);
	fd = open(dev_path, O_RDWR);
	if(fd < 0)
		printf("Failed to open \n");
	
	rd = ioctl(fd, I2C_SLAVE_FORCE, SLAVE_ADDR);
	if(rd < 0)
	{
		printf("ioctl error\n");
		return 1;
	}
	
	wt = write(fd, txbuffer, 10);
	usleep(10000);
	if(wt < 0)
		printf("could not write data\n");
	
	write (fd, testbuff, 2);
		
	rt = read(fd, rxbuffer, 10);
	
	if(rt < 0)
		printf("could not read data\n");
	for(count = 0; count < 8; count++){
		printf("Received data %x", rxbuffer[count]);	
	}
	printf("\n");
	return 0;
}


	

/* MPU6050 Accelerometer sensor reading
 * connect with ubx_bmd345eval_nrf52840 
 *   wihout main and while loop    */


#include <zephyr.h>
#include <sys/printk.h>
#include <device.h>
#include <drivers/i2c.h>
#include <drivers/gpio.h>
#include <kernel.h>
#include <init.h>

#define MPU6050_CHIP_ID                 0x68
#define MPU6050_REG_CHIP_ID             0x75
#define MPU6050_SLEEP_EN                BIT(6)
#define MPU6050_REG_PWR_MGMT1           0x6B

#define MPU6050_ACCEL_FS_SHIFT          3
#define MPU6050_REG_ACCEL_CFG           0x1C

static struct k_timer my_timer;


void sensor(const struct device *i2c_dev)
{

        i2c_dev = DEVICE_DT_GET(DT_NODELABEL(i2c0));
        uint8_t  ret, id;
        uint8_t buf[16];
        double AX,AY,AZ;

        if (!device_is_ready(i2c_dev)) {
                printk("I2C: Device is not ready.\n");
                return ;
        }

        /* check chip ID */

        if (i2c_reg_read_byte(i2c_dev, MPU6050_CHIP_ID ,
                              MPU6050_REG_CHIP_ID , &id) < 0) {
                printk("Failed to read chip ID.\n");
                return;
        	}else
                	printk("chip ID 0x%x\n",id);

        if (id != MPU6050_CHIP_ID) {
                printk("Invalid chip ID.\n");
                return;
        }
        /*  wake up chip */

        if (i2c_reg_update_byte(i2c_dev, MPU6050_CHIP_ID ,
                                MPU6050_REG_PWR_MGMT1, MPU6050_SLEEP_EN,
                                0) < 0) {
                printk("Failed to wake up chip.");
                return;
	        }else
                printk("success wake up chip\n");

	     
		/* x Axis reading MSB */
        	ret = i2c_burst_read(i2c_dev,MPU6050_CHIP_ID ,0x3B,&buf[0],1);
        	if(ret < 0) {
                	printk("failed to read the address\n");
                	return ;
               	}

		
		/* x Axis reading LSB */
	        ret = i2c_burst_read(i2c_dev,MPU6050_CHIP_ID ,0x3C,&buf[1],1);
       		if(ret < 0) {
                	printk("failed to read the address\n");
                	return;
		}

		/* Y Axis reading MSB */
		ret = i2c_burst_read(i2c_dev,MPU6050_CHIP_ID ,0x3D,&buf[2],1);
                if(ret < 0) {
                        printk("failed to read the address\n");
                        return ;
                }


		/* Y Axis reading LSB */
                ret = i2c_burst_read(i2c_dev,MPU6050_CHIP_ID ,0x3E,&buf[3],1);
                if(ret < 0) {
                        printk("failed to read the address\n");
                        return;
		}

		/* Z Axis reading MSB */
		ret = i2c_burst_read(i2c_dev,MPU6050_CHIP_ID ,0x3F,&buf[4],1);
                if(ret < 0) {
                        printk("failed to read the address\n");
                        return ;
                        }

		/* Z Axis reading LSB */
                ret = i2c_burst_read(i2c_dev,MPU6050_CHIP_ID ,0x40,&buf[1],1);
                if(ret < 0) {
                        printk("failed to read the address\n");
                        return;
       			 }

	/* Value = LSB + (MSB << 8) */

        AX = buf[1] + (buf[0] << 8);  
        AY = buf[3] + (buf[2] << 8);  
        AZ = buf[5] + (buf[4] << 8); 
        printk(" X = %f\n", ((AX * 0.244)/1000));
        printk(" Y = %f\n", ((AY * 0.244)/1000));
        printk(" Z = %f\n", ((AZ * 0.244)/1000));
        printk("\n");
        k_msleep(2000);


}

K_WORK_DEFINE(my_work ,sensor);

static void my_timer_handler(struct k_timer *dummy)
{
        k_work_submit(&my_work);
}

void func(void) 
{
	 k_timer_init(&my_timer,my_timer_handler,NULL);
         k_timer_start(&my_timer,K_SECONDS(3), K_MSEC(1000));
}

SYS_INIT(func,APPLICATION,3);

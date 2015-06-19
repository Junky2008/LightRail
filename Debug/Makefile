all: main test

main: main.o TriggerSensor.o LightSensor.o Motor.o HAL_GPIO.o HAL_UART.o HAL_ADC.o
	g++ main.o TriggerSensor.o LightSensor.o Motor.o HAL_GPIO.o HAL_UART.o HAL_ADC.o -o main

test: UnitTest.o TriggerSensor.o LightSensor.o Motor.o MOC_GPIO.o MOC_UART.o MOC_ADC.o MOC_SYS.o
	g++ -fprofile-arcs -ftest-coverage -fPIC -O0 -I../Test -I../Test/include -pthread UnitTest.o TriggerSensor.o LightSensor.o Motor.o MOC_GPIO.o MOC_UART.o MOC_ADC.o MOC_SYS.o -lgtest -o UnitTest

TriggerSensor.o:
	g++ -c ../Drivers/TriggerSensor.c

LightSensor.o:
	g++ -c ../Drivers/LightSensor.c

Motor.o:
	g++ -c ../Drivers/Motor.c

HAL_GPIO.o:
	g++ -c ../HAL/HAL_GPIO.c

HAL_UART.o:
	g++ -c ../HAL/HAL_UART.c

HAL_ADC.o:
	g++ -c ../HAL/HAL_ADC.c

main.o:
	g++ -c ../main.c

MOC_GPIO.o:
	g++ -c ../HAL/MOC/MOC_GPIO.c

MOC_UART.o:
	g++ -c ../HAL/MOC/MOC_UART.c

MOC_ADC.o:
	g++ -c ../HAL/MOC/MOC_ADC.c

MOC_SYS.o:
	g++  -c ../HAL/MOC/MOC_SYS.c

UnitTest.o:
	g++ -I../Test -I../Test/include -c ../Test/UnitTest.c

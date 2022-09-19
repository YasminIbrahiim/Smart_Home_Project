################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO.c \
../ICU.c \
../LCD.c \
../LCD_cfg.c \
../LED.c \
../LED_cfg.c \
../main.c 

OBJS += \
./DIO.o \
./ICU.o \
./LCD.o \
./LCD_cfg.o \
./LED.o \
./LED_cfg.o \
./main.o 

C_DEPS += \
./DIO.d \
./ICU.d \
./LCD.d \
./LCD_cfg.d \
./LED.d \
./LED_cfg.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



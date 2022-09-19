################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/EXT_EEPROM(Moaz)/EEPROM.c 

OBJS += \
./HAL/EXT_EEPROM(Moaz)/EEPROM.o 

C_DEPS += \
./HAL/EXT_EEPROM(Moaz)/EEPROM.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/EXT_EEPROM(Moaz)/EEPROM.o: ../HAL/EXT_EEPROM(Moaz)/EEPROM.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"HAL/EXT_EEPROM(Moaz)/EEPROM.d" -MT"HAL/EXT_EEPROM(Moaz)/EEPROM.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



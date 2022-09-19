################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Temp/Temp.c \
../APP/Temp/Temp_cfg.c 

OBJS += \
./APP/Temp/Temp.o \
./APP/Temp/Temp_cfg.o 

C_DEPS += \
./APP/Temp/Temp.d \
./APP/Temp/Temp_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Temp/%.o: ../APP/Temp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



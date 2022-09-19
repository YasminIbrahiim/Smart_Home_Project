################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/EXTINT/EXTINT1/EXTINT1.c 

OBJS += \
./MCAL/EXTINT/EXTINT1/EXTINT1.o 

C_DEPS += \
./MCAL/EXTINT/EXTINT1/EXTINT1.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/EXTINT/EXTINT1/%.o: ../MCAL/EXTINT/EXTINT1/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SERVICE/ICUM/ICUM.c \
../SERVICE/ICUM/ICUM_cfg.c 

OBJS += \
./SERVICE/ICUM/ICUM.o \
./SERVICE/ICUM/ICUM_cfg.o 

C_DEPS += \
./SERVICE/ICUM/ICUM.d \
./SERVICE/ICUM/ICUM_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
SERVICE/ICUM/%.o: ../SERVICE/ICUM/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



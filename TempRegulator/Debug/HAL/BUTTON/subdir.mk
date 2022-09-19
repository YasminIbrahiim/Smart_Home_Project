################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/BUTTON/BUTTON.c \
../HAL/BUTTON/BUTTON_cfg.c 

OBJS += \
./HAL/BUTTON/BUTTON.o \
./HAL/BUTTON/BUTTON_cfg.o 

C_DEPS += \
./HAL/BUTTON/BUTTON.d \
./HAL/BUTTON/BUTTON_cfg.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/BUTTON/%.o: ../HAL/BUTTON/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



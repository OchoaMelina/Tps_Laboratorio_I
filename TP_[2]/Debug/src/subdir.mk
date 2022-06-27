################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ArrayPassenger.c \
../src/Informes.c \
../src/TP_[2].c \
../src/input.c 

C_DEPS += \
./src/ArrayPassenger.d \
./src/Informes.d \
./src/TP_[2].d \
./src/input.d 

OBJS += \
./src/ArrayPassenger.o \
./src/Informes.o \
./src/TP_[2].o \
./src/input.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/ArrayPassenger.d ./src/ArrayPassenger.o ./src/Informes.d ./src/Informes.o ./src/TP_[2].d ./src/TP_[2].o ./src/input.d ./src/input.o

.PHONY: clean-src


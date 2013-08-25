################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tst/FizzBuzzTest.cpp \
../tst/Main.cpp 

OBJS += \
./tst/FizzBuzzTest.o \
./tst/Main.o 

CPP_DEPS += \
./tst/FizzBuzzTest.d \
./tst/Main.d 


# Each subdirectory must supply rules for building sources it contributes
tst/%.o: ../tst/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O2 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/huffman/huffman.cpp \
../src/huffman/main.cpp \
../src/huffman/pQueue.cpp 

OBJS += \
./src/huffman/huffman.o \
./src/huffman/main.o \
./src/huffman/pQueue.o 

CPP_DEPS += \
./src/huffman/huffman.d \
./src/huffman/main.d \
./src/huffman/pQueue.d 


# Each subdirectory must supply rules for building sources it contributes
src/huffman/%.o: ../src/huffman/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



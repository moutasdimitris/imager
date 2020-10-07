################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/skeleton/Imager.cpp \
../src/skeleton/ImagerPhantom.cpp \
../src/skeleton/ImagerUnix.cpp \
../src/skeleton/ImagerWin.cpp 

OBJS += \
./src/skeleton/Imager.o \
./src/skeleton/ImagerPhantom.o \
./src/skeleton/ImagerUnix.o \
./src/skeleton/ImagerWin.o 

CPP_DEPS += \
./src/skeleton/Imager.d \
./src/skeleton/ImagerPhantom.d \
./src/skeleton/ImagerUnix.d \
./src/skeleton/ImagerWin.d 


# Each subdirectory must supply rules for building sources it contributes
src/skeleton/%.o: ../src/skeleton/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -pedantic -pedantic-errors -w -Wall -Wextra -Werror -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



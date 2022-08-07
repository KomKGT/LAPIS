################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
ASM_UPPER_SRCS += \
../ML621367.ASM 

PRNS += \
./ML621367.prn 

PRNS__QUOTED += \
"./ML621367.prn" 

OBJS += \
./ML621367.obj 

OBJS__QUOTED += \
"./ML621367.obj" 


# Each subdirectory must supply rules for building sources it contributes
ML621367.obj: ../ML621367.ASM
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -D -DN -MS -O"./" -WRPEAST -PR"ML621367.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

ML621367.prn: ML621367.obj



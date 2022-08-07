################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source\ files/BlinkLED.c \
../source\ files/VLS.c \
../source\ files/irq_template.c \
../source\ files/main.c \
../source\ files/reset.c \
../source\ files/time_delay.c \
../source\ files/timer0.c \
../source\ files/wdt.c 

PRNS += \
./source\ files/BlinkLED.prn \
./source\ files/VLS.prn \
./source\ files/irq_template.prn \
./source\ files/main.prn \
./source\ files/reset.prn \
./source\ files/time_delay.prn \
./source\ files/timer0.prn \
./source\ files/wdt.prn 

PRNS__QUOTED += \
"./source files/BlinkLED.prn" \
"./source files/VLS.prn" \
"./source files/irq_template.prn" \
"./source files/main.prn" \
"./source files/reset.prn" \
"./source files/time_delay.prn" \
"./source files/timer0.prn" \
"./source files/wdt.prn" 

ASMS += \
./source\ files/BlinkLED.asm \
./source\ files/VLS.asm \
./source\ files/irq_template.asm \
./source\ files/main.asm \
./source\ files/reset.asm \
./source\ files/time_delay.asm \
./source\ files/timer0.asm \
./source\ files/wdt.asm 

ASMS__QUOTED += \
"./source files/BlinkLED.asm" \
"./source files/VLS.asm" \
"./source files/irq_template.asm" \
"./source files/main.asm" \
"./source files/reset.asm" \
"./source files/time_delay.asm" \
"./source files/timer0.asm" \
"./source files/wdt.asm" 

OBJS += \
./source\ files/BlinkLED.obj \
./source\ files/VLS.obj \
./source\ files/irq_template.obj \
./source\ files/main.obj \
./source\ files/reset.obj \
./source\ files/time_delay.obj \
./source\ files/timer0.obj \
./source\ files/wdt.obj 

OBJS__QUOTED += \
"./source files/BlinkLED.obj" \
"./source files/VLS.obj" \
"./source files/irq_template.obj" \
"./source files/main.obj" \
"./source files/reset.obj" \
"./source files/time_delay.obj" \
"./source files/timer0.obj" \
"./source files/wdt.obj" 

IS += \
./source\ files/BlinkLED.i \
./source\ files/VLS.i \
./source\ files/irq_template.i \
./source\ files/main.i \
./source\ files/reset.i \
./source\ files/time_delay.i \
./source\ files/timer0.i \
./source\ files/wdt.i 

IS__QUOTED += \
"./source files/BlinkLED.i" \
"./source files/VLS.i" \
"./source files/irq_template.i" \
"./source files/main.i" \
"./source files/reset.i" \
"./source files/time_delay.i" \
"./source files/timer0.i" \
"./source files/wdt.i" 


# Each subdirectory must supply rules for building sources it contributes
source\ files/BlinkLED.asm: ../source\ files/BlinkLED.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/BlinkLED.i: source\ files/BlinkLED.asm

source\ files/BlinkLED.obj: ./source\ files/BlinkLED.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/BlinkLED.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/BlinkLED.prn: source\ files/BlinkLED.obj

source\ files/VLS.asm: ../source\ files/VLS.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/VLS.i: source\ files/VLS.asm

source\ files/VLS.obj: ./source\ files/VLS.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/VLS.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/VLS.prn: source\ files/VLS.obj

source\ files/irq_template.asm: ../source\ files/irq_template.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/irq_template.i: source\ files/irq_template.asm

source\ files/irq_template.obj: ./source\ files/irq_template.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/irq_template.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/irq_template.prn: source\ files/irq_template.obj

source\ files/main.asm: ../source\ files/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/main.i: source\ files/main.asm

source\ files/main.obj: ./source\ files/main.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/main.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/main.prn: source\ files/main.obj

source\ files/reset.asm: ../source\ files/reset.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/reset.i: source\ files/reset.asm

source\ files/reset.obj: ./source\ files/reset.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/reset.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/reset.prn: source\ files/reset.obj

source\ files/time_delay.asm: ../source\ files/time_delay.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/time_delay.i: source\ files/time_delay.asm

source\ files/time_delay.obj: ./source\ files/time_delay.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/time_delay.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/time_delay.prn: source\ files/time_delay.obj

source\ files/timer0.asm: ../source\ files/timer0.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/timer0.i: source\ files/timer0.asm

source\ files/timer0.obj: ./source\ files/timer0.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/timer0.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/timer0.prn: source\ files/timer0.obj

source\ files/wdt.asm: ../source\ files/wdt.c
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	ccu8 -SD -ABW -TML621367 -MS -near -Fa"source files/" -Od -Zs -W1 "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/wdt.i: source\ files/wdt.asm

source\ files/wdt.obj: ./source\ files/wdt.asm
	@echo 'Building file: $<'
	@echo 'Invoking: Assembler'
	rasu8 -CD -ABW -SD -DN -MS -O"source files/" -WRPEAST -PR"source files/wdt.prn" -L -NS -NR -NPL -NPW "$<"
	@echo 'Finished building: $<'
	@echo ' '

source\ files/wdt.prn: source\ files/wdt.obj



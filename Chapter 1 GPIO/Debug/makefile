################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -f

# All of the sources participating in the build are defined here
-include sources.mk
-include source\ files/subdir.mk
-include subdir.mk
-include objects.mk

-include ../makefile.defs

# Export environment variables
export DCL=D:/U8Dev/Dcl
export INCLU8=D:/U8Dev/Inc;D:/U8Dev/BuildTools/V2_01_00/Inc
export LIBU8=D:/U8Dev/BuildTools/V2_01_00/Lib
export PATH=D:/U8Dev/Bin;D:/U8Dev/BuildTools/V2_01_00/Bin;D:/U8Dev/Utilities/Bin

# Add inputs and outputs from these tool invocations to the build variables 
ABS += \
Chapter\ 1\ GPIO.abs \

MAP += \
Chapter\ 1\ GPIO.map \


# All Target
all: $(ABS)

# Tool invocations
Chapter\ 1\ GPIO.abs: $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	rlu8 -D -SD -NS -CC -ABW $(OBJS__QUOTED),"Chapter 1 GPIO.abs",,"LU8100SW.LIB";
	@echo 'Finished building target: $@'
	@echo ' '

Chapter 1 GPIO.map: Chapter 1 GPIO.abs $(OBJS)

# Other Targets
clean:
	-$(RM) $(SC)$(SC__QUOTED)$(PRNS)$(PRNS__QUOTED)$(ABS)$(ABS__QUOTED)$(ROMHEXRB)$(ROMHEXRB__QUOTED)$(ROMHEXRA)$(ROMHEXRA__QUOTED)$(LOG)$(LOG__QUOTED)$(ASMS)$(ASMS__QUOTED)$(OBJHEX)$(OBJHEX__QUOTED)$(OBJS)$(OBJS__QUOTED)$(COMMON)$(COMMON__QUOTED)$(IS)$(IS__QUOTED)$(MAP)$(MAP__QUOTED)
	-@echo ' '

.PHONY: all clean dependents

-include ../makefile.targets

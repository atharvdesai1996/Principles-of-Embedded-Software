#################################################################################################
# Command for removing files
RM := rm -rf

#################################################################################################
# Include files
INCLUDES := \
	-I"CMSIS" \
	-I"source" \
	-I"board" \
	-I"drivers" \
	-I"utilities" \
	-I"startup"
	
ifeq ($(RUN),fb_debug)
Flag = -Dfb_debug
CC := arm-none-eabi-gcc
LL := arm-none-eabi-gcc
endif

ifeq ($(RUN),fb_run)
Flag = -Dfb_run
CC := arm-none-eabi-gcc
LL := arm-none-eabi-gcc
endif

ifeq ($(RUN),pc_debug)
Flag = -Dpc_debug
CC := gcc
LL := gcc
endif

ifeq ($(RUN),pc_run)
Flag = -Dpc_run
CC := gcc
LL := gcc
CFLAGS = -std=c99
endif

#################################################################################################
# Compiler and Linker 
#CC := arm-none-eabi-gcc
#
#LL := arm-none-eabi-gcc

#################################################################################################
# Binary/exectable to build
EXE := \
  ./debug/PES_PROJECT2.axf

#################################################################################################
# List of dependency files
C_DEPS = \
	./debug/startup_mkl25z4.d \
	./debug/system_MKL25Z4.d \
	./debug/board.d \
	./debug/clock_config.d \
	./debug/peripherals.d \
	./debug/pin_mux.d \
	./debug/fsl_clock.d \
	./debug/fsl_common.d \
	./debug/fsl_flash.d \
	./debug/fsl_gpio.d \
	./debug/fsl_lpsci.d \
	./debug/fsl_smc.d \
	./debug/fsl_uart.d \
	./debug/fsl_rtc.d \
	./debug/fsl_debug_console.d \
	./debug/main.d \
	./debug/RGBled.d
 
#################################################################################################
# List of object files
OBJS := \
	./debug/startup_mkl25z4.o \
	./debug/system_MKL25Z4.o	\
	./debug/board.o \
	./debug/clock_config.o \
	./debug/peripherals.o \
	./debug/pin_mux.o \
	./debug/fsl_clock.o \
	./debug/fsl_common.o \
	./debug/fsl_flash.o \
	./debug/fsl_gpio.o \
	./debug/fsl_lpsci.o \
	./debug/fsl_smc.o \
	./debug/fsl_uart.o \
	./debug/fsl_rtc.o \
	./debug/fsl_debug_console.o \
	./debug/main.o \
	./debug/RGBled.o
	

#################################################################################################
# Include generated dependency files (only if not clean target)
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif


#################################################################################################
# Linker Options
LL_OPTIONS := -nostdlib -Xlinker -Map="debug/PES_PROJECT2.map" \
			-Xlinker --gc-sections -Xlinker -print-memory-usage \
			-mcpu=cortex-m0plus -mthumb -T linkerfile.ld -o $(EXE)

#################################################################################################
# Compiler options
CC_OPTIONS := \
	-c \
	-std=gnu99 \
	-O0 \
	-g3 \
	-ffunction-sections \
	-fmessage-length=0\
	-fno-common \
	-fdata-sections \
	-fno-builtin \
	-mcpu=cortex-m0plus \
	-mthumb \
	
#################################################################################################
# Main (all) target
all: $(EXE)
	@echo "*** Yeah!!! Finished Building ***"

#################################################################################################
# Clean target
clean:
	-$(RM) $(EXECUTABLES) $(OBJS) $(EXE)
	-$(RM) ./debug/*.map
	-@echo "*******Clean Finished!!!*******"
	
#################################################################################################
#Rules to include all build targets
ifeq ($(RUN), fb_run)
#################################################################################################
# Build Options
B_OPTIONS := \
	-D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSDK_OS_BAREMETAL \
	-DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 \
	-DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 \
	-D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DFRDM_KL25Z -DFREEDOM -Dfb_run -specs=redlib.specs \
	
./debug/%.o: ./source/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) $(Flag) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
else ifeq ($(RUN), fb_debug)
#################################################################################################
# Build Options
B_OPTIONS := \
	-D__REDLIB__ -DCPU_MKL25Z128VLK4 -DCPU_MKL25Z128VLK4_cm0plus -DSssDK_OS_BAREMETAL \
	-DFSL_RTOS_BM -DSDK_DEBUGCONSOLE=1 -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 \
	-DSCANF_FLOAT_ENABLE=0 -DPRINTF_ADVANCED_ENABLE=0 -DSCANF_ADVANCED_ENABLE=0 \
	-D__MCUXPRESSO -D__USE_CMSIS -DDEBUG -DFRDM_KL25Z -DFREEDOM -Dfb_debug -specs=redlib.specs \
	
./debug/%.o: ./source/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) $(Flag) -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

else ifeq ($(RUN), pc_run)

	$(CC) $(CFLAGS) -pc_run.c


else ifeq ($(RUN), pc_debug)

	$(CC) $(CFLAGS) -pc_run.c


endif

#################################################################################################

$(EXE): $(OBJS) linkerfile.ld
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	$(LL) $(LL_OPTIONS) $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
 
#################################################################################################
# Rule to build the files in the source folder
./debug/%.o: ./source/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) $(Flag)  -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
#################################################################################################
# Rule to build the files in the CMSIS folder
./debug/%.o: ./board/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
 
./debug/%.o: ./CMSIS/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
./debug/%.o: ./drivers/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

./debug/%.o: ./utilities/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
	
./debug/%.o: ./startup/%.c
	@echo 'Building file: $<'
	$(CC) $(CC_OPTIONS) $(B_OPTIONS) $(INCLUDES) -MMD -MP -MF"./$(@:%.o=%.d)" -MT"./$(@:%.o=%.o)" -MT"./$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '
 # https://mcuoneclipse.com/2017/07/22/tutorial-makefile-projects-with-eclipse/
# Define standard console colors
BLACK        := $(shell tput -Txterm setaf 0)
RED          := $(shell tput -Txterm setaf 1)
GREEN        := $(shell tput -Txterm setaf 2)
YELLOW       := $(shell tput -Txterm setaf 3)
LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
PURPLE       := $(shell tput -Txterm setaf 5)
BLUE         := $(shell tput -Txterm setaf 6)
WHITE        := $(shell tput -Txterm setaf 7)
NC := $(shell tput -Txterm sgr0)

CC := gcc
CFLAGS := -D_WIN32_WINNT=0x0601 -DprojCOVERAGE_TEST=0 -O3 -g3 -Wall -Wextra -fmessage-length=0 -Wcast-qual
LDFLAGS := -Xlinker -Map=rtosdemo.map -lwinmm

# CURRENT ISSUE: need to link to library winmm to build 

BIN := bin
TARGET := win_demo.exe

REL_PATH_TO_RTOS := ../..
REL_PATH_TO_RTOS_Plus := ../../../FreeRTOS-Plus

INCLUDE_DIRS := -I.
INCLUDE_DIRS += -ITrace_Recorder_Configuration
INCLUDE_DIRS += -IDemosModifiedForLowTickRate
INCLUDE_DIRS += -I${REL_PATH_TO_RTOS}/Source
INCLUDE_DIRS += -I${REL_PATH_TO_RTOS}/Source/include
INCLUDE_DIRS += -I${REL_PATH_TO_RTOS}/Demo/Common/include
INCLUDE_DIRS += -I${REL_PATH_TO_RTOS}/Demo/Common/Minimal
INCLUDE_DIRS += -I${REL_PATH_TO_RTOS}/Source/portable/MSVC-MingW
INCLUDE_DIRS += -I${REL_PATH_TO_RTOS_Plus}/Source/FreeRTOS-Plus-Trace/Include

# Generalized all files in relevant directories to grab (internal)
C_FILES := $(wildcard *.c)
C_FILES += $(wildcard DemosModifiedForLowTickRate/*.c)

# Generalized all files in FreeRTOS Source
C_FILES += $(wildcard ${REL_PATH_TO_RTOS}/Source/*.c)

# Generalized all files in FreeRTOS-Plus Source for Trace functions
C_FILES += $(wildcard ${REL_PATH_TO_RTOS_Plus}/Source/FreeRTOS-Plus-Trace/*.c)

# MemMang specific file
C_FILES += ${REL_PATH_TO_RTOS}/Source/portable/MemMang/heap_5.c

# Windows version of the port objects (equivalent to Posix in Linux)
C_FILES += ${REL_PATH_TO_RTOS}/Source/portable/MSVC-MingW/port.c

# Specific set of files to include from Demo/Common/Minimal
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/AbortDelay.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/BlockQ.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/EventGroupsDemo.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/GenQTest.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/IntSemTest.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/MessageBufferAMP.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/MessageBufferDemo.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/PollQ.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/QPeek.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/QueueOverwrite.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/QueueSet.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/QueueSetPolling.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/StaticAllocation.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/StreamBufferDemo.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/StreamBufferInterrupt.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/TaskNotify.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/TimerDemo.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/blocktim.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/countsem.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/death.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/dynamic.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/flop.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/integer.c
C_FILES += ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/semtest.c


C_OBJS := $(patsubst %, $(BIN)/%, $(notdir $(C_FILES:.c=.o) ) )

OBJS := $(C_OBJS)

# Default make actions
all: dir $(TARGET)

# make dir
dir:
	@echo "$(BLUE)Creating bin/...$(NC)"
	mkdir -p bin

# build target
$(TARGET): $(OBJS)
	@echo "$(YELLOW)Linking objects...$(NC)"
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@
	@echo "$(GREEN)Finished!$(NC)"

deps := $(patsubst %.o,%.d,$(OBJS))
-include $(deps)
DEPFLAGS = -MMD -MF $(@:.o=.d)

# build object files
$(BIN)/%.o : %.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

$(BIN)/%.o : DemosModifiedForLowTickRate/%.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

$(BIN)/%.o : ${REL_PATH_TO_RTOS}/Source/%.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

$(BIN)/%.o : ${REL_PATH_TO_RTOS_Plus}/Source/FreeRTOS-Plus-Trace/%.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

$(BIN)/%.o : ${REL_PATH_TO_RTOS}/Source/portable/MemMang/%.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

$(BIN)/%.o : ${REL_PATH_TO_RTOS}/Source/portable/MSVC-MingW/%.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

$(BIN)/%.o : ${REL_PATH_TO_RTOS}/Demo/Common/Minimal/%.c
	@echo "$(LIGHTPURPLE)Compiling C...$(NC)"
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

.PHONY: clean help

clean:
	rm $(TARGET) bin/*.d bin/*.o

help:
	@echo "deps: $(deps)"

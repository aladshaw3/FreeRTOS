# NOTE: This Makefile was edited to 'build-in-place' the objects and
# dependencies such that other neigboring examples would not have to
# build again any common dependencies.

# ALSO NOTE: You need to run '.posix_demo.out' with 'sudo' permissions
# to test the TCP comms demo.

CC := gcc
CXX := g++
BIN := posix_demo.out

FREERTOS_DIR_REL := ../../../FreeRTOS
FREERTOS_DIR := $(abspath $(FREERTOS_DIR_REL))

FREERTOS_PLUS_DIR_REL := ../../../FreeRTOS-Plus
FREERTOS_PLUS_DIR := $(abspath $(FREERTOS_PLUS_DIR_REL))

INCLUDE_DIRS := -I.
INCLUDE_DIRS += -I${FREERTOS_DIR}/Source/include
INCLUDE_DIRS += -I${FREERTOS_DIR}/Source/portable/ThirdParty/GCC/Posix
INCLUDE_DIRS += -I${FREERTOS_DIR}/Source/portable/ThirdParty/GCC/Posix/utils
INCLUDE_DIRS += -I${FREERTOS_DIR}/Demo/Common/include
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/Include
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/portable/NetworkInterface/linux/
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/include/
INCLUDE_DIRS += -I${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/portable/Compiler/GCC/

C_SOURCE_FILES := $(wildcard *.c)
C_SOURCE_FILES += $(wildcard ${FREERTOS_DIR}/Source/*.c)
# Memory manager (use malloc() / free() )
C_SOURCE_FILES += ${FREERTOS_DIR}/Source/portable/MemMang/heap_3.c
# posix port
C_SOURCE_FILES += ${FREERTOS_DIR}/Source/portable/ThirdParty/GCC/Posix/utils/wait_for_event.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Source/portable/ThirdParty/GCC/Posix/port.c

# FreeRTOS TCP
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_DNS.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_DHCP.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_ARP.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_TCP_WIN.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_Stream_Buffer.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/portable/BufferManagement/BufferAllocation_2.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_IP.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_TCP_IP.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_UDP_IP.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/FreeRTOS_Sockets.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-TCP/portable/NetworkInterface/linux/NetworkInterface.c

# Demo library.
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/AbortDelay.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/BlockQ.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/blocktim.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/countsem.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/death.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/dynamic.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/EventGroupsDemo.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/flop.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/GenQTest.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/integer.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/IntSemTest.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/MessageBufferAMP.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/MessageBufferDemo.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/PollQ.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/QPeek.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/QueueOverwrite.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/QueueSet.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/QueueSetPolling.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/recmutex.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/semtest.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/StaticAllocation.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/StreamBufferDemo.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/StreamBufferInterrupt.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/TaskNotify.c
C_SOURCE_FILES += ${FREERTOS_DIR}/Demo/Common/Minimal/TimerDemo.c

# Trace library.
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/trcKernelPort.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/trcSnapshotRecorder.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/trcStreamingRecorder.c
C_SOURCE_FILES += ${FREERTOS_PLUS_DIR}/Source/FreeRTOS-Plus-Trace/streamports/File/trcStreamingPort.c

# C++ files
CXX_SOURCE_FILES := $(wildcard *.cpp)

CFLAGS := -O3 -DprojCOVERAGE_TEST=0
CXXFLAGS := -O3 -std=c++14 -DprojCOVERAGE_TEST=0
LDFLAGS := -O3 -pthread -lpcap

C_OBJ_FILES = $(C_SOURCE_FILES:%.c=%.o)

CXX_OBJ_FILES = $(CXX_SOURCE_FILES:%.cpp=%.o)

OBJ_FILES = $(C_OBJ_FILES) $(CXX_OBJ_FILES)

#DEP_FILE = $(C_OBJ_FILES:%.o=%.d)
DEP_FILE = $(OBJ_FILES:%.o=%.d)


# NOTE: when building with C++ files, the 'main' executable
#	must be compiled with g++.
${BIN} : ${OBJ_FILES}
	$(CXX) $^ $(CXXFLAGS) ${LDFLAGS} -o $@

-include ${DEP_FILE}
DEPFLAGS = -MMD -MF $(@:.o=.d)

#main_blinky.o : main_blinky.c
#	$(CXX) $(CXXFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@


#$(ODIR)/%.o: src/%.c $(DEPS)
#	$(CC) -O3 -c -o $@ $< $(CFLAGS)
#
#$(ODIR)/%.o: src/%.cpp $(DEPS)
#	$(CXX) -O3 -c -o $@ $< $(CXXFLAGS)
#
#$(EXE): $(OBJ)
#	$(CXX) -O3 -o $@ $^ $(CXXFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) ${INCLUDE_DIRS} $(DEPFLAGS) -c $< -o $@

.PHONY: clean help

clean:
	-rm -rf $(OBJ_FILES) $(DEP_FILE) $(BIN)

help:
	@echo "DEPFLAGS: $(DEPFLAGS)"

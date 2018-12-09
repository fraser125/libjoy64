#
# libn64/Makefile: Makefile for libn64.
#
# n64chain: A (free) open-source N64 development toolchain.
# Copyright 2014-16 Tyler J. Stachecki <stachecki.tyler@gmail.com>
#
# This file is subject to the terms and conditions defined in
# 'LICENSE', which is part of this source code package.
#

ifdef SystemRoot
FIXPATH = $(subst /,\,$1)
RM = del /Q
else
FIXPATH = $1
RM = rm -f
endif

AS = mips64-elf-as
AR = mips64-elf-gcc-ar
CC = mips64-elf-gcc
CPP = mips64-elf-cpp

RSPASM = $(call FIXPATH,$(CURDIR)/../tools/bin/rspasm)

CFLAGS = -Wall -Wextra -pedantic -std=c99 -I. -Iinclude
OPTFLAGS = -Os -march=vr4300 -mtune=vr4300 -mabi=eabi -mgp32 -mlong32 \
	-flto -ffat-lto-objects -ffunction-sections -fdata-sections \
	-G4 -mno-extern-sdata -mgpopt -mfix4300 -mbranch-likely \
	-mno-check-zero-division

ASMFILES = $(call FIXPATH,\
)

CFILES = $(call FIXPATH,\
	./src/si.c \
	./src/si_port.c \
	./src/si_auto.c \
)

UCODES = $(call FIXPATH,\
)

OBJFILES = \
	$(CFILES:.c=.o) \
	$(ASMFILES:.s=.o) \
	$(UCODES:.rsp=.o)

DEPFILES = $(OBJFILES:.o=.d)

#
# Primary targets.
#
libjoy64.a: $(OBJFILES)
	@echo $(call FIXPATH,"Building: libjoy64/$@")
	@$(AR) rcs $@ $^

#
# Generic compilation/assembly targets.
#
%.o: %.s
	@echo $(call FIXPATH,"Assembling: libjoy64/$<")
	@$(CC) -x assembler-with-cpp $(CFLAGS) $(OPTFLAGS) -MMD -c $< -o $@

%.o: %.c 
	@echo $(call FIXPATH,"Compiling: libjoy64/$<")
	@$(CC) $(CFLAGS) $(OPTFLAGS) -MMD -c $< -o $@

%.o: %.rsp %.rsps
	@echo $(call FIXPATH,"Assembling: $(ROM_NAME)/$@")
	@$(CPP) -E -Iucodes $< > $(<:.rsp=.rsppch)
	@$(RSPASM) $(<:.rsp=.rsppch) -o $(<:.rsp=.bin)
	@$(CC) -x assembler-with-cpp $(CFLAGS) $(OPTFLAGS) -MMD -c $(<:.rsp=.rsps) -o $@

#
# Clean project target.
#
.PHONY: clean
clean:
	@echo "Cleaning libjoy64..."
	@$(RM) libjoy64.a $(DEPFILES) $(OBJFILES)
	@$(RM) *.d $(DEPFILES) $(OBJFILES)
	@$(RM) *.o $(DEPFILES) $(OBJFILES)
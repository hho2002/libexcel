# Makefile for libexcel.

.PHONY: all clean

SRCS1 = example1.c
OBJS1 = $(SRCS1:.c=.o)

SRCS2 = example2.c
OBJS2 = $(SRCS2:.c=.o)

SRCS3 = merge1.c
OBJS3 = $(SRCS3:.c=.o)

SRCS4 = example3.c
OBJS4 = $(SRCS4:.c=.o)

SRCS5 = example4.c
OBJS5 = $(SRCS5:.c=.o)

CC = gcc
AR = ar

ifeq ($(OS),Windows_NT)
	RM = del /Q /F
else
	RM = rm -f
endif

INTERNAL_CFLAGS = -Wall -I../include
CPPFLAGS += -MMD -MP -MT $@
CFLAGS= -O2 -pipe

EXE1 = example1
EXE2 = example2
EXE3 = merge1
EXE4 = example3
EXE5 = example4

EXES = $(EXE1) $(EXE2) $(EXE3) $(EXE4) $(EXE5)

all: $(EXES)

debug: CPPFLAGS =
debug: CFLAGS = -O0 -g
debug: $(EXES)

$(EXE1): $(OBJS1) ../src/libexcel.a
	$(CC) $(CFLAGS) -o $(EXE1) $(OBJS1) ../src/libexcel.a

$(EXE2): $(OBJS2) ../src/libexcel.a
	$(CC) $(CFLAGS) -o $(EXE2) $(OBJS2) ../src/libexcel.a

$(EXE3): $(OBJS3) ../src/libexcel.a
	$(CC) $(CFLAGS) -o $(EXE3) $(OBJS3) ../src/libexcel.a

$(EXE4): $(OBJS4) ../src/libexcel.a
	$(CC) $(CFLAGS) -o $(EXE4) $(OBJS4) ../src/libexcel.a

$(EXE5): $(OBJS5) ../src/libexcel.a
	$(CC) $(CFLAGS) -o $(EXE5) $(OBJS5) ../src/libexcel.a

tst-string: tst-tstring.o ../src/libexcel.a
	$(CC) $(CFLAGS) -o $@ tst-tstring.o ../src/libexcel.a

clean:
	$(RM) *.o $(EXES)
	$(RM) *.d

.c.o:
	$(CC) $(INTERNAL_CFLAGS) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

# Include automatically generated dependency files
-include $(wildcard *.d)

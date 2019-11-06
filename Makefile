CFLAGS := -g -Wall
LDFLAGS := -lmpich

SOURCES := $(wildcard *.c)
TARGETS := $(SOURCES:.c=)

.PHONY : all clean
all : $(TARGETS)

clean :
	rm -f $(TARGETS)

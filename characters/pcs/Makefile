.PHONY: all clean

PCS=$(basename $(notdir $(wildcard *.c)))

CFLAGS = -I../include
CPPFLAGS = -L../lib -lmtaw

all: $(PCS)

$(PCS):
	gcc $(CFLAGS) $(CPPFLAGS) -o ../bin/$@ $@.c

clean:
	$(RM) -v $(foreach pc, $(PCS), ../bin/$(pc))

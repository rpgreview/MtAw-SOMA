.PHONY: all clean

NPCS=$(basename $(notdir $(wildcard *.c)))

CFLAGS = -I../
CPPFLAGS = -L../lib -lmtaw

all: $(NPCS)

$(NPCS):
	gcc $(CFLAGS) $(CPPFLAGS) -o ../bin/$@ $@.c

clean:
	$(RM) -v $(foreach npc, $(NPCS), ../bin/$(npc))

.PHONY: all clean

PCS=$(basename $(notdir $(wildcard characters/*.c)))
NPCS=$(basename $(notdir $(wildcard npcs/*.c)))
$(info PCS is $(PCS))

all: $(PCS) $(NPCS)

$(PCS):
	gcc -o bin/$@ -I./ common/*.c characters/$@.c

$(NPCS):
	gcc -o bin/$@ -I./ common/*.c npcs/$@.c

clean:
	rm -vf bin/$(PCS) bin/$(NPCS)

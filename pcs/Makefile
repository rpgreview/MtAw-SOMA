.PHONY: all clean

PCS=$(basename $(notdir $(wildcard characters/*.c)))
$(info PCS is $(PCS))

all: $(PCS)

$(PCS):
	gcc -o $@ -I./ common/*.c characters/$@.c

clean:
	rm -vf $(PCS)

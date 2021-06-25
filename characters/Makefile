.PHONY: all pcs npcs clean

all: pcs npcs

pcs npcs: lib/libmtaw.so
	$(MAKE) -C $@

lib/libmtaw.so:
	gcc -o lib/libmtaw.so --shared -fPIC -I./ common/*.c

clean:
	$(RM) -v bin/* lib/libmtaw.so

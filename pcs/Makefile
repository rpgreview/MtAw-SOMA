.PHONY: all characters npcs clean

all: characters npcs

characters npcs: lib/libmtaw.so
	$(MAKE) -C $@

lib/libmtaw.so:
	gcc -o lib/libmtaw.so --shared -fPIC -I./ common/*.c

clean:
	$(RM) -v bin/* lib/libmtaw.so

.PHONY: all clean

all:
	cd lib && make $@
	cd src && make $@
	
clean:
	cd lib && make $@
	cd src && make $@
	

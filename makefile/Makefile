.PHONY: all clean clean_left clean_right 

MODULES := left20 right20

all: clean $(MODULES)

$(MODULES):
	make -f $@.mk

clean: clean_left  clean_right

clean_left:
	make -f left20.mk clean

clean_right:
	make -f right20.mk clean


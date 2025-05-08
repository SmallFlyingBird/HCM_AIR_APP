.PHONY: all clean

MODULES := app 

all: clean $(MODULES)

$(MODULES):
	make -f $@.mk

clean: 
	make -f app.mk clean



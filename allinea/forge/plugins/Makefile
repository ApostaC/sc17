#
# This makefile makes the config file and wrapper library for
# the MPI history logging plugin

MPICC = mpicc -g
TARGET = ../lib/64/libmpihistory.so
HISTORY = history.xml

LOCALTARGET = $(HOME)/.allinea/plugins/libmpihistory.so
LOCALHISTORY = $(HOME)/.allinea/plugins/history.xml

all:	$(TARGET) $(HISTORY)

local: 	$(LOCALTARGET) $(LOCALHISTORY)


$(TARGET):	pmpilib.c
	$(MPICC) -shared $< -g -DPIC -fPIC -o $@


$(LOCALTARGET):	pmpilib.c
	mkdir -p ~/.allinea/plugins
	$(MPICC) -shared $< -g -DPIC -fPIC -o $@

pmpilib.c:	wrapper-source
	wrap/wrap.py $< -o $@

$(HISTORY):	wrapper-config
	wrap/wrap.py -s $< -o $@

$(LOCALHISTORY):	wrapper-config	
	mkdir -p ~/.allinea/plugins
	wrap/wrap.py -s $< -o $@
	sed -i 's%libmpihistory.so%$(LOCALTARGET)%g' $(LOCALHISTORY) 

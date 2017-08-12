# Compile and install the example custom metrics plugin along with the partial report.

# Path to the metrics plugin directory. The metric plugin API
# header files should be in the 'include/' subdirectory to this.
ALLINEA_METRIC_PLUGIN_DIR=../..

CC=gcc
CFLAGS=-fPIC -I$(ALLINEA_METRIC_PLUGIN_DIR)/include
LFLAGS=
DEFAULTCONFIGDIR=~/.allinea

CONFIGDIR = $(ALLINEA_CONFIG_DIR)
ifndef ALLINEA_CONFIG_DIR
    CONFIGDIR = $(DEFAULTCONFIGDIR)
endif

MAPCONFIGDIR = $(CONFIGDIR)/map/metrics
PERFCONFIGDIR = $(CONFIGDIR)/perf-report/reports

.PHONY: all
all: libcustom1.so
	@echo "Use 'make install' to install the metric to $(MAPCONFIGDIR) and the partial report to $(PERFCONFIGDIR) for testing."

libcustom1.so: custom1.c
	$(CC) $(CFLAGS) -shared -o $@ $< $(LFLAGS)

.PHONY: install-metric
install-metric: libcustom1.so custom1.xml
	cp $^ $(MAPCONFIGDIR)

.PHONY: install-partial
install-partial: report.xml
	cp $^ $(PERFCONFIGDIR)

$(CONFIGDIR)/%:
	mkdir -p $@

.PHONY: install
install: $(MAPCONFIGDIR) $(PERFCONFIGDIR) install-metric install-partial

.PHONY: clean
clean:
	-rm libcustom1.so

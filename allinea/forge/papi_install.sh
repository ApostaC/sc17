#!/bin/bash

echo "Welcome to the installer for 'PAPI metrics for Allinea MAP'"
echo "***********************************************************"
echo

PAPI_CUSTOM_METRIC_SRC_FILE="map/metrics/papi/lib-papi.c"
PAPI_DEFAULT_DIR=""
PAPI_LIB_DIR=""
PAPI_INC_DIR=""
SET_PAPI_DIRS="false"

# try to find PAPI installation directory
PAPI_AVAIL_DIR="$(which papi_avail)"
if [ -n "$PAPI_AVAIL_DIR" ]; then
	PAPI_DEFAULT_DIR="$(dirname $(dirname $PAPI_AVAIL_DIR))";
fi

# if a directory is found, tell the user
if [ -e "$PAPI_DEFAULT_DIR/lib/libpapi.so" ]; then
	echo "The PAPI library was found in $PAPI_DEFAULT_DIR/lib/";
    read -p "Do you want to use this PAPI library installation? [Y/N] " answer
    case $answer in
        [yY]*)
            PAPI_LIB_DIR=$PAPI_DEFAULT_DIR/lib
            PAPI_INC_DIR=$PAPI_DEFAULT_DIR/include
            ;;
        *)
          SET_PAPI_DIRS="true"
          ;;
    esac
else
	echo "PAPI library has not been automatically found on this computer";
    SET_PAPI_DIRS="true"
fi

if [ $SET_PAPI_DIRS == "true" ]; then
    echo "Please enter the directory of the PAPI library to be used by Allinea MAP (e.g. /usr/lib): ";
    read -r PAPI_LIB_DIR;
    echo
	echo "Please enter the PAPI include directory (e.g. /usr/include): ";
    read -r PAPI_INC_DIR;
    echo
fi

# check that the directory is valid (by checking that the libpapi.so file exists), and while it is not, ask the user for a valid directory
while [ ! -e $PAPI_LIB_DIR/libpapi.so ]
do
	echo "The PAPI installation directory you have chosen is invalid, $PAPI_LIB_DIR/libpapi.so doesn't exist"
    echo "Please enter the directory of the PAPI library to be used by Allinea MAP (e.g. /usr/lib): ";
    read -r PAPI_LIB_DIR;	
done

# find out where to install the metrics
echo "Type of installation? [S]ystem-wide/[P]ersonal"
read installation

while [ $installation != "S" ] && [ $installation != "P" ]
do
	echo "Unrecognised input. "
	echo "Type of installation? [S]ystem-wide/[P]ersonal"
    echo "Enter 'S' for a system-wide installation or 'P' for a personal installation: ";
	read installation;
done

# for application-wide installation, the metrics will go in forge/map/metrics
if [ $installation == "S" ]; then
	METRICS_DIR=$PWD
	# check that the user has write permissions
	if [ ! -w $METRICS_DIR/map/metrics ]; then
		echo "You do not have permission to make a system-wide installation.";
		installation="P";
	fi
fi

# for personal installation, the metrics will go in .allinea/map/metrics
if [ $installation == "P" ]; then
	METRICS_DIR=$ALLINEA_CONFIG_DIR
fi

if [ -z "$METRICS_DIR" ]; then
	METRICS_DIR=$HOME/.allinea
fi

METRICS_DIR=$METRICS_DIR/map/metrics
mkdir -p $METRICS_DIR

echo "Installing PAPI metrics..."
echo

# compile the PAPI metrics library
if gcc -fPIC -Imap/metrics/include -I$PAPI_INC_DIR -o $METRICS_DIR/lib-papi.so $PAPI_CUSTOM_METRIC_SRC_FILE -L$PAPI_LIB_DIR -lpapi -shared; then
    # copy the XML file to where it should be
    cp map/metrics/papi/papi.xml $METRICS_DIR
    cp map/metrics/papi/PAPI.config $METRICS_DIR

    echo "Installation complete"
    echo
    # prompt the user to set the environment variables
    echo "Set the following environment variable before starting Allinea MAP: "
    echo "        export ALLINEA_PAPI_CONFIG=$METRICS_DIR/PAPI.config"
    echo
    echo "If you are using a queuing system you should also set and export ALLINEA_PAPI_CONFIG to the compute nodes."
    echo "This can be done by adding the ALLINEA_PAPI_CONFIG export line in the job script before the MAP command line."

else
    echo "Error: Installation failed"
fi


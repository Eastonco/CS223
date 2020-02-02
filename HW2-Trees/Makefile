#
# Makefile framework for CptS223
#
# Hacked up by Aaron Crandall, 2017
#  Aaron S. Crandall <acrandal@wsu.edu
#

# Variables
GPP         = g++
CFLAGS      = -g -std=c++11 -Wall -Wshadow -Wconversion
GTESTFLAGS  = -pthread -lgtest
RM          = rm -f
BINNAME     = main
TESTNAME    = test_main
TESTFLAGS   = -fprofile-arcs -ftest-coverage
BINDIR      = bin
LCOVINFO    = coverage.info
COVHTMLDIR  = coverage_report

SHELL := /bin/bash

# Default is what happenes when you call make with no options
#  In this case, it requires that 'all' is completed
default: all

# All is the normal default for most Makefiles
#  In this case, it requires that Hello is completed
all: build

build:
	@echo "Nothing to do for build"

# Run your program
# Note: this will first execute the 'build' target to ensure a program to run
run: build
	@echo "Nothing to do for run"

# Builds the test driver system with gtest and gmock
test:
	@echo "Test checks for PDF file in this HW directory"
	@echo " NOTE: Linux filesystems are case sensitive"
	@echo "  This means the file extension (the letters after the .)"
	@echo "  should be lowercase in general."
	@if (test -f *.pdf || test -f *.PDF); then  	\
		echo "Solutions pdf file found - passed";	\
	else 											\
		echo "!!! - No solutions file found"; 		\
		exit 1; 									\
	fi

starter-tests: test

base-tests: test

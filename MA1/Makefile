#
# Makefile framework for CptS223
#
# Hacked up by Aaron Crandall, 2017
#  Aaron S. Crandall <acrandal@wsu.edu
#

# Variables
GPP         = g++
CFLAGS      = -g -std=c++11
GTESTFLAGS  = -pthread -lgtest
RM          = rm -f
BINNAME     = helloworld
TESTNAME    = test_helloworld
TESTFLAGS   = -fprofile-arcs -ftest-coverage
BINDIR      = bin
LCOVINFO    = coverage.info
COVHTMLDIR  = coverage_report
SCREENSHOT_TEST = test_screenshot.sh

# Default is what happenes when you call make with no options
#  In this case, it requires that 'all' is completed
default: all

# All is the normal default for most Makefiles
#  In this case, it requires that Hello is completed
all: build

# Hello depends upon helloworld.cpp, then runs the command:
#  g++ -g -std=c++11 -o HelloWorld helloworld.cpp
build: $(BINNAME).cpp
	mkdir -p $(BINDIR)
	$(GPP) $(CFLAGS) -o $(BINDIR)/$(BINNAME) $(BINNAME).cpp

# Run your program
# Note: this will first execute the 'build' target to ensure a program to run
run: build
	@echo "Running the $(BINNAME) program"
	./$(BINDIR)/$(BINNAME)

# Test the program - first build to ensure it works
starter-tests: build
	@echo "Testing the $(BINNAME) program."
	$(GPP) $(CFLAGS) $(TESTFLAGS) -o $(BINDIR)/$(TESTNAME) $(TESTNAME).cpp $(GTESTFLAGS)
	./$(BINDIR)/$(TESTNAME)

# Check for the screenshot file. This is a PHONY target, this means that there
#   are no files that it depends on being changed to run. This is done as
#   the file in question is of an unknown name and changes to the test itself
#   do not dictate when this needs to be run
.PHONY: base-tests
base-tests: 
	@bash $(SCREENSHOT_TEST)

# Generate a code coverage report to show our unit testing is working
#  gcov is installed with g++ by default
#  lcov needs to be installed 'apt-get install lcov'
#  genhtml comes with lcov
coverage: build test
	@echo "Generating code coverage report on unit testing"
	gcov --relative-only $(TESTNAME).cpp
	lcov --no-external --capture --directory . --output-file $(LCOVINFO)
	genhtml $(LCOVINFO) --output-directory $(COVHTMLDIR)
	@echo "Run 'make clean' to remove all of these temp files"
	@echo ">>> Go into the $(COVHTMLDIR) and load index.html with browser for report"
	@echo ">>> If this is the GitLab server, there should be artifacts to look at on the right for this testing coverage job"
	

# If you call "make clean" it will remove the built program
# Removes binaries: BINNAME, TESTNAME
# Removes code coverage temp files: *.gcno, *.gcda, *.gcov
clean veryclean:
	$(RM) $(BINDIR)/$(BINNAME) $(BINDIR)/$(TESTNAME) *.gcno *.gcda *.gcov $(LCOVINFO)
	$(RM) -r $(COVHTMLDIR)

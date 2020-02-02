#
# Makefile framework for CptS223
#
# Hacked up by Aaron Crandall, 2017
#  Aaron S. Crandall <acrandal@wsu.edu
#

# Variables
GPP         = g++
CFLAGS      = -g -std=c++11 -I . -Wall -Wshadow -Wconversion
GTESTFLAGS  = -pthread -lgtest
RM          = rm -f
BINNAME     = main
TESTNAME    = test_main
TESTFLAGS   = -fprofile-arcs -ftest-coverage
BINDIR      = bin
LCOVINFO    = coverage.info
COVHTMLDIR  = coverage_report

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

# Builds the test driver system with gtest and gmock
build-test: build
	@echo "Building the test driver program"
	$(GPP) $(CFLAGS) $(TESTFLAGS) -o $(BINDIR)/$(TESTNAME) $(TESTNAME).cpp $(GTESTFLAGS)

# Execute only starter tests - should all pass
starter-tests: build build-test
	@echo "Running assignment starter code tests"
	./$(BINDIR)/$(TESTNAME) --gtest_filter=Starter*

# Execute tests for the basic assignment - leaves out the "Big" tests
base-tests: build build-test
	@echo "Running tests for assignment's basic features"
	./$(BINDIR)/$(TESTNAME) --gtest_filter=Base*

# Execute big tests for basic assignment
big-tests: build build-test
	@echo "Running BIG tests for assignment's basic features"
	./$(BINDIR)/$(TESTNAME) --gtest_filter=Big*


# Test the program - first build to ensure it works - But not the "Big" tests
test: build build-test 
	@echo "Testing the full $(BINNAME) program suite."
	./$(BINDIR)/$(TESTNAME) --gtest_filter=-Big*
	@echo " -- NOTE: For larger tests run: \"make big-tests\""

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

# Executes a memory leak check using the valgrind tool
memcheck: build
	@echo "Running program checks like memory leaks and linting"
	valgrind --error-exitcode=1 --leak-check=full --trace-children=yes ./$(BINDIR)/$(BINNAME)


# If you call "make clean" it will remove the built program
# Removes binaries: BINNAME, TESTNAME
# Removes code coverage temp files: *.gcno, *.gcda, *.gcov
clean veryclean:
	$(RM) $(BINDIR)/$(BINNAME) $(BINDIR)/$(TESTNAME) *.gcno *.gcda *.gcov $(LCOVINFO)
	$(RM) -r $(COVHTMLDIR) $(BINDIR)

# If you call "make starwars" it'll give you Star Wars!"
# Must have telnet installed (apt-get install telnet)
movie:
	telnet towel.blinkenlights.nl

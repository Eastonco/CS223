# Hello World with unit testing

Hello World is a common first program to write. It shows that you can access your build environment, edit files, and actually run a program of your own creation. Normally, "Hello World" is very very short - often just a single print command in some kind of main function/routine. This Hello World is a little more complex. I *highly* suggest that you read through what's happening here because the pattern will be repeated throughout this course.

The reason this is a much more complex Hello World example is because it is designed to be *tested* and not just run. This is a form of unit testing: https://en.wikipedia.org/wiki/Unit\_testing

You'll notice that the print\_hello\_world() function doesn't just print to std::cout. If it did that, we'd need to close stdout, open it as a file to buffer the output and then look at what it printed to verify that it printed out the correct thing. Instead, the function is told where to print out. By default in our helloworld.cpp main() we pass it std::cout, which would be the normal use. That's what a user would see, but if you inspect the test\_helloworld.cpp program you'll find that it does something different. We use a stringbuffer instead of std::cout. That means when the print function "prints" to the ostream (stringbuffers inherit from ostream and are drop in replacements for them), the string it passes along is buffered in the stringbuffer. We can then inspect the contents for accuracy.

Why do this? There's actually three reasons:
  1) The tool can then run the Google Test (gtest) framework to run tests and tell us if our program is acting properly
  2) Future uses of print\_hello\_world() could pass other ostream objects to the class. These could be logging streams, a filehandle, a network socket, or anything else that's an ostream. You won't need to change print\_hello\_world one bit to be able to "print" to these very different places.
  3) This type of code is testable and buildable on the Git Lab Continuous Integration system. Every time you commit your code to the GitLab server (gitlab.eecs.wsu.edu) the server will try to build your code and run the tests. Later assignments shall have *many* tests that you'll need to satisfy to complete assignments. The automated tests let you know quickly about your progress.

To build the Hello World program, you can use GNU Make to execute the commands. This system uses what's called a Makefile to run commands. These are essentially scripts that have all kinds of dependency checking tools to ensure you're building software (or other things - I used Make to build my PhD dissertation in LaTeX) correctly and uniformly. The things you can run in this Makefile are:
  * make build
  * make test
  * make run
  * make clean

Build will build your program, test builds and runs the tests, run executes the main program, and clean removes temporary files.

### Google Test

To run the tests you'll need to install Google Test (gtest) onto your system. For Ubuntu/Mint/Debian (or Debian Linux forks), this HOWTO should show you the process:
    https://www.eriksmistad.no/getting-started-with-google-test-on-ubuntu/
  It's essentially about 6 commands that you can copy/paste into place.

### GitLab

Git is a program for keeping versions of files in a 'repository' (repo). As you edit files, you can commit versions to allow you check changes over time and even revert to old versions if things go off the rails.

GitLab is a server backend for Git. The server can act as a central origin for a Git repo. As you edit/update files, you commit and push them to the GitLab server. You then have a backed up copy of your repo.

Git allows for repo branches, (the main one is normally called 'master'), merging between branches, repos, and multiple origins. The whole system takes time and energy to learn, but it's incredibly worth figuring out. *Every* company who comes to hire interns and recent grads uses some kind of version control system and the #1 choice for industry today is Git.

In this course, the *only* way for you to turn in code is through git. You'll have a personal private repo that's setup for you on the VCEA/EECS GitLab server (gitlab.eecs.wsu.edu). You *must* commit and push your code there for the TAs to look at your work. Failure to push to the repo will leave you with zeros on assignment scores, so invest the time needed to learn how to use the tool.

Additionally, every assignment (should be every one) shall have a test harness with it. When your repo is given an assignment, these tests shall have failures, your job will be to make them pass. You can run these tests locally (which is way faster) by installing Google Test on your Linux system, while the GitLab server shall run the tests itself whenever you commit and push to the server.

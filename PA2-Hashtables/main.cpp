/*
 * Hash tables implementation 
 *
 * Contributors:
 *  Aaron Crandall <acrandal@wsu.edu> - 2019 - First version
 *
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

/*
 * Main function, but nothing much here
 */
int main( int argc, char* argv[] ) {
    std::cout << " [x] Running main program - nothing to do!" << std::endl;
    std::cout << "     Since it's quiet, here's a Mars Rover..." << std::endl;
    std::cout << std::endl;

    std::string image = R"( [''''''''''''''''''''''''''''''''''''''''''''''''''''''])" "\n"
                        R"( [ \--------MARS PATHFINDER MISSION - 1997-----~~~~~~~/ ])" "\n"
                        R"( [ |                                          {USA ///} ])" "\n"
                        R"( [ |                                          {32 /*\/} ])" "\n"
                        R"( [ |                                          {  /* *\} ])" "\n"
                        R"( [ |                                           ~~~~~~~| ])" "\n"
                        R"( [ |              __                       _          | ])" "\n"
                        R"( [ |             /\ `\_                   /\`\_       | ])" "\n"
                        R"(D[ |            /  ~   \      .          /  ~  \      | ])" "\n"
                        R"(a[ |___________/________\_____|_________/_______\_____| ])" "\n"
                        R"(n[ |   .^^____  ^       ______|_^.^  ___ ^ .  _ .^^  .| ])" "\n"
                        R"(a[ |.^. _/   _\_^  Q]-,  | __ |_  ^ |   \ ^^ / \  ^. ^| ])" "\n"
                        R"( [ | ^ |    '   \.     \_|/__\_|_ ^ \____\.^ \__\ ^ ^.| ])" "\n"
                        R"(9[ |^.^\____\____\^.^  (o):(o):(o)::::::::::::::::::::| ])" "\n"
                        R"(7[ /--------------------------------------------------\ ])" "\n"
                        R"(  '''''''''''''''''''''''''''''''''''''''''''''''''''''')" ;

    std::cout << image << std::endl;
    std::cout << std::endl;

    return 0;
}

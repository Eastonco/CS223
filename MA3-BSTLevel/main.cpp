/*
 * Binary Search Tree implementation 
 *  - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations BST
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 * Aaron Crandall - 2017 - Heavy overhaul of tests & behaviors
 * Aaron Crandall - 2019 - Integration with gtest and GitLab CI
 *
 */

#include <iostream>
#include <cstring>  // strcmp
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <math.h>   // pow (for exponents)

#include "BST.h"	//BST implementation

using namespace std;

/*
 * run big test - LOTS of data in your tree!
 */
/*
void run_big_test() {
    cout << " [t] Beginning BIG tree test! " << endl;
    srand ((unsigned int) time(NULL));  // Initialize random seed
    BST<int> bst = BST<int>();
    int tree_size = pow(2.0, 20.0);
    cout << endl << "  [t] Testing tree of size (2^20): " << tree_size << endl;
    cout << "Node # / Of #'s (\% done) : Value Inserted " << endl;
    for( int i = 1; i < tree_size + 1; i++ ) {
        int val = rand() % tree_size + 1;
        cout << "\r" << i << " / " << tree_size << " (" << 100.0*i / tree_size << "%)"  << "  :  " << val;
        bst.add(val);
    }

    cout << endl << endl;
    cout << "Nodes count (" << tree_size << "): " << bst.nodesCount();
    if( bst.nodesCount() == tree_size )
        cout << "\t[PASS]";
    else
        cout << "\t[FAIL]";
    cout << endl;
    cout << "Height: " << bst.height() << endl;
    cout << "Max path:  ";
    bst.printMaxPath();
    cout << endl << endl;

    cout << " [t] BIG tree test done!" << endl;
    return;
}
*/


/*
 * Main function - includes enabling test mode
 */
int main( int argc, char* argv[] ) {
	bool is_test_mode = false;
	bool is_BIG_test_mode = false;
	for( int i = 0; i < argc; i++ ) {
		if( !strcmp(argv[i], "--test" ) ) {
			cout << " [t] Enabling test mode. " << endl;
			is_test_mode = true;
		} else if ( !strcmp(argv[i], "--bigtest" ) ) {
			cout << " [t] Enabling BIG test mode. " << endl;
			is_BIG_test_mode = true;
        }
	}

	if( is_test_mode || is_BIG_test_mode ) {
		//run_tests();
        if( is_BIG_test_mode )
            {;}
 //           run_big_test();
	}else{
		cout << " [x] Running main program - nothing to do!" << endl;
        cout << "     Since it's quiet, here's a flower..." << endl << endl;
        cout << ""
"              __/)\n"
"           .-(__(=:\n"
"        |\\ |    \\)\n"
"ejm97   \\ ||\n"
"         \\||\n"
"          \\|\n"
"           |\n"
"        \n";
	}

    return 0;
}

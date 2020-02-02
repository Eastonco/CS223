#!/usr/bin/env python3
"""
    Script to generate lists of vectors in C++11 format

    Contributors:
        Aaron S. Crandall <acrandal@wsu.edu>

    Copyright 2019
    License: educational use only

    Inputs: STDIN with one string per line
    Outputs: c++11 formatted vector of strings in random order

    Options:    Total vector length
                Percentage of duplicates
"""

import argparse
import logging
import random
import sys


def handle_argv():
    """ Parse argv and pull out parameters """
    parser = argparse.ArgumentParser()
    parser.add_argument("-d", "--debug", action="store_true")
    parser.add_argument("-q", "--quiet", action="store_true")
    parser.add_argument("--total_strings", default=100, help="Total quantity of strings in vector")
    parser.add_argument("--pct_dups", default=20, help="Percentage of strings made as dups")
    parser.add_argument("--sorted", default=False, action="store_true", help="Whether to sort the strings in vector")
    parser.add_argument("--vector_name", default="myVec", help="The vector's variable name")
    args = parser.parse_args()

    args.total_strings = int(args.total_strings)
    args.pct_dups = float(args.pct_dups)
    return args


def setup_logging(args):
    """ Use arguments to set the logging level and do other bookeeping """
    logger = logging.getLogger()
    logger.setLevel(logging.INFO)
    if args.debug:
        logger.setLevel(logging.DEBUG)
    elif args.quiet:
        logger.setLevel(logging.WARN)

def read_in_strings():
    logging.info("Reading in STDIN for strings")
    input_strings = []
    for line in sys.stdin:
        input_strings.append(line.strip())
    logging.info("Done reading in STDIN for strings")
    return input_strings


def generate_vector(args):
    input_strings = read_in_strings()

    # Generate the non-duplicate strings
    non_dup_strings = []

    non_duplicate_count = int(args.total_strings * (1 - float(args.pct_dups) / 100))
    logging.info("Non Duplicate Count: {0}".format(non_duplicate_count))
    duplicate_count = args.total_strings - non_duplicate_count
    logging.info("Duplicate Count: {0}".format(duplicate_count))

    while len(non_dup_strings) < non_duplicate_count:
        random_string_index = random.randint(0, len(input_strings) - 1)
        selected_string = input_strings[random_string_index]
        if selected_string not in non_dup_strings:
            non_dup_strings.append(selected_string)
    logging.debug("Number of non-dups: {0}".format(len(non_dup_strings)))

    # Generate the duplicate strings
    dup_strings = []

    while len(dup_strings) < duplicate_count:
        random_string_index = random.randint(0, len(non_dup_strings) - 1)
        selected_string = non_dup_strings[random_string_index]
        if selected_string not in dup_strings:
            dup_strings.append(selected_string)
    logging.debug("Number of dups: {0}".format(len(dup_strings)))

    all_strings = non_dup_strings + dup_strings
    if args.sorted:
        logging.info("Sorting strings")
        all_strings.sort()
    else:
        logging.info("Shuffling strings")
        random.shuffle(all_strings)

    words_per_row = 10
    print("std::vector<std::string> {0}{1}".format(args.vector_name, '{'))
    rows = (int(len(all_strings) / words_per_row)) + 1
    for row_num in range(rows-1):
        curr_slice = all_strings[row_num * words_per_row : (row_num + 1) * words_per_row]
        row_str = "\", \"".join(curr_slice)
        row_str = "\"" + row_str + "\""
        if row_num < rows - 2:
            row_str += ","
        print("      " + row_str)
    print("    };")
    print()

    print("std::vector<std::string> {0}{1}".format(args.vector_name + "_dups", '{'))
    rows = (int(len(dup_strings) / words_per_row)) + 1
    for row_num in range(rows-1):
        curr_slice = dup_strings[row_num * words_per_row : (row_num + 1) * words_per_row]
        row_str = "\", \"".join(curr_slice)
        row_str = "\"" + row_str + "\""
        if row_num < rows - 2:
            row_str += ","
        print("      " + row_str)
    print("    };")


if __name__ == "__main__":
    args = handle_argv()
    setup_logging(args)

    logging.info("Starting vector generation")
    generate_vector(args)
    logging.info("Done")

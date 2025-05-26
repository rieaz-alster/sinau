Problem: Word Frequency Counter

Description:
Write a program that takes a string of text as input and counts how many times each word appears in it.

Requirements:

    Use std::unordered_map<std::string, int> to store word frequencies.

    Use C++11 features:

        auto for type deduction

        Range-based for loop to iterate over map entries

        Initializer list to populate a small test string for simplicity

Constraints:

    Words are separated by spaces only (no punctuation handling needed for now).

    Assume lowercase letters only.

Input:

    Input can be a hardcoded string initialized via std::string text = "this is a test this is only a test";

Expected Output:

this: 2
is: 2
a: 2
test: 2
only: 1



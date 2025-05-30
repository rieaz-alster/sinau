I found problem that is interesting to be solved. It is called Word Frequency Counter. It goes like this:

Write a program that takes a string of text as input and counts how many times each word appears in it.

Constraints:
    - Words are separated by spaces only (no punctuation handling needed for now).
    - Assume lowercase letters only.
    - Input can be a hardcoded string initialized via std::string text = "this is a test this is only a test";
    - Use C++98 only. (eg, with compiler flag --std==c++98).

Let's see the solution (in C++98):

1. Tokenize the string using string::find() and string::substr() to extract words separated by spaces.

    Code:
    size_t pos = text.find(' ');
    string substr = text.substr(0, pos);

    We also need to trim the input text, removing word that we picked before

    Code:
    text = text.substr(pos+1);

2. Put substrings into mapped answer, increment count each time it is appear
    With std::map<string, int> result as our variable for our answer, check if substring has already existing in our answer.

    Code:
    map<string, int>::iterator it = result.find(substr); 

    If it resulted with map::end(), that's it, substring not found, put new std::pair<> into result.
    Else, increment the substring count.

    Code:
    if(it == result.end())
    {
        /*If substring doesn't exist, add new pair*/
        result.insert(pair<string, int>(substr, 1));
    }
    else
    {
        /*If substring exist, increment its count*/
        it->second++;
    }

3. Display result
    Code:
    for(map<string, int>::iterator it = result.begin(); it != result.end(); it++)
    {
        cout << it->first << ": " << it->second << endl;
    }
    
This is the logic and snippet about how to solve this problem. Because it still use C++98, it feels verbose and manual.

Check the Github for solution:
https://github.com/rieaz-alster/sinau/tree/main/Lesson_WordFrequencyCounter

What do you think? How would you improve this in C++98 or later?
# Word Count

Given a phrase, count the occurrences of each word in that phrase.

For the purposes of this exercise you can expect that a word will always be one of:

1. A *number* composed of one or more ASCII digits (ie "0" or "1234") OR
2. A *simple word* composed of one or more ASCII letters (ie "a" or "they") OR
3. A *contraction* of two simple words joined by a single apostrophe (ie "it's" or "they're")

When counting words you can assume the following rules:

1. The count is *case insensitive* (ie "You", "you", and "YOU" are 3 uses of the same word)
2. The count is *unordered*; the tests will ignore how words and counts are ordered
3. Other than the apostrophe in a contraction all forms of *punctuation are ignored*
4. The words can be separated by any form of whitespace (ie "\t", "\n", " ")

For example, for the phrase 

    "That's the password: 'PASSWORD 123'!", cried the Special Agent.\nSo I fled.
    
the count would be:

    that's: 1
    the: 2
    password: 2
    123: 1
    cried: 1
    special: 1
    agent: 1
    so: 1
    i: 1
    fled: 1

## Example

```cpp
words("\"That's the password: 'PASSWORD 123'!\", cried the Special Agent.\nSo I fled.") == {{"that's", 1}, {"the", 2}, {"password", 2}, 
                                                                                            {"123", 1}, {"cried", 1}, {"special",1},
                                                                                            {"agent", 1}, {"so", 1}, {"i", 1}, {"fled", 1}}
```
## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)
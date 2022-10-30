# Anagram

An anagram is a rearrangement of letters to form a new word. Given a word and a list of candidates, select the sublist of anagrams of the given word.

Given `"listen"` and a list of candidates like `"enlists" "google" "inlets" "banana"` the program should return a list containing `"inlets"`.

## Example

```cpp
anagram subject("listen");
subject.matches({"enlists", "google", "inlets", "banana"}) == "inlets";
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)

# Scrabble Score

Given a word, compute the Scrabble score for that word.

**Letter Values**
You'll need these:

    Letter                           Value
    A, E, I, O, U, L, N, R, S, T       1
    D, G                               2
    B, C, M, P                         3
    F, H, V, W, Y                      4
    K                                  5
    J, X                               8
    Q, Z                               10

**Examples**
"cabbage" should be scored as worth 14 points:

* 3 points for C
* 1 point for A, twice
* 3 points for B, twice
* 2 points for G
* 1 point for E

And to total:

* `3 + 2*1 + 2*3 + 2 + 1`
* `= 3 + 2 + 6 + 3`
* `= 5 + 9`
* `= 14`

**Extensions**
* You can play a double or a triple letter.
* You can play a double or a triple word.

## Example

```cpp
score("cabbage") == 14;
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)

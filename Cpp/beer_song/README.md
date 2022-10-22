# Beer Song

Recite the lyrics to that beloved classic, that field-trip favorite: 99 Bottles of Beer on the Wall.

Note that not all verses are identical.

    99 bottles of beer on the wall, 99 bottles of beer.
    Take one down and pass it around, 98 bottles of beer on the wall.

    98 bottles of beer on the wall, 98 bottles of beer.
    Take one down and pass it around, 97 bottles of beer on the wall.

    97 bottles of beer on the wall, 97 bottles of beer.
    Take one down and pass it around, 96 bottles of beer on the wall.

    ...

    1 bottle of beer on the wall, 1 bottle of beer.
    Take it down and pass it around, no more bottles of beer on the wall.

    No more bottles of beer on the wall, no more bottles of beer.
    Go to the store and buy some more, 99 bottles of beer on the wall.

**For bonus points**
Did you get the tests passing and the code clean? If you want to, these are some additional things you could try:

* Remove as much duplication as you possibly can.
* Optimize for readability, even if it means introducing duplication.
* If you've removed all the duplication, do you have a lot of conditionals? Try replacing the conditionals with polymorphism, if it applies in this language. How readable is it?

## Example

```cpp
verse(8) == "8 bottles of beer on the wall, 8 bottles of beer.\n"
            "Take one down and pass it around, 7 bottles of beer on the wall.\n"
sing(8,7) == "8 bottles of beer on the wall, 8 bottles of beer.\n"
             "Take one down and pass it around, 7 bottles of beer on the wall.\n"
             "\n"
             "7 bottles of beer on the wall, 7 bottles of beer.\n"
             "Take one down and pass it around, 6 bottles of beer on the wall.\n"
```

## License
[MIT](https://choosealicense.com/licenses/mit/)

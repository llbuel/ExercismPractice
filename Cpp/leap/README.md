# Leap Year

Given a year, report if it is a leap year.

The tricky thing here is that a leap year in the Gregorian calendar occurs:

    on every year that is evenly divisible by 4
        except every year that is evenly divisible by 100
            unless the year is also evenly divisible by 400

For example, 1997 is not a leap year, but 1996 is. 1900 is not a leap year, but 2000 is.

## Example

```cpp
leap::is_leap_year(1800) == false

leap::is_leap_year(1996) == true
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)

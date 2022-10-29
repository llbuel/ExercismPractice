# Meetup

**Note:** The tests for this program use the Boost date-time libraries.

Calculate the date of meetups.

Typically meetups happen on the same day of the week. In this exercise, you will take a description of a meetup date, and return the actual meetup date.

Examples of general descriptions are:

* The first Monday of January 2017
* The third Tuesday of January 2017
* The wednesteenth of January 2017
* The last Thursday of January 2017

The descriptors you are expected to parse are: first, second, third, fourth, fifth, last, monteenth, tuesteenth, wednesteenth, thursteenth, friteenth, saturteenth, sunteenth

Note that "monteenth", "tuesteenth", etc are all made up words. There was a meetup whose members realized that there are exactly 7 numbered days in a month that end in '-teenth'. Therefore, one is guaranteed that each day of the week (Monday, Tuesday, ...) will have exactly one date that is named with '-teenth' in every month.

Given examples of a meetup dates, each containing a month, day, year, and descriptor calculate the date of the actual meetup. For example, if given "The first Monday of January 2017", the correct meetup date is 2017/1/2.

## Example

```cpp
scheduler meetup(boost::gregorian::Jan, 2017).first_monday() == boost::gregorian::date(2017, boost::gregorian::Jan, 2)
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)

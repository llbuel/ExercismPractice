# All Your Base

Convert a number, represented as a sequence of digits in one base, to any other base.

Implement general base conversion. Given a number in base **a**, represented as a sequence of digits, convert it to base **b**.

**Note**
* Try to implement the conversion yourself. Do not use something else to perform the conversion for you.

**About Positional Notation**

In positional notation, a number in base **b** can be understood as a linear combination of powers of **b**.

The number 42, in base 10, means:

    (4 * 10^1) + (2 * 10^0)

The number 101010, in base 2, means:

    (1 * 2^5) + (0 * 2^4) + (1 * 2^3) + (0 * 2^2) + (1 * 2^1) + (0 * 2^0)

The number 1120, in base 3, means:

    (1 * 3^3) + (1 * 3^2) + (2 * 3^1) + (0 * 3^0)

*(Performing the above computations will show all three are the same number, given in different bases)*

## Example

```cpp
convert(2,{1,0,1,0,1,0},10) == {4,2};
convert(3,{1,1,2,0},2) == {1,0,1,0,1,0};
```

## Installation/Usage

[See the ExercismPractice README for general usage and installation details.](https://github.com/Lignite17/ExercismPractice/blob/main/README.md)

## License
[MIT](https://choosealicense.com/licenses/mit/)

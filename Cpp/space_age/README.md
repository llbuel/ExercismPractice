# Space Age

Given an age in seconds, calculate how old someone would be on:

Mercury: orbital period 0.2408467 Earth years

Venus: orbital period 0.61519726 Earth years

Earth: orbital period 1.0 Earth years, 365.25 Earth days, or 31557600 seconds

Mars: orbital period 1.8808158 Earth years

Jupiter: orbital period 11.862615 Earth years

Saturn: orbital period 29.447498 Earth years

Uranus: orbital period 84.016846 Earth years

Neptune: orbital period 164.79132 Earth years

So if you were told someone were 1,000,000,000 seconds old, you should be able to say that they're 31.69 Earth-years old.

## Example 

```cpp
//An age given in seconds
age(30000000000)

//Age in Earth years and then in Saturn years
age.on_earth() == 95.06
age.on_saturn() == 3.23
```

## License
[MIT](https://choosealicense.com/licenses/mit/)

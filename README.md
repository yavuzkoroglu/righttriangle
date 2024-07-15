# righttriangle

Generates all the integer right triangles with a minimum side length less than or equal to `<min_side_limit>`.

## Usage

```
Usage: bin/righttriangle <min_side_limit>
```

## How To Clone This Repository

```
git clone https://github.com/yavuzkoroglu/righttriangle.git
cd righttriangle
```

## How To Build

```
make
```

## Example Usage (`<min_side_limit>` = 16)

```
bin/righttriangle 16
```

## Example Output (`<min_side_limit>` = 16)

```
  1: (  3,   4,   5)
  2: (  5,  12,  13)
  3: (  6,   8,  10)
  4: (  7,  24,  25)
  5: (  8,  15,  17)
  6: (  9,  12,  15)
  7: (  9,  40,  41)
  8: ( 10,  24,  26)
  9: ( 11,  60,  61)
 10: ( 12,  16,  20)
 11: ( 12,  35,  37)
 12: ( 13,  84,  85)
 13: ( 14,  48,  50)
 14: ( 15,  20,  25)
 15: ( 15,  36,  39)
 16: ( 15, 112, 113)
 17: ( 16,  30,  34)
 18: ( 16,  63,  65)
```

# righttriangle

Generates all the integer right triangles with a perimeter less than or equal to `<max_perimeter>`.

## Usage

```
Usage: bin/righttriangle <max_perimeter>
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

## Example Usage (`<max_perimeter>` = 100)

```
bin/righttriangle 100
```

## Example Output (`<max_perimeter>` = 100)

```
  1: perimeter = 12	( 3,  4,  5)
  2: perimeter = 24	( 6,  8, 10)
  3: perimeter = 30	( 5, 12, 13)
  4: perimeter = 36	( 9, 12, 15)
  5: perimeter = 40	(15,  8, 17)
  6: perimeter = 48	(12, 16, 20)
  7: perimeter = 56	( 7, 24, 25)
  8: perimeter = 60	(10, 24, 26)
  9: perimeter = 60	(15, 20, 25)
 10: perimeter = 70	(21, 20, 29)
 11: perimeter = 72	(18, 24, 30)
 12: perimeter = 80	(30, 16, 34)
 13: perimeter = 84	(21, 28, 35)
 14: perimeter = 84	(35, 12, 37)
 15: perimeter = 90	( 9, 40, 41)
 16: perimeter = 90	(15, 36, 39)
 17: perimeter = 96	(24, 32, 40)

```

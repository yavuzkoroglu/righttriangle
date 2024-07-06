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

## Example Usage (`<max_perimeter>` = 200)

```
bin/righttriangle 200
```

## Example Output (`<max_perimeter>` = 200)

```
  1: perimeter = 12   ( 3,  4,  5)
  2: perimeter = 24   ( 6,  8, 10)
  3: perimeter = 30   ( 5, 12, 13)
  4: perimeter = 36   ( 9, 12, 15)
  5: perimeter = 48   (12, 16, 20)
  6: perimeter = 56   ( 7, 24, 25)
  7: perimeter = 60   (10, 24, 26)
  8: perimeter = 60   (15, 20, 25)
  9: perimeter = 72   (18, 24, 30)
 10: perimeter = 84   (21, 28, 35)
 11: perimeter = 90   ( 9, 40, 41)
 12: perimeter = 90   (15, 36, 39)
 13: perimeter = 96   (24, 32, 40)
 14: perimeter = 108  (27, 36, 45)
 15: perimeter = 112  (14, 48, 50)
 16: perimeter = 120  (20, 48, 52)
 17: perimeter = 120  (30, 40, 50)
 18: perimeter = 132  (11, 60, 61)
 19: perimeter = 132  (33, 44, 55)
 20: perimeter = 144  (36, 48, 60)
 21: perimeter = 150  (25, 60, 65)
 22: perimeter = 156  (39, 52, 65)
 23: perimeter = 168  (21, 72, 75)
 24: perimeter = 168  (42, 56, 70)
 25: perimeter = 180  (18, 80, 82)
 26: perimeter = 180  (30, 72, 78)
 27: perimeter = 180  (45, 60, 75)
 28: perimeter = 182  (13, 84, 85)
 29: perimeter = 192  (48, 64, 80)

```
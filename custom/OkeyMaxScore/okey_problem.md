### 101 Okey Maximum Score

You are given $n$ tiles, each defined by a color (integer 1 - 4) and a number(1 - 13).

You can form groups of tiles. Each tile may belong to at most one group. There are two types of valid groups:

- **Set:** 3 or 4 tiles with the **same number** but **different colors**.
- **Run:** 3 or more tiles with the **same color** and **consecutive numbers**.

The score is the sum of the numbers on all the tiles used in groups.
Your task is to compute the maximum achievable score.

**Input**
- The first input line contains an integer $n$: the number of tiles.
- The following $n$ lines describe the tiles. Each line contains two integers $c$ and $x$: the color and the number of the tile.

**Output**
- Print one integer: the maximum achievable score.

### Examples
Input:
```
7
1 3
1 4
1 5
2 3
3 3
4 3
2 4
```
Output:
```
21
```

---

Input:
```
21
1 1
1 2
1 3
1 4
2 3
2 4
2 5
3 5
3 6
3 7
4 7
4 8
4 9
1 10
2 10
3 10
4 10
1 12
2 12
3 12
4 12

```
Output:
```
152
```

Explanation
[Red 1, Red 2, Red 3, Red 4] [Blue 3, Blue 4, Blue 5] [Yellow 5, Yellow 6, Yellow 7] [Black 7, Black 8, Black 9, Black 10] [Red 10, Blue 10, Yellow 10] [Red 12, Blue 12, Yellow 12, Black 12]

or

[Red 1, Red 2, Red 3, Red 4] [Blue 3, Blue 4, Blue 5] [Yellow 5, Yellow 6, Yellow 7] [Black 7, Black 8, Black 9] [Red 10, Blue 10, Yellow 10, Black 10] [Red 12, Blue 12, Yellow 12, Black 12]

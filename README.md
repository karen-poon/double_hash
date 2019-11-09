# double_hash

This program prints the result of double hashing depending on h1, h2 and keys.

- h1 is the first hash function
- h2 is the second hash function
- keys are the values to be inserted into the hash table

For example,
```
h1 = k % 11
h2 = 3k % 4 + 1
keys = {8, 19, 30, 12, 14, 13, 44}
```

The output will be:
```
0 --- 30
1 --- 12
2 --- 13
3 --- 14
4 --- 44
5
6
7
8 --- 8
9
10 --- 19
```

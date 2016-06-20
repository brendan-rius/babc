# babc

babc is a simple, yet useful, C library implementing some features a standard
library should have.

I co-wrote with [Louis Person](https://github.com/kureuil) during our first
year at Epitech, for our personal use. Thus, it respects a lot of Epitech's
standard and programming style.

The project does not rely on third-party libraries.

## Features

### Vectors

Vectors are dynamically-sized lists implemented with arrays.

### Strings

Strings are dynamically-sized strings, implemented with vectors. They support
some useful operations (replace, split, ...)

### Linked-lists

An implementation of linked lists.

### Hashtables

An implementation of hashtables (usually used as dictionaries).

### Binary search tree

An implementation of binary search trees.

### Dictionaries

A dictionary "interface" able to choose its implementation from:
 * linked list
 * hashtable

### Iterators and foreach loop

Most of the data structures provide iterators, that can be used in a "foreach"
loop.

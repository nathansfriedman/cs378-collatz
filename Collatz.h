// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2011
// Glenn P. Downing
// --------------------------

// --------
// includes
// --------

#include <cassert> // assert
#include <iostream> // endl, istream, ostream

// ------------
// collatz_read
// ------------

/**
* reads two ints into i and j
* @param r a std::istream
* @param i an int by reference
* @param j an int by reference
* @return true if that succeeds, false otherwise
*/
bool collatz_read (std::istream& r, int& i, int& j) {
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
    return true;}

// ------------
// collatz_eval
// ------------

/**
* @param i the beginning of the range, inclusive
* @param j the end of the range, inclusive
* @return the max cycle length in the range [i, j]
*/
int collatz_eval (int i, int j) {
    assert(i > 0);
    assert(j > 0);

    // <your code>
	int v = 1;
	int cycle_length = 1;
	while (i <= j) {
		int num = i;
		while (num != 1) {
			if (num % 2 == 0) {
				num = num / 2;
				++ cycle_length;
			}
			else {
				num = (3 * num + 1) / 2;
				cycle_length += 2;
			}
		}
		if (cycle_length > v) {
			v = cycle_length;
		}
		cycle_length = 1;
		++i;
	}

    assert(v > 0);
    return v;}

// -------------
// collatz_print
// -------------

/**
* prints the values of i, j, and v
* @param w a std::ostream
* @param i the beginning of the range, inclusive
* @param j the end of the range, inclusive
* @param v the max cycle length
*/
void collatz_print (std::ostream& w, int i, int j, int v) {
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;}

// -------------
// collatz_solve
// -------------

/**
* read, eval, print loop
* @param r a std::istream
* @param w a std::ostream
*/
void collatz_solve (std::istream& r, std::ostream& w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}

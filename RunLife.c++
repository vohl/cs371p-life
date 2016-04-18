// -------------------------
// projects/life/RunLife.c++
// Copyright (C) 2016
// Glenn P. Downing
// -------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // cout, endl
#include "Life.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----------------------
    // Life<ConwayCell> 21x13
    // ----------------------

    cout << "*** Life<ConwayCell> 21x13 ***\n" << endl;
    /*
    Simulate 12 evolutions.
    Print every grid (i.e. 0, 1, 2, 3, ... 12)
    */

    Life<ConwayCell> c1(21, 13);

    c1.readInGrid(cin);

    c1.simulate(12, 1);

    // ----------------------
    // Life<ConwayCell> 20x29
    // ----------------------

    cout << "*** Life<ConwayCell> 20x29 ***\n" << endl;
    /*
    Simulate 28 evolutions.
    Print every 4th grid (i.e. 0, 4, 8, ... 28)
    */

    Life<ConwayCell> c2(20, 29);

    c2.readInGrid(cin);

    c2.simulate(28, 4);

    // -----------------------
    // Life<ConwayCell> 109x69
    // -----------------------

    cout << "*** Life<ConwayCell> 109x69 ***\n" << endl;
    /*
    Simulate 283 evolutions.
    Print the first 10 grids (i.e. 0, 1, 2, ... 9).
    Print the 283rd grid.
    Simulate 40 evolutions.
    Print the 323rd grid.
    Simulate 2177 evolutions.
    Print the 2500th grid.
    */

    Life<ConwayCell> c3(109, 69);

    c3.readInGrid(cin);

    c3.simulate(9, 1);
    c3.simulate(283-9);
    c3.simulate(40);
    c3.simulate(2177);

    // -----------------------
    // Life<FredkinCell> 20x20
    // -----------------------

    cout << "*** Life<FredkinCell> 20x20 ***\n" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    Life<FredkinCell> f1(20, 20);

    f1.readInGrid(cin);

    f1.simulate(5, 1);

    // ----------------
    // Life<Cell> 20x20
    // ----------------

    cout << "*** Life<Cell> 20x20 ***\n" << endl;
    /*
    Simulate 5 evolutions.
    Print every grid (i.e. 0, 1, 2, ... 5)
    */

    Life<Cell> h1(20, 20);

    h1.readInGrid(cin);
    h1.simulate(5, 1);

    return 0;}
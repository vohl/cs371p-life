// --------
// includes
// --------

#include "gtest/gtest.h"
#include "Life.h"
#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair



// ------------
// AbstractCell
// ------------
TEST(TestLife, ac_construct1){
    AbstractCell x = AbstractCell('x');
    ASSERT_EQ(x._state, 'x');
}

TEST(TestLife, ac_isAlive){
    AbstractCell x = AbstractCell();
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, ac_countDiagonals){
    AbstractCell x = AbstractCell();
    ASSERT_EQ(x.countDiagonals(), false);
}

TEST(TestLife, ac_getState){
    AbstractCell x = AbstractCell('x');
    ASSERT_EQ(x.getState(), 'x');
}

TEST(TestLife, ac_clone){
    AbstractCell x = AbstractCell();
    ASSERT_EQ(x.clone(), nullptr);
}

// ----------
// ConwayCell
// ----------

TEST(TestLife, cc_construct0){
    ConwayCell x = ConwayCell();
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cc_construct1){
    ConwayCell x = ConwayCell('*');
    ASSERT_EQ(x._state, '*');
}

TEST(TestLife, cc_construct2){
    ConwayCell x = ConwayCell('*');
    ASSERT_EQ(x._life, true);
}

TEST(TestLife, cc_construct3){
    ConwayCell x = ConwayCell('.');
    ASSERT_EQ(x._life, false);
}

TEST(TestLife, cc_construct4){
    ConwayCell x = ConwayCell('.');
    ASSERT_EQ(x._state, '.');
}

TEST(TestLife, cc_isAlive1){
    ConwayCell x = ConwayCell('*');
    ASSERT_EQ(x.isAlive(), true);
}

TEST(TestLife, cc_isAlive2){
    ConwayCell x = ConwayCell('.');
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cc_countDiagonals){
    ConwayCell x = ConwayCell('.');
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cc_updateLife1){
    ConwayCell x = ConwayCell('*');
    x.updateLife(1);
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cc_updateLife2){
    ConwayCell x = ConwayCell('*');
    x.updateLife(1);
    ASSERT_EQ(x._state, '.');
}

TEST(TestLife, cc_updateLife3){
    ConwayCell x = ConwayCell('*');
    x.updateLife(1);
    ASSERT_EQ(x._life, false);
}

TEST(TestLife, cc_updateLife4){
    ConwayCell x = ConwayCell('*');
    x.updateLife(4);
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cc_updateLife5){
    ConwayCell x = ConwayCell('*');
    x.updateLife(4);
    ASSERT_EQ(x._state, '.');
}

TEST(TestLife, cc_updateLife6){
    ConwayCell x = ConwayCell('*');
    x.updateLife(4);
    ASSERT_EQ(x._life, false);
}

TEST(TestLife, cc_updateLife7){
    ConwayCell x = ConwayCell('.');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
}

TEST(TestLife, cc_updateLife8){
    ConwayCell x = ConwayCell('.');
    x.updateLife(3);
    ASSERT_EQ(x._state, '*');
}

TEST(TestLife, cc_updateLife9){
    ConwayCell x = ConwayCell('.');
    x.updateLife(3);
    ASSERT_EQ(x._life, true);
}

TEST(TestLife, cc_updateLife10){
    ConwayCell x = ConwayCell('*');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
}

TEST(TestLife, cc_updateLife11){
    ConwayCell x = ConwayCell('*');
    x.updateLife(3);
    ASSERT_EQ(x._state, '*');
}

TEST(TestLife, cc_updateLife12){
    ConwayCell x = ConwayCell('*');
    x.updateLife(3);
    ASSERT_EQ(x._life, true);
}

TEST(TestLife, cc_clone){
    ConwayCell x = ConwayCell('*');
    ConwayCell* y = x.clone();
    ASSERT_EQ(y->_state, x._state);
    ASSERT_EQ(y->_life, x._life);
}

// -----------
// FredkinCell
// -----------

TEST(TestLife, fc_construct0){
    FredkinCell x = FredkinCell();
    ASSERT_EQ(x._life, false);
    ASSERT_EQ(x._age, 0);
}

TEST(TestLife, fc_construct1){
    FredkinCell x = FredkinCell('-');
    ASSERT_EQ(x._life, false);
    ASSERT_EQ(x._age, 0);
    ASSERT_EQ(x._state, '-');
}

TEST(TestLife, fc_construct2){
    FredkinCell x = FredkinCell('+');
    ASSERT_EQ(x._life, true);
    ASSERT_EQ(x._age, 10);
    ASSERT_EQ(x._state, '+');
}

TEST(TestLife, fc_construct3){
    FredkinCell x = FredkinCell('5');
    ASSERT_EQ(x._life, true);
    ASSERT_EQ(x._age, 5);
    ASSERT_EQ(x._state, '5');
}

TEST(TestLife, fc_isAlive1){
    FredkinCell x = FredkinCell('-');
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, fc_isAlive2){
    FredkinCell x = FredkinCell('+');
    ASSERT_EQ(x.isAlive(), true);
}

TEST(TestLife, fc_countDiagonals){
    FredkinCell x = FredkinCell('-');
    ASSERT_EQ(x.countDiagonals(), false);
}

TEST(TestLife, fc_updateLife1){
    FredkinCell x = FredkinCell('-');
    x.updateLife(4);
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, fc_updateLife2){
    FredkinCell x = FredkinCell('-');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
    ASSERT_EQ(x._state, '0');
    ASSERT_EQ(x._age, 0);
}

TEST(TestLife, fc_updateLife3){
    FredkinCell x = FredkinCell('3');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
    ASSERT_EQ(x._state, '4');
    ASSERT_EQ(x._age, 4);
}

TEST(TestLife, fc_updateLife4){
    FredkinCell x = FredkinCell('+');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
    ASSERT_EQ(x._state, '+');
    ASSERT_EQ(x._age, 10);
}

TEST(TestLife, fc_updateLife5){
    FredkinCell x = FredkinCell('9');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
    ASSERT_EQ(x._state, '+');
    ASSERT_EQ(x._age, 10);
}

TEST(TestLife, fc_updateLife6){
    FredkinCell x = FredkinCell('+');
    x.updateLife(2);
    ASSERT_EQ(x.isAlive(), false);
    ASSERT_EQ(x._state, '-');
    ASSERT_EQ(x._age, 0);
}

TEST(TestLife, fc_clone){
    FredkinCell x = FredkinCell('+');
    FredkinCell* y = x.clone();
    ASSERT_EQ(x.isAlive(), y->isAlive());
    ASSERT_EQ(x._state, y->_state);
    ASSERT_EQ(x._age, y->_age);
}

// ----
// Cell
// ----
TEST(TestLife, cell_construct0){
    Cell x = Cell();
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_construct1){
    Cell x = Cell('.');
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_construct2){
    Cell x = Cell('*');
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_construct3){
    Cell x = Cell('+');
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_construct4){
    Cell x = Cell('2');
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_construct5){
    Cell x = Cell('0');
    ASSERT_EQ(x.countDiagonals(), false);
}

TEST(TestLife, cell_construct6){
    Cell x = Cell('-');
    ASSERT_EQ(x.countDiagonals(), false);
}

TEST(TestLife, cell_cconstruct1){
    Cell x = Cell('.');
    Cell y = Cell(x);
    ASSERT_EQ(y.countDiagonals(), true);
}

TEST(TestLife, cell_cconstruct2){
    Cell x = Cell('-');
    Cell y = Cell(x);
    ASSERT_EQ(y.countDiagonals(), false);
}

TEST(TestLife, cell_ass_op1){
    Cell x = Cell('.');
    Cell y = x;
    ASSERT_EQ(y.countDiagonals(), true);
}

TEST(TestLife, cell_ass_op2){
    Cell x = Cell('-');
    Cell y = x;
    ASSERT_EQ(y.countDiagonals(), false);
}

// TEST(TestLife, cell_acc_op1){
//     Cell x = Cell('.');
//     AbstractCell* y;
//     y = x->_handle_cell;
//     ASSERT_EQ(y.countDiagonals(), true);
// }

TEST(TestLife, cell_updateLife1){
    Cell x = Cell('9');
    x.updateLife(3);
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_updateLife2){
    Cell x = Cell('2');
    x.updateLife(3);
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_updateLife3){
    Cell x = Cell('*');
    x.updateLife(3);
    ASSERT_EQ(x.countDiagonals(), true);
}

TEST(TestLife, cell_updateLife4){
    Cell x = Cell('.');
    x.updateLife(1);
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cell_updateLife5){
    Cell x = Cell('*');
    x.updateLife(0);
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cell_updateLife6){
    Cell x = Cell('5');
    x.updateLife(0);
    ASSERT_EQ(x.isAlive(), false);
}

TEST(TestLife, cell_updateLife7){
    Cell x = Cell('.');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
}

TEST(TestLife, cell_updateLife8){
    Cell x = Cell('-');
    x.updateLife(3);
    ASSERT_EQ(x.isAlive(), true);
}

// ----
// Life
// ----

TEST(TestLife, Life_construct1){
    Life<Cell> x = Life<Cell>(10, 10);
    ASSERT_EQ(x._generation, 0);
}

TEST(TestLife, Life_readInGrid1){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    ASSERT_EQ(x._board.size(), 144);
}

TEST(TestLife, Life_readInGrid2){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    ASSERT_EQ(x._population, 0);
}

TEST(TestLife, Life_readInGrid3){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    ASSERT_EQ(x._population, 1);
}

TEST(TestLife, Life_simulate1){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("..***.....\n...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x._population, 6);
}

TEST(TestLife, Life_simulate2){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("..........\n...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x._population, 0);
}

TEST(TestLife, Life_simulate3){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("...*9*....\n...**.....\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x.at(14).countDiagonals(), true);
}

TEST(TestLife, Life_simulate4){
    Life<ConwayCell> x = Life<ConwayCell>(10, 10);
    istringstream y("..***.....\n...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x._population, 6);
}

TEST(TestLife, Life_simulate5){
    Life<ConwayCell> x = Life<ConwayCell>(10, 10);
    istringstream y("..........\n...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x._population, 0);
}

TEST(TestLife, Life_simulate6){
    Life<FredkinCell> x = Life<FredkinCell>(10, 10);
    istringstream y("----1-----\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x._population, 3);
}

TEST(TestLife, Life_simulate7){
    Life<FredkinCell> x = Life<FredkinCell>(10, 10);
    istringstream y("----1-----\n---111----\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n----------\n");
    x.readInGrid(y);
    x.simulate(1, 1);
    ASSERT_EQ(x._population, 9);
}

TEST(TestLife, Life_iterator){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("..........\n...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    vector<Cell>::iterator b = x.begin();
    vector<Cell>::iterator e = x.end();
    while(b != e) {++b; ASSERT_EQ(true, true);}
}

TEST(TestLife, Life_at){
    Life<Cell> x = Life<Cell>(10, 10);
    istringstream y("..........\n...*......\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n..........\n");
    x.readInGrid(y);
    ASSERT_EQ(x.at(0).isAlive(), false);
}
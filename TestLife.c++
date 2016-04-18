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
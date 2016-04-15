#ifndef LIFE_H
#define LIFE_H

//----------
// includes
//----------
#include <cstddef>
#include <iostream>
#include <vector>

using namespace std;

//--------------
// AbstractCell
//--------------
class AbstractCell{
protected:
    char _state;
public:
    AbstractCell(char state);

    //a getter for your life, but techinically just telling
    //me if you are alive/ I dont necceserily have to maintain
    //a private member that represent if you are alive
    virtual bool isAlive() = 0;

    //should this cell consider diagonal neighbors??
    virtual bool countDiagonals() = 0;

    //changing the state of the cell
    virtual void updateLife(int neighbors) = 0;

    //so we can print it out durring an update
    friend ostream& operator <<(ostream& lhs, const AbstractCell& rhs);
};

//inherits from abstract cell
//------------
// ConwayCell
//------------
class ConwayCell : public AbstractCell{
private:
	bool _life;
public:
    ConwayCell(char state);

    ~ConwayCell();

    bool countDiagonals();

    void updateLife(int neighbors);

    friend ostream& operator <<(ostream& lhs, const ConwayCell& rhs);
};

//inherits from abstract cell
//-------------
// FredkinCell
//-------------
class FredkinCell : public AbstractCell{
private:
    int _age;
    bool _life;
public:
    FredkinCell(char state);

    ~FredkinCell();

    bool countDiagonals();

    void updateLife(int neighbors);

    friend ostream& operator <<(ostream& lhs, const FredkinCell& rhs);
};

//------
// Cell
//------
class Cell{
private:
    AbstractCell * _handle_cell;
public:
    Cell(char alive);

    Cell(const Cell& rhs);

    Cell& operator =(const Cell& rhs);

    ~Cell();

    AbstractCell * operator ->();

    bool countDiagonals();

    void updateLife(int neighbors);

    friend ostream& operator <<(ostream& lhs, const Cell& rhs);
};

//------
// Life
//------
Template<typename T>
class Life{
public:
    using value_type = T;

    using reference = value_type&;
    using const_reference = const value_type&;

private:
    int _x;
    int _y;
    int _generation;
    int _population;
    vector<T> _board;
    vector<int> _neighbor_board;

    void show(int evolution);

public:
    Life(int y, int x);

    void readInGrid(istream & r);

    void simulate(int evolution, int step = 1);

    vector<value_type>::iterator begin();

    vector<value_type>::const_iterator begin() const;

    vector<value_type>::iterator end();

    vector<value_type>::const_iterator end() const;

    reference at(size_type);

    const_reference at(size_type) const;

    bool operator == (const Life &rhs);

    bool operator == (const Life &rhs) const;

    bool operator != (const Life &rhs);

    bool operator != (const Life &rhs) const;
};

#endif LIFE_H
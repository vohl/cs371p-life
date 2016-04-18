#ifndef LIFE_H
#define LIFE_H

//----------
// includes
//----------
#include <cstddef>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//--------------
// AbstractCell
//--------------
class AbstractCell{
protected:
    char _state;
public:
    AbstractCell();

    AbstractCell(char state);

    virtual ~AbstractCell();

    //a getter for your life, but techinically just telling
    //me if you are alive/ I dont necceserily have to maintain
    //a private member that represent if you are alive
    virtual bool isAlive();

    //should this cell consider diagonal neighbors??
    virtual bool countDiagonals();

    //changing the state of the cell
    virtual void updateLife(int neighbors);

    //cloning pattern so that when vector resizes copy constructor works as intended
    virtual AbstractCell * clone() const;

    char getState();

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
    ConwayCell();

    ConwayCell(char state);

    ~ConwayCell();

    bool isAlive();

    bool countDiagonals();

    void updateLife(int neighbors);

    ConwayCell * clone() const;

    friend ostream& operator <<(ostream& lhs, const ConwayCell& rhs);
};

//inherits from abstract cell
//-------------
// FredkinCell
//-------------
class FredkinCell : public AbstractCell{
private:
    bool _life;
    int _age;
public:
    FredkinCell();

    FredkinCell(char state);

    ~FredkinCell();

    bool isAlive();

    bool countDiagonals();

    void updateLife(int neighbors);

    FredkinCell * clone() const;

    friend ostream& operator <<(ostream& lhs, const FredkinCell& rhs);
};

//------
// Cell
//------
class Cell{
private:
    AbstractCell * _handle_cell;
public:
    Cell();

    Cell(char state);

    Cell(const Cell& rhs);

    Cell& operator =(const Cell& rhs);

    ~Cell();

    //This can be used to get the pointer indirectly call
    //methods belonging to that little turdNugget
    AbstractCell * operator ->() const;

    bool isAlive();

    bool countDiagonals();

    void updateLife(int neighbors);

    friend ostream& operator <<(ostream& lhs, const Cell& rhs);
};

//------
// Life
//------
template<typename T>
class Life{
private:
    int _x;
    int _y;
    int _generation;
    int _population;
    vector<T> _board;
    vector<int> _neighbor_board;

public:
    Life(int y, int x) : _x(x), _y(y), _generation(0), _population(0){}

    void readInGrid(istream & r){
        for (int i = 0; i < (_x+2); ++i){
            _board.push_back(T());
        }
        for (int i = 0; i < (_y); ++i){
            _board.push_back(T());
            string s;
            getline(r, s);
            istringstream sin(s);
            for (int j = 0; j < (_x); ++j){
                char c;
                sin >> c;
                T var = T(c);
                if (var.isAlive()){
                    ++_population;
                }
                _board.push_back(var);
                _neighbor_board.push_back(0);
            }
            _board.push_back(T());
        }
        for (int i = 0; i < (_x+2); ++i){
            _board.push_back(T());
        }
        string s;
        getline(r, s);
    }

    void show(){
        cout << "Generation = " << _generation << ", Population = " << _population << "." << endl;
        for (int i = 1; i <= _y; ++i){
            for (int j = 1; j <= _x; ++j){
                cout << _board[(i * (_x + 2)) + j];
            }
            cout << endl;
        }
        cout << endl;
    }

    void simulate(int evolution, int step = 0){
        for (int i = 0; i < evolution; ++i){
            if (step > 0){
                if ((i % step) == 0){
                    this->show();
                }
            }
            _population = 0;

            for (int row = 1; row <= _y; ++row){
                for (int col = 1; col <= _x; ++col){
                    int currindex = ((_x+2)*row) + col;
                    int neighindex = ((_x)*(row-1)) + col - 1;

                    _neighbor_board[neighindex] = 0;

                    if ((_board[currindex - (_x+2)]).isAlive()) ++_neighbor_board[neighindex];
                    if ((_board[currindex - 1]).isAlive()) ++_neighbor_board[neighindex];
                    if ((_board[currindex + 1]).isAlive()) ++_neighbor_board[neighindex];
                    if ((_board[currindex + (_x+2)]).isAlive()) ++_neighbor_board[neighindex];
                    if ((_board[currindex]).countDiagonals()){
                        if ((_board[currindex - (_x+2) - 1]).isAlive()) ++_neighbor_board[neighindex];
                        if ((_board[currindex - (_x+2) + 1]).isAlive()) ++_neighbor_board[neighindex];
                        if ((_board[currindex + (_x+2) + 1]).isAlive()) ++_neighbor_board[neighindex];
                        if ((_board[currindex + (_x+2) - 1]).isAlive()) ++_neighbor_board[neighindex];
                    }
                }
            }

            for (int row = 1; row <= _y; ++row){
                for (int col = 1; col <= _x; ++col){
                    int currindex = ((_x+2)*row) + col;
                    int neighindex = ((_x)*(row-1)) + col - 1;
                    (_board[currindex]).updateLife(_neighbor_board[neighindex]);
                    if ((_board[currindex]).isAlive()){
                        ++_population;
                    }
                }
            }
            ++_generation;
        }
        this->show();
    }

    typename vector<T>::iterator begin(){
        return _board.begin();
    }

    typename vector<T>::const_iterator begin() const{
        return _board.begin();
    }

    typename vector<T>::iterator end(){
        return _board.end();
    }

    typename vector<T>::const_iterator end() const{
        return _board.end();
    }

    T& at(int i){
        return _board.at(i);
    }

    const T& at(int i) const{
        return _board.at(i);
    }
};

#endif
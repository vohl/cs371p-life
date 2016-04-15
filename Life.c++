
//----------
// includes
//----------
#include <cstddef>
#include <iostream>
#include <vector>

#include "Life.h"

using namespace std;

//------------------
// friend_functions
//------------------
ostream& operator <<(ostream& lhs, const AbstractCell& rhs){
	return lhs << rhs._state;
}

ostream& operator <<(ostream& lhs, const ConwayCell& rhs){
	return lhs << rhs._state;
}

ostream& operator <<(ostream& lhs, const FredkinCell& rhs){
	return lhs << rhs._state;
}

ostream& operator <<(ostream& lhs, const Cell& rhs){
	return lhs << (*(rhs._handle_cell));
}

//--------------
// AbstractCell
//--------------
AbstractCell::AbstractCell(char state) : _state(state){}

//------------
// ConwayCell
//------------
ConwayCell::ConwayCell(char state) : AbstractCell(state){
    if (state == '*'){
        _life = true;
    }
    else if (state == '.'){
        _life = false;
    }
}

bool ConwayCell::countDiagonals(){
    return true;
}

void ConwayCell::updateLife(int neighbors){
    if (_life){
        if (neighbors < 2 || neighbors > 3){
            _life = false;
            _state = '.';
        }
    }
    else{
        if (neighbors == 3){
            _life = true;
            _state = '*';
        }
    }
}

//-------------
// FredkinCell
//-------------

FredkinCell::FredkinCell(char state) : AbstractCell(state){
    if (state == '-'){
        _life = false;
        _age = 0;
    }
    else if (state == '+'){
        _life = true;
        _age = 10;
    }
    else if (){
        
    }
}

bool FredkinCell::countDiagonals(){
    return false;
}

void FredkinCell::updateLife(int neighbors){

}

//------
// Life
//------

Life::Life(int y, int x){
	_x(x);
	_y(y);
	_generation(0);
	board = new vector<T>(((x+2)*(y+2)), T());
	neighbor_board = new vector<T>((x+2)*(y+2), 0);
} 

void Life::readInGrid(istream & r){
	string s;
	char currentCell; 
	getline(r, s);

	for(int row = 1; row <= _y; ++row){
		istringstream in(s);
		for(int col = 1; col <= _x; ++col){
			in >> currentCell;
			board[((_x+2)*row) + col] = (new T(currentCell));
			if(currentCell != '.') ++_population;
		}
		getline(r, s);
	}
}

void Life::simulate(int evolution, int step){
	std::cout << "Generation = 0, Population = " << _population << "." << std::endl;
	for(int row = 1; row <= _x; ++row){
		for (int col = 1; col <= _y; ++col){
			std::cout << board[(_x+2)*row + col];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	for(int i = 1; i <= evolution; ++i){		
		for(int row = 1; row <= _x; ++row){
			for (int col = 1; col <= _y; ++col){
				int currindex = ((_x+2)*row) + col; 
				if(board[currindex - (_x*2)]) ++neighbor_board[currindex];
				if(board[currindex - 1]) ++neighbor_board[currindex];
				if(board[currindex + 1]) ++neighbor_board[currindex];
				if(board[currindex + (_x*2)]) ++neighbor_board[currindex];
				if(board[currindex].countDiagonals()){
					if(board[currindex - (_x*2) - 1]) ++neighbor_board[currindex];
					if(board[currindex - (_x*2) + 1]) ++neighbor_board[currindex];
					if(board[currindex + (_x*2) + 1]) ++neighbor_board[currindex];
					if(board[currindex + (_x*2) - 1]) ++neighbor_board[currindex];
				}
			}
		}

		if(i%step == 0) std::cout << "Generation = " << 
			i << ", Population = " << _population << "." << std::endl;
		for(int row = 1; row <= _x; ++row){
			for (int col = 1; col <= _y; ++col){
				int currindex = ((_x+2)*row) + col;
				board[currindex].updateLife(neighbor_board[currindex]);
				if(i%step == 0) std::cout << board[currindex];
			}
			if(i%step == 0) std::cout << std::endl;
		}
		if(i%step == 0) std::cout << std::endl;
	}
}


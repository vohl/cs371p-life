
//----------
// includes
//----------
#include <cstddef>
#include <iostream>
#include <vector>

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
	return lhs << (rhs._handle_cell)->_state;
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
        if (neighbors < 2 && neighbors > 3){
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
    else if (state >= '0' && state <= '9'){
        _life = true;
        _age = state - '0';
    }
}

bool FredkinCell::countDiagonals(){
    return false;
}

void FredkinCell::updateLife(int neighbors){
	if (_life){
		if((neighbors%2) == 0){
			_life = false;
			_state = '-';
			_age = 0;
		}
		else{
			if(_age < 9){
				++_age;
				_state = _age + '0';
			}
			else{
				_age = 10;
				_state = '+';
			}
		}
	}
	else{
		if((neighbors%2) == 1){
			_life = true;
			_state = '0';
			_age = 0;
		}
	}
}

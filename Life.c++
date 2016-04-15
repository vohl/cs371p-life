
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
	return lhs << (*(rhs._handle_cell));
}

//--------------
// AbstractCell
//--------------
AbstractCell::AbstractCell(char state) : _state(state){}

//------------
// ConwayCell
//------------

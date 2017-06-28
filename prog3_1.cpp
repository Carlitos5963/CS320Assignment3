#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <lua.hpp>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}


using namespace std;
//Creates the lua state that this program will be using
lua_State *L;

int main(int argc, char *argv[])
{

	//Assignment header
	cout << "Assignment #3-1, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;

	// Assigns the lua state to the name L
	L = luaL_newstate();
	//Open lua libraries in the lua state L
	luaL_openlibs(L);

	// Execute the lua file entered in as a command line argument
	luaL_dofile(L, argv[1]);

	// Get the size of the stack between C and Lua
	//int stackSize = lua_gettop(L);
	// Pop off everything from the stack
	//lua_pop(L, stackSize);

	//Close the Lua environment
	lua_close(L);

	return 0;
}

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


using namespace std; // The namespace used in this program
lua_State *L; //Creates the lua state that this program will be using

int main(int argc, char *argv[])
{

	//Assignment header
	cout << "Assignment #3-1, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;

	
	L = luaL_newstate(); // Assigns the lua state to the name L
	luaL_openlibs(L); //Open lua libraries in the lua state L
	
	luaL_dofile(L, argv[1]); // Execute the lua file entered in as a command line argument

	lua_close(L); //Close the Lua environment

	return 0;
}

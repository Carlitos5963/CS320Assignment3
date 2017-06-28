#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
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
	cout << "Assignment #3-3, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;

	string str = "";
	char buff[256];
	fgets(buff, 65, stdin); //Takes in no more than 65 chars into the buff array
	//for(int i = 2; i < argc; i++){
	//	strcat(buff, argv[i]);
	//}

	cout << buff << endl;

	L = luaL_newstate(); // Assigns the lua state to the name L
	luaL_openlibs(L); //Open lua libraries in the lua state L
	
	luaL_dofile(L, argv[1]); // Execute the lua file entered in as a command line argument

	lua_close(L); //Close the Lua environment

	return 0;
}

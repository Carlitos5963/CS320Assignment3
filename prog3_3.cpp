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
double InfixToPostfix(const char* str);

int main(int argc, char *argv[])
{

	//Assignment header
	cout << "Assignment #3-3, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;

	double z;

	char buff[256]; // Used to hold user input
	fgets(buff, 65, stdin); //Takes in no more than 65 chars into the buff array


	//cout << buff << endl;

	L = luaL_newstate(); // Assigns the lua state to the name L
	luaL_openlibs(L); //Open lua libraries in the lua state L
	
	luaL_dofile(L, argv[1]); // Execute the lua file entered in as a command line argument
	z = InfixToPostfix(buff);
	cout << z << endl;

	lua_close(L); //Close the Lua environment

	return 0;
}

double InfixToPostfix(const char* str) {

	double z;
	cout << str << endl; // TEST! Used to test input is correct at this point

	luaL_dostring(L, "return InfixToPostfix(%s), str");
	//lua_pushstring(L, str); // Push string parameter to Lua function
	
	//if(luaL_pcall(L, 1, 1, 0) != 0)
	//	error(L, "Error running InfixToPostfhix: %s", lua_tostring(L, -1));
	lua_call(L, 1, 1);

	z = (double)lua_tonumber(L, -1);
	lua_pop(L, 1);
	return z;

}

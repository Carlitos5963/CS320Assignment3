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
const char* InfixToPostfix(const char* str);

int main(int argc, char *argv[])
{

	//Assignment header
	cout << "Assignment #3-3, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;

	const char* z;

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

const char* InfixToPostfix(const char* str) {

	const char *z;
	char infix[256];

	sprintf(infix, "return InfixToPostfix('%s')", str);
	cout << luaL_dostring(L, infix);

	//cout << infix << endl;

	z = lua_tostring(L, 1);
	lua_pop(L, 1);
	return z;

}

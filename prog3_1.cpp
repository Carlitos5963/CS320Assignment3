#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <lua.hpp>

//lua.hpp:
//extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
//}


using namespace std;
lua_State *L;

int main(int argc, char *argv[])
{

	cout << "Assignment #3-1, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;
	string fileName;
	
	if(argc > 1){
		fileName = argv[1];
	}


	char buff[256];

	L = luaL_newstate();
	luaL_openlibs(L);
	luaL_loadfile(L, "dofile(fileName)");

	lua_close(L);

	return 0;
}

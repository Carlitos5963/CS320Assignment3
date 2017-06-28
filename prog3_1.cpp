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


	L = luaL_newstate();
	luaL_openlibs(L);
	luaL_dofile(L, "test.lua");

	//lua_pcall(L, 0, LUA_MULTRET, 0);

	lua_close(L);

	return 0;
}

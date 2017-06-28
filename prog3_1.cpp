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


using namespace std;
lua_State *L;

int main(int argc, char *argv[])
{

	cout << "Assignment #3-1, Jose Carlos Gomez, JoseCarlosGomez69@gmail.com" << endl;
	string fileName;
	
	//if(argc > 1){
	//	fileName = argv[1];
	//}
	//cout << argv[0] << endl;
	//cout << argv[1] << endl;

	L = luaL_newstate();
	luaL_openlibs(L);
	//int status = 0;
	luaL_dofile(L, argv[1]);
	//if(status == 1)
	//	cout << "errors" << endl;
	//else
	//	cout << "success" << endl;

	int stackSize = lua_gettop(L);
	lua_pop(L, stackSize);

	//lua_pcall(L, 0, LUA_MULTRET, 0);

	lua_close(L);

	return 0;
}

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

	string fileName;
	
	if(argc > 1){
		fileName = argv[1];
		cout << fileName << endl;
	}


	char buff[256];

	L = luaL_newstate();
	luaL_openlibs(L);
	//luaL_dofile(L, fileName);

	lua_close(L);

	return 0;
}

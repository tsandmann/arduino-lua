#include <LuaWrapper.h>

LuaWrapper lua;

static int lua_wrapper_print(lua_State *lua_state) {
  String a = String(luaL_checkstring(lua_state, 1));
  Serial.println(a);
}

void setup() {
  lua.Lua_register("print", (const lua_CFunction) &lua_wrapper_print);
  Serial.begin(115200);
  String script = String("print('Hello world!')");
  Serial.println(lua.Lua_dostring(&script));
}

void loop() {

}

#include "LuaWrapper.h"

extern "C" {

  static int lua_wrapper_print(lua_State *lua) {
    String a = String(luaL_checkstring(lua, 1));
    Serial.println(a);
  }
}

LuaWrapper::LuaWrapper() {
  _state = luaL_newstate();
  lua_register(_state, "print", lua_wrapper_print);
}

String LuaWrapper::Lua_dostring(const String *script) {
  String scriptWithConstants = addConstants() + *script;
  String result;
  if (luaL_dostring(_state, scriptWithConstants.c_str())) {
    result += "# lua error:\n" + String(lua_tostring(_state, -1));
    lua_pop(_state, 1);
  }
  return result;
}

void LuaWrapper::Lua_register(const String name, const lua_CFunction function) {
  lua_register(_state, name.c_str(), function);
}

String LuaWrapper::addConstants() {
  String constants = "INPUT = " + String(INPUT) + "\r\n";
  constants += "OUTPUT = " + String(OUTPUT) + "\r\n";
  constants += "LOW = " + String(LOW) + "\r\n";
  constants += "HIGH = " + String(HIGH) + "\r\n";
  return constants;
}

/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * @file    lua_wrapper.cpp
 * @brief   Lua wrapper for C++
 * @author  François Dugast
 * @author  Scotty Franzyshen
 * @author  Timo Sandmann
 * @date    23.11.2019
 * @note    Based on <https://github.com/sfranzyshen/ESP-Arduino-Lua> and <https://github.com/fdu/ESP8266-Arduino-Lua>,
 *          adapted for use with the c't-Bot teensy framework and ported to C++14 by Timo Sandmann
 */

#include "lua_wrapper.h"

LuaWrapper::LuaWrapper() : p_state_ { luaL_newstate() } {
    luaopen_base(p_state_);
    luaopen_table(p_state_);
    luaopen_string(p_state_);
    luaopen_math(p_state_);
}

std::string LuaWrapper::Lua_dostring(const char* script) {
    std::string result;
    if (luaL_dostring(p_state_, script)) {
        result += "# lua error: ";
        result += lua_tostring(p_state_, -1);
        lua_pop(p_state_, 1);
    }
    return result;
}

void LuaWrapper::Lua_register(const char* name, const lua_CFunction function) {
    lua_register(p_state_, name, function);
}

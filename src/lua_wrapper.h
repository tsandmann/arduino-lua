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
 * @file    lua_wrapper.h
 * @brief   Lua wrapper for C++
 * @author  François Dugast
 * @author  Scotty Franzyshen
 * @author  Timo Sandmann
 * @date    23.11.2019
 * @note    Based on <https://github.com/sfranzyshen/ESP-Arduino-Lua> and <https://github.com/fdu/ESP8266-Arduino-Lua>,
 *          adapted for use with the c't-Bot teensy framework and ported to C++14 by Timo Sandmann
 */

#pragma once

#define LUA_USE_C89
#include "lua/lua.hpp"

#include <string>

class LuaWrapper {
public:
    LuaWrapper();

    std::string Lua_dostring(const char* script);

    void Lua_register(const char* name, const lua_CFunction function);

    auto get_state() const {
        return p_state_;
    }

private:
    lua_State* p_state_;
};

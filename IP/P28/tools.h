/**
 * @file tools.h
 * @author Jose Luis Cruz (j0z3ph@gmail.com)
 * @brief Tools to make interactive menus.
 * @version 0.1
 * @date 2022-11-30
 * 
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

#ifndef __TOOLS_H__
#define __TOOLS_H__

/**
 * @brief Limpia el buffer de entrada
 * 
 */
void limpiaBuffer();


/**
 * @brief Pausa la ejecucion del programa.
 * 
 */
void pausa();

/**
 * @brief Moves cursor to desired coordinates.
 * 
 * @param x X coordinate (column).
 * @param y Y coordinate (row).
 */
void gotoXY(int x, int y);

/**
 * @brief Clears command window.
 * 
 */
void clear();

/**
 * @brief Limpia la ventana de comandos
 * 
 */
void limpiarPantalla();

/**
 * @brief Prints the given menu. 
 * User can interact with menu using Up/Down arrows
 * and can select an option pressing the ENTER key.
 * 
 * @param numItems Number of items in the string array.
 * @param items String array. Each item is a menu option.
 * @param title Menu title.
 * @return int 0-base index of the selected item.
 */
int showMenu(int numItems, char* items[], char const *title);

#endif
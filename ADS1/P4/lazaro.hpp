/**
 * @file lazaro.hpp
 * @author Jose Luis Cruz (jlcruz@ipn.mx)
 * @brief Mi primer encabezado :>
 * @version 0.1
 * @date 2024-11-05
 *
 * @copyright Copyright (c) 2024
 *
 */
#ifndef __LAZARO_HPP__
#define __LAZARO_HPP__
// Declaracion de funciones

namespace jose
{

    /**
     * @brief Otra suma pero de tres.
     * 
     * @param a Primer valor
     * @param b Segundo valor
     * @param c Tercer valor
     * @return int La suma
     */
    int suma(int a, int b, int c = 0);

    /**
     * @brief Lo mismo que suma pero con flotantes.
     * 
     * @param a Primer flotante.
     * @param b Segundo flotante.
     * @return float La suma flotante.
     */
    float suma(float a, float b);

} // namespace jose

#endif
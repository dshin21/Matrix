//
// Created by danie on 2018-10-04.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>

matrix::matrix() : size{ 1 } {
    MATRIX[ 1 ] = 0;
}

matrix::matrix( int n ) : size{ n * n } {
    for ( int i = 0; i < size; ++i ) MATRIX[ i ] = 0;
}

matrix::matrix( int *int_arr, int n ) : size{ (int) sqrt( n ) * (int) sqrt( n ) } {
    if ( size != n ) std::cout << "Invalid size" << std::endl;
    else {
        MATRIX = new int[n];
        for ( int i = 0; i < size; ++i ) MATRIX[ i ] = int_arr[ i ];
    }
}

void matrix::set_value( int r, int c, int new_val ) {
    MATRIX[ r * size + c ] = new_val;
}

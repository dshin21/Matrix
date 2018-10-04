//
// Created by danie on 2018-10-04.
//

#include "matrix.hpp"

matrix::matrix() : size{ 1 } {
    MATRIX[ 1 ] = 0;
}

matrix::matrix( int n ) : size{ n * n } {
    for ( int i = 0; i < size; ++i ) MATRIX[ i ] = 0;
}

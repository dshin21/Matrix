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

int matrix::get_value( int r, int c ) {
    return MATRIX[ r * size + c ];
}

void matrix::clear() {
    for ( int i = 0; i < size; ++i ) {
        MATRIX[ i ] = 0;
    }
}

matrix matrix::identity() {
    matrix new_matrix( size );
    for ( int i = 0; i < size; ++i )
        new_matrix.MATRIX[ i ] = MATRIX[ i ];
    return new_matrix;
}

matrix::~matrix() {
    delete[] MATRIX;
}

ostream &matrix::operator<<( ostream &os ) {
    for ( int i = 0; i < size; ++i ) {
        os << MATRIX[ i ];
        if ( i % size == 0 ) os << "\n";
    }
    return os;}




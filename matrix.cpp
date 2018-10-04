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

int matrix::get_value( int r, int c ) const {
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
    return os;
}

bool operator==( const matrix &lhs, const matrix &rhs ) {
    if ( lhs.size != rhs.size )return false;
    for ( int i = 0; i < lhs.size; ++i )
        for ( int j = 0; j < lhs.size; ++j )
            if ( lhs.get_value( i, j ) != rhs.get_value( i, j ))
                return false;
    return true;
}

bool operator!=( const matrix &lhs, const matrix &rhs ) {
    return !operator==( lhs, rhs );
}

bool operator<( const matrix &lhs, const matrix &rhs ) {
    return lhs.size < rhs.size;
}

bool operator>( const matrix &lhs, const matrix &rhs ) {
    return lhs.size > rhs.size;
}

bool operator<=( const matrix &lhs, const matrix &rhs ) {
    return !operator>( lhs, rhs );
}

bool operator>=( const matrix &lhs, const matrix &rhs ) {
    return !operator<( lhs, rhs );
}

matrix &matrix::operator++() {
    for ( int i = 0; i < size; ++i )
        MATRIX[ i ]++;
    return *this;
}

const matrix matrix::operator++( int ) {
    for ( int i = 0; i < size; ++i )
        ++MATRIX[ i ];
    return *this;
}

matrix &matrix::operator--() {
    for ( int i = 0; i < size; ++i )
        MATRIX[ i ]--;
    return *this;
}

const matrix matrix::operator--( int ) {
    for ( int i = 0; i < size; ++i )
        --MATRIX[ i ];
    return *this;
}

matrix &matrix::operator=( matrix rhs ) {
    swap( *this, rhs );
    return *this;
}

void swap( matrix &lhs, matrix &rhs ) {
    std::swap( lhs.size, rhs.size );
    std::swap( lhs.size, rhs.size );
}

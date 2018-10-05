//
// Created by danie on 2018-10-04.
//

#include "matrix.hpp"
#include <math.h>
#include <iostream>

matrix::matrix() : size{ 1 } {
    MATRIX = new int[1];
}

matrix::matrix( int n ) : size{ n } {
    MATRIX = new int[n * n];
}

matrix::matrix( int *int_arr, int n ) : size{ (int) sqrt( n ) * (int) sqrt( n ) } {
    size = (int) sqrt( n );
    if ( size * size != n ) std::cout << "Invalid size";

    MATRIX = new int[n];
    for ( int i = 0; i < n; ++i )
        MATRIX[ i ] = int_arr[ i ];

}

void matrix::set_value( int r, int c, int new_val ) {
    MATRIX[ r * size + c ] = new_val;
}

int matrix::get_value( int r, int c ) const {
    return MATRIX[ r * size + c ];
}

void matrix::clear() {
    for ( int i = 0; i < size * size; ++i )
        MATRIX[ i ] = 0;
}

matrix matrix::identity() {
    matrix new_matrix( size );
    for ( int i = 0; i < size; ++i )
        for ( int j = 0; j < size; ++j )
            if ( i == j )
                new_matrix.set_value( i, j, 1 );
            else
                new_matrix.set_value( i, j, 0 );
    return new_matrix;
}

matrix::~matrix() {
    delete[] MATRIX;
}

ostream &operator<<( ostream &os, const matrix &matrix ) {
    for ( int i = 0; i < matrix.size; ++i ) {
        for ( int j = 0; j < matrix.size; ++j ) {
            os << matrix.MATRIX[ i * matrix.size + j ];
        }
        os << "\n";
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

matrix operator+( matrix lhs, const matrix &rhs ) {
    if ( lhs.size != rhs.size ) std::cout << "Invalid" << std::endl;
    else {
        matrix sum_matrix( lhs.size );
        for ( int i = 0; i < lhs.size; ++i )
            sum_matrix.MATRIX[ i ] += lhs.MATRIX[ i ] + rhs.MATRIX[ i ];
        return sum_matrix;
    }
}

matrix &matrix::operator+=( const matrix &rhs ) {
    if ( size != rhs.size ) std::cout << "Invalid" << std::endl;
    for ( int i = 0; i < size; ++i )
        MATRIX[ i ] += rhs.MATRIX[ i ];
    return reinterpret_cast<matrix &>(MATRIX);
}

matrix operator-( matrix lhs, const matrix &rhs ) {
    if ( lhs.size != rhs.size ) std::cout << "Invalid" << std::endl;
    else {
        matrix sum_matrix( lhs.size );
        for ( int i = 0; i < lhs.size; ++i )
            sum_matrix.MATRIX[ i ] -= lhs.MATRIX[ i ] + rhs.MATRIX[ i ];
        return sum_matrix;
    }
}

matrix &matrix::operator-=( const matrix &rhs ) {
    if ( size != rhs.size ) std::cout << "Invalid" << std::endl;
    for ( int i = 0; i < size; ++i )
        MATRIX[ i ] -= rhs.MATRIX[ i ];
    return reinterpret_cast<matrix &>(MATRIX);
}


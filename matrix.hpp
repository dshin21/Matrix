//
// Created by danie on 2018-10-04.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP

#include <iostream>

using namespace std;

class matrix {

    int size;
    int *MATRIX;
public:

    matrix();

    explicit matrix( int n );

    matrix( int int_arr[], int size );

    void set_value( int r, int c, int new_val );

    int get_value( int r, int c ) const;

    void clear();

    matrix identity();

    ~matrix();

    ostream &operator<<( ostream &os );

    friend bool operator==( const matrix &lhs, const matrix &rhs );

    friend bool operator!=( const matrix &lhs, const matrix &rhs );

    friend bool operator<( const matrix &lhs, const matrix &rhs );

    friend bool operator>( const matrix &lhs, const matrix &rhs );

    friend bool operator>=( const matrix &lhs, const matrix &rhs );

    friend bool operator<=( const matrix &lhs, const matrix &rhs );

    matrix &operator++();

    const matrix operator++( int );

    matrix &operator--();

    const matrix operator--( int );
};


#endif //MATRIX_MATRIX_HPP

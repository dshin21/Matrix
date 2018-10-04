//
// Created by danie on 2018-10-04.
//

#ifndef MATRIX_MATRIX_HPP
#define MATRIX_MATRIX_HPP


class matrix {
    int size;
    int *MATRIX;

    matrix();

    matrix( int n );

    matrix( int int_arr[], int size );

    void set_value(int r, int c, int new_val);

    int get_value(int r, int c);
    
};


#endif //MATRIX_MATRIX_HPP

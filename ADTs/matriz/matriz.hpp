#ifndef MATRIZ_H
#define MATRIZ_H
#include <QDebug>
#include "matrizadt.hpp"


class Matriz : public MatrizADT
{
public:
    int x;
    int y;
    int varx;
    int vary;
    double **matriz;

    Matriz(int x, int y);

    bool isEmpty();

    QString toString() const;

    bool isDivisible();

    double* getRow(const int y);

    double* getColumn(const int x);

    void insert(int x,int y, double value);

    void addRow(double *array);

    void addColumn(double *array);

    double determinant() const;

    MatrizADT* transposed();

    MatrizADT* multiply(double z);

    ~Matriz();
};

#endif // MATRIZ_H

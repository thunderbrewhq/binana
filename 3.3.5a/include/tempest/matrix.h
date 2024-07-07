#ifndef TEMPEST_MATRIX_H
#define TEMPEST_MATRIX_H

typedef struct C33Matrix C33Matrix;
typedef struct C34Matrix C34Matrix;
typedef struct C44Matrix C44Matrix;

struct C33Matrix {
  float a0;
  float a1;
  float a2;
  float b0;
  float b1;
  float b2;
  float c0;
  float c1;
  float c2;
};

struct C34Matrix {
  float a0;
  float a1;
  float a2;
  float b0;
  float b1;
  float b2;
  float c0;
  float c1;
  float c2;
  float d0;
  float d1;
  float d2;
};

struct C44Matrix {
  float a0;
  float a1;
  float a2;
  float a3;
  float b0;
  float b1;
  float b2;
  float b3;
  float c0;
  float c1;
  float c2;
  float c3;
  float d0;
  float d1;
  float d2;
  float d3;
};


#endif
/*author: Zeke Elkins
 *date: 3/27/14
 *description: a CUDA program to add two vectors of integers
 */

#define N 512 //the size of the vector

#include <iostream>
using namespace std;

//device code to add two arrays of numbers;
//each block handles a different element of the array

__global__ void add(int *a, int *b, int *c) {
  c[threadIdx.x] = a[threadIdx.x] + b[threadIdx.x];
}

//method that will generate n random integers between 0 and 99
//values are stored in the int array a
void random_ints(int* a, int n) {

  int i;
  for (i=0; i<n; ++i) {
  a[i] = rand() % 100;
  }

}

int main(void) {

  int *a, *b, *c;       //host copies of a, b, c NOTE THESE ARE NOW POINTERS
  int *d_a, *d_b, *d_c; // device copies of a, b, c
  int size = N * sizeof(int); //size of N integers

  //allocate space for device copies of a, b, c
  cudaMalloc((void **)&d_a, size);
  cudaMalloc((void **)&d_b, size);
  cudaMalloc((void **)&d_c, size);

  //allocate space for host copies of a, b, c and setup input vals
  a = (int *)malloc(size);
  random_ints(a, N);
  b = (int *)malloc(size);
  random_ints(b, N);
  c = (int *)malloc(size);

  //copy inputs to device
  cudaMemcpy(d_a, a, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_b, b, size, cudaMemcpyHostToDevice);

  // launch add() kernel on GPU with N threads
  add<<<1,N>>>(d_a, d_b, d_c);

  //copy result back to host
  cudaMemcpy(c, d_c, size, cudaMemcpyDeviceToHost);

  //print out the results
  for (int i=0; i<N; i++) {
    cout << a[i] << " plus " << b[i] << " equals " << c[i] << endl;
  }

  //cleanup
  free(a); free(b); free(c);
  cudaFree(d_a); cudaFree(d_b); cudaFree(d_c);

  return 0;

}
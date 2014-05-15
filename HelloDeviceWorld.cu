/*author: Zeke Elkins
 *date: 3/27/2014
 *description: a simple hello world program -- introducing CUDA device syntax 
*/

#include <iostream>
using namespace std;

__global__ void mykernel(void){
}

int main(void) {
 mykernel<<<1,1>>>(); 
 cout << "Hello World" << endl;
 return 0;
}


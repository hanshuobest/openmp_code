#include <iostream>
#include <omp.h>


using namespace std;

int main()
{
    cout << "Hello World!" << endl;
    int nthreads , tid ;
#pragma omp parallel private(nthreads , tid)
    {
        tid = omp_get_thread_num();
        std::cout<<"hello world from thread = " << tid << std::endl;

        if(tid == 0)
        {
            nthreads = omp_get_num_threads();
            std::cout<<"number of threads = " << nthreads << std::endl;
        }
    }

    return 0;
}

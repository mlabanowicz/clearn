#include <iostream>
#include <cstdlib> 
#include <unordered_map>
 
int main(void)
{
    unsigned int N,Q;
    int i,j;
    std::unordered_map<int, int> a;
    std::cin >> N;
    for(i = 0;i < N;i++){
       std::cin >> j;
       a[j]++;
    }
    std::cin >> Q;
    for(i = 0;i < Q;i++){
        std::cin >> j;
        std::cout << a[j] << std::endl;
    }
    return EXIT_SUCCESS;
}
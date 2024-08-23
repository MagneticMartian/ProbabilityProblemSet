#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <random>

template<typename T>
T max(std::vector<T> vec)
{
    return *std::max_element(vec.begin(),vec.end());
}
template<typename T>
T min(std::vector<T> vec)
{
    return *std::min_element(vec.begin(),vec.end());
}
int main(int argc, char* argv[])
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0,1.0);

    int N = atoi(argv[1]);
    double k = atof(argv[2]);

    int tot = 0;
    for(int m = 0; m < 1000000; m++){
        std::vector<double> X;
        for(int i = 0; i < N; i++)
            X.push_back(dis(gen));
        auto A = min(X);
        auto B = max(X);
        if(A <= k && B >= 1-k)
            tot += 1;
    }
    std::cout << tot/1000000.0 << '\n';
}

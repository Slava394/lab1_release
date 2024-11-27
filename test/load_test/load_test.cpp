#include <iostream>
#include <vector>
#include <chrono>
#include "../../utils/gnuplot-iostream.h"
#include "../../pointers/unique_ptr.hpp"
#include "../../pointers/shared_weak_ptr.hpp"


void uniqueLoadTest(std::vector<std::pair<int, double>>& dataPoints, int start, int end, int step) 
{
    for (int n = start; n <= end; n += step) 
    {
        std::vector<UniquePtr<int>> pointers;
        pointers.reserve(n);
        auto startTime = std::chrono::high_resolution_clock::now();
        for (int index = 0; index < n; ++index) 
        {
            pointers.emplace_back(new int(index));
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endTime - startTime;
        dataPoints.emplace_back(n, duration.count());
        std::cout << "Количество объектов: " << n << ", Время: " << duration.count() << " секунд\n";
    }
}

void sharedLoadTest(std::vector<std::pair<int, double>>& dataPoints, int start, int end, int step) 
{
    for (int n = start; n <= end; n += step) 
    {
        std::vector<SharedPtr<int>> pointers;
        pointers.reserve(n);
        auto startTime = std::chrono::high_resolution_clock::now();
        for (int index = 0; index < n; ++index) 
        {
            pointers.emplace_back(new int(index));
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endTime - startTime;
        dataPoints.emplace_back(n, duration.count());
        std::cout << "Количество объектов: " << n << ", Время: " << duration.count() << " секунд\n";
    }
}

void weakLoadTest(std::vector<std::pair<int, double>>& dataPoints, int start, int end, int step) 
{
    for (int n = start; n <= end; n += step) 
    {
        std::vector<WeakPtr<int>> pointers;
        pointers.reserve(n);
        SharedPtr<int> sharedPtr(new int(n));
        auto startTime = std::chrono::high_resolution_clock::now();
        for (int index = 0; index < n; ++index) 
        {
            pointers.emplace_back(sharedPtr);
        }
        auto endTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> duration = endTime - startTime;
        dataPoints.emplace_back(n, duration.count());
        std::cout << "Количество объектов: " << n << ", Время: " << duration.count() << " секунд\n";
    }
}

int main() 
{
    Gnuplot gp1, gp2, gp3;
    std::vector<std::pair<int, double>> dataPoints1, dataPoints2,  dataPoints3, 
                                        dataPoints4, dataPoints5, dataPoints6;
    uniqueLoadTest(dataPoints1, 1, 10000, 50);
    uniqueLoadTest(dataPoints2, 1000000, 100000000, 1000000);
    sharedLoadTest(dataPoints3, 1, 10000, 50);
    sharedLoadTest(dataPoints4, 1000000, 100000000, 1000000);
    weakLoadTest(dataPoints5, 1, 10000, 50);
    weakLoadTest(dataPoints6, 1000000, 100000000, 1000000);
    gp1 << "set multiplot layout 2,1 title 'Нагрузочные тесты UniquePtr'\n";
    gp1 << "set title 'UniquePtr (небольшие данные)'\n";
    gp1 << "set xlabel 'Количество объектов'\n";
    gp1 << "set ylabel 'Время (секунды)'\n";
    gp1 << "plot '-' with linespoints title 'Время выполнения'\n";
    gp1.send1d(dataPoints1);
    gp1 << "set title 'UniquePtr (большие данные)'\n";
    gp1 << "set xlabel 'Количество объектов'\n";
    gp1 << "set ylabel 'Время (секунды)'\n";
    gp1 << "plot '-' with linespoints title 'Время выполнения'\n";
    gp1.send1d(dataPoints2);
    gp2 << "set multiplot layout 2,1 title 'Нагрузочные тесты SharedPtr'\n";
    gp2 << "set title 'SharedPtr (небольшие данные)'\n";
    gp2 << "set xlabel 'Количество объектов'\n";
    gp2 << "set ylabel 'Время (секунды)'\n";
    gp2 << "plot '-' with linespoints title 'Время выполнения'\n";
    gp2.send1d(dataPoints3);
    gp2 << "set title 'SharedPtr (большие данные)'\n";
    gp2 << "set xlabel 'Количество объектов'\n";
    gp2 << "set ylabel 'Время (секунды)'\n";
    gp2 << "plot '-' with linespoints title 'Время выполнения'\n";
    gp2.send1d(dataPoints4);
    gp3 << "set multiplot layout 2,1 title 'Нагрузочные тесты WeakPtr'\n";
    gp3 << "set title 'WeakPtr (небольшие данные)'\n";
    gp3 << "set xlabel 'Количество объектов'\n";
    gp3 << "set ylabel 'Время (секунды)'\n";
    gp3 << "plot '-' with linespoints title 'Время выполнения'\n";
    gp3.send1d(dataPoints5);
    gp3 << "set title 'WeakPtr (большие данные)'\n";
    gp3 << "set xlabel 'Количество объектов'\n";
    gp3 << "set ylabel 'Время (секунды)'\n";
    gp3 << "plot '-' with linespoints title 'Время выполнения'\n";
    gp3.send1d(dataPoints6);
    return 0;
}
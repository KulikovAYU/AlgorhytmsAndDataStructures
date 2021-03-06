// AlgoImpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "TreesAlgorhytms.h"
#include <TreesGenerator.h>


int main()
{
   /* const auto& undirTree = TreeGenerator::CreateUndirectedTree();
    const auto& reqNode = TreesAlgo_4::findReqNode(0,undirTree);
    const auto& res = TreesAlgo_4::BuildNewTreeByVertex(reqNode);*/
    const auto& undirTree = TreeGenerator::CreateUndirectedTree1();
    const auto& res = TreesAlgo_5::GetCenterOfTheTree(undirTree);
    //int n = TreesAlgo_3::GetHeight(TreeGenerator::CreateStrBinaryTree());
    std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

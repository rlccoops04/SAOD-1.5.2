#include <iostream>
struct TNode
{
    int data;
    TNode* pLeft;
    TNode* pRight;
};
bool isEmpty(TNode* pRoot)
{
    if (pRoot == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void searchNode(TNode* pCurrent, int searchdata, TNode*& pSearched)
{
    TNode* pTemp;
    bool Stop = false;
    if (not Stop)
    {
        pTemp = pCurrent;
        if (pTemp != nullptr)
        {
            if (pTemp->data == searchdata)
            {
                pSearched = pTemp;
                Stop = true;
            }
            else
            {
                searchNode(pTemp->pLeft, searchdata, pSearched);
                searchNode(pTemp->pRight, searchdata, pSearched);
            }
        }
    }
}
void addNode(TNode*& pRoot, int searchdata, int newdata)
{
    if (isEmpty(pRoot))
    {
        pRoot = new TNode{ newdata,nullptr,nullptr };
    }
    else
    {
        TNode* pCurrent;
        searchNode(pRoot, searchdata, pCurrent);
        if (pCurrent->pLeft != nullptr && pCurrent->pRight != nullptr)
        {
            std::cout << "Невозможно добавить потомка." << std::endl;
        }
        else if (pCurrent->pLeft == nullptr && pCurrent->pRight != nullptr)
        {
            TNode* pTemp = new TNode();
            pCurrent->pLeft = pTemp;
            pTemp->data = newdata;
        }
        else if (pCurrent->pLeft != nullptr && pCurrent->pRight == nullptr)
        {
            TNode* pTemp = new TNode();
            pCurrent->pRight = pTemp;
            pTemp->data = newdata;
        }
        else if (pCurrent->pLeft == nullptr && pCurrent->pRight == nullptr)
        {
            int choiceway;
            std::cout << "Добавить левого (1) или правого (2) потомка: ";
            std::cin >> choiceway;
            if (choiceway == 1)
            {
                TNode* pTemp = new TNode();
                pCurrent->pLeft = pTemp;
                pTemp->data = newdata;
            }
            else
            {
                TNode* pTemp = new TNode();
                pCurrent->pRight = pTemp;
                pTemp->data = newdata;
            }
        }
    }
}
void displayBackSymmetric(TNode* pCurrent, int lvl)
{
    if (pCurrent != nullptr)
    {
        lvl++;
        displayBackSymmetric(pCurrent->pRight, lvl);
        for (int i = 0; i < lvl - 1; i++)
        {
            std::cout << "     ";
        }
        std::cout << pCurrent->data << std::endl;
        displayBackSymmetric(pCurrent->pLeft, lvl);
    }
}
void clearMemory(TNode*& pCurrent)
{
    if (pCurrent != nullptr)
    {
        clearMemory(pCurrent->pLeft);
        clearMemory(pCurrent->pRight);
        delete pCurrent;
    }
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    TNode* pRoot = NULL;
    bool menu = true;
    int choicemenu;
    int searchdata;
    int newdata;
    while (menu)
    {
        std::cout << "1) Добавление вершины\n"
            "2) Построчный вывод дерева с помощью основных правил обхода\n"
            "3) Уничтожение всего дерева"
            "4) Выход" << std::endl;
        std::cin >> choicemenu;
        switch (choicemenu)
        {
        case 1:
            std::cout << "Введите информационную часть вершины: ";
            std::cin >> newdata;
            if (isEmpty(pRoot))
            {
                addNode(pRoot, 1, newdata);
            }
            else
            {
                std::cout << "Для какой вершины добавить потомков: ";
                std::cin >> searchdata;
                addNode(pRoot, searchdata, newdata);
            }
            break;
        case 2:
            displayBackSymmetric(pRoot, 0);
            break;
        case 3:
            clearMemory(pRoot);
            break;
        default:
            clearMemory(pRoot);
            menu = false;
            break;
        }
    }
}



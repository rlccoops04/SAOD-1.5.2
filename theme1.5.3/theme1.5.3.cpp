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
void SearchNode(TNode* pCurrent, int searchdata, TNode*& pSearched)
{
    bool Stop = false;
    while (not Stop)
    {
        TNode* pTemp = pCurrent;
        if (pTemp != nullptr)
        {
            if (pTemp->data == searchdata)
            {
                pSearched = pTemp;
                Stop = true;
            }
            else
            {
                SearchNode(pTemp->pLeft, searchdata, pSearched);
                SearchNode(pTemp->pRight, searchdata, pSearched);
            }
        }
    }
}
void AddNode(TNode* pRoot, int searchdata, int newdata)
{
    if (isEmpty(pRoot))
    {
        TNode* pRoot = new TNode{ newdata,nullptr,nullptr };
    }
    else
    {
        TNode* pCurrent;
        int choicenapr;
        SearchNode(pRoot, searchdata, pCurrent);
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
            std::cout << "Добавить левого (1) или правого (2) потомка: ";
            std::cin >> choicenapr;
            if (choicenapr == 1)
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
void DisplayBackSymmetric(TNode* pCurrent, int lvl)
{
    if (pCurrent != nullptr)
    {
        lvl++;
        DisplayBackSymmetric(pCurrent->pRight, lvl);
        for (int i = 0; i < lvl - 1; i++)
        {
            std::cout << "     ";
        }
        std::cout << pCurrent->data << std::endl;
        DisplayBackSymmetric(pCurrent->pLeft, lvl);
    }
}
void ClearMemory(TNode*& pCurrent)
{
    if (pCurrent != nullptr)
    {
        ClearMemory(pCurrent->pLeft);
        ClearMemory(pCurrent->pRight);
        delete pCurrent;
    }
}
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    std::cout << "Симметричный обход: " << std::endl;
    DisplayBackSymmetric(pRoot, 0);
    ClearMemory(pRoot);
}



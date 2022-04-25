#include <iostream>
struct TNode
{
    int data;
    TNode* pLeft;
    TNode* pRight;
};
void AddNodes(TNode*& pCurrent, int aN)
{
    TNode* pTemp;
    int Nleft, Nright;
    if (aN == 0)
    {
        pCurrent = nullptr;
    }
    else
    {
        Nleft = aN / 2;
        Nright = aN - Nleft - 1;
        pTemp = new TNode();
        pTemp->data = rand() % 99;
        AddNodes(pTemp->pLeft, Nleft);
        AddNodes(pTemp->pRight, Nright);
        pCurrent = pTemp;
    }
}
void DisplayForward(TNode* pCurrent, int lvl)
{
    if (pCurrent != nullptr)
    {
        for (int i = 0; i < lvl; i++)
        {
            std::cout << "     ";
        }
        std::cout << pCurrent->data << std::endl;
        DisplayForward(pCurrent->pLeft, lvl + 1);
        DisplayForward(pCurrent->pRight, lvl + 1);
    }
}
void DisplaySymmetric(TNode* pCurrent, int lvl)
{
    if (pCurrent != nullptr)
    {
        lvl++;
        DisplaySymmetric(pCurrent->pLeft, lvl);
        for (int i = 0; i < lvl - 1; i++)
        {
            std::cout << "     ";
        }
        std::cout << pCurrent->data << std::endl;
        DisplaySymmetric(pCurrent->pRight, lvl);
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
    int N;
    std::cout << "Введите количество вершин: ";
    std::cin >> N;
    TNode* pRoot = nullptr;
    AddNodes(pRoot, N);
    bool menu = true;
    int choicemenu;
    while (menu)
    {
        std::cout << "1) Обратно - симметричный обход.\n"
            "2) Симметричный обход.\n"
            "3) Прямой обход.\n"
            "4) Выход.\n\n"
            "Ввод: ";
        std::cin >> choicemenu;
        switch (choicemenu)
        {
        case 1:
            std::cout << "Обратно - симметричный обход: " << std::endl;
            DisplayBackSymmetric(pRoot, 0);
            std::cout << "\n\n";
            break;
        case 2:
            std::cout << "Симметричный обход: " << std::endl;
            DisplaySymmetric(pRoot, 0);
            std::cout << "\n\n";
            break;
        case 3:
            std::cout << "Прямой обход: " << std::endl;
            DisplayForward(pRoot, 0);
            std::cout << "\n\n";
            break;
        default:
            menu = false;
            ClearMemory(pRoot);
            break;
        }
    }
}


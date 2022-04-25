#include <iostream>
struct TNode
{
    int data;
    TNode* pLeft;
    TNode* pRight;
};
struct StackElement
{
    TNode* data;
    StackElement* previous;
    int lvl;
};
bool isEmpty(StackElement* stack)
{
    return stack == NULL;
}
void push(TNode* data, StackElement*& stack)
{
    if (isEmpty(stack))
    {
        stack = new StackElement{ data, nullptr };
    }
    else
    {
        stack = new StackElement{ data, stack };
    }
}
StackElement* pop(StackElement*& stack0)
{
    StackElement* pTemp;
    pTemp = stack0;
    stack0 = stack0->previous;
    pTemp->previous = nullptr;
    return pTemp;
}
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
void DisplaySymmetric(TNode* pCurrent, StackElement* stack)
{
    int lvl = 0;
    bool Stop = false;
    while (not Stop)
    {
        while (pCurrent != nullptr)
        {
            lvl += 1;
            push(pCurrent, stack);
            stack->lvl = lvl;
            pCurrent = pCurrent->pLeft;
        }
        if (isEmpty(stack))
        {
            Stop = true;
        }
        else
        {
            for (int i = 0; i < stack->lvl - 1; i++)
            {
                std::cout << "     ";
            }
            lvl = stack->lvl;
            pCurrent = pop(stack)->data;
            std::cout << pCurrent->data << std::endl;
            pCurrent = pCurrent->pRight;
        }
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
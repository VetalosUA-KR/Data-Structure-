#include <iostream>
#include "binary_tree.h"
#include "kolejka.h"

using namespace std;

/**
Удаление указаного элемента
*/
void binary_tree::usun(int data)
{
    Node * tmp = root;
    /// Ищем нужный нам элемент
    while(tmp->data != data && tmp != nullptr)
    {
        if(tmp->data < data)
        {
            tmp = tmp->right;
        }
        else if(tmp->data > data)
        {
            tmp = tmp->left;
        }
    }

    ///Если он являеться "листьем"
    if(tmp->left == nullptr && tmp->right == nullptr)
    {
        Node * toDel = tmp;
        if(tmp->parent->right == tmp)
        {
            tmp->parent->right = nullptr;
        }
        else
        {
            tmp->parent->left = nullptr;
        }
        delete toDel;
    }

    /// если есть только один потомок
    else if(tmp->left == nullptr || tmp->right == nullptr)
    {
        Node * toDelete = tmp;
            /// Удаление правого элемента
        if(tmp->parent->right == tmp)
        {
            ///ЛЕВЫЙ элемент встанет на новое место
            if(tmp->left != nullptr)
            {
                tmp->parent->right = tmp->left;
                tmp->left->parent = tmp->parent;
            }
            ///ПРАВЫЙ элемент встанет на новое место
            else if(tmp->right != nullptr)
            {
                tmp->parent->right = tmp->right;
                tmp->right->parent = tmp->parent;
            }
        }
            /// Удаление левого элемента
        else if(tmp->parent->left == tmp)
        {
            ///ЛЕВЫЙ элемент встанет на новое место
            if(tmp->left != nullptr)
            {
                tmp->parent->left = tmp->left;
                tmp->left->parent = tmp->parent;
            }
            ///ПРАВЫЙ элемент встанет на новое место
            else if(tmp->right != nullptr)
            {
                tmp->parent->left = tmp->right;
                tmp->right->parent = tmp->parent;
            }
        }
        delete toDelete;
    }

    /// Есть оба потомка
    else
    {
        /// Отделяем левое под-древо
        Node * oldLeft = tmp->left;

        /// В правом под-древе идем максимально в лево
        Node * previouseNewLeft = nullptr;
        Node * newLeft = tmp->right->left;
        while(newLeft != nullptr)
        {
            previouseNewLeft = newLeft;
            newLeft = newLeft->left;
        }

        /// На место удаление ставим новые элемент с права
        if(tmp->parent->left == tmp)
        {
            tmp->parent->left = tmp->right;
        }
        else if(tmp->parent->right == tmp)
        {
            tmp->parent->right = tmp->right;
        }
        tmp->right->parent = tmp->parent;

        /// Вставляем старое левое поддерево в правое поддерево максимально в лево
        previouseNewLeft->left = oldLeft;
        oldLeft->parent = newLeft;
    }
}


/**
Левый поворот
*/
void binary_tree::leftRotation()
{
    Node * newRoot = root->right;

    /// Сохраняем старое значение корня, "отрезая" правую часть
    Node * oldLeft = root;

    /// Если у нашего нового корня есть под-древо с лева, сохраняем его
    Node * newRootLeftTree = newRoot->left;
    /*if(newRoot->left != nullptr)
    {
        newRootLeftTree = newRoot->left;
    }*/

    /// Вставляем в место левого под-древа нашей новой вершини, старое левое под-древо вместе с старым корнем
    newRoot->left = oldLeft;

    /// Если у нового коря было под-древо с лева, вставляем его в правое под-древо старого корня
    if(newRootLeftTree != nullptr)
    {
        oldLeft->right = newRootLeftTree;
    }

    root = newRoot;
}

/**
Правый поворот
*/
void binary_tree::rightRotation()
{
    Node * newRoot = root->left;
    Node * oldRight = root;
    Node * newRootRightTree = newRoot->right;

    newRoot->right = oldRight;

    if(newRootRightTree != nullptr)
    {
        oldRight->left = newRootRightTree;
    }
    root = newRoot;
}

/**
Добавление элемента
*/
void binary_tree::addElement(int data)
{
    Node * newElement = new Node(data);
    if(root == nullptr)
    {
        root = newElement;
    }
    else
    {
        Node * previouse = nullptr;
        Node * current = root;


        while(current != nullptr)
        {
            previouse = current;
            if(current->data > data)
            {
                current = current->left;
            }
            else if(current->data < data)
            {
                current = current->right;
            }
        }
        if(previouse->data > data)
        {
            previouse->left = newElement;
        }
        else if(previouse->data < data)
        {
            previouse->right = newElement;
        }
        newElement->parent = previouse;
    }
    size++;

}

void binary_tree::wypisz(Node * current, int l)
{
     if(current != nullptr)
     {
         wypisz(current->right, l+3);
         for(int i = 1; i <= l; i++)
         {
             cout<<"   ";
         }
         cout<<current->data<<endl;
         wypisz(current->left, l+3);
     }
}


/**void binary_tree::wypiszPrzezKolejku()
{
    kolejka k;
    k.addElement(root);
    while(k.head != nullptr)
    {
        cout<<k.head<<" ";
        if(k.head->bn->left != nullptr)
        {
            k.addElement(k.head->bn->left);
        }
        else if(k.head->bn->right != nullptr)
        {
            k.addElement(k.head->bn->right);
        }
        k.pop();
    }
}*/











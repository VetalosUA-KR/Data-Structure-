#include <iostream>
#include "binary_tree.h"
#include "kolejka.h"

using namespace std;

/**
�������� ��������� ��������
*/
void binary_tree::usun(int data)
{
    Node * tmp = root;
    /// ���� ������ ��� �������
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

    ///���� �� ��������� "�������"
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

    /// ���� ���� ������ ���� �������
    else if(tmp->left == nullptr || tmp->right == nullptr)
    {
        Node * toDelete = tmp;
            /// �������� ������� ��������
        if(tmp->parent->right == tmp)
        {
            ///����� ������� ������� �� ����� �����
            if(tmp->left != nullptr)
            {
                tmp->parent->right = tmp->left;
                tmp->left->parent = tmp->parent;
            }
            ///������ ������� ������� �� ����� �����
            else if(tmp->right != nullptr)
            {
                tmp->parent->right = tmp->right;
                tmp->right->parent = tmp->parent;
            }
        }
            /// �������� ������ ��������
        else if(tmp->parent->left == tmp)
        {
            ///����� ������� ������� �� ����� �����
            if(tmp->left != nullptr)
            {
                tmp->parent->left = tmp->left;
                tmp->left->parent = tmp->parent;
            }
            ///������ ������� ������� �� ����� �����
            else if(tmp->right != nullptr)
            {
                tmp->parent->left = tmp->right;
                tmp->right->parent = tmp->parent;
            }
        }
        delete toDelete;
    }

    /// ���� ��� �������
    else
    {
        /// �������� ����� ���-�����
        Node * oldLeft = tmp->left;

        /// � ������ ���-����� ���� ����������� � ����
        Node * previouseNewLeft = nullptr;
        Node * newLeft = tmp->right->left;
        while(newLeft != nullptr)
        {
            previouseNewLeft = newLeft;
            newLeft = newLeft->left;
        }

        /// �� ����� �������� ������ ����� ������� � �����
        if(tmp->parent->left == tmp)
        {
            tmp->parent->left = tmp->right;
        }
        else if(tmp->parent->right == tmp)
        {
            tmp->parent->right = tmp->right;
        }
        tmp->right->parent = tmp->parent;

        /// ��������� ������ ����� ��������� � ������ ��������� ����������� � ����
        previouseNewLeft->left = oldLeft;
        oldLeft->parent = newLeft;
    }
}


/**
����� �������
*/
void binary_tree::leftRotation()
{
    Node * newRoot = root->right;

    /// ��������� ������ �������� �����, "�������" ������ �����
    Node * oldLeft = root;

    /// ���� � ������ ������ ����� ���� ���-����� � ����, ��������� ���
    Node * newRootLeftTree = newRoot->left;
    /*if(newRoot->left != nullptr)
    {
        newRootLeftTree = newRoot->left;
    }*/

    /// ��������� � ����� ������ ���-����� ����� ����� �������, ������ ����� ���-����� ������ � ������ ������
    newRoot->left = oldLeft;

    /// ���� � ������ ���� ���� ���-����� � ����, ��������� ��� � ������ ���-����� ������� �����
    if(newRootLeftTree != nullptr)
    {
        oldLeft->right = newRootLeftTree;
    }

    root = newRoot;
}

/**
������ �������
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
���������� ��������
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











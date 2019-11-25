#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "list.h"
#include "student.h"

using namespace std;

int main()
{
    const int N=2;
    string file[N]={"GRA.txt", "SID.txt"};
    List<Student> l;

    for(int i = 0; i < N; i++)
    {

        /**
            ��������� ������ �� ������ GRA.txt � SID.txt, ��������� �� � ��������� List<Student> l
            ��� ������ � ��������� ���������� ������������� �� ����������� ������������ �������
        */
        ifstream in(file[i]);/// ���������� ��� ���������� ������ �� �����
        if(!in)
        {
            cout << "File not found " << file[i] << endl;
            return 1;
        }

        while(!in.eof())
        {
            /// ������� ������ ��� ���������� �������� ������ � ���������� ������
            string surname, names;
            int index;
            float mark;

            in >> surname;
            in.ignore(); /// ����� ���� ��� �������� �������, "�������" ������

            string line;
            getline(in, line); /// �������� ��� ����� ��� ������� � ������� ����� �������

            unsigned last_space = line.rfind(' ');/// �������� �� ��� ���� ����� ���������� ������� (������)
            unsigned before_last_space = line.rfind(' ', last_space - 1);/// ��� ��� �������� �� ��� ���� ����� ���������� ������� (������)

            /// � ���� ���������� �������� ���� ��� ��� �����(��� ����� ������� �� ����� ��� ������� � ������)
            names = line.substr(0, before_last_space);

            /// ���������� ����� ��������� ������ � ������� � ������
            istringstream iline(line.substr(before_last_space + 1));
            iline >> index >> mark;

            try
            {
                Student s;
                s.setSurname(surname);
                s.setNames(names);
                s.setIndex(index);
                s.setMark(mark);

                l.insert(s);
            }
            catch(exception &e)
            {
                cout << e.what() << endl;
            }

        }

        in.close();
    }

    /**
        ���������� ������ �� ����� INF.txt
        1) ������� ������ �� ����� ������ ���� ������, ������ ������� ����� �� ������� � ������
        2) ����� ������ ���� �������� � ����������� ���� ( �������  ->  �. )
    */
    ofstream out("INF.txt");
    int counter = l.size();
    for(int i = 0; i <  counter; i++)
    {
        Student s = l.pop();
        out << s.getIndex() << ";" << s.getMark() << ";" << s.getSurname() << " " << s.getShortNames() << endl;
    }
    out.close();

    return 0;
}

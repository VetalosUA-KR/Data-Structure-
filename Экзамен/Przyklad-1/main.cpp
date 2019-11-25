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
            —читываем данные из файлов GRA.txt и SID.txt, записыва€ их в структуру List<Student> l
            при записи в структуру необходимо отсортировать по возростанию относительно индекса
        */
        ifstream in(file[i]);/// переменна€ дл€ считывани€ данных из файла
        if(!in)
        {
            cout << "File not found " << file[i] << endl;
            return 1;
        }

        while(!in.eof())
        {
            /// —оздаем буферы дл€ временного хранени€ данных с прочтенной строки
            string surname, names;
            int index;
            float mark;

            in >> surname;
            in.ignore(); /// после того как записали фамилию, "убираем" пробел

            string line;
            getline(in, line); /// получаем всю линию Ѕ≈« фамилии и пробела после фамилии

            unsigned last_space = line.rfind(' ');/// отрезаем то что идет после последнего пробела (оценку)
            unsigned before_last_space = line.rfind(' ', last_space - 1);/// еще раз отрезаем то что идет после последнего пробела (индекс)

            /// в этой переменной хранитс€ наше им€ или имена(все после фамилии до конца без индекса и оценки)
            names = line.substr(0, before_last_space);

            /// записываем ранее отрезаные данные о индексе и оценке
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
        ¬ыписываем данные из файла INF.txt
        1) пор€док вывода на экран должен быть измене, первый столбец будет не фамили€ а индекс
        2) имена должны быть выписаны в сокращенном виде ( ¬италий  ->  ¬. )
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

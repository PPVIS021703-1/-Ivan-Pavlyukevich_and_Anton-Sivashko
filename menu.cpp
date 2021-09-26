#include <fstream>
#include <Windows.h>
#include <string>
#include "dict.h"


using namespace std;

//! interface :)
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    dict* slov = new dict();
    int choice = 1;
    while (choice) {
        system("cls");
        cout << "�������� ��������:\n";
        cout << "1. �������� ����� (��� ������� � ������������� �����)\n";
        cout << "2. ������� �����\n";
        cout << "3. ������� ������� �� �����\n";
        cout << "4. ����� �������� ����������� �����\n";
        cout << "5. ������ �������� ����������� �����\n";
        cout << "6. ���������� ���� � �������\n";
        cout << "7. ��������� ������� �� �����\n";
        cout << "0. �����.\n";
        cout << "������� ��������: ";
        cin >> choice;
        if (!choice) {
            system("cls");
            break;
        }
        int choice_case = 1;
        switch (choice) {
        case 1:
            while (choice_case) {
                system("cls");
                string eng_word, rus_word;
                cout << "������� ���������� �����: ";
                cin >> eng_word;

                int translation_count = 1;
                cout << "������� ��������� ��� ����� ����� �� ������: ";
                cin >> translation_count;
                for (int i = 0; i < translation_count; i++)
                {
                    cout << "������� " << i + 1 << "-� ������� �� �������: ";
                    cin >> rus_word;
                    *slov += make_pair(eng_word, rus_word);
                }
                cout << "������� �� �� �������� ���? (1 - ��, 0 - ���) ";
                cin >> choice_case;
            }
            break;

        case 2:
            while (choice_case) {
                system("cls");
                string del_word;
                cout << "������� �����, ������� �� ������� �������: ";
                cin >> del_word;
                *slov -= del_word;
                cout << "������� �� �� ������� ���? (1 - ��, 0 - ���) ";
                cin >> choice_case;
            }
            break;

        case 3:
            while (choice_case) {
                system("cls");
                string del_tr;
                cout << "������� �����, ������� �������� �� ������� �������: ";
                cin >> del_tr;
                cout << "��������: \n";
                for (int i = 0; i < slov->tr_count(del_tr); i++)
                {
                    cout << i + 1 << ". " << (*slov)[make_pair(del_tr, i)] << endl;
                }
                cout << "������� ��� ����� ������� �� ������ �������: ";
                int tr_numb;
                cin >> tr_numb;

                slov->delete_one_translation(del_tr, tr_numb);

                cout << "������� �� �� ������� ������� ���? (1 - ��, 0 - ���) ";
                cin >> choice_case;
            }
            break;

        case 4:
            while (choice_case) {
                system("cls");
                string tr_word;
                cout << "������� �����, ������� �� ������ ���������: ";
                cin >> tr_word;
                cout << "�������: " << (*slov)[tr_word] << endl;
                cout << "������� �� �� ��������� ���? (1 - ��, 0 - ���) ";
                cin >> choice_case;
            }
            break;

        case 5:
            while (choice_case) {
                system("cls");
                string change_word, new_word;
                cout << "������� �����, ������� �������� ����� ��������: ";
                cin >> change_word;

                if (slov->tr_count(change_word) == 1)
                {
                    cout << "������� �������: " << (*slov)[change_word] << "\n������� ����� �������: ";
                    cin >> new_word;
                    (*slov)[make_pair(change_word, 0)] = new_word;
                }
                else {
                    cout << "��������: \n";
                    for (int i = 0; i < slov->tr_count(change_word); i++)
                    {
                        cout << i + 1 << ". " << (*slov)[make_pair(change_word, i)] << endl;
                    }
                    cout << "������� ��� ����� ������� �� ������ ��������: ";
                    int tr_numb;
                    cin >> tr_numb;
                    cout << "������� ����� �������: ";
                    cin >> new_word;
                    (*slov)[make_pair(change_word, tr_numb - 1)] = new_word;

                }
                cout << "������� �� �� �������� ���? (1 - ��, 0 - ���) ";
                cin >> choice_case;
            }
            break;

        case 6:
            while (choice_case) {
                system("cls");
                string del_word;
                cout << "� �������: " << (*slov).length() << " �����." << endl;
                cout << "������� \"0\" ��� �����������: ";
                cin >> choice_case;
            }
            break;

        case 7:
            while (choice_case) {
                system("cls");
                string file_name = "dictionary.txt";
                /*cout << "������� ��� �����: ";
                cin >> file_name;*/
                ifstream inp_file;
                inp_file.open(file_name);
                if (inp_file.is_open()) {
                    string inp_line;
                    while (!inp_file.eof()) {
                        getline(inp_file, inp_line);
                        string inp_eng = inp_line.substr(0, inp_line.find('\t'));
                        string inp_rus = inp_line.substr(inp_line.find('\t') + 1);
                        int space_index = 0;
                        string rus_tr;
                        for (int i = 0; i < inp_rus.length(); i++) ///��������� ������ ����� ������ �� ������ ��������
                        {
                            if (inp_rus[i] == ' ')
                            {
                                rus_tr = inp_rus.substr(space_index, i - space_index);
                                *slov += make_pair(inp_eng, rus_tr);
                                space_index = i + 1;
                            }
                        }
                        rus_tr = inp_rus.substr(space_index, inp_rus.length());
                        *slov += make_pair(inp_eng, rus_tr);
                    }
                    inp_file.close();
                    cout << "������� �� ����� ������� ��������!" << endl;
                }
                else
                    cout << "���� �� ������!" << endl;
                cout << "������� \"0\" ��� �����������: ";
                cin >> choice_case;
            }
            break;
        }
    }

}
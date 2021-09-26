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
        cout << "Âûáåðèòå äåéñòâèå:\n";
        cout << "1. Äîáàâèòü ñëîâî (èëè ïåðåâîä ê ñóùåñòâóþùåìó ñëîâó)\n";
        cout << "2. Óäàëèòü ñëîâî\n";
        cout << "3. Óäàëèòü ïåðåâîä èç ñëîâà\n";
        cout << "4. Ïîèñê ïåðåâîäà àíãëèéñêîãî ñëîâà\n";
        cout << "5. Çàìåíà ïåðåâîäà àíãëèéñêîãî ñëîâà\n";
        cout << "6. Êîëè÷åñòâî ñëîâ â ñëîâàðå\n";
        cout << "7. Çàãðóçèòü ñëîâàðü èç ôàéëà\n";
        cout << "0. Âûõîä.\n";
        cout << "Ââåäèòå äåéñòâèå: ";
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
                cout << "Ââåäèòå àíãëèéñêîå ñëîâî: ";
                cin >> eng_word;

                int translation_count = 1;
                cout << "Ñêîëüêî ïåðåâîäîâ äëÿ ýòîãî ñëîâà âû õîòèòå: ";
                cin >> translation_count;
                for (int i = 0; i < translation_count; i++)
                {
                    cout << "Ââåäèòå " << i + 1 << "-é ïåðåâîä íà ðóññêîì: ";
                    cin >> rus_word;
                    *slov += make_pair(eng_word, rus_word);
                }
                cout << "Æåëàåòå ëè âû äîáàâèòü åùå? (1 - äà, 0 - íåò) ";
                cin >> choice_case;
            }
            break;

        case 2:
            while (choice_case) {
                system("cls");
                string del_word;
                cout << "Ââåäèòå ñëîâî, êîòîðîå âû æåëàåòå óäàëèòü: ";
                cin >> del_word;
                *slov -= del_word;
                cout << "Æåëàåòå ëè âû óäàëèòü åùå? (1 - äà, 0 - íåò) ";
                cin >> choice_case;
            }
            break;

        case 3:
            while (choice_case) {
                system("cls");
                string del_tr;
                cout << "Ââåäèòå ñëîâî, ïåðåâîä êîòîðîãî âû æåëàåòå óäàëèòü: ";
                cin >> del_tr;
                cout << "Ïåðåâîäû: \n";
                for (int i = 0; i < slov->tr_count(del_tr); i++)
                {
                    cout << i + 1 << ". " << (*slov)[make_pair(del_tr, i)] << endl;
                }
                cout << "Ïåðåâîä ïîä êàêèì íîìåðîì âû õîòèòå óäàëèòü: ";
                int tr_numb;
                cin >> tr_numb;

                slov->delete_one_translation(del_tr, tr_numb);

                cout << "Æåëàåòå ëè âû óäàëèòü ïåðåâîä åùå? (1 - äà, 0 - íåò) ";
                cin >> choice_case;
            }
            break;

        case 4:
            while (choice_case) {
                system("cls");
                string tr_word;
                cout << "Ââåäèòå ñëîâî, êîòîðîå âû õîòèòå ïåðåâåñòè: ";
                cin >> tr_word;
                cout << "Ïåðåâîä: " << (*slov)[tr_word] << endl;
                cout << "Æåëàåòå ëè âû ïåðåâåñòè åùå? (1 - äà, 0 - íåò) ";
                cin >> choice_case;
            }
            break;

        case 5:
            while (choice_case) {
                system("cls");
                string change_word, new_word;
                cout << "Ââåäèòå ñëîâî, ïåðåâîä êîòîðîãî íóæíî èçìåíèòü: ";
                cin >> change_word;

                if (slov->tr_count(change_word) == 1)
                {
                    cout << "Òåêóùèé ïåðåâîä: " << (*slov)[change_word] << "\nÂâåäèòå íîâûé ïåðåâîä: ";
                    cin >> new_word;
                    (*slov)[make_pair(change_word, 0)] = new_word;
                }
                else {
                    cout << "Ïåðåâîäû: \n";
                    for (int i = 0; i < slov->tr_count(change_word); i++)
                    {
                        cout << i + 1 << ". " << (*slov)[make_pair(change_word, i)] << endl;
                    }
                    cout << "Ïåðåâîä ïîä êàêèì íîìåðîì âû õîòèòå èçìåíèòü: ";
                    int tr_numb;
                    cin >> tr_numb;
                    cout << "Ââåäèòå íîâûé ïåðåâîä: ";
                    cin >> new_word;
                    (*slov)[make_pair(change_word, tr_numb - 1)] = new_word;

                }
                cout << "Æåëàåòå ëè âû èçìåíèòü åùå? (1 - äà, 0 - íåò) ";
                cin >> choice_case;
            }
            break;

        case 6:
            while (choice_case) {
                system("cls");
                string del_word;
                cout << "Â ñëîâàðå: " << (*slov).length() << " ñëîâà." << endl;
                cout << "Ââåäèòå \"0\" äëÿ ïðîäîëæåíèÿ: ";
                cin >> choice_case;
            }
            break;

        case 7:
            while (choice_case) {
                system("cls");
                string file_name = "dictionary.txt";
                /*cout << "Ââåäèòå èìÿ ôàéëà: ";
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
                        for (int i = 0; i < inp_rus.length(); i++) ///ðàçáèâàåì âòîðóþ ÷àñòü ñòðîêè íà ðàçíûå ïåðåâîäû
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
                    cout << "Ñëîâàðü èç ôàéëà óñïåøíî çàãðóæåí!" << endl;
                }
                else
                    cout << "Ôàéë íå îòêðûò!" << endl;
                cout << "Ââåäèòå \"0\" äëÿ ïðîäîëæåíèÿ: ";
                cin >> choice_case;
            }
            break;
        }
    }

}

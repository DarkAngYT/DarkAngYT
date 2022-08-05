// Импортирование библиотек 

#include <iostream>
#include <string>
#include <unistd.h> // Библиотека, которую я изучил самостоятельно
#include <time.h> // Библиотека, которую я тоже изучил сам

// Неймспейс для класса std

using namespace std;

// Класс "RegLog"

template <typename T> class RegLog
{
    // Private код:
    
    T _name, _password, _nickname;
    
    // Public код:
    
    public:
        RegLog(T Name, T Password, T Nickname, T name1, T password1)
        {
            cout << "Enter your name!" << endl;
            cin >> Name;
            cout << "Okay, enter your password! " << endl;
            cin >> Password;
            
            cout << "Nice, last step! Enter your nickname!" << endl;
            cin >> Nickname;
            
            sleep(1); // Вот и одна из команд, которая из библиотеки "unistd.h". Фактически, работает, как задержка
            
            cout << '\n' << "Hello, " << Nickname << "!" << endl;
            
            sleep(1);
            
            cout << '\n' << "Sorry, but you need log in! After log in, chat is open! :)" << endl;
            
            sleep(1);
            
            // Присваивание данных приватным переменным в целе защиты
            
            _name = Name;
            _password = Password;
            _nickname = Nickname;
            
            // Код с оператором goto. Знаю, использовать этот оператор нежелательно, но пришлось...
            
            Login:
                cout <<'\n' << "Enter your name!" << endl;
                cin >> name1;
                cout << "Well... Finally, enter your password!" << endl;
                cin >> password1;
                
                if(name1 != _name or password1 != _password)
                {
                    cout << '\n' << "No - no - no! Try again!" << '\n' << endl;
                    goto Login;
                }
                    
                    cout << '\n' << "Perfect! Chat is open. have fun :)" << endl;
        }
};

int RandNum(int min, int max)
{
  // Генератор случайных чисел
  
  srand(time(NULL));

  // Случайное число, загаданное в диапазоне(формула):
  
  int num = min + rand() % (max - min + 1); // Сама формула
  
  return num;
}

// Основная функция "main"

int main()
{
    // Вызов шаблонного класса для активации регистрации и логина
    
    string _name, _password, _nickname, _name1, _password1;
    RegLog <string> (_name, _password, _nickname, _name1, _password1);
    
    sleep(2);
    
    Chat:
        int Rand;
        string cmd;
    
        cout << "If you wanna start, write '/start'. But, if you wanna leave from chat, write '/stop'" << '\n' << endl;
        cin >> cmd;
        
        int stop = 0;
        string mes;
        
        // Условия для нормальной работы чата:
        
        if(cmd == "/start")
        {
            // Цикл в условии
            
            while(stop != 1)
            {
                cout << "My message : " << endl; 
                cin >> mes;
                
                int Rand = RandNum(2, 7); // Генерация рандомного числа, с помощью библиотек "stdlib.h" и "time.h"
                
                sleep(Rand);
                
                cout << "Message is delivery!" << '\n' << endl;
            }
        }
        
        else if(cmd == "/stop")
        {
            cout << "Okay, have a nice day!" << endl;
            stop += 1;
        }
        else
        {
            cout << "Invalid command!" << endl;
            goto Chat;
        }
        
    return 0; // Возвращаем 0, обозначая, что сессия была успешно выполнена
}
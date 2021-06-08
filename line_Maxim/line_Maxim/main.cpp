#include <vector>
#include <iostream>

std::vector<int> Q = {1,0,0,1,1};

// пометить i-го в очереди Q как 0/1 спокойный/неспокойный
void worry_quiet(std::vector<int> &Q, int i, unsigned char wq)
{
    Q[i] = wq;
}

void Come_addQuiet_delAny(std::vector<int> &Q, int ra)
{
    while(ra-- > 0) Q.push_back(0); // добавляем в конец ra-спокойных

    while(ra++ < 0) Q.pop_back(); // удаляем с конца очереди ra-человек
}

// метод возвращает количество неспокойных
int WorryCount(std::vector<int> &Q)
{
    int c = 0; // итератор неспокойных
    for(int i = Q.size() - 1; i > 0; i--) if(Q[i] == 1) c++;

    return c;
}
int main()
{
    // помечаем i-го в очереди Q как 0/1 спокойный/неспокойный
    worry_quiet(/*очередь*/ Q, /* i-й */ 3, /* 0/1 спок/неспок*/ 0); // 0 - спокойный, 1 - неспокойный
    // добавляем в конец очереди спокойных(+) или удаляем с конца очереди(-) любого
    Come_addQuiet_delAny(Q, 2);
    Come_addQuiet_delAny(Q, -3);
    // выводим количество неспокойных в очереди
    std::cout << "Restless count: " << WorryCount(Q);
    
    return 0;
}

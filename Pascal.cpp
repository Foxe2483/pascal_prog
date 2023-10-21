#include<iostream>
#include<string>
#include<stdlib.h>

std::string out_num(int count, int i) {

    std::string answ = std::to_string(i);
    int a = count/2 - answ.size();
    for(int b = 0; b != a; b++) answ += " ";
    return answ;
}

int main() {

    int quan;
    std::cout<<"Quantity:";
    std::cin >> quan;
    int num;
    std::cout<< "The number:";
    std::cin >> num;

    int mas[1000][1000]={{num}};

    for(int x = 1; x != quan; x++) {
        for(int y = 0; y != quan; y++) {

            mas[x][y] = mas[x-1][y] + mas[x][y-1];
            std::cout << out_num(quan, mas[x][y]) << " ";

        }
        std::cout<<std::endl;
    }

    for(int x = 1; x != quan; x++) {
            mas[x][quan-1] = mas[x-1][quan-1] + mas[x][quan-2];
            std::cout << out_num(quan, mas[x][quan-1]) << " ";
    }
    std::cout<< out_num(quan, (mas[quan-2][quan-1] + mas[quan-1][quan-2])*2) <<std::endl;

    exit(1);
    return 0;
}

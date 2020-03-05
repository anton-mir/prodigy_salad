#include <iostream>
#include <vector>
#include "Salads.h"

salad_ref GreekCreator::create() {
    std::cout << "Cooking Greek salad for you, will be added to your order." << std::endl;
    return std::make_unique<Greek>(100,1,100);
}

salad_ref PotatoeCreator::create() {
    std::cout << "Cooking Potatoe salad for you, will be added to your order." << std::endl;
    return std::make_unique<Potatoe>(200, 2, 200);
}

salad_ref cookSalad(Creator &salad)
{
    return salad.create();
}

int main() {

    char input;
    std::vector<salad_ref> order_list;
    GreekCreator creator_greek;
    PotatoeCreator creator_potatoe;
    do {
        std::cout << "What do you want?\n"
                     "1: Greek salad\n"
                     "2: Potatoe salad\n"
                     "P: Print your oder list\n"
                     "Q: Checkout" << std::endl;
        std::cin >> input;
        switch (input) {
            case '1':
            {
                order_list.push_back(cookSalad(creator_greek));
            }
                break;
            case '2':
            {
                order_list.push_back(cookSalad(creator_potatoe));
            }
                break;
            case 'P':
            case 'p':
            {
                for (auto& iterator: order_list) {
                    std::cout << iterator->print_salad_name() << std::endl;
                }
            }
                break;
            case 'q':
            case 'Q':
                break;
            default:
                std::cout << "Hmmm... What?" << std::endl;
                break;
        }
    } while (input != 'Q' && input != 'q');

    if (!order_list.empty()) {
        std::cout << "Your order is ready!" << std::endl;
        float total_price = 0;
        for (auto& iterator: order_list) {
            std::cout << iterator->print_salad_name() <<
                      " : Weight " << iterator->get_weight() <<
                      " : Calories " << iterator->get_calories() <<
                      " : Price " << iterator->get_price() << std::endl;
            total_price += iterator->get_price();
        }
        std::cout << "Pay your price now: " << total_price << std::endl;
    }
    else {
        std::cout << "Wasted my time bastard!" << std::endl;
    }



    return 0;
}



#include <iostream>

// Local.
#include "options.h"
#include "underlying.h"


int main(void) {

    // Underlyings test.

    int nstocks = 10;
    int nbonds = 9;
    int ncurrencies = 4;
    int ncommodities = 2;
    
    std::vector<Underlying> underlyings;


    for (int i = 0; i < nstocks; i++) {
        underlyings.push_back(
            Underlying((float) 1.0, asset_type::stock)
        );
    }
    
    for (int i = 0; i < nbonds; i++) {
        underlyings.push_back(
            Underlying((float) 2.0, asset_type::bond)
        );
    }

    for (int i = 0; i < ncurrencies; i++) {
        underlyings.push_back(
            Underlying((float) 1.0, asset_type::currency)
        );
    }
    
    for (int i = 0; i < ncommodities; i++) {
        underlyings.push_back(
            Underlying((float) 1.0, asset_type::commodity)
        );
    }

    
    std::cout << " Predicted number of underlyings " << (nstocks + nbonds + ncurrencies + ncommodities) << "\n";
    std::cout << " Number of underlyings" << Underlying::get_underlyings().size() << "\n";
   

    int stock_count = 0;
    int bond_count = 0;
    int currency_count = 0;
    int commodity_count = 0;

    for (auto &underlying : underlyings) {
        switch (underlying.get_asset_type()) {
            case asset_type::stock:
                stock_count++;
                break;

            case asset_type::bond:
                bond_count++;
                break;

            case asset_type::currency:
                currency_count++;
                break;

            case asset_type::commodity:
                commodity_count++;
                break;

        }
    }

    std::cout << stock_count << std::endl;
    std::cout << bond_count << std::endl;
    std::cout << currency_count << std::endl;
    std::cout << commodity_count << std::endl;
    
    underlyings.clear();         // capacity at 0 after clear.
    underlyings.shrink_to_fit();  // shrunk allocated memory to 0.

        // alternatively we can call underlyings.~vector(); or 
        // new (&underlyings) std::vector<Underlying>(); etc...
        // but not recommended. 

     
    // Options test.
    Underlying underlying((float) 1.38, asset_type::stock);

    std::vector<EuropeanOption> options;
    for (int i = 0; i < 50; i++) {
        options.emplace_back(
            EuropeanOption(underlying, option_type::put)
        );
    }


    for (auto &option : options) {
        auto [i, j] = option.get_index();
        std::cout << i << ", " << j << "\n";
    }

    return 0;

};

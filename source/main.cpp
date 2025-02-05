#include "Ordering.h"
#include "Menu.h"
#include <iostream>

using namespace seneca;

int main() {
    // Initialize the Ordering object with data files
    Ordering order("drinks.csv", "foods.csv");
    
    // Check if Ordering initialized successfully
    if (!order) {
        std::cerr << "Failed to open data files or the data files are corrupted!\n";
        return 1;
    }

    // Create the Main Menu with a trailing space in the title for proper formatting
    Menu mainMenu("Seneca Restaurant ", "End Program", 0, 3);
    mainMenu << "Order" << "Print Bill" << "Start a New Bill" << "List Foods" << "List Drinks";

    while (true) {
        // Display the Main Menu and get user selection
        size_t selection = mainMenu.select();

        switch (selection) {
            case 1: // Order
                {
                    bool stayInOrderMenu = true; // Flag to control the Order Menu loop

                    while (stayInOrderMenu) {
                        // Create the Order Menu with proper indentation
                        Menu orderMenu("Order Menu", "Back to main menu", 1, 3);
                        orderMenu << "Food" << "Drink";

                        // Display the Order Menu and get user selection
                        size_t orderSelection = orderMenu.select();

                        switch (orderSelection) {
                            case 1: // Food
                                order.orderFood();
                                break;

                            case 2: // Drink
                                order.orderDrink();
                                break;

                            case 0: // Back to Main Menu
                                stayInOrderMenu = false; // Exit the Order Menu loop
                                break;

                            default: // Invalid selection in Order Menu
                                std::cout << "Invalid selection in Order Menu.\n";
                        }
                    }
                }
                break;

            case 2: // Print Bill
                order.printBill(std::cout);
                break;

            case 3: // Start a New Bill
                order.resetBill();
                break;

            case 4: // List Foods
                order.listFoods();
                break;

            case 5: // List Drinks
                order.listDrinks();
                break;

            case 0: // End Program
            {
                // Check if there are unsaved bills
                if (order.hasUnsavedBill()) {
                    // Create the Confirmation Menu
                    Menu confirmExit("You have bills that are not saved, are you sue you want to exit?", "No", 0, 3);
                    confirmExit << "Yes";

                    // Display the Confirmation Menu and get user selection
                    size_t confirmSelection = confirmExit.select();

                    if (confirmSelection == 1) { // Yes
                        std::cout << "Goodbye!\n";
                        return 0;
                    }
                    else if (confirmSelection == 0) { // No
                        // Return to Main Menu
                    }
                    else { // Invalid selection in Confirmation Menu
                        std::cout << "Invalid selection in Confirmation Menu.\n";
                    }
                }
                else {
                    // No unsaved bills, exit normally
                    std::cout << "Goodbye!\n";
                    return 0;
                }
            }
            break;

            default: // Invalid selection in Main Menu
                std::cout << "Invalid selection.\n";
        }
    }

    return 0;
}

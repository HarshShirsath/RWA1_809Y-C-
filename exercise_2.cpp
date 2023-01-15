#include <iostream>
#include <string>
#include <vector>

int main () {
    char elements[9]  = { 0 };
    char pegColors[3] = { 'r', 'b', 'g' };

    std::vector<int> indices;
    std::string input;
    std::string str;
    do {
        for (int i = 0; i < 9; ++i) {
            elements[i] = 0;
        }

        for (int colorIndex = 0; colorIndex < 3; ++colorIndex) {        //This line provides the option of three colors(pegs) which are to be picks
            do {
                switch (colorIndex) {
                case 1: {
                    std::cout << "Do you want to pick up the blue pegs (y/n)\n";
                    break;
                }
                case 2: {
                    std::cout
                    << "Do you want to pick up the green pegs (y/n)\n";
                    break;
                }
                case 0:
                default: {
                    std::cout << "Do you want to pick up the red pegs (y/n)\n";
                    break;
                }
                }
                std::getline (std::cin, input);
                if (input[0] == 'n') {
                    break;
                }
            } while (input[0] != 'y');

            if (input[0] == 'n') {
                continue;
            }

            int pegsPlaced = 0;
            do {
                switch (colorIndex) {
                case 1: {
                    std::cout
                    << "where do you want to place the blue pegs(1-9)\n";
                    break;
                }
                case 2: {
                    std::cout
                    << "where do you want to place the green pegs(1-9)\n";
                    break;
                }
                case 0:
                default: {
                    std::cout
                    << "where do you want to place the red pegs(1-9)\n";
                    break;
                }
                }
                std::getline (std::cin, str);

                while (str.size () > 0) {                       //this parses the string which is been answered as an input
                    int index       = -1;
                    char delim      = ' ';
                    size_t position = str.find (delim, 0);

                    if (position != std::string::npos) {
                        std::string token = str.substr (0, position);
                        str.erase (0, position + 1);
                        index = atoi (token.c_str ());
                    } else {
                        index = atoi (str.c_str ());
                        str.erase (0, str.size ());
                    }

                    if (index > 0 && index <= 9) {
                        if (elements[index - 1] == 0) // This means the spot is empty! and a peg can be placed!
                        {
                            indices.push_back (index);
                            pegsPlaced++;
                        } else {
                            std::cout << "Pegs of other color already exists "
                                         "at this spot. Please try again with "
                                         "different indices.\n";
                            pegsPlaced = 0;
                            indices.clear ();
                            break;
                        }
                    }
                }
            } while (pegsPlaced == 0);

            for (int x = 0; x < indices.size (); ++x) {
                elements[indices[x] - 1] = pegColors[colorIndex];
            }
            indices.clear ();

            std::cout
            << "---------------------------------------------------\n";
            for (int i = 0; i < 9; ++i) {
                if (elements[i] == 0) {
                    std::cout << i + 1 << ' ';
                } else {
                    std::cout << elements[i] << ' ';
                }

                if ((i + 1) % 3 == 0) {
                    std::cout << '\n';
                }
            }
        }

        std::cout << "---------------------------------------------------\n";
        std::cout << "Final Positions of the pegs:\n";          //this prints the entire matrix 
        for (int i = 0; i < 9; ++i) {
            if (elements[i] == 0) {
                std::cout << i + 1 << ' ';
            } else {
                std::cout << elements[i] << ' ';
            }

            if ((i + 1) % 3 == 0) {
                std::cout << '\n';
            }
        }

        std::cout << "Try Again? (Y/N) \n";                 //Provides you a window to try the program again from start
        std::getline (std::cin, input);
    } while (input[0] != 'n');
}
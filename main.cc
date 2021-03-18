/**
 * @file main.cpp
 * @brief Executible to copy a file to X targets
 */

#include <stdint.h>
#include <iostream>

#include "hw5_mcp.h"

// -----------------------------------------------------------------------------
// Global Vars
std::string source;
std::vector<std::string> destinations;

static bool basic_arg_parser(int argc, char *argv[])
{
    bool ret_val = true;

    if (3 > argc)
    {
        std::cerr << "MCP ERR: Incorrect number of arguments passed in." << std::endl;
        ret_val = false;
    }
    else
    {
        // check if arg exists
        for (int i = 1; i < (argc-1); i+=2)
        {
            if ("-t" == std::string(argv[i]))
            {
                destinations.push_back(std::string(argv[i+1]));
            }
            else if ("-s" == std::string(argv[i]))
            {
                // If source already assigned
                if (source != "")
                {
                    std::cerr << "MCP ERR: Cannot have multiple source files" << std::endl;
                    ret_val = false;
                    break;
                }
                else
                {
                    source = std::string(argv[i+1]);
                }
            }
            else
            {
                std::cerr << "MCP ERR: Incorrect option passed in" << std::endl;
                ret_val = false;
                break;
            }
        }
    }

    return ret_val;
}

static void print_help()
{
    std::cout << "\nMCP: Multiple Copy Paster\n" \
        "This program is utlized to copy a file to multiple target locations.\n" \
        "\nOptions:\n" \
        "    -s  : Source file [Required, not repeatable]\n" \
        "    -t  : Destination file(s) [Required, repeatable]\n" \
        "    -h  : Display help\n" \
        "\nExample Usage:\n" \
        "   mcp -s source.txt -t dest1.txt -t dest2.txt" << std::endl;
}

int main(int argc, char *argv[])
{
    // Clear global vars
    source = "";
    destinations.clear();    

    if (!basic_arg_parser(argc,argv))
    {
        print_help();
    }
    else
    {
        FileMultiplier fm;

        if (0 != fm.copy(source))
        {
            fm.print_err();
        }

        for (auto e : destinations)
        {
            if (0 != fm.paste(e))
            {
                fm.print_err();
            }
        }
    }

    return 0;
}
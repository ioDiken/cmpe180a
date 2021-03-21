/**
 * @file mcp.ccc
 * @brief Executible to copy a file to X targets
 * @author Nicolas Diken
 * @SJSUID 011280893
 * 
 * Note:
 *   This looks rather messy as I implemented it using a separate library
 *   that I included in the main. This is rather messy to include in a single
 *   source file, but oh well?
 */

#include <stdint.h>
#include <stdbool.h>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

// -----------------------------------------------------------------------------
// Global Vars

std::string source_file;
std::vector<std::string> destination_files;

int mcp_errno;

// -----------------------------------------------------------------------------
// Macro Variables

#define MCP_ERR_NO_ERROR                    (0)
#define MCP_ERR_SOURCE_FILE_EMPTY           (-2)
#define MCP_ERR_SOURCE_FILE_DNE             (-3)
#define MCP_ERR_DEST_FILE_EXISTS            (-4)

// -----------------------------------------------------------------------------
// File Multiplier Class

class FileMultiplier
{
public:
    FileMultiplier()
    {
        mcp_errno = MCP_ERR_NO_ERROR;
    }

    ~FileMultiplier() = default;

    int copy(const std::string& source)
    {
        int ret_val = -1;

        if (check_src(source))
        {
            ret_val = 0;
            src = std::ifstream(source.c_str(), std::fstream::in);
        }

        return ret_val;
    }


    int paste(const std::string& destination)
    {
        int ret_val = -1;

        if (check_dst(destination))
        {
            ret_val = 0;

            std::ofstream dst(destination.c_str());
            dst << src.rdbuf();
        }

        return ret_val;
    }

    void print_err()
    {
        switch(mcp_errno)
        {
            case MCP_ERR_SOURCE_FILE_EMPTY:
                std::cerr << "MCP ERR: Source file is empty" << std::endl;
                break;
            
            case MCP_ERR_SOURCE_FILE_DNE:
                std::cerr << "MCP ERR: Source file does not exist" << std::endl;
                break;
            
            case MCP_ERR_DEST_FILE_EXISTS:
                std::cerr << "MCP ERR: Desination file does exists" << std::endl;
                break;
            
            default:
                break;
        }
    }

private:
    std::ifstream src;

    bool check_src(const std::string& file)
    {
        bool ret_val = true;
        std::ifstream f(file.c_str(), std::fstream::in);

        if (!f)
        {
            mcp_errno = MCP_ERR_SOURCE_FILE_DNE;
            ret_val = false;
        }

        return ret_val;
    }

    bool check_dst(const std::string& file)
    {
        bool ret_val = true;

        std::ifstream f(file.c_str(), std::fstream::in);

        if (f)
        {
            mcp_errno = MCP_ERR_DEST_FILE_EXISTS;
            ret_val = false;
        }

        return ret_val;
    }
};

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
                if (std::find(destination_files.begin(), destination_files.end(), std::string(argv[i+1])) != destination_files.end())
                {
                    std::cerr << "MCP ERR: Cannot repeat desination files." << std::endl;
                    ret_val = false;
                    break;
                }
                else
                {
                    destination_files.push_back(std::string(argv[i+1]));
                }
            }
            else if ("-s" == std::string(argv[i]))
            {
                // If source already assigned
                if (source_file != "")
                {
                    std::cerr << "MCP ERR: Cannot have multiple source files" << std::endl;
                    ret_val = false;
                    break;
                }
                else
                {
                    source_file = std::string(argv[i+1]);
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
    source_file = "";
    destination_files.clear();    

    if (!basic_arg_parser(argc,argv))
    {
        print_help();
    }
    else
    {
        FileMultiplier fm;

        if (0 != fm.copy(source_file))
        {
            fm.print_err();
        }
        else
        {
            for (auto e : destination_files)
            {
                if (0 != fm.paste(e))
                {
                    fm.print_err();
                }
            }
        }

    }

    return 0;
}
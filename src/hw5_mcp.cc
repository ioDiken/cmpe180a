/**
 * @file hw5_mcp.h
 * @brief Copy Files
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "hw5_mcp.h"
#include <iostream>

// -----------------------------------------------------------------------------
// Local Variables

int mcp_errnoo;

// -----------------------------------------------------------------------------
// File Multiplier Functions

FileMultiplier::FileMultiplier()
{
    mcp_errnoo = MCP_ERR_NO_ERROR;
}

int FileMultiplier::copy(const std::string& source)
{
    int ret_val = -1;

    if (check_src(source))
    {
        ret_val = 0;
        src = std::ifstream(source.c_str(), std::fstream::in);
    }

    return ret_val;
}

int FileMultiplier::paste(const std::string& destination)
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

void FileMultiplier::print_err()
{
    switch(mcp_errnoo)
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

bool FileMultiplier::check_src(const std::string& file)
{
    bool ret_val = true;
    std::ifstream f(file.c_str(), std::fstream::in);

    if (!f)
    {
        mcp_errnoo = MCP_ERR_SOURCE_FILE_DNE;
        ret_val = false;
    }

    return ret_val;
}

bool FileMultiplier::check_dst(const std::string& file)
{
    bool ret_val = true;

    std::ifstream f(file.c_str(), std::fstream::in);

    if (f)
    {
        mcp_errnoo = MCP_ERR_DEST_FILE_EXISTS;
        ret_val = false;
    }

    return ret_val;
}
/**
 * @file arg_parser.h
 * @brief Create a list of arguments to parse & look for
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#include "arg_parser.h"

// // Overload Map insert
// ArgumentParser::pair<string, vector<string>> insert(const value_type& value)
// {
//     this[value.first].insert(value.second);
// }

// Return True if all args parsed
bool ArgumentParser::parse_args(int argc, char *argv[])
{
    bool ret_val = true;

    // vector of options
    vector<string> opts;
    for(std::map<string,vector<string>>::iterator it = m.begin(); it != m.end(); it++)
    {
        opts.push_back(it->first);
    }

    // check if arg exists
    for (int i = 1; i < (argc-1); i+=2)
    {
        if (std::find(opts.begin(), opts.end(), argv[i]) == opts.end())
        {
            ret_val = false;
            break;
        }
    }

    return ret_val;
}
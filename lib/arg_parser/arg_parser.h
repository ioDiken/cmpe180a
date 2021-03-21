/**
 * @file arg_parser.h
 * @brief Create a list of arguments to parse & look for
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#ifndef DED99A72_E703_46E7_9504_2C062038118B
#define DED99A72_E703_46E7_9504_2C062038118B

#include <stdbool.h>
#include <stdint.h>
#include <string>
#include <vector>
#include <map>

using namespace std;

class ArgumentParser
{
public:

    ArgumentParser() {};
    ~ArgumentParser() = default;

    bool parse_args(int argc, char *argv[]);

    bool add_option(string arg, int flags);
    bool add_option(const char* arg, int flags);

    string get_option(string arg);
    string get_option(const char* arg);
    vector<string> get_options(string arg);
    vector<string> get_options(const char* arg);

    // Flags for args
    struct FLAGS
    {
        static const int REQUIRED = 0x1;
        static const int REPEATABLE = 0x2;
    };

    // Overload Map insert
    // pair<string, vector<string>> insert(const value_type& value);

private:
    map<string,vector<string>> args;
    bool parse_next_arg();
};


#endif /* DED99A72_E703_46E7_9504_2C062038118B */

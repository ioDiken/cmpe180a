/**
 * @file hw5_mcp.h
 * @brief Copy Files
 * @sjsuid 011280893
 * @author Nicolas Diken
 */

#ifndef BFC01192_EE67_4214_9782_78D38A378F25
#define BFC01192_EE67_4214_9782_78D38A378F25

#include <stdint.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <fstream>

#define MCP_ERR_SOURCE_FILE_EMPTY           (-2)
#define MCP_ERR_SOURCE_FILE_DNE             (-3)
#define MCP_ERR_DEST_FILE_EXISTS            (-4)

extern int mcp_errno;

class FileMultiplier
{
public:
    FileMultiplier() {};
    ~FileMultiplier() = default;

    int copy(const std::string& source);
    int paste(const std::string& destination);

private:
    std::ifstream src;

    bool check_src(const std::string& file);
    bool check_dst(const std::string& file);
};

#endif /* BFC01192_EE67_4214_9782_78D38A378F25 */

#include <fstream>
#include <string>
#include <cmath>

std::string solve(const std::string &path, int dst_x, int dst_y)
{
    std::string path_new = path;
    int x = 0, y = 0;
    for (int i = 0; i < path.size(); ++i)
    {
        switch (path[i])
        {
        case 'U':
            ++y;
            break;
        
        case 'D':
            --y;
            break;

        case 'R':
            ++x;
            break;
        
        case 'L':
            --x;
            break;
        }
    }
    int diff_x = x - dst_x, diff_y = y - dst_y;
    int hoz_remove = std::abs(diff_x), vert_remove = std::abs(diff_y);
    int i = path_new.size() - 1;
    while (i >= 0 && hoz_remove > 0 && vert_remove > 0)
    {
        while (path_new[i] == (diff_x < 0 ? 'L' : 'R') && hoz_remove > 0)
        {
            path_new.erase(i);
            --i; --hoz_remove;
        }
        while (path_new[i] == (diff_y < 0 ? 'D' : 'U') && vert_remove > 0)
        {
            path_new.erase(i);
            --i; --vert_remove;
        }
    }
    return path_new;
}

int main(int argc, char const *argv[])
{
    std::ifstream input("CHEMLAB.inp");
    std::ofstream output("CHEMLAB.out");
    int n;
    input >> n;
    std::string s;
    std::getline(input, s);
    int dst_x, dst_y;
    input >> dst_x >> dst_y;
    output << solve(s, dst_x, dst_y);
    return 0;
}

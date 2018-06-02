#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

enum Direction
{
    NW,
    N,
    NE,
    W,
    E,
    SW,
    S,
    SE
};

string getline(ifstream&);
int find(char*, int, int, string);
bool scan(char*, int, int, int, int, string, int, Direction);

int main(int argc, char* argv[])
{
    ifstream file(argc == 0 ? "input.txt" : argv[1]);

    if(!file.good())
    {
        cout << "FATAL: Canot open input file!" << endl;
        return -1;
    }

    string output = "";

    int cases = stoi(getline(file));

    for(int t = 0; t < cases; ++t)
    {
        int h = stoi(getline(file));
        int w = stoi(getline(file));

        char* grid = new char[w * h];
        for(int r = 0; r < h; ++r)
        {
            string line = getline(file);
            if(line.length() < w) line = line.append(w - line.length(), ' ');
            for(int c = 0; c < w; ++c)
            {
                grid[(r * w) + c] = line[c];
            }
        }

        int result = find(grid, w, h, getline(file));

        delete[] grid;

        output += "Case " + to_string(t + 1) + ": " + to_string(result) + '\n';
    }

    cout << output;

    return 0;
}

string getline(ifstream& stream)
{
    string buffer = "";
    getline(stream, buffer);
    return buffer;
}

int find(char* grid, int grid_width, int grid_height, string find)
{
    int count = 0;

    for(int r = 0; r < grid_height; ++r)
    {
        for(int c = 0; c < grid_width; ++c)
        {
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::NW)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::N)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::NE)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::W)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::E)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::SW)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::S)) count++;
            if(scan(grid, grid_width, grid_height, r, c, find, 0, Direction::SE)) count++;
        }
    }

    return count;
}

bool scan(char* grid, int grid_width, int grid_height, int r, int c, string find, int position, Direction direction)
{
    if(position == find.length()) return true;

    switch(direction)
    {
        case Direction::NW:
            if(c < 0 || r < 0) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r - 1, c - 1, find, position + 1, direction);
            break;

        case Direction::N:
            if(r < 0) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r - 1, c, find, position + 1, direction);
            break;

        case Direction::NE:
            if(r < 0 || c == grid_width) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r - 1, c + 1, find, position + 1, direction);
            break;

        case Direction::W:
            if(c < 0) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r, c - 1, find, position + 1, direction);
            break;

        case Direction::E:
            if(c == grid_width) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r, c + 1, find, position + 1, direction);
            break;

        case Direction::SW:
            if(c < 0 || r == grid_height) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r + 1, c - 1, find, position + 1, direction);
            break;

        case Direction::S:
            if(r == grid_height) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r + 1, c, find, position + 1, direction);
            break;

        case Direction::SE:
            if(c == grid_width || r == grid_height) return false;
            if(grid[(r * grid_width) + c] == find[position]) return scan(grid, grid_width, grid_height, r + 1, c + 1, find, position + 1, direction);
            break;
    }

    return false;
}
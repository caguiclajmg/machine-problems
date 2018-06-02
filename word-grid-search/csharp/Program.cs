using System;
using System.IO;
using System.Text;

class Program
{
    public static int Main(string[] args)
    {
        var path = args.Length == 0 ? "input.txt" : args[0];

        if (!File.Exists(path))
        {
            Console.WriteLine($"FATAL: Cannot open input file!");
            return -1;
        }

        var output = new StringBuilder();

        var file = new StreamReader(path);
        var cases = Convert.ToInt32(file.ReadLine());

        for (int t = 0; t < cases; ++t)
        {
            var h = Convert.ToInt32(file.ReadLine());
            var w = Convert.ToInt32(file.ReadLine());

            var grid = new char[h, w];
            for (int r = 0; r < h; ++r)
            {
                var line = file.ReadLine().PadRight(w);
                for (int c = 0; c < w; ++c)
                {
                    grid[r, c] = line[c];
                }
            }

            var result = Find(grid, file.ReadLine());
            output.Append($"Case {t + 1}: {result}\n");
        }

        Console.Write(output);

        return 0;
    }

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

    static int Find(char[,] grid, String find)
    {
        int count = 0;

        for (int y = 0; y < grid.GetLength(0); ++y)
        {
            for (int x = 0; x < grid.GetLength(1); ++x)
            {
                foreach (Direction direction in Enum.GetValues(typeof(Direction)))
                {
                    if (Scan(grid, x, y, find, 0, direction)) count++;
                }
            }
        }

        return count;
    }

    static bool Scan(char[,] grid, int x, int y, String find, int position, Direction direction)
    {
        if (position == find.Length) return true;

        switch (direction)
        {
            case Direction.NW:
                if (x < 0 || y < 0) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x - 1, y - 1, find, position + 1, direction);
                break;

            case Direction.N:
                if (y < 0) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x, y - 1, find, position + 1, direction);
                break;

            case Direction.NE:
                if (y < 0 || x == grid.GetLength(1)) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x + 1, y - 1, find, position + 1, direction);
                break;

            case Direction.W:
                if (x < 0) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x - 1, y, find, position + 1, direction);
                break;

            case Direction.E:
                if (x == grid.GetLength(1)) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x + 1, y, find, position + 1, direction);
                break;

            case Direction.SW:
                if (x < 0 || y == grid.GetLength(0)) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x - 1, y + 1, find, position + 1, direction);
                break;

            case Direction.S:
                if (y == grid.GetLength(0)) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x, y + 1, find, position + 1, direction);
                break;

            case Direction.SE:
                if (x == grid.GetLength(1) || y == grid.GetLength(0)) return false;
                if (grid[y, x] == find[position]) return Scan(grid, x + 1, y + 1, find, position + 1, direction);
                break;
        }

        return false;
    }
}
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace _3dSurfaceArea
{
    class Program
    {
        static int AreaSurface(int[][] a, int h, int w)
        {
            int s = 0;
            int[] vetx = { -1, 1, 0, 0 };
            int[] vety = { 0, 0, 1, -1 };

            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    s += 2;

                    if(i == 0)
                    {
                        s += a[i][j];
                    }

                    if (i == h - 1)
                    {
                        s += a[i][j];
                    }

                    if (j == 0)
                    {
                        s += a[i][j];
                    }

                    if(j == w - 1)
                    {
                        s += a[i][j];
                    }
                    for (int k = 0; k < 4; k++)
                    {
                        int tempx = vetx[k] + i;
                        int tempy = vety[k] + j;

                        if (tempx >= 0 && tempx < h && tempy >= 0 && tempy < w)
                        {
                            s += Math.Max(0, a[tempx][tempy] - a[i][j]);
                        }
                    }
                }
            }

            return s;
        }

        static void Main(string[] args)
        {
            string[] lines = Console.ReadLine().Split(' ');
            var h = Convert.ToInt32(lines[0]);
            var w = Convert.ToInt32(lines[1]);
            int[][] a = new Int32[h][];

            for(int i = 0; i < h; i++)
            {
                a[i] = Array.ConvertAll(Console.ReadLine().Split(' '), Int32.Parse);
            }

            Console.WriteLine(AreaSurface(a, h, w));

        }
    }
}


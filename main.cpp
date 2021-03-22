using System;
using static System.Console;
using System.Linq;

namespace ConsoleApp5
{
    class Program
    {

        static (int min, int max) MinMax_1(int[] array)
        {
            return (array.Min(), array.Max());
        }
        static void PrintArray_1(int[] array)
        {
            foreach (var item in array)
            {
                Write(item + " ");
            }
        }

        static int Max(int[,] arr)
        {
            int b_max = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (arr[i, j] > b_max)
                        b_max = arr[i, j];
                }
            }
            return b_max;
        }

        static void Max_common(int[] arr_A, int[,] arr_B, int[] result_arr)
        {
            int w = 0;
            for (int i = 0; i < arr_A.Length; i++)
            {
                for (int q = 0; q < 3; q++)
                {
                    for (int j = 0; j < 4; j++)
                    {
                        if (arr_B[q, j] == arr_A[i])
                        {

                            result_arr[w] = arr_B[q, j];
                            w++;
                        }
                    }
                }
            }
        }


        static void PrintArray_2(int[,] array)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    Write(array[i, j] + "|");
                }
                WriteLine();
            }
        }

        static int Sum_1(int[] arr)
        {
            int sum1 = 0;
            for (int i = 0; i < 5; i++)
            {
                sum1 += arr[i];
            }
            return sum1;
        }

        static int Sum_2(int[,] array)
        {
            int sum2 = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    sum2 += array[i, j];
                }
            }
            return sum2;
        }
        static int EvenNum_1(int[] arr)
        {
            int sum1Even = 0;
            for (int i = 0; i < 5; i++)
            {
                if (arr[i] % 2 == 0)
                    sum1Even += arr[i];
            }
            return sum1Even;
        }

        static int NotEven_2(int[,] array)
        {
            int sumNotEven = 0;
            for (int i = 0; i < 3; i++)
            {

                for (int j = 0; j < 4; j++)
                {
                    if (j % 2 != 0)
                    {
                        sumNotEven += array[i, j];
                    }
                }
            }
            return sumNotEven;
        }

        static int multiplying_1(int[] arr)
        {
            int mult1 = 1;
            for (int i = 0; i < 5; i++)
            {
                mult1 *= arr[i];
            }
            return mult1;
        }

        static int multiplying_2(int[,] array)
        {
            int mult2 = 1;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    mult2 *= array[i, j];
                }
            }
            return mult2;
        }

        static void Main()
        {
            (int, string, char) temp = (5, "test", 'y');
            WriteLine(temp.Item1);

            var arr_A = new int[5];
            var arr_B = new int[3, 4];

            for (int i = 0; i < 5; i++)
            {
                WriteLine("Введите число:");
                arr_A[i] = Convert.ToInt32(ReadLine());
            }

            Random rand = new Random();
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    arr_B[i, j] = rand.Next(0, 10);
                }
            }
            WriteLine("Массив А");
            PrintArray_1(arr_A);
            WriteLine("\nМассив B");
            PrintArray_2(arr_B);
            int[] arr_result = new int[arr_A.Length];

            int sumCommon = Sum_1(arr_A) + Sum_2(arr_B);
            WriteLine("\nСумма всех элеменов массивов: " + sumCommon);
            Max_common(arr_A, arr_B, arr_result);
            WriteLine("\nОбщий максиммальный элемент массивов: " + arr_result.Max());
            WriteLine("\nОбщий минимальный элемент массивов: " + arr_result.Min());
            int multCommon = multiplying_1(arr_A) + multiplying_2(arr_B);
            WriteLine("\nПроизведение всех элеменов массивов: " + multCommon);
            WriteLine("\nСумма всех четных элеменов массива А: " + EvenNum_1(arr_A));
            WriteLine("\nСумма всех нечетных столбцов элеменов массива В: " + NotEven_2(arr_B));

        }
    }
}

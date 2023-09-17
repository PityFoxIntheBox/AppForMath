#include <stdint.h>
#include <iostream>
#include <math.h>

/// <summary>
/// Функция вывода данных
/// </summary>
/// <param name="i">Параметр для вызова соответствующего сценария вывода данных</param>
/// <param name="x1">Параметр для первого корня уравнения или факториала</param>
/// <param name="x2">Параметр для второго корня уравнения</param>
void output(int i, float x1, float x2)
{
    switch (i)
    {
    case 1:
        printf("Корни квадратного уравенения равны %5.2f и %5.2f", x1, x2);
        break;
    case 2:
        printf("Корни линейного уравенения равны %5.2f и %5.2f", x1, x2);
        break;
    case 3:
        printf("Факториал вашего числа равен %5.2f", x1);
        break;
    default:
        break;
    }
}

/// <summary>
/// Функция для вычисления квадратного уравнения
/// </summary>
/// <param name="x1">Параметр для первого коэффицента уравнения</param>
/// <param name="x2">Параметр для второго коэффицента уравнения</param>
/// <param name="x3">Параметр для второго коэффицента уравнения</param>
void square(float x1, float x2, float x3)
{
    float d, x, xx;
    d = pow(x2, 2) - 4 * x1 * x3;
    x = (-x2 + sqrt(d)) / (2 * x1);
    xx = (-x2 - sqrt(d)) / (2 * x1);
    output(1, x, xx);
}

/// <summary>
/// Функция для вычисления системы линейных уравнений
/// </summary>
/// <param name="x1">Параметр для первого коэффицента первого уравнения</param>
/// <param name="x2">Параметр для второго коэффицента первого уравнения</param>
/// <param name="x3">Параметр для третьего коэффицента первого уравнения</param>
/// <param name="x4">Параметр для первого коэффицента второго уравнения</param>
/// <param name="x5">Параметр для второго коэффицента второго уравнения</param>
/// <param name="x6">Параметр для третьего коэффицента второго уравнения</param>
void linear(float x1, float x2, float x3, float x4, float x5, float x6)
{
    float x = (x3 * x5 - x2 * x6) / (x1 * x5 - x2 * x4);
    float xx = (x1 * x6 - x4 * x3) / (x1 * x5 - x2 * x4);
    output(2, x, xx);
}

/// <summary>
/// Функция для вычисления факториала
/// </summary>
/// <param name="x1">Параметр для числа факториала</param>
void factorial(float x1)
{
    float x = 1;
    for (int i = 1; i <= x1; i++)
    {
        x *= i;
    }
    output(3, x, x);
}

/// <summary>
/// Фукнция для ввода параметров (сделано максимально возможное количество переменных для универсального ввода)
/// </summary>
/// <param name="i">Параметр для вызова соответствующего сценария ввода данных</param>
void input(int i)
{
    float x1, x2, x3, x4, x5, x6;
    switch (i)
    {
        case 1:
            printf("Введите 3 коэфифцента через Enter\n");
            scanf_s("%f", &x1);
            scanf_s("\n%f", &x2);
            scanf_s("\n%f", &x3);
            square(x1,x2,x3);
            break;
        case 2:
            printf("Пример уравнения для корректного ввода a1x+b1y=c1 и a2x+b2x=c2\n");
            printf("Введите три коэффицента первого уравнения через Enter\n");
            scanf_s("%f", &x1);
            scanf_s("\n%f", &x2);
            scanf_s("\n%f", &x3);
            printf("Введите три коэффицента второго уравнения через Enter\n");
            scanf_s("%f", &x4);
            scanf_s("\n%f", &x5);
            scanf_s("\n%f", &x6);
            linear(x1, x2, x3, x4, x5, x6);
            break;
        case 3:
            printf("Введите число для которого нужно вывести факториал (число должно быть целым)\n");
            scanf_s("%f", &x1);
            factorial(x1);
            break;
        default:
            printf("Так нельзя, выберите один из вариантов (их всего 3)");
            break;
    }
}


/// <summary>
/// Функция для диалога с пользователем и вызова соответствующих других функций
/// </summary>
void menu()
{
    while (1)
    {
        int i;
        printf("Здравствуйте, введите пожалуйста то, что вы хотите вычислить \n1)Квадратное уравнение\n2)Система двух линейных уравнений\n3)Факториал\n");
        scanf_s("%d", &i);
        input(i);
        printf("\nХотите ли вы продолжить работу?\n1)Да\n2)Нет\n");
        scanf_s("%d", &i);
        if (i == 2)
        {
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    menu();
}



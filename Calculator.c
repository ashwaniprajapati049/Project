#include <stdio.h>
#include <math.h>
int CIRCLE()
{
    int radius;
    int sam;
    printf("please enter the radius of CIRCLE ");
    scanf("%d", &radius);
    sam = 3.14 * radius * radius;
    return sam;
}
int rectangle()
{
    int length, brigth, jam;
    printf("Enter the Length & brigth of Rectangle ");
    scanf("%d %d", &length, &brigth);
    jam = length * brigth;
    return jam;
}
float triangle()
{
    float base, hight;
    float dam;
    printf("Enter the base & hight ");
    scanf("%f %f", &base, &hight);
    dam = 0.5 * base * hight;
    return dam;
}
int Areaofsqaure()
{
    int side, ram;
    printf("Enter the side of sqaure:");
    scanf("%d", &side);
    ram = side * side;
    return ram;
}
int VolumeOfcube()
{
    int side, rom;
    printf("Enter the side of cube ");
    scanf("%d", &side);
    rom = side * side * side;
    return rom;
}
int Addition()
{
    int a, b, add;
    printf("Enter the first & second value:");
    scanf("%d%d", &a, &b);
    add = a + b;
    return add;
}
int Multiplication()
{
    int a, b, multi;
    printf("Enter the first & second value:");
    scanf("%d%d", &a, &b);
    multi = a * b;
    return multi;
}
int Substraction()
{
    int a, b, subs;
    printf("Enter the first & second value:");
    scanf("%d%d", &a, &b);
    subs = a - b;
    return subs;
}
int Division()
{
    int a, b, divi;
    printf("Enter the first & second value:");
    scanf("%d%d", &a, &b);
    divi = a / b;
    return divi;
}
int Sqaure()
{
    int a, sq;
    printf("Enter the number:");
    scanf("%d",&a);
    sq = a * a;
    return sq;
}
float SqaureRoot()
{

    float a;
    float b;
    printf("Enter the number:");
    scanf("%f",&a);
    for (b = 0.001; b * b < a; b = b + 0.001)
        ;
    printf("\n%.2f", b);
    return b;
}
int Cube()
{
    int a, cub;
    printf("Enter the number:");
    scanf("%d", &a);
    cub = a * a * a;
    return cub;
}
int QuardiaticEquation()
{

    double a, b, c, discriminant, root1, root2, realPart, imagPart;
    printf("Enter coefficients a, b and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("root1 = %.2lf and root2 = %.2lf", root1, root2);
    }

    else if (discriminant == 0)
    {
        root1 = root2 = -b / (2 * a);
        printf("root1 = root2 = %.2lf;", root1);
    }
    else
    {
        realPart = -b / (2 * a);
        imagPart = sqrt(-discriminant) / (2 * a);
        printf("root1 = %.2lf+%.2lfi and root2 = %.2f-%.2fi", realPart, imagPart, realPart, imagPart);
    }

    return root1, root2, realPart, imagPart;
}

int main()
{
    printf("SELECT AN OPERATION TO PERFORM THE CALCULATION IN C CALCULATOR -\n");
    printf("1.Area of CIRCLE\n");
    printf("2.Area of Rectangle\n");
    printf("3.Area of Triangle\n");
    printf("4.Area of Sqaure\n");
    printf("5.Volume of Cube \n");
    printf("6.Addition:\n");
    printf("7.Subtraction:\n");
    printf("8.Division:\n");
    printf("9.Multiplication:\n");
    printf("10.Sqaure:\n");
    printf("11.Sqaure root:\n");
    printf("12.Cube:\n");
    printf("13.Quardiatic Equation:\n");

    int select;
    printf("PLease,MAke a choice:");
    scanf("%d", &select);
    switch (select)
    {
    case 1:
        printf("Area of CIRCLE=%d", CIRCLE());
        printf("\n************************************************************************");
        break;
    case 2:
        printf("Area of Rectangle=%d", rectangle());
        printf("\n************************************************************************");
        break;
    case 3:
        printf("Area of Triangle=%.2f", triangle());
        printf("\n************************************************************************");
        break;

    case 4:
        printf("Area of sqaure=%d", Areaofsqaure());
        printf("\n************************************************************************");
        break;
    case 5:
        printf("volume of cube =%d", VolumeOfcube());
        printf("\n************************************************************************");
        break;
    case 6:
        printf("The addition of two number is = %d", Addition());
        printf("\n************************************************************************");
        break;
    case 7:
        printf("The Subsrtaction of two number is= %d", Substraction());
        printf("\n************************************************************************");
        break;
    case 8:
        printf("The divisonof Two number is = %d", Division());
        printf("\n************************************************************************");
        break;
    case 9:
        printf("The multiplication of two number is = %d", Multiplication());
        printf("\n************************************************************************");
        break;
    case 10:
        printf("The sqaure of entered number is = %d", Sqaure());
        printf("\n************************************************************************");
        break;
    case 11:
        printf("The sqaureroot of entered number is = %d", SqaureRoot());
        printf("\n************************************************************************");
        break;
    case 12:
        printf("The cube is given number is = %d ", Cube());
        printf("\n************************************************************************");
        break;
    case 13:
        printf("The factor is given Equation is = %d %d", QuardiaticEquation());
        printf("\n************************************************************************");
         break;

    default:
        printf("Error!!");
        break;
    }
}

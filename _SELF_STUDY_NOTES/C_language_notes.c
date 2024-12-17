// C Syntax is as follows:
        /* #include <stdio.h>
        int main(void)
        {
            printf("Hello!\n");
            return 0;
        } */

    // #include extends the mentioned ".h" file in the working ".c" file so we can use the c functions
    // <stdio.h> is the ".h" file extended in the file written inside "<>"
    // int main(void) is function in the c file i.e. called automatically when the code runs
    //     where int is the datatype returned by the function (e.g. return 0;) and main is the name of the function
    //     inside the "()" arguments are written if no arguments then type void as argument
    //     arguments are info given to the function to produce output from outside the function
    // printf("Hi\n"); is the function from stdio.h to print the string (text inside qoutes) or data to the screen
    //     \n is similar to enter key (next line) and ";" is termination point of the function or line of the code


// 0. COMMENTS IN C LANGUAGE
    // single line comments are written as // this is comment shortcut in vscode "ctrl+/"
    // multiline comment are written as /* this is multi line comment */

// 1. DATA TYPES IN C
    // mainly three datatypes in c as: int, float, char
    // application wise can also use bool and strings
    // Declaration
        // int a = 7;   // 4 byte
        // float = 1.0145;  // 4 byte
        // char = 'a';    // 1 byte
        // bool = true; // needs <stdbool.h> file   //1 byte
        // string is an array of characters so declared as  1. char str[10];     2.char str[]="abcd";   3.char* str = "abcd";
    // more types are unsigned int, short, long, double, long double
    //to get the memory size of any datatype use the following
        // sizeof(datatype)     ex. sizeof(int)     // returns the size of datatype in bytes

    // Rules For Naming Variables
        // variables must start with letters or underscore only
        // Camal casing is allowed in naming
        // numbers can be used in the naming

    // Constants in C
        // Const int a = 5;     // the value can never be changed in the program

// 2. TYPES OF OPERATORS IN C
    // Arithematic operators    --> +   -   /   *   %
    // Logical Operators        --> &&(AND)     ||(OR)      !(NOT)
    // Assignment Operators     --> =   +=  -=  *=  %=
    // Relational Operators     --> ==  !=  <   >   <=  >=
    // Bitwise operators        --> &  |  ^  ~  <<  >>      // works on the the bit level   and,  or,  xor,  once compliment,  left shift,  right shift

    // increament -->    ++
    // Decreament -->    --
    // Misc operators -->   & (address of)      * (pointer)     ?: (Ternary / conditional operator)


// 3. USER INPUT
    // to get the input from the user use "scanf()" function
        // int i;
        // printf("input: ");
        // scanf("%d", &i);     // after the scanf function you will automatically be on the next line so no need for \n
        // printf("input is %d", i);

// 4. TYPE CASTING
    //converting the datatype of an variable's value or variable itself to another datatype
    // int i = 5;   // to convert the 5 as char in the new char variable use
    // char c = (char) i;
    // or use the following to get the result directly
        // printf("the int is now float: %f", (float) i);

// 5. CONDITIONAL STATEMENTS (DECISION MAKING) IN C
    // c has "if", "if else", "else if" and "switch" statements
    // c also has conditional operators
    /*
    if(condition)
    {
        code;
    } else if(condition)
    {
        code;
    }else
    {
        code;
    }
    */
    /*
    int i = 1;
    switch(i):
        case 1:
            code;
            break;
        case 2:
            code;
            break;
        default:
            code;
            break;
    */
    // use the Ternary operator (Short hand if else) as follows
    // int i = (condition) ? value1 : value2;        // if the condition is true the i = value1 else if the condition is false i = value2
        // ex. int i = x<y ? 5 : 10

// 6. LOOPING IN C
    // loops contains block of code to repeat until the condition is satisfied
    // C has loops as: "for", "while", "do while"
    // while loop
         /*
        int i = 0;
        while (i < 5)   // while (condition)
        {
            code;
            i++;        // increment
        }
        */
    // do while loop    // will implement at least once
        /*
        int i = 0;
        do
        {
            code;
            i++;
        }while (i < 5);
        */
    // for loop
        /*
        for (int i = 0; i < 5; i++)
        {
            code;
        }
        */

// 7. FUNCTIONS IN C
    // Function declration is as follows
        // return_type function_name(parameter_type parameter_name){       // parameter is the data function needs to perform the task in it
        //     code;
        //     return value;
        // }
    // Function usage is as follows
        // function_name(argument_name)    // argument is an info given to the function to produce the result
        // can also just give the value of the argument instead of variables
    // Functions are written after the main function, but you must writer its prototype before the main function
        // prototype --> return_type function_name(parameters);     // just copy paste first line after writing the function and add ";"

// 8. STRINGS IN C
    // char *str = "Hello Wolrd!";     // or
    // char str[] = "Hello World!";    // or
    // char str[20];       str = "Hello World!";

// 9. SCOPE OF VARIABLE
    // variable can be local or globle
    // local variable is an variable created in the "{}" and is available for only that scope  // here {} is scope of the variable
        // cant be accessed from outside of the scope
    // global variable are available for all the functions including main function to use and update
        // declared outside any scope mainly before main function
        // local var takes priority if you declare the var with same name as global var for the scope of local var

// 10. ARRAYS IN C
    // array is an sequential group of the elements of same type
    // int arr[] = {0, 1, 2, 3, 4, 5};
                 // 0  1  2  3  4  5    <-- array index start from 0
    // can use loops to change the array values and print them
    // to use array values --> arr[index_number]

// 11. POINTERS
    // pointers are variables that stores the address of anothe variable
        // int a = 5;
        // int *ptr = &a;       // "&" is "address of" operator     // "*" is declaration of the pointer
    // you can change the value of original variable with the pointers
        // *ptr = 10    // now a is 10  // here "*" is pointing at the location of variable "a" or is "at this address" operator    // called as dereferencing
    // used to send the address of an variable directly into function   --> call by reference

// 12. STRUCTURES
    // can store data of different datatypes
    // declaration
        // typedef struct{
        //     int srNo;
        //     char bookName[40];
        //     char Author[40];
        //     float price;
        // } books;
    // the above creats the an struct named "books"
    // to access the elements of the struct -->
        // books.srNo = 76;

// RECURSION IN C
    // function calling itself inside it with base condition

# 0. MODULES IN PYTHON
    # top few lines of python file should contain modules as:
        # import module_name  # to import the complete module
        # from module_name import objects/function_name   # to import specific things from module

# 1. COMMENTS IN PYTHON
    # use "#" for single line comments
    # use triple qoutes for multi line comment as (''' Multi Line Comment ''')

# 2. VARIABLES IN PYTHON
    # to declare any variable in python just write name of var and assign it's value
        # name = "this is string" # string
        # age = 5                 # integer
        # weight = 3.14           # float
    # main datatype in python are Numbers, Strings, Lists, Tuples, Dictionaries

# 3. OPERATORS IN PYTHON
    # Arithematic operators   --> +, -, /, *, %, **, //
    # Logical operators       --> and or not

# 4. PRINT STATEMENT
    # print("text here")  # pyhon doesnt need \n but if you want to chang the ending use the following
    # print("text here", end = "")
    # print("%s is text" %('this'))   # the "this" will replace "%s"
    # print("%d is int", variable)      // this is like C programming language
    # Python has a different way to print variables called as f-string  or  formated string
# *     # print(f"{var_name} text after variable value")
    # print("text " * 50)         # prints the string for 50 times

# 5. LISTS IN PYTHON
    # same as array in C
        # char = ['a', 'b', 'c', 'd']
        # char[0] = 'z'   # accessing and changing 0 index element of list

    # lists can be extended or shortned
        # char.append('e')  // will add the element to list at "old_index + 1" position
        # char.insert(2, 'f')   // this will put the value at index "2" and all values after that will get there index no. incremented
        # char.remove('f')  // will remove the element from list and adjust the indexing without changing order
    # can add two or more lists
        # list1 = ['a', 'b', 'c']   and     list2 = ['d', 'e']
        # list = list1 + list2      // the result will be --> ['a', 'b', 'c', 'd', 'e']
    # list functions
        # len(list)     // will return the number of total elements present in the list
        # max(list)     // returns the largest number or last element of the alphabaticaly ordered list
        # min(list)     // returns the smallest number or first element for alphabatically ordered list

# 6. TUPLES IN PYTHON
    # tupl = (1, 2, 3, 4)
    # same as list, just cant change the value once assigned
    # other functions of list work on tuples

# 7. DICTIONARIES IN PYTHON
    # stores the data in key:value pairs
    # dict = ('key1': 15,
    #         'key2': 55,
    #         'key3': 5)
    # can access the data as
        # dict['key1'] = 25   // changes key1 value to 25
    # function to return the name of all the keys in dict
        # dict.keys()
    # function to return all the values in the dict
        # dict.values()

# 8. USER INPUT
    # var = input("text to show :")   // this function gets the user input as string and stores it in var
    # to convert input to other datatype
        # var = int(input("text to show: "))    // converts the input into int

# 9. CONDITIONAL STATEMENTS IN PYTHON
    # if, if else, elif
    # if (condition):
    #     code
    # elif (condition):
    #     code
    # else:
    #     code

# 10. LOOPS IN PYTHON
    # for loop with range
        # for i in range(value):
            # code
        # range(15) will start from 0 and end at 14 cause this are first 15 elements
        # i will carray the value of current itteration in the loop
    # for loop with lists   // loops for every value of the list
        # for i in list:
            # code
    # do while loop
        # do:
        #     code
        # while(condition)
    # while loop    // loops untill the condition is true
        # while(condition):
            # code
            # continue
    # break used to to stop the loop
    # continue used to skip the current iteration but countinue the loop
    # use break and continue with if statement

# 11. FUNCTIONS IN PYTHON
    # functions are defined using "def" keyword as:
        # def function_name(parameters):
        #     code
        #     return value
    # calling functions
        # function_name(arguments)

# 12. STRINGS AND STRING FUNCTION
    # str = "this is string"    // declaration
    # str[0:6]    // returns everything from index 0 and before index 6   i.e. skips index 6    // result--> this i
    # str[-2:]    // returns last 2 indexes     // start is strlen-2 and end is last element    // result--> ng
    # str[:-2]    // returns string without last 2 char     // starts from start of str and ends at strlen-2    //result--> this is stri

    # str.capitalize()  // capitalizes the first letter of string   //result--> This is string
    # str.find("this")  // finds the word in string and if the word is in the string then, returns the index number of the first letter of the word // result--> 0
                        # if the word not found in string then returns -1
    # str.replace("letters in str", "letters to replace with")   // eg. str.replace("is", "are")     // result--> thare are string

# 13. FILE I/O
    # file open syntax
        # file_var = open("new.txt", "w")   // creats new file, but if the file already exist then truncates it here
    # file write syntaxt
        # file_var.write("Hello, World!")   // this is written in the txt file
    # file closing
        # file_var.close()  // this is must if opening the file as above
    # if the file is in the same folder as py file just write the filename, otherwise you need to write the file path for different folder

    # modes to open file
        # r   -   read
        # w   -   write
        # r+  -   read and write
        # w+  -   write and read
        # a   -   append

    # can also use the following if dont want to close file
        # with open('filename.txt', 'w') as file:
        #     file.write("Hello, World!")   // this will work for the normal text file but for files like csv you need to create an reader variable as following

    # python has "csv" module to work with csv file (comma separated values)
        # this module has functions as DictReader, DictWriter which reads the csv file as an "list of dictionaries" and writes an dicttionary to the csv file and
        # reader, writer which simply reads and writes the csv file
        # with open(filename.csv, "r") as file:
        #     file_reader_var = csv.DictReader(file)  // this will create an dictionry with first line of csv file as keys  // file_reader_var is an iterable datatype variable
        #     for row in file_reader_var:
        #         print(row)              // this will print the row from csv file one by one


# 14. OBJECTS IN PYTHON
    # class class_name:
    #     __varname = 0   // if var starts with "__" double underscores then the variable cant be accessed by any objects directly
    #                     // to access this variables, create an function to return or change its value inside class and call the function from its created object
    #     def get_var(self):              // function to return the __varname
    #         return self.__varname
    #     def set_var(self, value):       // function to change the __varname
    #         self.__varname = value
    #     def __init__(self, value):      // this is called as constructor  // this is usefull when declaring the object // while declaring the object you can assign it values without calling above functions
    #         self.__varname = value      // __init__ is function declaring object for the class and assigning value to the specified variables   ex. //obj = class_name(value)

    # object declaration --> obj_name = classname()
    # if the class has constructor(__init__) then can also assign values while declaring the object as --> obj_name = class_name(var1_value, var2_value)

# 15. calling the main function
    # if the python file has functions then you need to either write the main code after the functions are written or as follows
        # int main():                           // write the main function as the first function
            # code in the main function
        # if __name__ == "__main__":            // at the end of file
        #     main()
    # you can directly call the main function at the end as --> main()
    # but if the python file is included as an module then the code will run automatically instead of running after being called
    # with the above if statement the py file works as both separate function and module

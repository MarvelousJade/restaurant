# Project: Dine-In Digital, A Restaurant Ordering System
- Version 0.6 
  milestones 1 and 2 open for submission.
  milestone 2 out for preview

## Objective 
In this project, you will build an application that enables waiters to take customer orders for food and drinks and generate a bill upon the order's completion. Each bill will have a unique number, and once an order is finalized, the bill will be saved in a separate file named according to its bill number.


### Milestones

|Milestone| Revision  |Comments | Walkthrough |
|------|:---:|:---:| :---: |
| [MS1](#milestone-1) | V1.0 | open | [Video](https://youtu.be/fLKefJo04ME) |
| [MS2](#milestone-2) | V1.0 | open | [Video](https://youtu.be/3TFA6RT0O4U) |
| [MS3](#milestone-3) | V1.0  | preview  | |
| [MS4](#milestone-4) | V1.0  | |  |
| [MS5](#milestone-5) | V1.0 |  |  |

For this project, you will develop an application that enables waiters to take customer orders for food and drinks, and generate a bill upon completion of the order.

Each bill will be numbered, and after an order is finalized, a copy of the bill will be saved in a separate file titled with the corresponding bill number.


## Milestones due dates
This project will be done in 5 milestones and each milestone will have its due date. The due date of each milestone is stated below, and it is based on the amount of work to be done for that milestone. 

## Final project mark and due dates

|Milestone| Mark | Due date | Submission Policy|
|:------:|:---:|:---:|-------|
| MS1 | 10% | Nov 10 | gets full mark even if 1 week late. gets 0% afterwards|
| MS2 | 10% | Nov 15 | gets full mark even if 1 week late. gets 0% afterwards|
| MS3 | 10% | TBA | gets full mark even if 1 week late. gets 0% afterwards|
| MS4 | 10% | TBA | gets full mark even if 1 week late. gets 0% afterwards|
| MS5 | 60% |  Dec 5 | See below|

> To make the final submission of the project easier and to make it possible to partially submit a project we have divided the submission of milestone 5 into six small ones. Each submission is worth 10% of the project mark. Your project will be marked only if you have all four milestones and at least have one of the 6 six submissions of milestone 5. 

|Milestone 5<br/> Divided into<br/>Six submission| Mark | Due date | Submission Policy|
|:------|:---:|:---:|-------|
| m51 (Functional Menu system) | 10% | Dec 5| 10% penalty for each day being late up to 5 days|
| m52 (Fool proof data entry) | 10% |Dec 5| 10% penalty for each day being late up to 5 days|
| m53 (List Food and Drink) | 10% | Dec 5| 10% penalty for each day being late up to 5 days|
| m54 (Order Food And Drink) | 10% | Dec 5| 10% penalty for each day being late up to 5 days|
| m55 (Print and save bill) | 10% | Dec 5| 10% penalty for each day being late up to 5 days|
| m56 (Reset Bill and Safe exit) | 10% | Dec 5| 10% penalty for each day being late up to 5 days|

> The first 4 milestones will not be marked based on the code but on their success and their timely submissions. You may modify or debug your previous code as you are going through the milestones. The only milestone that is going to be scrutinized based on your code will be milestone 5. If you require any feedback on your first four milestones you need to ask your professor to do so.

***NOTE:***<br/>
**Your project will receive a mark of zero if any of the first four milestones are not submitted by the rejection date <br />For your project to be marked, you must submit the first 4 milestones and at least one of the 6 submissions of Milestone 5**

You can check the due date of each milestone using the ```-due``` flag in the submission command:
```bash
~profname.proflastname/submit 2??/prj/m? -due
```
- replace **2??** with the subject code
- replace **m?** with the milestone number

## Citation, Sources

When submitting your work, all the files submitted should carry full student information along with the "citation and sources" information. See the following example:

If you have multiple submissions of the same milestone, please update the Revision History in each submission so your professor knows what changes to look for.

```C++
/* Citation and Sources...
Final Project Milestone ? 
Module: Whatever
Filename: Whatever.cpp
Version 1.0
Author	John Doe
Revision History
-----------------------------------------------------------
Date      Reason
2024/?/?  Preliminary release
2024/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code 
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
OR
-----------------------------------------------------------
Write exactly which part of the code is given to you as help and 
who gave it to you, or from what source you acquired it.
-----------------------------------------------------------*/
```

**Failing to include the above citation in any of the files containing your work will cause the rejection of your project submission**

## Compiling and Testing Your Program

All your code should be compiled using this command on `matrix`:

```bash
g++ -Wall -std=c++11 -g -o ws file1.cpp file2.cpp ...
```

- `-Wall`: the compiler will report all warnings
- `-std=c++11`: the code will be compiled using the C++11 standard
- `-g`: the executable file will contain debugging symbols, allowing *valgrind* to create better reports
- `-o ws`: the compiled application will be named `ws`

After compiling and testing your code, run your program as follows to check for possible memory leaks (assuming your executable name is `ws`):

```bash
valgrind --show-error-list=yes --leak-check=full --show-leak-kinds=all --track-origins=yes ws
```

- `--show-error-list=yes`: show the list of detected errors
- `--leak-check=full`: check for all types of memory problems
- `--show-leak-kinds=all`: show all types of memory leaks identified (enabled by the previous flag)
- `--track-origins=yes`: tracks the origin of uninitialized values (`g++` must use `-g` flag for compilation, so the information displayed here is meaningful).

To check the output, use a program that can compare text files.  Search online for such a program for your platform, or use *diff* available on `matrix`.

> All the code written in the project must be implemented in the **seneca** namespace.

> Make sure that all the debugging code and debugging comments are removed before submission.

## Project Implementation notes:  *Very Important, read carefully*
- All the code written in this project should be within the namespace seneca.
- You are free and encouraged to add any attributes(member variables), functions and methods (member functions) you find necessary to complete your code. If you are not sure about your strategy for adding functionalities and properties to your classes, ask your professor for advice.  
- If any methods are being added and they are not called outside the scope of the class, make sure they are private.

- Unless you are asked for a specific definition, name the variables, and functions yourself. Use proper names and follow the naming conventions instructed by your professor. Having meaningless and misleading names will attract a penalty.

- When creating methods (member functions) make sure to make them constant if in their logic, they are not modifying their class.

- When passing an object or variable by address or reference, if they are not to be modified, make sure they are passed as constant pointers and references.

- If an Empty state is required for an object, it is considered to be an “invalid” empty state, and objects in this state should be rendered unusable.

- A module called **Utils** is added to the project that can be used for your custom functions and classes in your implementation. This module has already few methods you an use <br /> You can add any custom code of your own to the **Utils** module to be used throughout the project. <br /> 

- You may reuse and copy any code your professor provided `with citation` for your workshops or functions you may have from previous work in this subject or other subjects and place it in the Utils module. 

# Project Modules Overview

The project is divided into six main modules and a main module that launches the application:

1. Utils
2. Menu
3. Billable
4. Food
5. Drink
6. Ordering
7. main


## Utils
This module should include utility functions used throughout the project to simplify development. For example:

- Functions for dynamic memory allocation for C-strings.
- Foolproof input handling functions (e.g., to ensure valid data types).
- Other common helper functions to prevent code duplication.


## Menu
In this module, unlike the other modules you have created, there are two classes:

- `MenuItem` Class: Represents individual items on the menu.
- `Menu` Class: Manages a collection of `MenuItem` objects and allows the user to select items from the menu.

> You will implement member functions and operators that handle adding, removing, and displaying MenuItem objects and facilitate user interaction for selection.

 `MenuItem` and `Menu`. The `Menu` class owns a series of `MenuItem` objects and provides selection facilities for the user. 

## Billable
Abstract Base Class: This class serves as a foundation for all items that can be billed (e.g., food and drinks). 

It will define common interfaces (pure virtual functions) that derived classes must implement.

## Food

Derived Class: Inherits from Billable and represents a food item. This class should allow for different portion sizes, such as:

- Child portion
- Adult portion

## Drink

Derived Class: Inherits from Billable and represents a drink item. It should support various sizes:

- Small
- Medium
- Large
- Extra Large

## Ordering

This module manages the ordering process and will include methods for:

- Loading available foods and drinks from data files.
- Displaying food and drink lists separately.
- Taking customer orders (interacting with the Menu class).
- Generating and printing the bill.
- Saving a copy of the bill to a file named after the bill number.

## Main. 

The main module should initialize and coordinate the program by:

- Creating an Ordering object.
- Handling user interactions (as the waiter) to navigate the ordering process.
- Calling methods from the Ordering class to execute actions based on user input.



# Milestone 1


> Note: As we move forward through the milestones of this project, remember that, like in any real-life project, we may need to revisit previous implementations to make changes or corrections to accommodate future requirements.

## `constants.h`
This header file is used to hold all the constant values used in the project. For now, add the following constant value:

- `MaximumNumberOfMenuItems` set to 20. (preferably unsigned)


## MenuItem class

Initially, we will implement this class as a standalone class. We will test it and make sure it works correctly. In Milestone 2, we will implement the Menu class, which is a composition of MenuItem objects.

When creating a menu formatted like the one below, the `title`, the `numbered rows`, and even `the prompt` for data entry at the end are considered MenuItem objects:

```text
Seneca Resturant                        <----  title
 1- Order                               <----  numbered row
 2- Print Bill
 3- Start a New Bill                    <----  numbered row
 4- List Foods
 5- List Drinks                         <----  numbered row
 0- End Program
>                                       <----  the prompt
```

In a module called Menu (i.e., Menu.h and Menu.cpp), create a class called MenuItem.

The MenuItem class must have a minimum of four attributes:

- A character pointer to hold the MenuItem content dynamically.
- An integer (preferably unsigned) to keep track of the number of indentations.
- An integer (preferably unsigned) to keep track of the size of each indentation in characters.
- An integer to be used for the numbering of MenuItem objects.


### Constructoin
The MenuItem should be constructed using the following four values:

- A C-string holding the content. This should be stored dynamically in the MenuItem content.
- The number of indentations.
- The size of each indentation.
- An integer for the row number (only used for numbered menu items).

#### Constructor Validations

If any of the following conditions occur, the MenuItem should be set to a safe empty state:

- The content is nullptr, empty, or consists only of whitespace characters.
- Any of the indentation or indentation size values exceed 4.
- The row value is greater than `MaximumNumberOfMenuItems`.

### Rule of three
The Rule of Three must be applied to MenuItem to ensure it is not copyable or assignable to another MenuItem, and that the memory is properly deallocated when a MenuItem is destroyed.

### bool Type Conversion Overload
If a MenuItem is cast to a bool, it should return false if it is in a safe empty state and true if it is a valid MenuItem.

### Display
The MenuItem class should have a display member function that outputs the formatted content of the MenuItem to an ostream. This function should be defined as follows:
```c++
ostream& display(ostream& ostr) const;
```
#### Function Requirements:
- The function should output the formatted content of the `MenuItem` to the given `ostream`.
- If the `MenuItem` is valid (m_content is not null), the function should:
   - Display the content with proper indentation based on the `indentation number` and the `indentation size`. 
   - Include the `row` number formatted as a two-character-wide value followed by `"- "` if row is non-negative.
   - Display the content without any leading whitespace. (skip the spaces in conent)
- If the MenuItem is in an invalid or safe empty state (e.g., m_content is null), the function should output `"??????????"`.
#### Output Expectations:
- Indentation should be added to align the content appropriately.
- The row number, if present, should be right-aligned and followed by `"- "`.
- If the content is invalid, display `"??????????"` instead.

## ms1 tester program

[ms1.cpp](ms1/ms1.cpp)

### Sample Execution

[correct_output.txt](ms1/correct_output.txt)


## MS1 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp and ms1.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m1
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)

# Milestone 2

## Menu class

Add a class to the `Menu` module called `Menu`. The `Menu` class must own the `MenuItem` class as part of its composition. To enforce this, the `MenuItem` class should only be accessible by the `Menu` class.

To achieve this, remove the `public` keyword from the `MenuItem` class and make it fully private.

Forward declare the `Menu` class above the `MenuItem` class and add Menu as a friend to the `MenuItem` class.

With this change, only the Menu class can instantiate the `MenuItem` class.

### Attributes
- Add three integer (preferably unsigned) attributes to keep track of the i`ndentation number and size` for the `MenuItem` objects, as well as the `number of MenuItem objects` currently held in the Menu.

- Add three `MenuItem` attributes for the `title`, `exit option`, and `selection entry prompt` of the Menu. Note that since `MenuItem` does not have a default constructor, these attributes must be initialized in `the member initializer list`. Ensure the initialization order matches the order in which the attributes are declared in the `Menu` class, as some compilers may issue warnings if the order is inconsistent. 
   > Note that the row number of the `exit option` should be set to zero.

- Add an `array` of `MenuItem` pointers sized according to the constant `MaximumNumberOfMenuItems`. The additional MenuItem objects should be stored `dynamically` in this array. Ensure that the number of `MenuItem` objects does not exceed the size of the array.

### Construction
Create a Menu constructor with the following four arguments:

- A C-string for the title.
- A C-string for the exit option content, defaulted to "Exit".
- An indentation number, defaulted to zero.
- An indentation size, defaulted to 3.

Initialize the corresponding attributes with the above arguments, and initialize the selection entry prompt MenuItem to "> ".

Set all elements of the pointer array to nullptr.

### `<< Operator` Overload for Menu

Implement the `<< operator` overload for the `Menu` class to add new `MenuItem` objects `dynamically`.

#### Requirements:
- The operator should take a `const char*` representing the `content` of a new `MenuItem`.
- Check if the current number of `MenuItem` objects is less than `MaximumNumberOfMenuItems` before adding a new item.
- If the condition is met:
   - Dynamically create a new `MenuItem` using the provided `menuItem content`, the current indentation level, the indentation size , and the row number (calculated as number-of-menu-items + 1).
   - Store the new `MenuItem` pointer in the MenuItem pointer array.
   - Increment number-of-menu-items to reflect the addition.
- Return `*this` to allow chaining of the operator.
#### Constraints:
- Ensure that number-of-menu-items does not exceed `MaximumNumberOfMenuItems`. If the array is full, the operation should not add a new item or increment number-of-menu-items.

This operator overload will enable the use of the << operator to add MenuItem objects to a Menu, enhancing readability and simplifying the process of building a Menu.

### Rule of five
Copying and assignment of a Menu object should be explicitly prevented. Although this is inherently enforced by the MenuItem attributes being private to the Menu class, adding a deleted copy constructor and copy assignment operator as comments enhances code maintainability and clarity.

Implement a destructor that iterates through the array of MenuItem pointers, deletes each non-null pointer, and sets them to nullptr to safely release allocated memory.

### select Method 
```c++
size_t select() const;
```
Implement the select method for the `Menu` class that performs the following actions:

#### Requirements:
- Display the Title: If the `Menu` object has a title, it should be displayed first.
- Display `Menu` Items: Iterate through all `MenuItem` objects stored in the `Menu` and display them one by one.
- Display `Exit Option`: Display the `exit option MenuItem` after the list of main `MenuItem` objects.
- Display the `Selection Prompt`: Display the `selection prompt` `MenuItem` to the user to indicate that input is expected.
- Return the User's Selection: Obtain and return a validated integer input representing the user's choice. The input should only be valid if it falls within the range of 0 (representing the exit option) to the number of MenuItem objects currently in the Menu. See the `getint funtion` suggestion below.
#### Expected Outcome:
- The method should output the full menu structure in a readable format and handle the user’s selection.
- The method should ensure that the selection is a valid integer within the specified range before returning it.
#### Sample output
Here are two menus; first as zero indentation, second one has one indentation
```text
Seneca Resturant
 1- Order
 2- Print Bill
 3- Start a New Bill
 4- List Foods
 5- List Drinks
 0- End Program
> 1
   Order Menu
    1- Food
    2- Drink
    0- Back to main menu
   >
```

### Insertion operator overload into ostream
Create an `operator<<` overload for the Menu class:
```c++
size_t operator<<(std::ostream& ostr, const Menu& m);
```
#### Requirements:
- The operator should handle output to an ostream.
- When ostr is cout (check their address and make sure they are the same), the operator should invoke the select() method of the Menu class and return the user's selection.
- The return value should be the result of the select() method, representing the user’s choice from the menu.
- If the ostream is not cout, do not perform the selection operation; simply return 0.
#### Outcome:
- The operator should display the Menu on cout and allow the user to make a selection, returning the valid selection as a size_t.
- Ensure that the operator returns 0 when used with any ostream other than cout.

> Note that this insertion overload, unlike other DO NOT return the ostream reference.

## Utils module foolproof entry functions
> The following will be tested in milestone 6

To ensure foolproof data entry, consider writing two functionw in the Utils module and using them within your select method.

### getint
   ```c++
   int getInt(int min, int max);
   ```
Create a method in the Utils class to handle integer input with the following requirements:

#### Requirements:
- Prompt for Valid Input: Continuously prompt the user until a valid integer is entered.
- Handle Empty Input: If the user presses enter without typing anything, display:
   ```text
   You must enter a value: 
   ```
- Validate Integer Input: If the user enters non-integer data, display:
   ```text
   Invalid integer: 
   ```
   Clear the error state before prompting again.
- Check for Trailing Characters: If there are extra characters after the integer, display:
   ```text
   Only an integer please: 
   ```
   Prompt the user again for input.
- Clear Input Buffer: After processing input, clear any remaining characters in the input buffer to prepare for the next entry.

#### Outcome:
The method should only return a valid integer after ensuring it meets all the above criteria.
The logic should prevent any invalid or unexpected input from being processed, ensuring the program can handle user input robustly.

### getint(min,max)
```c++
int getInt(int min, int max);
```
Create an overload of the getInt() function in the Utils module:

#### Requirements:
- This function should repeatedly prompt the user for integer input until a valid value within the specified range (min to max, inclusive) is provided.
- Use the getInt() function to handle basic integer input and validation.
- If the entered value is outside the specified range, display an error message and prompt the user to try again.
- The process should continue until the user enters a value that meets the range criteria.
#### Expected Error Message:
- If the input value is out of range, display:
   ```text
   Invalid value: [min <= value <= max], try again:
   ```
   > Replace min and max with the respective values passed as arguments.
#### Outcome:
The function should return a valid integer that lies within the min to max range after ensuring that all input is properly validated and error-handled.

## ms2 tester program

[ms2.cpp](ms2/ms2.cpp)

### Sample Execution

[correct_output.txt](ms2/correct_output.txt)

### Data Entry for ms2
```text
1<ENTER>
0<ENTER>
2<ENTER>
2<ENTER>
0<ENTER>
0<ENTER>
0<ENTER>
```

### Date Entry for foolproof entry
> Will be tested in milstone 6
```text
<ENTER>
abc<ENTER>
123abc<ENTER>
-1<ENTER>
4<ENTER>
0<ENTER>
```
> Also try running option 3 for the Final Milestone Application Demo and see how it works.
### Foolproof entry output sample
```text
Milestone 2
 1- Run Test 1
 2- Run Test 2
 3- Final Milestone Application Demo
 0- Exit
>
You must enter a value: abc
Invalid integer: 123abc
Only an integer please: -1
Invalid value: [0<= value <=3], try again: 4
Invalid value: [0<= value <=3], try again: 0
Have a good day!
```


## MS2 Submission 

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp and ms2.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m2
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)


## Milestone 3: Billable, Food, and Drink Modules

> **Note:**  
In this milestone, as before, you can simplify your code by using functions from the `Utils` module. This module provides utilities for tasks such as dynamic memory allocation, foolproof data entry, and string manipulation. Refer to the `Utils` functions whenever you encounter a repetitive or low-level operation, as this can help you focus on the main logic of your classes.

---

### `Billable` Class
The `Billable` class serves as an abstract base for items that can be added to a customer’s bill. It contains attributes and methods that define shared functionality among all billable items.

1. **Attributes:**
   - **`m_name`**: A dynamically allocated C-string to hold the name or description of the item.
   - **`m_price`**: A `double` representing the base price of the item.

2. **Protected Methods:**
   - **`void price(double value)`**: Sets the item’s price.
   - **`void name(const char* name)`**: Sets the item’s name, handling dynamic allocation.

3. **Public Methods and Overloads:**
   - **Constructors and Destructor**:
     - A default constructor initializes an empty `Billable` item.
     - Copy constructor and assignment operator to handle deep copies of dynamic members.
     - A virtual destructor ensures proper cleanup of derived objects.

   - **Virtual Methods**:
     - **`double price() const`**: Returns the item’s price, allowing derived classes to override if needed.

   - **Pure Virtual Methods** (to be implemented in derived classes):
     - **`ostream& print(ostream& ostr=cout)const`**: Displays item information in a formatted way.
     - **`bool order()`**: Takes customer order for details of the item (e.g., size, customizations).
     - **`bool ordered()const`**: Returns true if details have been set, indicating the item is ordered.
     - **`ifstream& read(ifstream& file)`**: Reads item details from an input file.

   - **Operator Overloads**:
      ```c++
      double operator+(double money, const Billable& B);
      double& operator+=(double& money, const Billable& B);
      ```
     - `+` and `+=` are overloaded to allow adding an item’s price to a total amount (of type `double`), enabling easy bill calculations.
     - **Conversion Operator (`operator const char*()const`)**: Provides access to the name for display or comparison.

---

### `Drink` Class
The `Drink` class inherits from `Billable` and represents a drink item. It adds functionality to manage the drink size and customizes price based on size.

1. **Attributes:**
   - **`m_size`**: A `char` indicating the size of the drink (e.g., `'S'` for small, `'M'` for medium, `'L'` for large, and `'X'` for extra large). If `m_size` is unset, it defaults to a safe empty state, and `"....."` will display for the size.

2. **Public Methods**:
   - **`print`**: Overrides `Billable`’s print to display or save the drink’s name, size, and price.
   
      The `print` method outputs the drink in the following format:
      - **name**: Up to 25 characters in 28 spaces, left-justified and padded with dots (`'.'`).
      - **size**: Displays as `"SML.."`, `"MID.."`, `"LRG.."`, `"XLR.."` for small, medium, large, and extra large sizes, respectively. If size is unset (i.e., `!ordered()`), it displays as `"....."`.
      - **price**: Right-justified in 7 spaces, padded with spaces and displayed with 2 decimal places.

   - **`order`**:  Overrides `Billable`’s order as follows:
      Displays a menu for drink size selection with 3 indentations:
      ```text
      Drink Size Selection
         1- Small
         2- Medium
         3- Large
         4- Extra Large
         0- Back
      >
      ```
     Sets the order size to its acceptable values or leaves it unset if "Back" is selected.

     The method returns `true` if the size was selected (indicating it was ordered) or `false` if not.

   - **`ordered`**:  Overrides `Billable`’s ordered, returning `true` if a size has been selected.

   - **`read`**:  Overrides `Billable`’s read.
     Reads the drink’s details from a comma-separated input file in the following format:
     ```text
     name of drink,price
     ```
     Example:
     ```text
     Orange Juice,3.5<Newline>
     ```
     If the read is successful, the details are set to corresponding values; otherwise, nothing changes.

   - **`price`**: Adjusts the base price based on `m_size` as follows:
     - Returns `Billable` price if size is large or if item is not ordered.
     - For small, returns half of the price; for medium, returns 3/4 of the price; and for extra large, returns 1.5 times the original price.

3. Since this class does not manage resources outside of its scope, it does not require implementing the rule of three. The object is always created in a safe empty state.

---

### `Food` Class
The `Food` class, derived from `Billable`, represents a food item and includes functionality for customization and portion type.

1. **Attributes:**
   - **`m_ordered`**: A boolean flag indicating whether the item has been ordered.
   - **`m_child`**: A boolean representing if the food is a child portion, which affects pricing.
   - **`m_customize`**: A dynamically allocated C-string for storing customization notes (e.g., "No onions").

2. **Public Methods and Overloads**:
   - **Constructors and Destructor**: The copy constructor, assignment operator, and destructor manage dynamic allocation for `m_customize`. The no-argument constructor leaves the object in a safe empty state.

   - **`print`**: Overrides `Billable`’s print to display or save the food item’s details, including portion type. Customizations are printed only if the `ostream` object is `cout`:
     - **name**: Up to 25 characters in 28 spaces, left-justified and padded with dots (`'.'`).
     - **portion type**: Displays `"Child"` or `"Adult"` if `ordered()` is `true` and `m_child` is set. Otherwise, it displays `"....."`.
     - **price**: Right-justified in 7 spaces, padded with spaces, and displayed with 2 decimal places.
     - **customizations**: If `m_customize` is not null and `ostream` is `cout`, it prints `" >> "` followed by the first 30 characters of `m_customize`. Otherwise, nothing is printed.

   - **`order`**:  Overrides `Billable`’s order as follows:
      Displays a menu for food portion selection with 3 indentations:
      ```text
      Food Size Selection
         1- Adult
         2- Child
         0- Back
      > 
      ```
      Sets the order portion to its acceptable values, setting `m_ordered` to `true`. If "Back" is selected, the portion remains unset.

      If a portion is ordered, the user is prompted for customization:
      ```text
      Special instructions
      > 
      ```
      If the user just presses enter, no customization is added, and `m_customize` remains null. Otherwise, customization instructions are stored in `m_customize` (you may refer to the `Utils` functions for dynamic memory allocation here).

      The method returns `true` if a portion is ordered, or `false` if not.

   - **`ordered`**:  Overrides `Billable`’s ordered, returning the `m_ordered` flag.

   - **`read`**:  Overrides `Billable`’s read.
     Reads the food’s details from a comma-separated input file in the following format:
     ```text
     name of Food,price
     ```
     Example:
     ```text
     Pasta with Tomato sauce,3.5<Newline>
     ```
     If the read is successful, the details are set to corresponding values; otherwise, the object remains unchanged.

   - **`price`**: Overrides `Billable`’s price. 
     Returns half the price if ordered and `m_child` is true, indicating a child portion; otherwise, it returns the original `Billable` price.
## ms3 tester program

TBA

### Sample Execution

TBA

### Data Entry for ms3
TBA



## MS3 Submission  (not opened yet)

> If you would like to successfully complete the project and be on time, **start early** and try to meet all the due dates of the milestones.


Upload your source code and the tester program (**Utils.cpp, Utils.h, Menu.h , Menu.cpp, Billable.h, Billable.cpp, Drink.h, Drink.cpp, Food.h, Food.cpp and ms3.cpp**) to your `matrix` account. Compile and run your code using the `g++` compiler [as shown in the introduction](#compiling-and-testing-your-program) and make sure that everything works properly.

Then, run the following command from your account (replace `profname.proflastname` with your professor’s Seneca userid):
```
~profname.proflastname/submit 2??/prj/m3
```
and follow the instructions.

- *2??* is replaced with your subject code


### The submit program's options:
```bash
~prof_name.prof_lastname/submit DeliverableName [-submission options]<ENTER>
[-submission option] acceptable values:
  "-due":
       Shows due dates only
       This option cannot be used in combination with any other option.
  "-skip_spaces":
       Do the submission regardless of incorrect horizontal spacing.
       This option may attract penalty.
  "-skip_blank_lines":
       Do the submission regardless of incorrect vertical spacing.
       This option may attract penalty.
  "-feedback":
       Check the program execution without submission.
```

## [Back to milestones](#milestones)

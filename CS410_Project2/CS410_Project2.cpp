// CS410_Project2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


// Declarations for program functions
int  CheckUserPermissionAccess();

void  DisplayInfo(string clientArray[]);

void  ChangeCustomerChoice(string clientArray[]);





int main()
{
    // Varables to be used to hold access and userchoice values.
    int perAccess;
    int userChoice;

    // Client array to hold hard coaded client data.
    string client[5] = { "1. Bob Jones selected option 1",
                         "2. Sarah Davis selected option 2",
                         "3. Amy Friendly selected option 1",
                         "4. Johnny Smith selected option 1",
                         "5. Carol Spears selected option 2" };



    // output statement for the company as well as who its created by
    cout << "Hello! Welcome to our Investment Company\n";
    cout << "Created by Corey L Nance\n";

    //do while loop to call the CheckUserPermissonAccess function and check the output to only finish when access is granted.
    do {

        //Original code showed data before checking permissions. Code is changed around to check permissions first 
        // then display the data.
        perAccess = CheckUserPermissionAccess();

        // Added if statement to throw an error if CheckUserPermissionAccess ever returns any number other than 1 or 0.
        if (perAccess != 1 && perAccess != 0) {
            cout << "Access Permission denied. Current Interger output not accepted\n";
            return 0;
        }

        if (perAccess == 0) {
            cout << " Invalid Password. Please try again \n";

        }
    } while (perAccess != 1);


    // do while loop to ask user for options until the user chooses to end the program.
    do {
        cout << "What would you like to do?\n";
        cout << "DISPLAY the client list(enter 1)\n";
        cout << "CHANGE a client's choice (enter 2)\n";
        cout << "Exit the program.. (enter 3)\n";


        // To fix vulnerability The input is restricted to stay between 1 and 3 
        // also has to be an integer. 
        cin >> userChoice;
        while (cin.fail() || userChoice > 3 || userChoice < 1) {
            cout << "Please Enter a number between 1 and 3" << std::endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> userChoice;
        }

        switch (userChoice) {
        case 1:
            cout << "You chose 1\n";
            DisplayInfo(client);
            break;
        case 2:
            cout << "You chose 2\n";
            ChangeCustomerChoice(client);
            break;
        case 3:
            cout << "You chose 3\n";
        default:
            cout << "switch case default statement";
        }
    } while (userChoice != 3);



}



// Function to check the user name and password, 
int  CheckUserPermissionAccess() {


    string userName;
    string userPassword;

    //Password verification should be checked against a database.
    string verPass = "123";
    int value;

    /* Potential vulnerability is having the user be able to put in any size username. 
    To fix this was to add restrictions on username length and input data type.
    Also user name is never checked. */
    cout << " Enter your username:\n";
    cin >> userName;
    while (cin.fail() || userName.length() > 50 || userName.length() < 4) {
        cout << "Please enter a user name under 50 Characters and at least 4 Characters in length that also is within min and max range" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userName;
    }

    /* Potential vulnerability is having the user be able to put in any size password.
    To fix this was to add restrictions on password length and input data type.*/
    cout << " Enter your password:\n";
    cin >> userPassword;
    while (cin.fail() || userPassword.length() > 3 || userPassword.length() < 3) {
        cout << "Please enter a password exactly 3 characters long" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userPassword;
    }

    if (userPassword.compare(verPass) == 1) {

        return 0;
    }

    if (userPassword.compare(verPass) == 0) {
        return 1;
    }


}






// function to display client info
void  DisplayInfo(string clientArray[]) {


    cout << "Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)\n";

    int size = 0;

    while (!clientArray[size].empty())
        ++size;

    cout << "The array size is " << size << " \n";


    /*Potential liability was having a hard coded for loop length for the array. 
    A problem can come up if the array is shorter than 5 or if the array is larger than 5
    A fix for this is to create a variable to hold the array length and then use that 
    variable in the for loop. To fix this would be to first Change the array of names to 
    a more scalable container then use a variable to scale along with the size of the 
    container.
    */
  

    for (int i = 0; i < size; i++) {
        cout << clientArray[i] << "\n";
    }


}

// function to allow for the user to make changes to client info.
void  ChangeCustomerChoice(string clientArray[]) {

    string userNum;
    int serviceChoice;
    



    cout << "Enter the number of the client that you wish to change\n";
    cin >> userNum;
  
    /*Potential liability is to allow for userNum to be any length.  The selections 
    would only be 1 character in so if its greater than 1 character then user has to 
    re-enter input.*/
    while (cin.fail() || userNum.length() > 1 || userNum.length() < 1 || stoi(userNum) > 5) {
        cout << "Please enter a valid selction between 1 and 5" << std::endl;
        cin.clear();
        cin.ignore(256, '\n');
        cin >> userNum;
    }

    /*Potential liability was having a hard coded for loop length for the array.
      A problem can come up if the array is shorter than 5 or if the array is larger than 5
      A fix for this is to create a variable to hold the array length and then use that
      variable in the for loop. To fix this would be to first Change the array of names to
      a more scalable container then use a variable to scale along with the size of the
      container.
      */
    
    for (int i = 0; i < 5; i++) {
        if (clientArray[i].find(userNum + ".") != -1) {
            cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement\n";
            
            cin >> serviceChoice;
            while (cin.fail() || serviceChoice > 2 || serviceChoice < 1) {
                cout << "Please enter a password exactly 3 characters long" << std::endl;
                cin.clear();
                cin.ignore(256, '\n');
                cin >> serviceChoice;
            }

            if ((serviceChoice == 1) && (clientArray[i].find("option 1") != -1)) {
                clientArray[i].replace(clientArray[i].find("option 1"), 8, "option 1");
            }
            else if ((serviceChoice == 1) && (clientArray[i].find("option 2") != -1)) {
                clientArray[i].replace(clientArray[i].find("option 2"), 8, "option 1");
            }
            if ((serviceChoice == 2) && (clientArray[i].find("option 1") != -1)) {
                clientArray[i].replace(clientArray[i].find("option 1"), 8, "option 2");
            }
            else if ((serviceChoice == 2) && (clientArray[i].find("option 2") != -1)) {
                clientArray[i].replace(clientArray[i].find("option 2"), 8, "option 2");
            }

            cout << clientArray[i] << "\n";
        }


    }
}



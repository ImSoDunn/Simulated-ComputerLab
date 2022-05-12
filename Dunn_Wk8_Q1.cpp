
#include <iostream>
#include <cstdlib>
using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes
void createArrays(IntPtr labs[], int labsizes[]);
void freeArrays(IntPtr labs[]);
void showLabs(IntPtr labs[], int labsizes[]);
void login(IntPtr labs[], int labsizes[]);
void logoff(IntPtr labs[], int labsizes[]);
void search(IntPtr labs[], int labsizes[]);


// ======================
// createArrays:
// Creates the dynamic arrays for the labs.
// The first array is the array of labs,
// The second array contains the size (or number of computers)
// we will put in each lab.  This dictates the size of the dynamic
// array.
// ======================
void createArrays(IntPtr labs[], int labsizes[])
{
    for (int i = 0; i < 4; i++)
    {
        //Point each input of array labs[] to dynamic array of size labsizes
        labs[i] = new int[labsizes[i]]; 
        for (int j = 0; j < labsizes[i]; j++)
        {
            labs[i][j] = j + 1;
        } 
    }
}
// ======================
// freeArrays:
// Releases memory we allocated with "new".
// ======================
void freeArrays(IntPtr labs[])
{
    //Compelete the function
    for (int i; i < 4; i++)
    {
        delete [] labs[i];
    }
}
// ======================
// showLabs:
// Displays the status of all labs (who is logged into which computer).
// ======================
void showLabs(IntPtr labs[], int labsizes[])
{

    //Compelete the function
    for (int i= 0; i <4; i++)
    {
        cout << "Lab " << (i + 1) << ": ";
        for (int j = 0; j < labsizes[i]; j++)
        {
            cout << labs[i][j] << " ";
        }
        cout << endl;
    }
}
// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[])
{
    int loginID, station, computer;
    //Compelete the function
    cout << "Enter your log in ID followed by the computer station you wish to use, followed by which computer in that station.";
    cin >> loginID;
    cin >> station;
    cin >> computer;

    labs[station - 1 ][computer - 1] = loginID; 
}
// ======================
// logoff:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logoff(IntPtr labs[], int labsizes[])
{
    //Compelete the function
    //search(labs, labsizes);

    int id = -1, i,j;
    bool loggedIn = false;
    // Get input from the keyboard, validating data ranges
    while ((id < 0) || (id > 99999))
    {
        cout << "Enter the 5 digit ID number of the user to log off:" << endl;
        cin >> id;
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < labsizes[i]; j++)
        {
            if (labs[i][j] == id)
            {
                labs[i][j] = j + 1;
                loggedIn = true;
                break;
            }
        }
        
    }
    if (loggedIn == true)
    {
        cout << "User has been successfully logged off." << endl;
    }

}
// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[])
{
    int id = -1, i,j;
    bool loggedIn = false;
    // Get input from the keyboard, validating data ranges
    while ((id < 0) || (id > 99999))
    {
        cout << "Enter the 5 digit ID number of the user to find:" << endl;
        cin >> id;
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < labsizes[i]; j++)
        {
            if (labs[i][j] == id)
            {
                //labs[i][j] = j + 1;
                loggedIn = true;
                cout << "The User " << id << " is logged into station " << j + 1 << " in lab " << i + 1 << endl; 
                break;
            }
        }
        
    }

    //Compelete the function
    if (loggedIn == false)
    {
        cout << "That user is not logged in." << endl;
    }
    return;
}
// ======================
//     main function
// ======================
int main()
{
    IntPtr labs[NUMLABS];  // Array to reference each lab
    int labsizes[NUMLABS]; // Number of computers in each lab
    int choice = -1;
    // Initialize labsizes to those given in the problem
    labsizes[0] = 5; // 5 computers in lab 1
    labsizes[1] = 6;
    labsizes[2] = 4;
    labsizes[3] = 3; // 3 computers in lab 4
    // Create ragged array structure
    createArrays(labs, labsizes);
    // Main Menu
    while (choice != 0)
    {
        cout << endl;
        showLabs(labs, labsizes);
        cout << "MAIN MENU" << endl;
        cout << "0) Quit" << endl;
        cout << "1) Simulate login" << endl;
        cout << "2) Simulate logoff" << endl;
        cout << "3) Search" << endl;
        cin >> choice;
        if (choice == 1)
        {
            login(labs, labsizes);
        }
        else if (choice == 2)
        {
            logoff(labs, labsizes);
        }
        else if (choice == 3)
        {
            search(labs, labsizes);
        }
    }
    freeArrays(labs); // Free memory before exiting
    return 0;
}
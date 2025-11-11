//
// Created by Christopher Vaughn on 10/29/25.
//
/**
 * @file FileUtils.cpp
 * @brief Implements utility functions for handling file operations.
 *
 * @author Aaron Vasquez
 * @date November 10, 2025
 * @version 1.0
 */

#include "FileUtils.h"
#include "Exceptions.h"     // Include for student's custom exceptions
#include <iostream>         // For cout, cerr, cin
#include <string>           // For string
#include <fstream>          // For ifstream

using namespace std;

/**
 * @brief Attempts to open a file, handling failures and retries.
 * * This function contains the logic that the student must
 * convert to use try...catch with FileOpenException.
 *
 * @param file The ifstream object to be opened (passed by reference).
 * @param initialFilename The first filename to try.
 */
void openFileForReading(std::ifstream& file, std::string initialFilename) {

    // STUDENT TODO: Replace the following 'if' block with a
    // try...catch block that throws and catches a FileOpenException.

    file.open(initialFilename);
    try {
        if (!file.is_open())
        {
            throw FileOpenException("Error: File could not be opened: " + initialFilename);
        }
        else {
            cout << "File opened successfully: " << initialFilename << endl;
        }
    }
    catch (FileOpenException& excpt)
    {
        cout << excpt.what() << endl; // Print out error context

        // This logic should be inside your 'catch' block
        string alternativeFilename;
        cout << "Enter alternative filename: ";
        cin >> alternativeFilename;
        file.open(alternativeFilename);

        try {
            if (!file.is_open())
            {
                throw FileOpenException("Error: Failed to open alternative file. Exiting.");
            }
            else {
                cout << "Alternative file opened successfully: " << alternativeFilename << endl;
            }
        }
        catch (FileOpenException& excpt)
        {
            cout << excpt.what() << endl; // Print out error context
            exit(1); // Exit program with error code
        }
    }
}


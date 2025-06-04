# Hotel-Booking
## NAME                ID
1.LEALEM SISAY       RNS-0262/23
2.LEMI TADESSE       RMNS-7076/23
3.MATIAS TAMIRE      RMNS-5825/23
4.KULSUM AHMEDIN     RMNS-6408/23
5.LALAWIT TEFERI     RMNS-4473/23
6.KIDIST ABEBE       RNS-9562/23



## ALGORITHM


The provided C++ code implements a simple hotel management system. It break down the bookRoom and manageBookedRooms functions.
bookRoom() Function 

The bookRoom() function handles the process of creating a new booking for a customer.
Here's a step-by-step explanation:

 1. Create New Customer Node: A new Customer object is dynamically allocated using new Customer.
 2. Input Customer Details:
   * Customer ID: It prompts the user to enter a unique customer ID using inputID(true). The true argument ensures that the entered ID is checked for uniqueness against existing customers.
   * Name: It takes the customer's name using inputName().
   * Phone Number: It takes the customer's phone number using inputPhone().
   * Room Number: It prompts for a room number using inputRoom(). This function ensures the room number is within the valid range (1-10) and is not already booked.
 3. Input Check-in Date:
   * It prompts the user to enter the check-in date in DD/MM/YYYY format using inputDate("Enter Check-in Date").
   * Validation: It validates that the check-in date is not in the past. For testing purposes, a fixed current date (June 4, 2025) is used for comparison, but it can be changed to getCurrentDate() for real-time validation.
 4. Input Check-out Date:
   * It prompts the user for the check-out date using inputDate("Enter Check-out Date").
   * Validation: It ensures that the check-out date is strictly after the check-in date.
 5. Calculate Stay Duration and Total Bill:
   * The checkIn and checkOut dates are converted from Date structs to integer format (YYYYMMDD).
   * stayDays is calculated using daysBetween(checkInDate, checkOutDate).
   * totalBill is calculated by multiplying stayDays with PRICE_PER_DAY (which is 500 Birr).
 6. Mark Room as Booked: The rooms array, which keeps track of room availability, is updated to mark the chosen roomNumber as true (booked).
 7. Add Customer to Linked List:
   * The newCustomer node is added to the end of the head- ξεκίνησε linked list. If the list is empty (head is nullptr), the newCustomer becomes the head.
 8. Display Booking Summary: The function then displays a summary of the booking, including check-in date, check-out date, stay duration, and total bill.
 9. Save Data: Finally, saveCustomersToFile() is called to persist the updated customer data to "customers.txt".
manageBookedRooms() Function
The manageBookedRooms() function provides a sub-menu for managing existing room bookings. It allows the user to view, search, and sort customer booking information.
Here's how it works:
 10.  Display Sub-Menu: It presents a menu with the following options:
   * "1. Display All Booked Rooms"
   * "2. Search for a Customer by ID"
   * "3. Sort Customers by ID (and then display)"
   * "0. Back to Main Menu"
 11. Get User Choice: It prompts the user to choose an option.
 12. Process Choice with switch statement:
   * Case 1: displayAllBookedRooms(): If the user chooses 1, it calls displayAllBookedRooms() to show a formatted list of all current bookings.
   * Case 2: searchCustomer(): If the user chooses 2, it calls searchCustomer() to allow the user to find a specific booking by ID.
   * Case 3: sortCustomers() and displayAllBookedRooms(): If the user chooses 3, it first calls sortCustomers() to sort the linked list of customers by their ID. After sorting, it calls displayAllBookedRooms() again to show the newly sorted list.
   * Case 0: Return: If the user chooses 0, the function returns, taking the user back to the main menu.
   * Default: For any other invalid input, it displays an "Invalid option" message.
 13. Loop: The menu continues to be displayed in a while (true) loop until the user chooses option 0 to go back.
 
Algorithm for main() Function (Overall Hotel Management System)
 14. System Initialization:
   * Load all existing customer booking data from storage.
   * Prepare internal data structures (linked list, room availability).
 15. Main Application Loop:
   * Repeat Indefinitely:
     * Display Menu: Present the user with a list of available actions (e.g., "Book Room", "Manage Bookings", "Exit").
     * Get User Input: Prompt the user to select an action.
     * Execute Action:
       * If the user chooses "Display Available Rooms", execute the "Display Available Rooms" routine.
       * If the user chooses "Book Room", execute the "Book Room" routine.
       * If the user chooses "Manage Booked Rooms", execute the "Manage Booked Rooms Sub-menu" routine.
       * If the user chooses "Update Check-out Date", execute the "Update Booking" routine.
       * If the user chooses "Delete Booking", execute the "Delete Booking" routine.
       * If the user chooses "Exit":
         * Perform necessary memory cleanup (deallocate all customer records).
         * Terminate the application.
       * If the input is invalid, inform the user and continue the loop.
Explanation of its "shortness" (algorithmically):
This algorithm is already as short as it can be while still being clear about the system's core loop and responsibilities. The "shortness" comes from:
 16. Delegation: The main algorithm doesn't describe how to book a room or manage bookings; it simply states that a specific "routine" (which is another function's algorithm) is executed. This makes the main algorithm high-level and brief.
 17. Looping: The Repeat Indefinitely structure concisely captures the continuous operation of the system until an explicit exit command.
 18. Conditional Execution: The If...then...else structure effectively routes control to the appropriate sub-algorithm based on user choice.
Any further shortening would likely involve merging steps or removing essential details, which would reduce clarity rather than improve it for an algorithmic description.
 ## HOW TO RUN ## How to Run the Code
1. Clone the repository to your local machine.
2. Open the terminal and navigate to the repository directory.
3. Compile the C++ code using:
 ```bash
 g++ main.cpp -o main
Run the compiled program:
./main
Output
The program will output:

       Hotel Management Menu 
          1. Display Available Rooms
           2. Book Room
           3. Manage Booked Rooms (View, Search, Sort)
           4. Update Check-out Date
           5. Delete Booking (Archive Customer)
            0. Exit
Contributing
Feel free to contribute to this project by forking the
repository and submitting a pull request.
License
This project is licensed under the MIT License.
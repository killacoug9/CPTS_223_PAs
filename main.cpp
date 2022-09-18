/*
critera: 

Commands should be stored in a file called commands.csv, in the form  
command, ”description” 
 For example, the first row could be:  
ls, “Short for lists; displays the file and directory names in the current 
working directory.” 
  
Please note that you should place “” around your description so that it is 
interpreted as one value in the .csv file. Each command,”description” pair 
should be placed on its own line in the file. Commands may be added and 
removed from the file through the program. At least the following 30 
commands should be supported at the beginning of the game: 



Player profiles must be stored in a file called profiles.csv. Each profile 
includes a name and current points. The format for a profile is name,points. 

Upon startup of the program, the Linux command and description pairs 
from commands.csv must be loaded into a singly linked list that was 
constructed from a 2 parameter template (see “Play Game Requirement” 
design considerations). All commands may be inserted at the front of the list 
as they are read from the file. Also, the user name and points pairs 
from profiles.csv must be loaded into a profiles array. All user name 
and points pairs must also be loaded at the front (index 0) of the array. Is 
this a poor design decision? You will discuss this as part of the assignment! 
See the “Other Requirements” section. 
*/

/*
each spot in the list is gonna habe
    command
    desc
    is_active

way to shuffle linked list? thats better than randoomization
    have length. Find rand, then make that choice a added to a new list. remove from old list. Decrement Lis len 

*/

#include "./components/headers/AppWrapper.hpp"

int main(int argc, char *argv[]) {
    AppWrapper app(true);
    app.run();

    return 0;
}

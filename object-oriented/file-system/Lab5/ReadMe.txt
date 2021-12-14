The tests listed below are based off of the code written in Lab5.cpp, where we instantiated various objects as related to the commands 
that we created for file system. 

Tests Ran

1. Basic Command Prompt Functions Test

Once Lab5.exe is run, the console prompts the user to enter help for a list of commands, q to quit the program, or help followed by
a command name to in order to see the information regarding a specific command. These functions all work as intended, as q exits
the program. help returns the following output, which are all the commands available in the program.

cat
cp
ds
ls
rm
rn
touch

Lastly, help cat for example returns information regarding the cat function as does help followed by the rest of the commands.

2. LS Command Test

First, we created some test files (test.txt, test.img, random.txt, random.img). After creating the files, calling ls 
displays the following output:

random.img random.txt
test.img test.txt

Calling ls -m to display the metadata of the files returns the following output:

random.img      image   0
random.txt      text    0
test.img        image   0
test.txt        text    0

To ensure the metadata function works correctly, we edited test.txt using the cat command. Now calling ls -m 
displays the following output:

random.img      image   0
random.txt      text    0
test.img        image   0
test.txt        text    11

The ls command works fully, as it displays all files, file types, and the correct metadata of the files based off of what they contain.

3. Remove Command

We called rm test.txt to remove this file. We also called rm test.img to delete an image file type to cover all bases. 
The program notifies us that this file has been removed, and calling ls now displays this output:

random.img random.txt

Therefore, the remove command is fully operational as it deleted both files as necessary.

4. Password Protected Touch Command

We created a password protected file with this command. The input was as follows: 

 $ touch test.txt -p
Enter password: test
test.txt created successfully.

Calling ls displays the file correctly, but we will test to see if the password protection worked correctly in future tests.

5. Cat Command

We began by calling this command the non-password protected files. When attempting to edit the image file, an error is returned 
as it is not possible to add text to this file type. Therefore we edited random.txt and were able to successfully save the results
of the edit with the command :wq. Typing in :q caused the edits to not be saved. We were able to see the results of the edit using 
the ds command. 

In addition, we tested the append functionality of the cat command, adding onto the changes made on the text file. This also proved
to be successful, verified by the ds command.

Next, we attempted to use the cat command on the password protected file test.txt. If the password wasn't entered correctly, edits
made to the file were not saved. Once the password was entered correctly, edits made to the file were saved, but with and without
the append functionality.

6. Display Command

The display command has proven to be successful, as it was used to verify previous edits made. It works with the -d option as well, 
both for password protected and unprotected files. 

7. Copy Command

We tested the copy command on both for password protected and unprotected files. Both worked successfully, and for the password protected
files, in order to display the copied file, the password for the original was required to access it.

8. Macro Commands: Rename Command

We developed the rename command as a macro command, and tested it as described below. We called the command on a file named random.txt,
set it to be called ordinary. After this, using the ls command shows a file named ordinary.txt and no instance of a file named random.txt.
Displaying the file shows that it is the same file, as it has simply been rennamed. This was tested on all file types and files with
passwords.

We ran the tests described above to confirm the functionality of the commands we built as well as various small test cases to
confirm that everything was fully functional.
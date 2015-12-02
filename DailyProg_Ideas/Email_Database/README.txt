/u/Phillight 's Challenge

https://www.reddit.com/r/dailyprogrammer_ideas/comments/3v1m9x/easy_email_database_manager/

Description

Dailyprogrammer is setting up an .edu domain, where potential users can create their own email address in this domain. The email is automatically generated to the following specifications:
the name of the email must end in @dailypro.edu
the part of the email preceding @ is the first letter of the first name, and the first 7 letters of the last name.
the name of the email preceding @ must add a number to the email if that email already exists in the database. For example, if there's already a John Smith in the Email database (with the email jsmith@dailypro.edu), then the next 'J' (John, Joel, etc) Smith gets the Email jsmith2@dailypro.edu, and the next would get jsmith3, and so on.
In this challenge, you are asked to: maintain all of the names along with that person's newly generated email in a database file (e.g., database.txt).

An example of a database file:

	John Smith - jsmith@dailypro.edu
	Joseph Smith - jsmith2@dailypro.edu
	Krishna Jourdan - kjourdan@dailypro.edu
	Lenard Hullinger - lhulling@dailypro.edu
	Joel Smith - jsmith3@dailypro.edu
	John Patters - jpatters@dailypro.edu
	John Patterson - jpatters2@dailypro.edu

Example Program:

	Email Database
	New name?: Morgan Freeman
	Assigned Email: mfreeman@dailypro.edu

and now the database file looks like this:

	John Smith - jsmith@dailypro.edu
	Joseph Smith - jsmith2@dailypro.edu
	Krishna Jourdan - kjourdan@dailypro.edu
	Lenard Hullinger - lhulling@dailypro.edu
	Joel Smith - jsmith3@dailypro.edu
	John Patters - jpatters@dailypro.edu
	John Patterson - jpatters2@dailypro.edu
	Morgan Freeman - mfreeman@dailypro.edu

You can start with an empty database file, or make one up. The input to the program can be any name (first and last).
This challenge tests your ability to perform some text processing (substring matching, concatenation, rewriting) as well as process and update a text file in the target programming language.
Possible extensions/variations:
allow the user the ability to view the contents of the database right in the program
allow each user to have an account name in addition to an email, making sure the account is not already in the database
allow each user to have a password, and maybe encrypt it within the database with something simple (shifting the alphabet one letter, nothing fancy).

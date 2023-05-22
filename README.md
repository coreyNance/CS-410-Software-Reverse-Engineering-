# CS-410-Software-Reverse-Engineering-


## 2.	Explain the security vulnerabilities that are found in the blocks of C++ code.

The first vulnerability is within the main function.  This is where cin is used to take in user input and save it to the variable userChoice.  This type of vulnerability can result in causing a buffer overflow which would exceed the lowest or highest number the variable type can hold.  Also userChoice is to take in an integer but one could try to input a string or character. This is a security vulnerability because an attacker could enter a value they know is not expected and then use the error to find other potential vulnerabilities. A buffer overflow could cause unexpected actions including given up security.

The next potential vulnerability has to do with the first output statements.  In the original code, the output statements were before the user information was checked.  This is a vulnerability because an unauthorized user will have access to parts of the data without going through authorization first.

For the next vulnerability, this when the CheckUserPermissionAccess is called and returns a value. Even though its not very likely, the CheckUserPermissionAccess function could be manipulated into returning a number that’s neither 1 or 0.This is a security vulnerability because if the function returns anything other than 1 or 0, the rest of the program is expecting 1 or 0 so attackers may be able to exploit that loop hole. 

The next vulnerability has to do with the userName input for the CheckUserPermissionAccess.  This is another area where the user input can overflow the buffer or be an input that the program doesn’t expect. This is a security vulnerability because an attacker could enter a value they know is not expected and then use the error to find other potential vulnerabilities. A buffer overflow could cause unexpected actions including giving up security.

The next vulnerability has to do with the userPassword input for the CheckUserPermissionAccess.  This is another area where the user input can overflow the buffer or be an input that the program doesn’t expect. This is a security vulnerability because an attacker could enter a value they know is not expected and then use the error to find other potential vulnerabilities. A buffer overflow could cause unexpected actions including giving up security.

The next vulnerability is with the for loop in the DispalyInfo function that has a hard coded value in the for loop. If an array is greater than 5 the for loop will then have unexpected outcomes.  This is a potential vulnerability because an attacker can intentionally try to overflow the buffer, or cause an array overflow or underflow to try and exploit the hole.

Another vulnerability has to do with the userNum input for the ChangeCustomerChoice.  This is another area where the user input can overflow the buffer or be an input that the program doesn’t expect. This is a security vulnerability because an attacker could enter a value they know is not expected and then use the error to find other potential vulnerabilities. A buffer overflow could cause unexpected actions including giving up security.

Another vulnerability has to do with the serviceChoice input for the ChangeCustomerChoice.  This is another area where the user input can overflow the buffer or be an input that the program doesn’t expect. This is a security vulnerability because an attacker could enter a value they know is not expected and then use the error to find other potential vulnerabilities. A buffer overflow could cause unexpected actions including giving up security.

The next vulnerability is with the for loop in the DChangeCustomerChoice function that has a  hard coded value in the for loop. If an array is greater than 5 the for loop will then have unexpected outcomes.  This is a potential vulnerability because an attacker can intentionally try to overflow the buffer, or cause an array overflow or underflow to try and exploit the hole.

Describe recommendations for how the security vulnerabilities can be fixed. 


For the userChoice input vulnerability, there are a few ways to fix it.  To try and fix this security hole. I would create a loop to check for proper input datatype, Then check to make sure the input value does not exceed the max or min values of a datatype.  Then I would check to make sure the input matches the input selections and are not able to greater or smaller than the menu selection range. This will be fixed by implementing checks to make sure the input is within desired parameters.

For the output statement vulnerability, the way I would fix this is by first removing the output statements from the main function Then move that information into the Displaymenu function. Then not call that function until the user is validated. 

For The CheckUserPermissionAccess call, checking to make sure its either a 1 or 0 would help to control any unexpected actions.  This call would also be checked to make sure that the return does not exceed the min or max of what the datatype can hold and give a controlled error log if the buffer does happen to overflow. This will be fixed by implementing checks to make sure the input is within desired parameters.

For the userName input, here the input would have to be validated.  Also introducing userName length limits will help to keep the userName from overflowing the buffer. Validating the userName length will help with keeping secure userNames without potential areas to exploit. This will be fixed by implementing checks to make sure the input is within desired parameters.

For the userPassword input, here the input would have to be validated.  Also introducing Password length limits will help to keep the Password from overflowing the buffer. Validating the password length will help with keeping secure password without potential areas to exploit. This will be fixed by implementing checks to make sure the input is within desired parameters.

With the for loop, this loop is set to a maximum of 5 iterations. The potential vulnerability comes from if the array is ever to be smaller than 5 entries or larder than 5 entries.  If its smaller the program will error, but its better that I handle the error.  If its bigger then the program will generate and out of bounds error that a hacker could then exploit. The fix would be to try and set up the for loop to be based on the array size. This will be fixed by changing the hard coded 5 to a variable based on the array size.

For the userNum input, here the input would have to be validated and checked to make sure it’s a number.  Also, userNum should be limited to the number of selections available.  Also, userNum should be checked to make sure it never overflows the buffer.   This will be fixed by implementing checks to make sure the input is within desired parameters. 

For the serviceChoice input, here the input would have to be validated and checked to make sure it’s a number.  Also, serviceChoice should be limited to the number of selections available.  Also, serviceChoice should be checked to make sure it never overflows the buffer.  This will be fixed by implementing checks to make sure the input is within desired parameters.

With the for loop, this loop is set to a maximum of 5 iterations. The potential vulnerability comes from if the array is ever to be smaller than 5 entries or larder than 5 entries.  If its smaller the program will error, but its better that I handle the error.  If its bigger then the program will generate and out of bounds error that a hacker could then exploit. The fix would be to try and set up the for loop to be based on the array size. This will be fixed by changing the hard coded 5 to a variable based on the array size. 

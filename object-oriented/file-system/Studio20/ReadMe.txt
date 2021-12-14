It's necessary to delete the pointer to the actual file due to the fact that the proxy object will now point to the original file, 
and it would be incorrect to have multiple pointers to the original. Therefore, the pointer should be deleted. 

Test Code:

4. int main()
{
	TextFile* myfile = new TextFile("myfile.txt");
	vector<char> text = { 'a', 'b', 'c', 'd', ' ', 'r', 'a', 'n', 'd', 'o', 'm', '.' };
	PasswordProxy* protectedmyfile = new PasswordProxy(myfile, "password");
	protectedmyfile->write(text);
	vector<char> toprint = protectedmyfile->read();
	for (char c : toprint) {
		cout << c;
	}
	return 0;
}

Please input your password:
(my input here:) password
abcd random.

As can see, the code worked as anticipated, complete with double-checked password entry. When I put in the wrong password:
Please input your password:
(my input here:) blah

nothing is displayed
Test Code:

int main()
{
	SimpleFileSystem* mySystem = new SimpleFileSystem();
	SimpleFileFactory* myFactory = new SimpleFileFactory();
	string filename1 = "picture.img";
	string filename2 = "text.txt";
	AbstractFile* file1 = myFactory->createFile(filename1);
	AbstractFile* file2 = myFactory->createFile(filename2);
	vector<char> vect1a = { 'X','X',' ','X','2' };
	vector<char> vect2a = { 'a', 'b', 'c', 'd','e','f','g' };
	file1->write(vect1a);
	file2->write(vect2a);
	vector<char> vect1b = file1->read();
	vector<char> vect2b = file2->read();
	vect1b.push_back('b');
	vect2b.push_back('h');
	file1->write(vect1b);
	file2->write(vect2b);
	vector<char> read1 = file1->read();
	vector<char> read2 = file2->read();

	cout << "This is file 1: " << filename1 << endl;
	for (int i = 0; i < read1.size(); i++)
		cout << read1.at(i) << ' ';
	cout << "\n\n";

	cout << "This is file 2: " << filename2 << endl;
	for (int i = 0; i < read2.size(); i++)
		cout << read2.at(i) << ' ';

	return 0;
}
OUTPUT:
This is file 1: picture.img
XX X2b


This is file 2: text.txt
abcdefgh

It worked, as we originally wrote to the files, created new vectors to .read() to, push_back() to those vectors, wrote them back, and then
printed the new .read() vectors with a for loop.


The sequence of communication is as follows: the visit method is implemented by the visitor and is called for all elements in the
relevant data structure. The classes that can accept the visitor have a defined accept method that allow acceptable visitors to enter.

The concept of delegation comes into play when considering the BasicDisplayVisitor class. This class passes the address of the variable
to the relevant call. With the concept of delegation, a request is dispatched to the accepted visitor object, similar to this. This object
then performs the operation, or actually visits the relevant element.

If we have many unique visitors, it may be difficult to use this pattern to implement the previously mentioned functionalities because
it would be too widespread and difficult to account for all of the potential visitors. 